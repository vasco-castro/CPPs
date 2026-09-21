
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

static bool openFiles(const std::string &filename, std::ifstream &readFile, std::ofstream &writeFile) {

	// Check inFile opens
	readFile.open(filename.c_str());
	if (!readFile.is_open())
		return (std::cerr << "Cannot open " << filename << std::endl, false);

	// Check outFile opens
	std::string filename_replace(filename + ".replace");
	writeFile.open(filename_replace.c_str());
	if (!writeFile.is_open())
		return (std::cerr << "Cannot open " << filename_replace << std::endl, false);

	return true;
}

static std::string replaceAll(const std::string &str, const std::string &s1, const std::string &s2) {

	std::string result;
	std::size_t start = 0;
	std::size_t found;
	while ((found = str.find(s1, start)) != std::string::npos) {
		result.append(str, start, found - start);	// text before the match
		result.append(s2);							// replacement
		start = found + s1.length();				// continue after the match
	}
	result.append(str, start, std::string::npos);	// rest after the last match
	return result;
}

static bool sed(const std::string &filename, const std::string &s1, const std::string &s2) {

	if (filename.empty())
		return (std::cerr << "Error: filename cannot be empty" << std::endl, false);
	if (s1.empty())
		return (std::cerr << "Error: The string to replace cannot be empty" << std::endl, false);
	
	std::ifstream readFile;
	std::ofstream writeFile;
	if (!openFiles(filename, readFile, writeFile))
		return false;

	// Reads all file into buffer, calls replaceAll with the buffer, and writes into outFile.
	std::stringstream buffer;
	buffer << readFile.rdbuf();
	std::string content = buffer.str();
	writeFile << replaceAll(content, s1, s2);

	readFile.close();
	writeFile.close();
	return true;
}

int main(int argc, char const *argv[]) {
	if (argc != 4)
		return (std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl, 1);

	if (sed(argv[1], argv[2], argv[3]))
		return 0;
	return 1;
}


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

static bool readWholeFile(const std::string &filename, std::string &content) {

	std::ifstream readFile(filename.c_str());
	if (!readFile.is_open())
		return (std::cerr << "Cannot open " << filename << std::endl, false);

	// A directory opens successfully, so probe it: peek() sets badbit on a
	// directory but only eofbit on a legitimately empty file.
	readFile.peek();
	if (readFile.bad())
		return (std::cerr << "Cannot read " << filename << ": not a regular file" << std::endl, false);

	std::stringstream buffer;
	buffer << readFile.rdbuf();
	if (readFile.bad())
		return (std::cerr << "Error while reading " << filename << std::endl, false);

	content = buffer.str();
	return true;
}

static bool writeWholeFile(const std::string &filename, const std::string &content) {

	std::ofstream writeFile(filename.c_str());
	if (!writeFile.is_open())
		return (std::cerr << "Cannot open " << filename << std::endl, false);

	writeFile << content;
	writeFile.close();	// close() flushes, so errors only surface after it
	if (writeFile.fail())
		return (std::cerr << "Error while writing " << filename << std::endl, false);

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

	// Read fully before creating the output file, so a read failure never
	// leaves a stray .replace behind.
	std::string content;
	if (!readWholeFile(filename, content))
		return false;

	return writeWholeFile(filename + ".replace", replaceAll(content, s1, s2));
}

int main(int argc, char const *argv[]) {
	if (argc != 4)
		return (std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl, 1);

	if (sed(argv[1], argv[2], argv[3]))
		return 0;
	return 1;
}

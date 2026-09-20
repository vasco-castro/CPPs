
#include <string>
#include <iostream>
#include <fstream>

bool sed(std::string filename, std::string s1, std::string s2) {

	// Check inFile opens
	std::ifstream readFile(filename.c_str());
	if (!readFile.is_open())
		return (std::cerr << "Cannot open " << filename << std::endl, false);
	
	// Check outFile opens
	std::string filename_replace(filename + ".replace");
	std::ofstream writeFile(filename_replace.c_str());
	if (!writeFile.is_open())
		return (std::cerr << "Cannot open " << filename_replace << std::endl, false);

	std::string line;
	while (std::getline(readFile, line)) {
		std::size_t i = 0;
		while ((i = line.find(s1, i)) != std::string::npos) {
			line.erase(i, s1.length());
			line.insert(i, s2);
			i += s2.length();
		}
		writeFile << line;
		if (!readFile.eof())
			writeFile << std::endl;
	}

	readFile.close();
	writeFile.close();
	return true;
}

int main(int argc, char const *argv[])
{
	if (argc != 4)
		return (std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl, 1);

	if (sed(argv[1], argv[2], argv[3]))
		return 0;
	return 1;
}

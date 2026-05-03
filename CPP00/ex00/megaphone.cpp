#include <iostream>
#include <string>

void megaphone(std::string arg)
{
	for (size_t i = 0; i < arg.length(); i++)
		std::cout << static_cast<char>(std::toupper(arg[i]));
}

int main(int argc, char const *argv[])
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			megaphone(argv[i]);
		std::cout << std::endl;
	}
	return 0;
}

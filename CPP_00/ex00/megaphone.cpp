#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int j = 1; j < argc; j++)
	{
		std::string	str(argv[j]);
		for (size_t i = 0; i < str.length() ; i++)
			std::cout << (char) std::toupper(str[i]);
	}
	std::cout << std::endl;
	return (0);
}


#include"Harl.hpp"


int main(int argc,char **argv)
{
	Harl hhaarrll;

	if (argc != 2)
	{
		std::cout << "Enter DEBUG, INFO, WARNING or ERROR as parameter depending on the message you wanna read." << std::endl;
		return (0);
	}

	hhaarrll.complain(argv[1]);

	return (0);
}

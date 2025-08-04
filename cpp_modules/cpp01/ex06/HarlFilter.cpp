
#include "HarlFilter.hpp"

static int		getLevel(std::string level);

void	Harl::complain(std::string level)
{
	void	(Harl::*pf[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int		lvl = getLevel(level);

	if (lvl < 0)	
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	switch (lvl)
	{
		case DEBUG :
		{
			for (; lvl < 4; lvl++)
				(this->*pf[lvl])();
			break;
		}
		case INFO :
		{
			for (; lvl < 4; lvl++)
				(this->*pf[lvl])();	
			break;	
		}
		case WARNING :
		{
			for (; lvl < 4; lvl++)
				(this->*pf[lvl])();
			break;
		}
		case ERROR :
		{
			for (; lvl < 4; lvl++)
				(this->*pf[lvl])();
			break;	
		}
	}
/*	for (; lvl < 4; lvl++)
		(this->*pf[lvl])();
*/}

static int		getLevel(std::string level)
{
	int 		i;
	std::string msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < 4; i++)
	{
		if (level.compare(msg[i]) == 0)
			return (i);
	}
	return (-1);
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}


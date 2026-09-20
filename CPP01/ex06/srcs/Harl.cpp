
#include "Harl.hpp"

void Harl::debug(void) const {
	std::cout << MSG_DEBUG << std::endl;
}

void Harl::info(void) const {
	std::cout << MSG_INFO << std::endl;
}

void Harl::warning(void) const {
	std::cout << MSG_WARNING << std::endl;
}

void Harl::error(void) const {
	std::cerr << MSG_ERROR << std::endl;
}

int Harl::getLevel(std::string level) const {
	std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; ++i)
			if (names[i] == level)
					return (i);
	return (LVL_NONE);
}

void Harl::complain(std::string level) const {
	switch (getLevel(level)) {
		case LVL_DEBUG:
			this->debug();
		case LVL_INFO:
			this->info();
		case LVL_WARNING:
			this->warning();
		case LVL_ERROR:
			return this->error();
		default:
			std::cout << MSG_DEFAULT << std::endl;
	}
}

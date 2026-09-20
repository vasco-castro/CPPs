
#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

# define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
# define INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
# define ERROR "This is unacceptable! I want to speak to the manager now."
# define DEFAULT "[ Probably complaining about insignificant problems ]"

enum e_level {
      LVL_DEBUG = 0,
      LVL_INFO,
      LVL_WARNING,
      LVL_ERROR,
      LVL_NONE
};

class Harl {
	private:
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error(void) const;
		int  getLevel(std::string level) const;
	public:
		void complain(std::string level) const;
};

#endif
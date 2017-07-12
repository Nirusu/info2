#ifndef __SPACESHIP_HPP__
#define __SPACESHIP_HPP__

#include <string>

class Spaceship {
public:
	std::string type;
	int speed;
	 Spaceship(std::string type, int speed);
	 bool operator==(Spaceship);
};

#endif


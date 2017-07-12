#ifndef __BINARY_SEARCH_HPP
#define __BINARY_SEARCH_HPP__

#include <vector>
#include <string>
#include "Spaceship.hpp"

// es wird die Liste aller Schiffe übergeben und der Eintrag nach dem wir suchen
int binary_search_upper(std::vector<Spaceship> ships, Spaceship ship);

#endif

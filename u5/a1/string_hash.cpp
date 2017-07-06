#include "string_hash.hpp"

unsigned char string_hash(std::string s) {
	
	// für das Hashing werden verschiedene Berechnungen auf dem String s durchgeführt
	// das Ergebnis soll in einem int zwischengespeichert werden
	int ret = 0;
	// führen Sie hier die auf dem Blatt angegebenen Berechnungen durchgeführt...
	if (s.length() == 0)
	{
		return 0;
	}
	else
	{
		char tail = s[s.length() - 1]; // get the last char of s
		std::string head = s.substr(0, s.length() - 1); // cut off s: s is our head, we just overwrite the original string
		ret = string_hash(head) ^ tail; // recursively call function again
		ret = (ret << 1 | ret >> 7); // rotate 7 to the right if we can't rotate left by 1 anymore
	}
	// weil später ein char als key verwendet wird, muss hier noch ein cast durchgeführt werden
	return (unsigned char)ret;
}
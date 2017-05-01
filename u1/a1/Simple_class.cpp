#include "Simple_class.hpp"
Simple_class::Simple_class(int input) {
    integer = input;
}
int Simple_class::get() {
	return integer;
}
void Simple_class::set(int input) {
    integer = input;
}
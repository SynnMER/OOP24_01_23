#include "IPerson.h"
#include <iostream>
void Person::fight() {
	std::cout << "Person is fighting" << std::endl;
}
const std::string& Person::getName() {
	return _name;
}
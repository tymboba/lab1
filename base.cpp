#include "base.h"

Base::Base() {cout << "Called a parameterless constructor for the Base class\n";}

Base::Base(const string& n) {cout << "The constructor with parameters for the Base class is called\n";}

Base::Base(const Base& other) {cout << "The copy constructor for the Base class is called\n";}

Base::~Base() {cout << "Called virtual destructor for Base class\n";}
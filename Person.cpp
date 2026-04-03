//Person.cpp
#include "Person.h"

Person::Person() : name(""), id(0) {}

Person::Person(string n, int i) : name(n), id(i) {}

void Person::setName(string n) {
    name = n;
}

void Person::setId(int i) {
    id = i;
}

string Person::getName() const {
    return name;
}

int Person::getId() const {
    return id;
}

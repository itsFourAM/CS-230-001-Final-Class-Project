//Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;

public:
    Person();
    Person(string n, int i);

    void setName(string n);
    void setId(int i);

    string getName() const;
    int getId() const;

    virtual void displayInfo() const = 0;
    virtual ~Person() {}
};

#endif

//mypatients.h
#ifndef MYPATIENTS_H
#define MYPATIENTS_H

#include "Person.h"
#include <iostream>
using namespace std;

class Patient : public Person {
private:
    int age;
    string appointmentDate;   // mm-dd-yyyy

public:
    Patient();
    Patient(string n, int i, int a, string apptDate);

    int getAge() const;
    string getAppointmentDate() const;

    void setAge(int a);
    void setAppointmentDate(string apptDate);

    void displayInfo() const override;

    friend ostream& operator<<(ostream& os, const Patient& p);
};

#endif

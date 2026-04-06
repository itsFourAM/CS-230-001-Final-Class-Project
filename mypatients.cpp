//mypatients.cpp
#include "mypatients.h"

Patient::Patient() : Person(), age(0), appointmentDate("") {}

Patient::Patient(string n, int i, int a, string apptDate)
    : Person(n, i), age(a), appointmentDate(apptDate) {}

int Patient::getAge() const {
    return age;
}

string Patient::getAppointmentDate() const {
    return appointmentDate;
}

void Patient::setAge(int a) {
    age = a;
}

void Patient::setAppointmentDate(string apptDate) {
    appointmentDate = apptDate;
}

void Patient::displayInfo() const {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Age: " << age << endl;
    cout << "Appointment Date: " << appointmentDate << endl;
}

ostream& operator<<(ostream& os, const Patient& p) {
    os << "[Name: " << p.getName()
       << ", ID#: " << p.getId()
       << ", Age: " << p.getAge()
       << ", Appointment Date: " << p.getAppointmentDate() << "]";
    return os;
}

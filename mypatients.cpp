#include "mypatients.h"

Patient::Patient() : name(""), id(0), age(0), appointmentDate("") {}

Patient::Patient(const std::string& n, int i, int a, const std::string& apptDate)
    : name(n), id(i), age(a), appointmentDate(apptDate) {}

std::string Patient::getName() const {
    return name;
}

int Patient::getId() const {
    return id;
}

int Patient::getAge() const {
    return age;
}

std::string Patient::getAppointmentDate() const {
    return appointmentDate;
}

void Patient::setName(const std::string& n) {
    name = n;
}

void Patient::setId(int i) {
    id = i;
}

void Patient::setAge(int a) {
    age = a;
}

void Patient::setAppointmentDate(const std::string& apptDate) {
    appointmentDate = apptDate;
}

std::ostream& operator<<(std::ostream& os, const Patient& p) {
    os << "[Name: " << p.getName()
       << ", ID#: " << p.getId()
       << ", Age: " << p.getAge()
       << ", Appointment Date: " << p.getAppointmentDate() << "]";
    return os;
}

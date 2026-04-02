#ifndef MYPATIENTS_H
#define MYPATIENTS_H

#include <string>
#include <iostream>

class Patient {
private:
    std::string name;
    int id;
    int age;
    std::string appointmentDate;   // mm-dd-yyyy

public:
    Patient();
    Patient(const std::string& n, int i, int a, const std::string& apptDate);

    std::string getName() const;
    int getId() const;
    int getAge() const;
    std::string getAppointmentDate() const;

    void setName(const std::string& n);
    void setId(int i);
    void setAge(int a);
    void setAppointmentDate(const std::string& apptDate);

    friend std::ostream& operator<<(std::ostream& os, const Patient& p);
};

#endif

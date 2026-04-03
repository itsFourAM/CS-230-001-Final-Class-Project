//PatientList.h
#ifndef PATIENTLIST_H
#define PATIENTLIST_H

#include "Node.h"
#include <string>
using namespace std;

class PatientList {
private:
    Node* head;

    string toLowerCase(const string& str) const;
    bool lessCaseInsensitive(const string& a, const string& b) const;

public:
    PatientList();
    ~PatientList();

    void addPatient(string name, int id, int age, string appointmentDate);
    Patient* findPatientById(int id);
    bool deletePatient(int id);
    void displayAllPatients() const;
    void insertionSort();
};

#endif

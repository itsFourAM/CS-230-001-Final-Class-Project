//PatientList.cpp
#include "PatientList.h"
#include <iostream>
#include <cctype>
using namespace std;

PatientList::PatientList() {
    head = nullptr;
}

PatientList::~PatientList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

string PatientList::toLowerCase(const string& str) const {
    string lower = str;
    for (int i = 0; i < lower.length(); i++) {
        lower[i] = tolower(static_cast<unsigned char>(lower[i]));
    }
    return lower;
}

bool PatientList::lessCaseInsensitive(const string& a, const string& b) const {
    return toLowerCase(a) < toLowerCase(b);
}

void PatientList::addPatient(string name, int id, int age, string appointmentDate) {
    if (findPatientById(id) != nullptr) {
        cout << "A patient with that ID already exists.\n";
        return;
    }

    Patient newPatient(name, id, age, appointmentDate);
    Node* newNode = new Node(newPatient);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    insertionSort();
    cout << "Patient added successfully.\n";
}

Patient* PatientList::findPatientById(int id) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.getId() == id) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

bool PatientList::deletePatient(int id) {
    if (head == nullptr) {
        return false;
    }

    if (head->data.getId() == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data.getId() != id) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return false;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return true;
}

void PatientList::displayAllPatients() const {
    if (head == nullptr) {
        cout << "No patients in the list.\n";
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}

void PatientList::insertionSort() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* sorted = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;

        if (sorted == nullptr || lessCaseInsensitive(current->data.getName(), sorted->data.getName())) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != nullptr &&
                   !lessCaseInsensitive(current->data.getName(), temp->next->data.getName())) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    head = sorted;
}

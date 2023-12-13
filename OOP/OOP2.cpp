#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Private;

class Personal {
private:
    string name;
    string surname;
    int roll_no;
    string branch;
    string div;
    Private* privateData;

public:
    Personal() : name(""), surname(""), roll_no(0), branch(""), div(""), privateData(nullptr) {}

    friend class Private;

    void input();
    void displayRecord() const;
};

class Private {
private:
    string DOB;
    string blood;
    string phone;
    string address;
    string drivingLicenseNo;

public:
    Private() : DOB(""), blood(""), phone(""), address(""), drivingLicenseNo("") {}

    friend class Personal;

    void inputPrivateInfo() {
        cout << "Enter Date of Birth: ";
        cin >> DOB;
        cout << "Enter Blood Group: ";
        cin >> blood;
        cout << "Enter Phone Number: ";
        cin >> phone;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter Driving License Number: ";
        cin >> drivingLicenseNo;
    }

    void displayPrivateInfo() const {
        cout << "Date of Birth: " << DOB << endl;
        cout << "Blood Group: " << blood << endl;
        cout << "Phone Number: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "Driving License Number: " << drivingLicenseNo << endl;
    }
};

void Personal::input() {
    cout << "Enter the name of the student: ";
    cin >> name;
    cout << "Enter the surname of the student: ";
    cin >> surname;
    cout << "Enter the roll number of the student: ";
    cin >> roll_no;
    cout << "Enter the class of the student: ";
    cin >> branch;
    cout << "Enter the division of the student: ";
    cin >> div;

    privateData = new Private();
    privateData->inputPrivateInfo();
}

void Personal::displayRecord() const {
    cout << "Name: " << name << " " << surname << endl;
    cout << "Roll Number: " << roll_no << endl;
    cout << "Class: " << branch << endl;
    cout << "Division: " << div << endl;

    if (privateData) {
        privateData->displayPrivateInfo();
    }
}

int main() {
    vector<Personal> students;
    int recordsCreated = 0;

    char choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Input student data\n";
        cout << "2. Display student data\n";
        cout << "3. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                {
                    Personal student;
                    student.input();
                    students.push_back(student);
                    recordsCreated++;
                    cout << "\nStudent data entered successfully.\nTotal records: " << recordsCreated << "\n";
                }
                break;
            case '2':
                for (int i = 0; i < students.size(); ++i) {
                    cout << "\nStudent " << i + 1 << "\n";
                    students[i].displayRecord();
                    cout << endl;
                }
                break;
            case '3':
                cout << "\nExiting the program.\n";
                break;
            default:
                cout << "\nInvalid choice.\n";
        }

    } while (choice != '3');

    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_STUDENTS = 100;

class Student {
private:
    char name[20];
    char surname[20];
    int roll_no;
    char branch[6];
    char div[2];

public:
    Student() : roll_no(0), name(""), surname(""), branch(""), div("") {}

    friend class STUD;

    void input() {
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
    }

    void displayHeader() {
        cout << "\nRoll\tName\tClass\tDiv\n";
    }

    void display() {
        cout << roll_no << "\t" << name << " " << surname << "\t" << branch << "\t" << div << endl;
    }

    void displayRecord(const char *DOB, const char *blood, const char *phone, const char *address, const char *drivingLicenseNo) const {
        cout << "\nRoll Number: " << roll_no << endl;
        cout << "Name: " << name << " " << surname << endl;
        cout << "Class: " << branch << endl;
        cout << "Division: " << div << endl;
        cout << "Date of Birth: " << DOB << endl;
        cout << "Blood Group: " << blood << endl;
        cout << "Phone Number: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "Driving License Number: " << drivingLicenseNo << endl;
    }
};

int main() {
    Student students[MAX_STUDENTS];
    int totalRecords = 0;

    char choice;
    do {
        cout << "\nMENU:\n";
        cout << "1. Input Data\n";
        cout << "2. Display Data\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                if (totalRecords < MAX_STUDENTS) {
                    students[totalRecords].input();
                    totalRecords++;
                    cout << "\nTOTAL NUMBER OF RECORDS CREATED: " << totalRecords << endl;
                } else {
                    cout << "\nMaximum number of records reached.\n";
                }
                break;
            case '2':
                if (totalRecords > 0) {
                    students[0].displayHeader();
                    for (int i = 0; i < totalRecords; i++) {
                        const char DOB[11] = "01-01-2000"; // Replace with the actual DOB
                        const char blood[5] = "O+"; // Replace with the actual blood group
                        const char phone[15] = "1234567890"; // Replace with the actual phone number
                        const char address[100] = "123 Main St, City"; // Replace with the actual address
                        const char drivingLicenseNo[20] = "DL123456"; // Replace with the actual license number

                        students[i].displayRecord(DOB, blood, phone, address, drivingLicenseNo);
                    }
                } else {
                    cout << "\nNo records to display.\n";
                }
                break;
            case '3':
                cout << "\nExiting the program.\n";
                return 0;
            default:
                cout << "\nInvalid choice.\n";
                break;
        }

        cout << "Do you want to go to the main menu? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

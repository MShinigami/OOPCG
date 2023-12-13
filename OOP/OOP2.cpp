#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Privacy;

class Personal 
{
private:
    string name;
    string surname;
    int roll;
    string branch;
    string division;
    Privacy* privData;

public:
    Personal() : name(""), surname(""), roll(0), branch(""), division(""), privData(nullptr) {}

    friend class Privacy;

    void input();
    void display() const;
};

class Privacy 
{
private:
    string dob;
    string blood;
    string phone;
    string address;
    string dlNo;

public:
    Privacy() : dob(""), blood(""), phone(""), address(""), dlNo("") {}

    friend class Personal;

    void input() 
    {
        cout << "Enter Date of Birth: ";
        cin >> dob;
        cout << "Enter Blood Group: ";
        cin >> blood;
        cout << "Enter Phone Number: ";
        cin >> phone;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter Driving License Number: ";
        cin >> dlNo;
    }

    void display() const 
    {
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << blood << endl;
        cout << "Phone Number: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "Driving License Number: " << dlNo << endl;
    }
};

void Personal::input() 
{
    cout << "Enter the name of the student: ";
    cin >> name;
    cout << "Enter the surname of the student: ";
    cin >> surname;
    cout << "Enter the roll number of the student: ";
    cin >> roll;
    cout << "Enter the class of the student: ";
    cin >> branch;
    cout << "Enter the division of the student: ";
    cin >> division;

    privData = new Privacy();
    privData->input();
}

void Personal::display() const 
{
    cout << "Name: " << name << " " << surname << endl;
    cout << "Roll Number: " << roll << endl;
    cout << "Class: " << branch << endl;
    cout << "Division: " << division << endl;

    if (privData) 
    {
        privData->display();
    }
}

int main() 
{
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

        switch (choice) 
        {
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
                for (int i = 0; i < students.size(); ++i) 
                {
                    cout << "\nStudent " << i + 1 << "\n";
                    students[i].display();
                    cout << endl;
                }
                break;

            case '3':
                break;

            default:
                cout << "\nInvalid choice.\n";
        }

    } 
    while (choice != '3');
    return 0;
}

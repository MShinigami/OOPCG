#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student 
{
private:
    int roll;
    string name;

public:
    Student() : roll(0), name("") {}
    Student(int r, const string& n) : roll(r), name(n) {}

    void accept() 
    {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> roll;
    }

    void display() const 
    {
        cout << "Name: " << name << "\n";
        cout << "Roll Number: " << roll << "\n";
    }

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};

ostream& operator<<(ostream& os, const Student& student) 
{
    os << student.name << '\n' << student.roll << '\n';
    return os;
}

istream& operator>>(istream& is, Student& student) 
{
    getline(is, student.name);
    is >> student.roll;
    is.ignore();
    return is;
}

int main() 
{
    ofstream outFile("student_records.txt");
    if (!outFile.is_open()) 
    {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    char choice;
    int count = 0;
    Student s;
    do 
    {
        cout << "Enter details for Student " << count + 1 << ":\n";
        s.accept();
        outFile << s;
        cout << "Do you want to enter details for another student? (y/n): ";
        cin >> choice;
        count++;
    }
    while (choice == 'y' || choice == 'Y');
    outFile.close();

    ifstream inFile("student_records.txt");
    if (!inFile.is_open()) 
    {
        cerr << "Failed to open the file for reading." << endl;
        return 1;
    }

    int i = 0;
    while (inFile >> s) 
    {
        cout << "Student " << ++i << " details:\n";
        s.display();
    }

    inFile.close();
    cout << "Number of records created: " << count << endl;

    return 0;
}

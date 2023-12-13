#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Record 
{
    int code;
    string name;
    int quantity;
    double cost;
};

void displayRecord(const vector<Record>& records) 
{
    cout << setw(15) << "Code" << setw(20) << "Name" << setw(10) << "Quantity" << setw(10) << "Cost" << "\n";
    cout << setfill('-') << setw(65) << "\n" << setfill(' ');

    for (const auto& record : records) 
    {
        cout << setw(15) << record.code << setw(20) << record.name << setw(10) << record.quantity << setw(10) << "Rs." << record.cost << "\n";
    }
    cout << endl;
}

int main() 
{
    vector<Record> records;

    int choice;

    do 
    {
        cout << "\n\n";

        cout << "Menu:\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Sort Records by Name\n";
        cout << "4. Search for Record by Name\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        cout << "\n\n";

        switch (choice) 
        {
            case 1: 
            {
                Record newRecord;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, newRecord.name);
                cout << "Enter Code: ";
                cin >> newRecord.code;
                cout << "Enter Quantity: ";
                cin >> newRecord.quantity;
                cout << "Enter Cost: Rs.";
                cin >> newRecord.cost;

                records.push_back(newRecord);
                break;
            }

            case 2:
                displayRecord(records);
                break;

            case 3:
                sort(records.begin(), records.end(),[](const Record& a, const Record& b) 
                    {
                         return a.name < b.name;
                    }
                );
                cout << "Records sorted by Name.\n";
                break;

            case 4: 
            {
                string searchName;
                cout << "Enter the name to search: ";
                cin.ignore();
                getline(cin, searchName);

                auto it = find_if(records.begin(), records.end(),[searchName](const Record& record) 
                    { 
                       return record.name == searchName; 
                    }
                );

                if (it != records.end()) 
                {
                    cout << "Record found:\n";
                    cout << "Name: " << it->name << "\nCode: " << it->code << "\nQuantity: " << it->quantity << "\nCost: " << it->cost << "\n";
                } 
                else 
                {
                    cout << "Record not found.\n";
                }
                break;
            }

            case 5:
                cout << "\n THANK YOU \n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } 
    while (choice != 5);
    return 0;
}

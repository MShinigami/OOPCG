#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct ItemRecord {
    int itemCode;
    string itemName;
    int quantity;
    double cost;
};

void displayrecord(const vector<ItemRecord>& item_records) {
    cout << setw(15) << "Item Code" << setw(20) << "Item Name" << setw(10) << "Quantity" << setw(10) << "Cost" << "\n";
    cout << setfill('-') << setw(65) << "\n" << setfill(' ');

    for (const auto& record : item_records) {
        cout << setw(15) << record.itemCode << setw(20) << record.itemName << setw(10) << record.quantity << setw(10) << "Rs." << record.cost << "\n";
    }
    cout << endl;
}

int main() {
    vector<ItemRecord> item_records;

    int choice;

    do {
        cout << "\n\n";

        cout << "Menu:\n";
        cout << "1. Add Item Record\n";
        cout << "2. Display Item Records\n";
        cout << "3. Sort Item Records by Name\n";
        cout << "4. Search for Item by Name\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        cout << "\n\n";

        switch (choice) {
            case 1: {
                ItemRecord new_item;
                cout << "Enter Item Name: ";
                cin.ignore();
                getline(cin, new_item.itemName);
                cout << "Enter Item Code: ";
                cin >> new_item.itemCode;
                cout << "Enter Quantity: ";
                cin >> new_item.quantity;
                cout << "Enter Cost: Rs.";
                cin >> new_item.cost;

                item_records.push_back(new_item);
                break;
            }
            case 2:
                displayrecord(item_records);
                break;
            case 3:
                sort(item_records.begin(), item_records.end(),
                     [](const ItemRecord& a, const ItemRecord& b) {
                         return a.itemName < b.itemName;
                     });
                cout << "Item Records sorted by Name.\n";
                break;
            case 4: {
                string search_name;
                cout << "Enter the name to search: ";
                cin.ignore();
                getline(cin, search_name);

                auto it = find_if(item_records.begin(), item_records.end(),
                                  [search_name](const ItemRecord& record) { return record.itemName == search_name; });

                if (it != item_records.end()) {
                    cout << "Record found:\n";
                    cout << "Name: " << it->itemName << "\nItem Code: " << it->itemCode << "\nQuantity: " << it->quantity << "\nCost: " << it->cost << "\n";
                } else {
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

    } while (choice != 5);

    return 0;
}

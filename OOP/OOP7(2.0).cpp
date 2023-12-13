#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct SPair {
    string first;
    long long second;
};

int main() {
    map<string, long long> sp;

    cout << "Enter state populations. Type '~' to finish.\n";

    do {
        string state;
        long long pop;

        cout << "Enter state name: ";
        getline(cin, state);

        if (state == "~") {
            break;
        }

        cout << "Enter population: ";
        cin >> pop;
        cin.ignore();

        sp[state] = pop;

    } while (true);

    do {
        cout << "\nMENU\n";
        cout << "1. Display Sorted list by name\n";
        cout << "2. Display Sorted list by population\n";
        cout << "3. Search for a state by name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice : ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                map<string, long long> sorted(sp.begin(), sp.end());

                cout << "\nSorted by Name:\n";
                for (const auto &pair : sorted) {
                    cout << pair.first << ": " << pair.second << endl;
                }
                break;
            }
            case 2: {
                vector<SPair> sorted(sp.begin(), sp.end());
                sort(sorted.begin(), sorted.end(),
                     [](const auto &a, const auto &b) { return a.second < b.second; });

                cout << "\nSorted by Population:\n";
                for (const auto &pair : sorted) {
                    cout << pair.first << ": " << pair.second << endl;
                }
                break;
            }
            case 3: {
                cout << "\nEnter the name of a state: ";
                string state;
                getline(cin, state);

                auto it = sp.find(state);

                if (it != sp.end()) {
                    cout << "Population of " << state << ": " << it->second << endl;
                } else {
                    cout << "Population data not available for " << state << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (true);

    return 0;
}

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    map<string, long long> statep;

    cout << "\nEnter state populations. Type '~' to finish.\n";

    while (true) {
        string state;
        long long population;

        cout << "\nEnter state name: ";
        getline(cin, state);

        if (state == "~") {
            break;
        }

        cout << "Enter population: ";
        cin >> population;
        cin.ignore();

        statep[state] = population;
    }

    map<string, long long> sortedStatePopulations(statep.begin(), statep.end());

    cout << "\nSorted State Populations:\n";
    for (const auto &pair : sortedStatePopulations) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "\nEnter the name of a state: ";
    string state;
    getline(cin, state);

    auto it = statep.find(state);

    if (it != statep.end()) {
        cout << "Population of " << state << ": " << it->second << endl;
    } else {
        cout << "Population data not available for " << state << endl;
    }

    return 0;
}

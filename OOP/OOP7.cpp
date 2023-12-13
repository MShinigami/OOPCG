#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    map<string, long long> sp;

    cout << "\nEnter state populations. Type '~' to finish.\n";

    while (true) 
    {
        string s;
        long long p;

        cout << "\nEnter state name: ";
        getline(cin, s);

        if (s == "~") 
        {
            break;
        }

        cout << "Enter population: ";
        cin >> p;
        cin.ignore();

        sp[s] = p;
    }

    map<string, long long> sortedSp(sp.begin(), sp.end());

    cout << "\nSorted State Populations:\n";
    for (const auto &p : sortedSp) 
    {
        cout << p.first << ": " << p.second << endl;
    }

    cout << "\nEnter the name of a state: ";
    string st;
    getline(cin, st);

    auto it = sp.find(st);

    if (it != sp.end()) 
    {
        cout << "Population of " << st << ": " << it->second << endl;
    } 
    else 
    {
        cout << "Population data not available for " << st << endl;
    }

    return 0;
}

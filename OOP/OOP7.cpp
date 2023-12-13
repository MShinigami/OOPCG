#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    map<string, long long> statePopulations;
    statePopulations["Uttar Pradesh"] = 199812341;
    statePopulations["Maharashtra"] = 112372333;
    statePopulations["Bihar"] = 104099452;
    statePopulations["West Bengal"] = 91276115;
    statePopulations["Andhra Pradesh"] = 84580777;
    statePopulations["Madhya Pradesh"] = 72626809;
    statePopulations["Tamil Nadu"] = 72147030;
    statePopulations["Rajasthan"] = 68548437;
    statePopulations["Karnataka"] = 61095297;
    statePopulations["Gujarat"] = 60439692;
    statePopulations["Odisha"] = 41974218;
    statePopulations["Telangana"] = 35198978;
    statePopulations["Kerala"] = 33406061;
    statePopulations["Jharkhand"] = 32988134;
    statePopulations["Assam"] = 31205576;
    statePopulations["Punjab"] = 27743338;
    statePopulations["Haryana"] = 25545198;
    statePopulations["Chhattisgarh"] = 25351462;
    statePopulations["Uttarakhand"] = 10086292;
    statePopulations["Himachal Pradesh"] = 6864602;
    statePopulations["Tripura"] = 3673917;
    statePopulations["Meghalaya"] = 2966889;
    statePopulations["Manipur"] = 2855794;
    statePopulations["Nagaland"] = 1978502;
    statePopulations["Goa"] = 1458502;
    statePopulations["Arunachal Pradesh"] = 1458545;
    statePopulations["Mizoram"] = 1097206;
    statePopulations["Sikkim"] = 610577;

    map<string, long long> sortedStatePopulations(statePopulations.begin(), statePopulations.end());

    for (const auto& pair : sortedStatePopulations) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout<<"\n";
    cout << "Enter the name of a state: ";
    string stateName;
    getline(cin, stateName);
    auto it = statePopulations.find(stateName);

    if (it != statePopulations.end()) {
        cout << "Population of " << stateName << ": " << it->second << endl;
    } else {
        cout << "Population data not available for " << stateName << endl;
    }

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(arr[i], arr[min]);
        }
    }
}

int main() {
    int choice;
    const int Max = 100;
    int iArray[Max];
    float fArray[Max];
    int int_array = 0;
    int float_array = 0;

    do {
        cout << "\n" << endl;
        cout << "Select an operation:" << endl;
        cout << "1. Enter Integer Values" << endl;
        cout << "2. Enter Floating Point Values" << endl;
        cout << "3. Sort Integer Array" << endl;
        cout << "4. Sort Floating Point Array" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of integer values: ";
                cin >> int_array;
                cout << "Enter " << int_array << " integer numbers:" << endl;
                for (int i = 0; i < int_array; i++) {
                    cin >> iArray[i];
                }
                break;

            case 2:
                cout << "Enter the number of floating-point values: ";
                cin >> float_array;
                cout << "Enter " << float_array << " floating point numbers:" << endl;
                for (int i = 0; i < float_array; i++) {
                    cin >> fArray[i];
                }
                break;

            case 3:
                if (int_array > 0) {
                    selectionSort(iArray, int_array);
                    cout << "Sorted Integer Array: ";
                    for (int i = 0; i < int_array; i++) {
                        cout << iArray[i] << " ";
                    }
                    cout << endl;
                } else {
                    cout << "No integer values entered. Please enter values first." << endl;
                }
                break;

            case 4:
                if (float_array > 0) {
                    selectionSort(fArray, float_array);
                    cout << "Sorted Float Array: ";
                    for (int i = 0; i < float_array; i++) {
                        cout << fArray[i] << " ";
                    }
                    cout << endl;
                } else {
                    cout << "No float values entered. Please enter values first." << endl;
                }
                break;

            case 5:
                cout << "Exiting." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option (1-5)." << endl;
        }
    } while (choice != 5);

    return 0;
}

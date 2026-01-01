#include "Footage.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int choice;
    Footage f;

    do {
        cout << "\nCCTV Footage Management System\n";
        cout << "1. Add Footage\n";
        cout << "2. Display All\n";
        cout << "3. Search Footage\n";
        cout << "4. Delete Footage\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                f.addFootage();
                break;

            case 2: {
                ifstream inFile("data/footage.dat", ios::binary);
                while (inFile.read(reinterpret_cast<char*>(&f), sizeof(f)))
                    f.displayFootage();
                inFile.close();
                break;
            }

            case 3: {
                int id;
                cout << "Enter Camera ID: ";
                cin >> id;
                searchFootage(id);
                break;
            }

            case 4: {
                int id;
                cout << "Enter Camera ID to delete: ";
                cin >> id;
                deleteFootage(id);
                break;
            }

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

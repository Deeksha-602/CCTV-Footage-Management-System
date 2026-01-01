#include "Footage.h"

int Footage::getCameraId() const {
    return cameraId;
}

void Footage::addFootage() {
    cout << "Enter Camera ID: ";
    cin >> cameraId;

    cout << "Enter Date (DD-MM-YYYY): ";
    cin >> date;

    cout << "Enter Time (HH:MM): ";
    cin >> time;

    cout << "Enter Duration (minutes): ";
    cin >> duration;

    cin.ignore();
    cout << "Enter Location: ";
    cin.getline(location, 50);

    ofstream outFile("data/footage.dat", ios::binary | ios::app);
    outFile.write(reinterpret_cast<char*>(this), sizeof(*this));
    outFile.close();

    cout << "Footage added successfully!\n";
}

void Footage::displayFootage() const {
    cout << "Camera ID: " << cameraId
         << "\nDate: " << date
         << "\nTime: " << time
         << "\nDuration: " << duration << " mins"
         << "\nLocation: " << location
         << "\n----------------------\n";
}

void searchFootage(int id) {
    ifstream inFile("data/footage.dat", ios::binary);
    Footage f;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&f), sizeof(f))) {
        if (f.getCameraId() == id) {
            f.displayFootage();
            found = true;
        }
    }

    if (!found)
        cout << "No footage found.\n";

    inFile.close();
}

void deleteFootage(int id) {
    ifstream inFile("data/footage.dat", ios::binary);
    ofstream outFile("data/temp.dat", ios::binary);

    Footage f;
    while (inFile.read(reinterpret_cast<char*>(&f), sizeof(f))) {
        if (f.getCameraId() != id)
            outFile.write(reinterpret_cast<char*>(&f), sizeof(f));
    }

    inFile.close();
    outFile.close();

    remove("data/footage.dat");
    rename("data/temp.dat", "data/footage.dat");

    cout << "Footage deleted successfully.\n";
}

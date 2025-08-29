#include <iostream>
using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;   

public:
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
    }

    Train(int tNo, const char* tName, const char* src, const char* dest, const char* tTime) {
        trainNumber = tNo;
        strcpy(trainName, tName);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, tTime);
        trainCount++;
    }

    ~Train() {
        trainCount--;
    }

    void setTrainNumber(int tNo) { trainNumber = tNo; }
    int getTrainNumber() { return trainNumber; }

    void setTrainName(const char* tName) { strcpy(trainName, tName); }
    char* getTrainName() { return trainName; }

    void setSource(const char* src) { strcpy(source, src); }
    char* getSource() { return source; }

    void setDestination(const char* dest) { strcpy(destination, dest); }
    char* getDestination() { return destination; }

    void setTrainTime(const char* tTime) { strcpy(trainTime, tTime); }
    char* getTrainTime() { return trainTime; }

    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);

        trainCount++;
    }

    void displayTrainDetails() {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    static int getTrainCount() {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];  
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;
    }

    void addTrain() {
        if (totalTrains < 100) {
            cout << "\n Enter Train Details \n";
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        } else {
            cout << "Train list is full!" << endl;
        }
    }

    void displayAllTrains() {
        if (totalTrains == 0) {
            cout << "No train records available!" << endl;
        } else {
            for (int i = 0; i < totalTrains; i++) {
                cout << "\nTrain " << (i + 1) << " details:\n";
                trains[i].displayTrainDetails();
            }
        }
    }

    void searchTrainByNumber(int number) {
        bool found = false;
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "\nTrain found:\n";
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Train with number " << number << " not found!" << endl;
        }
    }
};

int main() {
    RailwaySystem system;
    int choice;

    do {
        cout << "\n Railway Reservation System Menu \n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.addTrain();
            break;
        case 2:
            system.displayAllTrains();
            break;
        case 3: {
            int num;
            cout << "Enter Train Number to search: ";
            cin >> num;
            system.searchTrainByNumber(num);
            break;
        }
        case 4:
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);
}
/*   Output :-
 
--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 1

--- Enter Train Details ---
Enter Train Number: 101
Enter Train Name: RNW
Enter Source: surat
Enter Destination: mumbai
Enter Train Time: 10 pm

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 2

Train 1 details:
Train Number: 101
Train Name: RNW
Source: surat
Destination: mumbai
Train Time: 10 pm

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 3
Enter Train Number to search: 102
Train with number 102 not found!

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 4
Exiting the system. Goodbye!
 
*/
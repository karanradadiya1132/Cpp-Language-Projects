#include <iostream>
using namespace std;

class TimeConverter 
{
    public:
    void secondsToHHMMSS(int totalSeconds) {
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;

        cout << "HH:MM:SS => " 
             << hours << ":" 
             << (minutes < 10 ? "0" : "") << minutes << ":" 
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }

    void hhmmssToSeconds(int hours, int minutes, int seconds) {
        int totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
        cout << "Total seconds = " << totalSeconds << endl;
    }
};

   int main() 
{
    TimeConverter converter;
    int choice;

    do {
        cout << "\n Time Converter Menu \n";
        cout << "1. Convert Seconds to HH:MM:SS\n";
        cout << "2. Convert HH:MM:SS to Seconds\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int totalSeconds;
                cout << "Enter total seconds: ";
                cin >> totalSeconds;
                converter.secondsToHHMMSS(totalSeconds);
                break;
            }
            case 2: {
                int hours, minutes, seconds;
                cout << "Enter hours: ";
                cin >> hours;
                cout << "Enter minutes: ";
                cin >> minutes;
                cout << "Enter seconds: ";
                cin >> seconds;
                converter.hhmmssToSeconds(hours, minutes, seconds);
                break;
            }
            case 3:
                cout << "Exiting program...!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while(choice != 3);
}


/*    Output :-


 Time Converter Menu
1. Convert Seconds to HH:MM:SS
2. Convert HH:MM:SS to Seconds
3. Exit
Enter your choice: 1
Enter total seconds: 456
HH:MM:SS => 0:07:36

 Time Converter Menu
1. Convert Seconds to HH:MM:SS
2. Convert HH:MM:SS to Seconds
3. Exit
Enter your choice: 2
Enter hours: 1
Enter minutes: 02
Enter seconds: 03
Total seconds = 3723

 Time Converter Menu
1. Convert Seconds to HH:MM:SS
2. Convert HH:MM:SS to Seconds
3. Exit
Enter your choice: 3
Exiting program...!


   
*/
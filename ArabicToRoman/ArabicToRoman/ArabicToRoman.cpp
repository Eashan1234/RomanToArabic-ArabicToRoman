// ArabicToRoman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <io.h>
#include <fcntl.h>

using namespace std;

int main()
{
    bool replay = false;
    char replayc;
    int mnu = 0;

    //This is the replay loop
    do {
        //Main menu
        cout << "1 - Roman --> Arabic\n";
        cout << "2 - Arabic --> Roman\n";
        cout << "3 - Exit\n";
        cout << "Please select one: \n";
        cin >> mnu;

        //Roman --> Arabic user selection
        if (mnu == 1) {
            char roman[40]; //Input stream array
            long value[40]; //Value conversion array
            int total = 0;  //Running total value

            cout << "The Maximum for this program is 39999(|X||X||X|M|X|CMXCIX)\n";
            cout << "Enter Roman Numeral\n";
            
            cin >> roman; //Inputting the roman numeral from user input
            cin.ignore(80, '\n');

            //Conversion:
            for (int i = 0; i <= 39; i++) {
                switch (roman[i]) {
                case '|':
                    if (roman[i + 1] == 'X') {
                        value[i] = 10000;
                        value[i + 1] = 0;
                        i++;
                    }
                    else if (roman[i + 1] == 'V') {
                        value[i] = 5000;
                        value[i + 1] = 0;
                        i++;
                    }
                    else {
                        value[i] = 0;
                    }
                    break;
                case 'M':
                    value[i] = 1000;
                    break;
                case 'L':
                    value[i] = 50;
                    break;
                case 'C':
                    value[i] = 100;
                    break;
                case 'D':
                    value[i] = 500;
                    break;
                case 'X':
                    value[i] = 10;
                    break;
                case 'V':
                    value[i] = 5;
                    break;
                case 'I':
                    value[i] = 1;
                    break;
                default:
                    value[i] = 0;
                    break;
                }
            }

            //Adding algorithm
            for (int i = 0; i <= 39; i++) {
                //cout << value[i] << endl;
                if (value[i] < value[i + 1]) {
                    total -= value[i];
                }
                else {
                    total += value[i];
                }
            }

            cout << total;
        }//Arabic --> Roman user selection
        else if (mnu == 2) {
            long arabic;
            int roman[10];
            int total = 0;
            int thousands;
            int hundreds;
            int five_hundreds;
            int tens;
            int fives;
            int ones;
            int fifty;
            int ten_thousands;
            int five_thousands;

            cout << "The Maximum for this program is 39999(|X||X||X|M|X|CMXCIX)\n";
            cout << "Enter Arabic Number\n";

            cin >> arabic; //User input for arabic numeral
            
            //Splitting up the number into organized sections that can be used in the conversion process
            ten_thousands = (arabic - (arabic % 10000)) / 10000;
            arabic -= 10000 * ten_thousands;
            five_thousands = (arabic - (arabic % 10000)) / 10000;
            arabic -= 5000 * five_thousands;
            thousands = (arabic - (arabic % 1000)) / 1000;
            arabic -= 1000 * thousands;
            five_hundreds = (arabic - (arabic % 500)) / 500;
            arabic -= 500 * five_hundreds;
            hundreds = (arabic - (arabic % 100)) / 100;
            arabic -= 100 * hundreds;
            fifty = (arabic - (arabic % 50)) / 50;
            arabic -= 50 * fifty;
            tens = (arabic - (arabic % 10)) / 10;
            arabic -= 10 * tens;
            fives = (arabic - (arabic % 5)) / 5;
            arabic -= 5 * fives;
            ones = arabic;
          

            //Algorithm for the conversion:

            if (thousands == 4 && five_thousands == 1) {
                thousands = 9;
                five_thousands -= 1;
            }

            if (thousands == 9 && ten_thousands == 0) {
                cout << "M";
                cout << "|X|";
                thousands -= 9;
            }

            for (int i = 0; i <= (ten_thousands - 1); i++) {
                cout << "|X|";
                if (thousands == 9 && (ten_thousands - i) == 1) {
                    cout << "M";
                    cout << "|X|";
                    thousands -= 9;
                    break;
                }
            }



            for (int i = 0; i <= five_thousands - 1; i++) {
                if (thousands == 4 && five_thousands == 1) {
                    tens = 9;
                    break;
                }
                cout << "|V|";
                if (thousands == 4 && (five_thousands - i) == 1) {
                    cout << "M";
                    cout << "|V|";
                    thousands -= 4;
                    break;
                }
            }

            if (thousands == 4 && five_thousands == 1) {
                thousands = 9;
                five_thousands -= 1;
            }

            if (hundreds == 9 && thousands == 0) {
                cout << "C";
                cout << "M";
                hundreds -= 9;
            }

            if (hundreds == 4 && five_hundreds == 1) {
                hundreds = 9;
                five_hundreds -= 1;
            }

            for (int i = 0; i <= (thousands - 1); i++) {
                cout << "M";
                if (hundreds == 9 && (thousands - i) == 1) {
                    cout << "C";
                    cout << "M";
                    hundreds -= 9;
                    break;
                }
            }

            if (hundreds == 4 && five_hundreds == 0) {
                cout << "C";
                cout << "D";
                hundreds -= 4;
            }

            for (int i = 0; i <= five_hundreds - 1; i++) {
                if (hundreds == 4 && five_hundreds == 1) {
                    hundreds -= 4;
                    break;
                }
                cout << "D";
                if (hundreds == 4 && (five_hundreds - i) == 1) {
                    cout << "C";
                    cout << "D";
                    hundreds -= 4;
                    break;
                }
            }

            if (tens == 4 && fifty == 1) {
                tens = 9;
                fifty -= 1;
            }

            if (tens == 9 && hundreds == 0) {
                cout << "X";
                cout << "C";
                tens -= 9;
            }

            for (int i = 0; i <= hundreds - 1; i++) {
                cout << "C";
                if (tens == 9 && (hundreds - i) == 1) {
                    cout << "X";
                    cout << "C";
                    tens -= 9;
                    break;
                }
            }

            if (tens == 4 && fifty == 0) {
                cout << "X";
                cout << "L";
                tens -= 4;
            }

            for (int i = 0; i <= fifty - 1; i++) {
                if (tens == 4 && fifty == 1) {
                    tens = 9;
                    break;
                }
                cout << "L";
                if (tens == 4 && (fifty - i) == 1) {
                    cout << "X";
                    cout << "L";
                    tens -= 4;
                    break;
                }
            }

            if (ones == 4 && fives == 1) {
                ones = 9;
                fives -= 1;
            }

            if (ones == 9 && tens == 0) {
                cout << "I";
                cout << "X";
                ones -= 9;
            }

            for (int i = 0; i <= tens - 1; i++) {
                cout << "X";
                if (ones == 9 && (tens - i) == 1) {
                    cout << "I";
                    cout << "X";
                    ones -= 9;
                    break;
                }
            }

            

            if (ones == 4 && fives == 0) {
                cout << "I";
                cout << "V";
                ones -= 9;
            }

            for (int i = 0; i <= fives - 1; i++) {
                cout << "V";
                if (ones == 4 && (fives - i) == 1) {
                    cout << "I";
                    cout << "V";
                    ones -= 4;
                    break;
                }
            }

            for (int i = 0; i <= ones - 1; i++) {
                if (ones == 9) {
                    cout << "I";
                    cout << "X";
                    ones -= 9;
                    break;
                }
                cout << "I";
            }
            
            cout << endl;

            //cout << total << endl;
            //cout << "Thousands: " << thousands << endl;
            //cout << "Hundreds: " << hundreds << endl;
            //cout << "Fifty: " << fifty << endl;
            //cout << "Tens: " << tens << endl;
            //cout << "Fives: " << fives << endl;
            //cout << "Ones: " << ones << endl;
        }
        else{
            return 0;
        }
        

        cout << "\nDo you want to replay? y/n";
        cin >> replayc;

        if (replayc == 'y') {
            replay = true;
        }
        else {
            replay = false;
        }
    } while (replay);

    return 0;
}


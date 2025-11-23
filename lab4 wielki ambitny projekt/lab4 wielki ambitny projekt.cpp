

#include <iostream>
#include <limits>
#include "headerFile.h";
using namespace std;

int DataCounter; // zlicza ile jest zapisanych wartości (każda konwersja to +2 do tej liczby
double memory[100] = { 0 }; // tablica przechowująca wartości liczbowe tempteratur
char memoryUnit[100] = { ' ' }; //tablica przechowująca symbole temperatur

int main() {
    float degrees;
    bool yesno;
    int choice;
    DataCounter = 0;

    while (1) {
        system("cls"); //wywołuje polecenie systemowe clear screen

        if (DataCounter >= 99) {
            cout << "Memory full. Clear history?" << endl;
            cout << "1 - Yes" << endl;
            cout << "2 - No (Exit program)" << endl;
            cin >> yesno;
            if (yesno == true) {
                DataCounter = 0;
            }
            else {
                cout << "Exiting program";
                waitForEnter();
                return 0;
            }
        }


        else {
            menu();
            cin >> choice;
            switch (choice)
            {
            case 1:
                degrees = getF();
                degrees = check(degrees, 'F'); // sprawdza, czy temperatura mieści się we właściwym zakresie; jeśli tak, zwraca ją, a jeśli nie, to zwraca -999.0
                if (degrees == -999.0) {
                    cout << "Invalid temperature." << endl;
                    waitForEnter();
                }
                else {
                    cout << "Temperature in Celsius: " << FtoC(degrees) << endl; //wyświetla przekonwertowaną temperaturę
                    memory[DataCounter] = degrees; //zapisuje wprowadzoną temperaturę
                    memoryUnit[DataCounter] = 'F'; //i jej symbol
                    DataCounter++; 
                    memory[DataCounter] = FtoC(degrees); //zapisuje przekonwertowaną temperaturę i symbol
                    memoryUnit[DataCounter] = 'C';
                    DataCounter++; // łącznie DataCounter=DataCounter+2 po każdej konwersji
                    waitForEnter();
                }
                break;
            case 2:
                degrees = getF();
                degrees = check(degrees, 'F');
                if (degrees == -999.0) {
                    cout << "Invalid temperature." << endl;
                    waitForEnter();
                }
                else {
                    cout << "Temperature in Kelvin: " << FtoK(degrees) << endl;
                    memory[DataCounter] = degrees;
                    memoryUnit[DataCounter] = 'F';
                    DataCounter++;
                    memory[DataCounter] = FtoK(degrees);
                    memoryUnit[DataCounter] = 'K';
                    DataCounter++;
                    waitForEnter();
                }
                break;
            case 3:
                degrees = getC();
                degrees = check(degrees, 'C');
                if (degrees == -999.0) {
                    cout << "Invalid temperature." << endl;
                    waitForEnter();
                }
                else {
                    cout << "Temperature in Fahrenheit: " << CtoF(degrees) << endl;
                    memory[DataCounter] = degrees;
                    memoryUnit[DataCounter] = 'C';
                    DataCounter++;
                    memory[DataCounter] = CtoF(degrees);
                    memoryUnit[DataCounter] = 'F';
                    DataCounter++;
                    waitForEnter();
                }

                break;
            case 4:
                degrees = getC();
                degrees = check(degrees, 'C');
                if (degrees == -999.0) {
                    cout << "Invalid temperature." << endl;
                    waitForEnter();
                }
                else {
                    cout << "Temperature in Kelvin: " << CtoK(degrees) << endl;
                    memory[DataCounter] = degrees;
                    memoryUnit[DataCounter] = 'C';
                    DataCounter++;
                    memory[DataCounter] = CtoK(degrees);
                    memoryUnit[DataCounter] = 'K';
                    DataCounter++;
                    waitForEnter();
                }

                break;
            case 5:
                degrees = getK();
                degrees = check(degrees, 'K');
                if (degrees == -999.0) {
                    cout << "Invalid temperature." << endl;
                    waitForEnter();
                }
                else {
                    cout << "Temperature in Celsius: " << KtoC(degrees) << endl;
                    memory[DataCounter] = degrees;
                    memoryUnit[DataCounter] = 'K';
                    DataCounter++;
                    memory[DataCounter] = KtoC(degrees);
                    memoryUnit[DataCounter] = 'C';
                    DataCounter++;
                    waitForEnter();
                }
                break;
            case 6:
                degrees = getK();
                degrees = check(degrees, 'K');
                if (degrees == -999.0) {
                    cout << "Invalid temperature." << endl;
                    waitForEnter();
                }
                else {
                    cout << "Temperature in Fahrenheit: " << KtoF(degrees) << endl;
                    memory[DataCounter] = degrees;
                    memoryUnit[DataCounter] = 'K';
                    DataCounter++;
                    memory[DataCounter] = KtoF(degrees);
                    memoryUnit[DataCounter] = 'F';
                    DataCounter++;
                    waitForEnter();
                }
                break;

            case 7:
                if (DataCounter == 0) {
                    cout << "No history available." << endl;
                    waitForEnter();
                }
                else {
                    menu2();
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        for (int i = 0; i < DataCounter; i += 2) { //sprawdza tylko temperatury wprowadzone
                            if (memoryUnit[i] == 'F') { 
                                int EntryNumber = (i / 2) + 1;
                                cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                            }
                            else
                                continue;
                        }
                        break;
                    case 2:
                        for (int i = 0; i < DataCounter; i += 2) {
                            if (memoryUnit[i] == 'C') {
                                int EntryNumber = (i / 2) + 1;
                                cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                            }
                            else
                                continue;
                        }
                        break;
                    case 3:
                        for (int i = 0; i < DataCounter; i += 2) {
                            if (memoryUnit[i] == 'K') {
                                int EntryNumber = (i / 2) + 1;
                                cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                            }
                            else
                                continue;
                        }
                        break;
                    default:
                        cout << "Conversion History:" << endl;
                        for (int i = 0; i < DataCounter; i += 2) {
                            int EntryNumber = (i / 2) + 1;
                            cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                            
                        }
                    }
                    waitForEnter();
                    break;

            default:
                cout << "Exiting program";
                waitForEnter();
                return 0;
                }
            }
        }
    }
}



float FtoC(float degrees){ 
    float result = (5.0 / 9.0) * (degrees - 32.0);
    return result;
}

float FtoK(float degrees) { 
    float result = (5.0 / 9.0) * (degrees + 459.67);
    return result;
}
float CtoF(float degrees) { 
    float result = (9.0 / 5.0) * degrees + 32.0;
    return result;
}

float CtoK(float degrees) { 
    float result = degrees + 273.15;
    return result;
}

float KtoC(float degrees) { 
    float result = degrees - 273.15;
        return result;
}

float KtoF(float degrees) { 
    float result = degrees*(9.0/5.0)-459.67;
    return result;
}

void menu() {
    cout << endl << "Enter a number to choose an option: " << endl;
    cout << "1 - convert Fahrenheit to Celsius" << endl;
    cout << "2 - convert Fahrenheit to Kelvin" << endl;
    cout << "3 - convert Celsius to Fahrenheit" << endl;
    cout << "4 - convert Celsius to Kelvin " << endl;
    cout << "5 - convert Kelvin to Celsius" << endl;
    cout << "6 - convert Kelvin to Fahrenheit" << endl;
	cout << "7 - show history" << endl;
    cout << "8 - exit the program" << endl; 
    //zad 1. lab 6. = ???
}

void menu2() {
    cout << endl << "Enter a number to choose which part of history to show: " << endl;
    cout << "1 - conversions from F to C and to K" << endl;
    cout << "2 - conversions from C to F and to K" << endl;
    cout << "3 - conversions from K to C and F" << endl;
    cout << "4 - full history" << endl;
}

float getF() {
    float F;
    cout << "Enter the temperature in Fahrenheit: ";
    cin >> F;
    return F;
}

float getC() {
    float C;
    cout << "Enter the temperature in Celsius: ";
    cin >> C;
    return C;
}

float getK() {
    float K;
    cout << "Enter the temperature in Kelvin: ";
    cin >> K;
    return K;
}

float check(float temp, char u) { //u for unit
    if (u == 'K') { // jeśli check (degrees, 'K'), to sprawdź, czy temp<0 – jeśli tak, to zwróć -999
        if (temp < 0.0) {
            return -999.0;
        }
    }
    else if (u == 'C') { //jeśli check (degrees, 'C'), to sprawdź, czy temp<-273.15 - ...
        if (temp < -273.15) {
            return -999.0;
        } 
    }
    else if (u == 'F') { //jeżeli check(degrees,'F'), to sprawdź, czy temp<-459.67 - ...
        if (temp < -459.67) {
            return -999.0;
        }
    }
    else { // jeżeli jednostka to nie K, C lub F, to też zwróć -999, bo to błąd
        return -999.0;
    }
    return temp; //jeżeli temperatura ma poprawną jednostkę i jest większa niż minimum dla tej jednoski, po prostu zwróć temperaturę
}

void waitForEnter() {
    cout << endl << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); /* z pomocą copilot; wyjaśnienie na przyszłość: 
    pomija/usuwa wszystkie znaki do i włącznie ze znakiem nowej linii, który został po naciśnięciu Enter, 
    dzięki czemu cin.get() nie zwraca tego "/n" natychmiast i nie zaczyna od nowa od razu, tylko czeka na 
    kolejny Enter */
    cin.get();
}


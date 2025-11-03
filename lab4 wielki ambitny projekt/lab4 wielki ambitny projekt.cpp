

#include <iostream>
#include <limits>
using namespace std;

float FtoC(float degrees); // Fahr to Celsius prototype
float FtoK(float degrees);
float CtoF(float degrees);
float CtoK(float degrees);
float KtoC(float degrees);
float KtoF(float degrees);
void menu();
float getF();
float getC();
float getK();
float check(float temp, char u);
void waitForEnter();


int main() {
    float degrees;
    int choice;


    while (1) {
        system("cls");

        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            degrees = getF();
            degrees = check(degrees, 'F');
            if (degrees == -999.0) {
                cout << "Invalid temperature." << endl;
                waitForEnter();
            }
            else {
                cout << "Temperature in Celsius: " << FtoC(degrees) << endl;
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
                waitForEnter();
            }
            break;

        default:
            cout << "Exiting program";
            waitForEnter();
            return 0;
            }
        }

        return 0;
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
    cout << "7 - exit the program" << endl;
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
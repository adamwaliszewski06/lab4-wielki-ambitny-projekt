

#include <iostream>
using namespace std;

float FtoC(float degrees); // Fahr to Celsius prototype
float FtoK(float degrees);
float CtoF(float degrees);
float CtoK(float degrees);
float KtoC(float degrees);
float KtoF(float degrees);

int main() { 
  float degrees, result;
    int choice;

    cout << "Enter a number to choose: " << endl << "1 - convert Fahrenheit to Celsius" << endl << "2 - convert Fahrenheit to Kelvin" << endl
        << "3 - convert Celsius to Fahrenheit" << endl << "4 - convert Celsius to Kelvin " << endl
        << "5 - convert Kelvin to Celsius" << endl << "6 - convert Kelvin to Fahrenheit" << endl << "7 - exit the program" << endl;
    cin >> choice;

   switch (choice)
    {
    case 1:
        cout << "Enter the temperature in Fahrenheit: ";
        cin >> degrees;
        cout << "Temperature in Celsius: " << FtoC(degrees) << endl;
        break;
    case 2:
        cout << "Enter the temperature in Fahrenheit: ";
        cin >> degrees;
        cout << "Temperature in Kelvin: " << FtoK(degrees) << endl;
        break;
    case 3:
        cout << "Enter the temperature in Celsius: ";
        cin >> degrees;
        cout << "Temperature in Fahrenheit: " << CtoF(degrees) << endl;
        break;
    case 4:
        cout << "Enter the temperature in Celsius: ";
        cin >> degrees;
        cout << "Temperature in Kelvin: " << CtoK(degrees) << endl;
        break;
    case 5:
        cout << "Enter the temperature in Kelvin: ";
        cin >> degrees;
        cout << "Temperature in Celsius: " << KtoC(degrees) << endl;
        break;
    case 6:
        cout << "Enter the temperature in Kelvin: ";
        cin >> degrees;
        cout << "Temperature in Fahrenheit: " << KtoF(degrees) << endl;
        break;
    default:
        return 0;
    }
   
  


    return 0;
}

float FtoC(float degrees) { //works
    float result = (5.0 / 9.0) * (degrees - 32.0);
    return result;
}

float FtoK(float degrees) { //works
    float result = (5.0 / 9.0) * (degrees + 459.67);
    return result;
}
float CtoF(float degrees) { //works
    float result = (9.0 / 5.0) * degrees + 32.0;
    return result;
}

float CtoK(float degrees) { //works
    float result = degrees + 273.15;
    return result;
}

float KtoC(float degrees) { //works
    float result = degrees - 273.15;
        return result;
}

float KtoF(float degrees) { //works
    float result = degrees*(9.0/5.0)-459.67;
    return result;
}


#include <iostream>
using namespace std;

float FtoC(float stopnie); // Fahr to Celsius prototype
float FtoK(float stopnie);
float CtoF(float stopnie);
float CtoK(float stopnie);
float KtoC(float stopnie);
float KtoF(float stopnie);

int main() { 
    float fahr, celsius;
    for (fahr = 0.0; fahr <= 200; fahr = fahr + 20) {
        celsius = FtoC(fahr);
        cout << fahr << "   " << celsius << endl;
    }
    return 0;
}

float FtoC(float stopnie) { 
    float wynik = (5.0 / 9.0) * (stopnie - 32.0);
    return wynik;
}
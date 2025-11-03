

#include <iostream>
using namespace std;

float FtoC(float stopnie); // Fahr to Celsius prototype
float FtoK(float stopnie);
float CtoF(float stopnie);
float CtoK(float stopnie);
float KtoC(float stopnie);
float KtoF(float stopnie);

int main() { 
    float stopnie, wynik;
    cin >> stopnie;
    wynik = KtoF(stopnie);
    cout << "Wynik: " << wynik;


    return 0;
}

float FtoC(float stopnie) { //dziala
    float wynik = (5.0 / 9.0) * (stopnie - 32.0);
    return wynik;
}

float FtoK(float stopnie) { //dziala
    float wynik = (5.0 / 9.0) * (stopnie + 459.67);
    return wynik;
}
float CtoF(float stopnie) { //dziala
    float wynik = (9.0 / 5.0) * stopnie + 32.0;
    return wynik;
}

float CtoK(float stopnie) { //dziala
    float wynik = stopnie + 273.15;
    return wynik;
}

float KtoC(float stopnie) { //dziala
    float wynik = stopnie - 273.15;
        return wynik;
}

float KtoF(float stopnie) { //dziala
    float wynik = stopnie*(9.0/5.0)-459.67;
    return wynik;
}
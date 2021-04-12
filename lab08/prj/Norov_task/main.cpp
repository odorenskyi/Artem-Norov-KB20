#include <iostream>
#include "ModulesNorov.h"
#include <windows.h>
#include <locale.h>
#include  <stdio.h>

using namespace std;

void dev_information()
{
    setlocale(LC_ALL, "Ukr");
    cout << ("\n------------------------------------\n"
           "|        Norov Artem, CNTU         |\n"
           "|        Ќоров јртем, ÷Ќ“”         |"
           "\n------ (c) All Rights Reserved -----\n\n");
}
int main()
{
    setlocale(LC_ALL, "Ukr");
    dev_information();

    float x, y, z, S;
    char a, b;

    cout << "”ведiть x: ";
    cin >> x;
    cout << "”ведiть y: ";
    cin >> y;
    cout << "”ведiть z: ";
    cin >> z;
    cout << "”ведiть a: ";
    cin >> a;
    cout << "”ведiть b: ";
    cin >> b;
    cout << "a + 5 > b + 2: " << boolalpha << (a + 5 > b + 2) << endl;
    cout << "x у дес€тковiй системi = " << dec << x << endl;
    cout << "x у шiстнадц€тковiй  системi = " << hex << x << endl;
    cout << "y у дес€тковiй системi = " << dec << y << endl;
    cout << "y у шiстнадц€тковiй  системi = " << hex << y << endl;
    cout << "z у дес€тковiй системi = " << dec << z << endl;
    cout << "z у шiстнадц€тковiй  системi = " << hex << z << endl;
    S = s_calculation(x, y, z);
    cout << "\n S = " << s_calculation(x, y, z) << endl;
    system("pause");
    return 0;
}

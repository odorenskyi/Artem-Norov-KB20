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
           "|        Норов Артем, ЦНТУ         |"
           "\n------ (c) All Rights Reserved -----\n\n");
}
int main()
{
    setlocale(LC_ALL, "Ukr");
    dev_information();

    int x, y, z;
    float S;
    char a, b;
    cout << "Уведiть x: ";
    cin >> x;
    if(x < -21){
        cout << "Некоректно введене значення, x не може буди меншим за -21";
        return 0;
    }
    do{
        cout << "Уведiть y: ";
        cin >> y;
        cout << "Уведiть z: ";
        cin >> z;
        if(y == 0 && z < 0){
            cout << "Некоректно введене значення, y не може дорiвнювати нулю, поки z має вiд'ємне  значення" << endl;
        }
        if(z == 0 && y < 0){
            cout << "Некоректно введене значення, z не може дорiвнювати нулю, поки y має вiд'ємне  значення" << endl;
        }
    }while((y == 0 && z < 0) || (z == 0 && y < 0));
    cout << "Уведiть a: ";
    cin >> a;
    cout << "Уведiть b: ";
    cin >> b;
    cout << "a + 5 > b + 2: " << boolalpha << (a + 5 > b + 2) << endl;
    cout << "x у десятковiй системi = " << dec << x << endl;
    cout << "x у шiстнадцятковiй  системi = " << hex << x << endl;
    cout << "y у десятковiй системi = " << dec << y << endl;
    cout << "y у шiстнадцятковiй  системi = " << hex << y << endl;
    cout << "z у десятковiй системi = " << dec << z << endl;
    cout << "z у шiстнадцятковiй  системi = " << hex << z << endl;
    S = s_calculation(x, y, z);
    cout << "\n S = " << s_calculation(x, y, z) << endl;
    system("pause");
}

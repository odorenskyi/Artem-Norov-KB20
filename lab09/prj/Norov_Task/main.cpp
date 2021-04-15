#include <iostream>
#include "ModulesNorov.h"
#include <windows.h>
#include <locale.h>
#include <stdio.h>

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
    int x, y, z, N;
    float length, W;
    char input = ' ';
    setlocale(LC_ALL, "Ukr");
    dev_information();
    cout << "Введiть '7' для виклику s_calculation.  " << endl;
    cout << "Введiть '5' для виклику функцiї задачi 9.1.  " << endl;
    cout << "Введiть '4' для виклику функцiї задачi 9.2.  " << endl;
    cout << "Введiть '3' для виклику функцiї задачi 9.3.  " << endl;
    cout << "Введiть 't', 'T' або 'C' для виходу з програми." << endl;
    while(true){
        cout << "Введiть ключ: ";
        cin >> input;
        if(input == '7'){
            cout << "Уведiть x: ";
            cin >> x;
            cout << "Уведiть y: ";
            cin >> y;
            cout << "Уведiть z: ";
            cin >> z;
            do{
                if(x < -21){
                    cout << "Некоректно введене значення, x не може буди меншим за -21" << endl;
                    cout << "Уведiть x: ";
                    cin >> x;
                }
                if(y == 0 && z < 0){
                    cout << "Некоректно введене значення, y не може дорiвнювати нулю, поки z має вiд'ємне  значення" << endl;
                    cout << "Уведiть y: ";
                    cin >> y;
                    cout << "Уведiть z: ";
                    cin >> z;
                }
                if(z == 0 && y < 0){
                    cout << "Некоректно введене значення, z не може дорiвнювати нулю, поки y має вiд'ємне  значення" << endl;
                    cout << "Уведiть y: ";
                    cin >> y;
                    cout << "Уведiть z: ";
                    cin >> z;
                }
                if(y == 0){
                    cout << "Некоректно введене значення, y не може дорiвнювати нулю" << endl;
                    cout << "Уведiть y: ";
                    cin >> y;
                }
                if(z == 0){
                    cout << "Некоректно введене значення, z не може дорiвнювати нулю" << endl;
                    cout << "Уведiть z: ";
                    cin >> z;
                }
            }while((y == 0 && z < 0) || (z == 0 && y < 0) || y == 0 || z == 0 || x < -21);
            cout << "\nS = " << s_calculation(x, y, z) << endl << endl;
        }else if(input == '5'){
            cout << "\nВведiть силу вiтру: ";
            cin >> W;
            do{
                if(0 > W){
                    cout << "Некоректно введене значення, сила вiтру не може вiд'ємне значення";
                    cout << "\nВведiть силу вiтру: ";
                    cin >> W;
                }
            }while (0 > W);
            cout << "\nБал Бофорта = " << Beaufortmark(W) << endl << endl;
        }else if(input == '4'){
            cout << "\nВведiть довжину обхвату голови у сантиметрах(53-62): ";
            cin >> length;
            do{
                if(length < 53 || length > 62){
                    cout << "Некоректно введене значення, обхвату голови не може бути бiльшим за 62 та меншим за 53";
                    cout << "\nВведiть довжину обхвату голови у сантиметрах(53-62): ";
                    cin >> length;
                }
            }while (length < 53 || length > 62);
            cout << "\nРозмiр шолому = " << (char)Helmetsize(length) << endl << endl;
        }else if(input == '3'){
            int mask_2 = 0b00000000000000000000000000000001;
                cout << "\nВведiть цiле число вiд 0 до 10008000: ";
                cin >> N;
            do{
                if(N < 0 || N > 10008000){
                    cout << "Некоректно введенi данi, N має бути не бiльше нiж 10008000 та меншим нiж 0" << endl;
                    cout << "\nВведiть цiле число вiд 0 до 10008000: ";
                    cin >> N;
                }
            }while (N < 0 || N > 10008000);
            if(!(N & (mask_2 << 15))){
                cout << "Кiлькiсть двiйкових нулiв = " << BinD15(N) << endl << endl;
            }else{
                cout << "Кiлькiсть двiйкових одиниць = " << BinD15(N) << endl << endl;
            }
        }else if(input == 't' || input == 'T' || input == 'C'){
            break;
        }else {
            cout << "Невiрно введений ключ. \a" << endl;
        }
    }
    system("pause");

    return 0;
}

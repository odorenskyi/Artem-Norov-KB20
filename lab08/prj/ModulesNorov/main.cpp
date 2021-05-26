#include <iostream>
#include <math.h>
#include <clocale>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <wchar.h>
#include <bitset>
#include <ctime>
#include "ModulesNorov.h"

using namespace std;

float s_calculation(float x, float y, float z){
    const double P = 3.141592653589793;
    float S = 0.5 *((pow(y,2) + 2 * z)/(sqrt(7*P + x))) - sqrt(exp(fabs(x)) + (sqrt(fabs(y - z))/sin(z*y)));
    return S;
}

double Beaufortmark(double W){
    if (W < 0.3){
        return 0.0;
    }else if (W >= 0.3 && W <= 1.5){
        return 1.0;
    }else if (W >= 1.6 && W <= 3.3){
        return 2.0;
    }else if (W >= 3.4 && W <= 5.4){
        return 3.0;
    }else if (W >= 5.5 && W <= 7.9){
        return 4.0;
    }else if (W >= 8.0 && W <= 10.7){
        return 5.0;
    }else if (W >= 10.8 && W <= 13.8){
        return 6.0;
    }else if (W >= 13.9 && W <= 17.1){
        return 7.0;
    }else if (W >= 17.2 && W <= 20.7){
        return 8.0;
    }else if (W >= 20.8 && W <= 24.4){
        return 9.0;
    }else if (W >= 24.5 && W <= 28.4){
        return 10.0;
    }else if (W >= 28.5 && W <= 32.6){
        return 11.0;
    }else if (W >= 32.7){
        return 12.0;
    }
    return W;
}
std::string  Helmetsize(std::string length){
    std::string sizesh;
    int d = atoi(length.c_str());
    if (d == 53 || d == 54){
        sizesh = "XS";
        return sizesh;
    }
    if (d == 55 || d == 56){
        sizesh = "S";
        return sizesh;
    }
    if (d == 57 || d == 58){
        sizesh = "M";
        return sizesh;
    }
    if (d == 59 || d == 60){
        sizesh = "L";
        return sizesh;
    }
    if (d == 61 || d == 62){
        sizesh = "XL";
        return sizesh;
    }
    if(d > 62 || d < 53){
        sizesh = "E";
        return sizesh;
    }
}

int BinD15(int N){
    int result = 0;
    bool flag = false;
    for (int n=sizeof(int)*8-1; n>-1; n--)  {
        if((N>>n)&1)
            if(!flag) {
                flag = true;
            }
        if (flag){
            if((N>>15)&1){
                result += ((N>>n)&1)? 1 : 0;
            }else{
                result += ((N>>n)&1)? 0 : 1;
            }
        }
    }
    return result;
}
void Task10_1()
{
    string file_1 = "OutFile.txt";
    string file_2 = "InFile.txt";
    ofstream fout;
    ifstream fin;
    fin.open(file_2);
    if (!fin.is_open()){
        fin.close();
        fout.open(file_2);
        cout << "Помилка пiд час вiдкриття файлу, для роботи застосунка не виявленно файла \"InFile.txt\"" << endl;
        fout.close();
        fin.open(file_2);
    }
    char Articles;
    string WordFind;
    char c;
    int pos = 0;
    int ArtCounter = 0;
    fout.open(file_1);
    if (!fin.is_open()){
        cout << "Помилка пiд час вiдкриття файлу, для роботи застосунка не виявленно файла \"InFile.txt\"" << endl;
    }
    if (!fout.is_open()){
        cout << "Помилка пiд час вiдкриття файлу, для роботи застосунка не виявленно файла \"OutFile.txt\"" << endl;
    }else{
        fout << "Розробник: Норов Артем Центральноукраїнський нацiональний технiчний унiверситет Місто Кропивницький, Україна 2021";
        while(!fin.eof()){
            fin.get(Articles);
            if(Articles == '\n')
                ArtCounter++;
        }
        fout << "\n";
        fout << "Кiлькiсть абзацiв у файлi InFile = " << ArtCounter << endl;
        fout << "\n";
        fin.close();
        fin.open(file_2);
        while(!fin.eof()){
            fin.get(c);
            WordFind.push_back(c);
        }
        fin.close();
        string arr[] {"університет","Україна","блокнот","університету","університетом","Україні", "Україною" , "Україно", "блокнота", "блокнотові" };
        pos = WordFind.find(*arr);
        if(pos == -1){
                fout << "У файлi InFile.txt немає слiв: \"Україна\", \"унiверситет\" та \"блокнот\"";
            }else{
                fout << "У файлi InFile.txt наявнi слова: \"Україна\", \"унiверситет\" та \"блокнот\"";
            }
    }
    fout << "\n";
    fout.close();
    fin.close();
}
void Task10_2()
{
    string file1 = "InFile.txt";
    string file2 = "InFile.txt";
    char Pointing;
    int PointCounter = 0;
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    ifstream fin;
    ofstream fout;
    fin.open(file1);
    fout.open(file2, ios_base::app);
    if(!fin.is_open()){
        cout << "Помилка пiд час вiдкриття файлу";
    }else{
        while(!fin.eof()){
            fin.get(Pointing);
            if(Pointing == '.'){
                PointCounter++;
            }
            if(Pointing == ','){
                PointCounter++;
            }
            if(Pointing == '!'){
                PointCounter++;
            }
            if(Pointing == '?'){
                PointCounter++;
            }
            if(Pointing == '-'){
                PointCounter++;
            }
            if(Pointing == ';'){
                PointCounter++;
            }
            if(Pointing == ':'){
                PointCounter++;
            }
            if(Pointing == '('){
                PointCounter++;
            }
            if(Pointing == ')'){
                PointCounter++;
            }
            if(Pointing == '"'){
                PointCounter++;
            }
            if(Pointing == '{'){
                PointCounter++;
            }
            if(Pointing == '}'){
                PointCounter++;
            }
            if(Pointing == '`'){
                PointCounter++;
            }
        }
        fout << "\n";
        fout << "Кiлькiсть пунктуацiйних знакiв у файлi = " << PointCounter << endl;
        fout << "Дата й час дозапису iнформацiї: " << asctime(timeinfo);
    }
    fin.close();
    fout.close();
}
void Task10_3()
{
    string file2 = "OutFile.txt";
    ofstream fout;
    int x, y, z;
    int b = 0;
    float Result = 0;
    fout.open(file2, ios_base::app);
    if(!fout.is_open()){
        cout << "Помилка пiд час вiдкриття файлу";
    }else{
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
    while(b <= 1){
        cout << "Уведiть число b: ";
        cin >> b;
    }
    fout << "\n";
    Result = s_calculation(x,y,z);
    fout << "Результат s_calculation у десятковiй cистемi: " << dec << Result << endl;
    fout << "Число b у двiйковому кодi = " << bitset<32>(b) << endl;
    }
    fout.close();
}


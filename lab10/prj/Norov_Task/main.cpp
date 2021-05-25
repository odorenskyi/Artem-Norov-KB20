#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <bitset>
#include "ModulesNorov.h"
using namespace std;


string readFile(const string& fileName)
{
    ifstream f(fileName);
    stringstream ss;
    ss << f.rdbuf();
    return ss.str();
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
int main()
{
    setlocale(LC_ALL,"");
    cout << "Task by Norov Artem, CNTU, 2021" << endl;
    cout << endl;
    Task10_1();
    Task10_2();
    Task10_3();
    cout << endl;
    system("pause");
}

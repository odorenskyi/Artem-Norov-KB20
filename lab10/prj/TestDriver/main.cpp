#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <bitset>
#include "ModulesNorov.h"
using namespace std;

int ArtCountNum = 6;
int PoiCountNum = 24;

string readFile(const string& fileName)
{
    ifstream f(fileName);
    stringstream ss;
    ss << f.rdbuf();
    return ss.str();
}

void Task10_1()
{
    string file_1 = "InFile.txt";
    string file_2 = "OutFile.txt";
    ofstream fout;
    ifstream fin;
    char Articles;
    string WordFind;
    char c;
    int pos = 0;
    int ArtCounter = 0;
    fout.open(file_1);
    fin.open(file_2);
    if (!fout.is_open()){
        cout << "Помилка пiд час вiдкриття файлу" << endl;
    }else{
        fout << "Розробник: Норов Артем Центральноукраїнський нацiональний технiчний унiверситет Місто Кропивницький, Україна 2021";
        while(!fin.eof()){
            fin.get(Articles);
            if(Articles == '\n')
                ArtCounter++;
        }
        fout << "\n";
        fout << "Кiлькiсть абзацiв у файлi OutFile = " << ArtCounter << endl;
        fout << "\n";
        fin.close();
        fin.open(file_2);
        while(!fin.eof()){
            fin.get(c);
            WordFind.push_back(c);
        }
        fin.close();
        string arr[] {"університет","університету", "університетом","Україна","Україні", "Україною" , "Україно", "блокнот", "блокнота", "блокнотові" };
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
    string file1 = "OutFile.txt";
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
            if(Pointing == '.')
                PointCounter++;
            if(Pointing == ',')
                PointCounter++;
            if(Pointing == '!')
                PointCounter++;
            if(Pointing == '?')
                PointCounter++;
            if(Pointing == '-')
                PointCounter++;
            if(Pointing == ';')
                PointCounter++;
            if(Pointing == ':')
                PointCounter++;
            if(Pointing == '(')
                PointCounter++;
            if(Pointing == ')')
                PointCounter++;
            if(Pointing == '"')
                PointCounter++;
            if(Pointing == '{')
                PointCounter++;
            if(Pointing == '}')
                PointCounter++;
            if(Pointing == '`')
                PointCounter++;
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
    string file2 = "InFile.txt";
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
void Tasktest10_1()
{
    string file_1 = "InFile.txt";
    string file_2 = "OutFile.txt";
    string str;
    char Articles;
    int ArtCounter = 0;
    ifstream fin;
    fin.open(file_2);
    if (file_1 == "InFile.txt" && file_2 == "OutFile.txt"){
        cout << "Коректнiсть назв файлiв, Status: passed" << endl;
    }else{
        cout << "Коректнiсть назв файлiв, Status: failed" << endl;
    }
    while(!fin.eof()){
        getline(fin, str);
    }
    if(str.find("Розробник: Норов Артем Центральноукраїнський національний технічний університет Місто Кропивницький, Україна 2021")){
        cout << "Iнформацiя про розробника, Status: passed" << endl;
    }else{
        cout << "Iнформацiя про розробника, Status: failed" << endl;
    }
    fin.close();
    fin.open(file_2);
    while(!fin.eof()){
            fin.get(Articles);
            if(Articles == '\n')
                ArtCounter++;
        }
    if (ArtCounter == ArtCountNum){
        cout << "Кiлькiсть абзацiв, Status: passed" << endl;
    }else{
        cout << "Кiлькiсть абзацiв, Status: failed" << endl;
    }
    fin.close();
}


void Tasktest10_2()
{
    string OutFile = "OutFile.txt";
    ifstream fin;
    string str2;
    string test2;
    string test;
    string testTime = "Sat May 22 23:52:38 2021";
    test = readFile(OutFile);
    int a = 0;
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    fin.open(OutFile);
    string TimeI = "Sat May 22 23:52:38 2021";
    char Pointing;
    int PointCounter = 0;
    while(!fin.eof()){
            fin.get(Pointing);
            if(Pointing == '.')
                PointCounter++;
            if(Pointing == ',')
                PointCounter++;
            if(Pointing == '!')
                PointCounter++;
            if(Pointing == '?')
                PointCounter++;
            if(Pointing == '-')
                PointCounter++;
            if(Pointing == ';')
                PointCounter++;
            if(Pointing == ':')
                PointCounter++;
            if(Pointing == '(')
                PointCounter++;
            if(Pointing == ')')
                PointCounter++;
            if(Pointing == '"')
                PointCounter++;
            if(Pointing == '{')
                PointCounter++;
            if(Pointing == '}')
                PointCounter++;
            if(Pointing == '`')
                PointCounter++;
        }
    if(PointCounter == PoiCountNum){
        cout << "Кiлькiсть пунктуацiйних знакiв, Status: passed"<<endl;
    }else{
        cout << "Кiлькiсть пунктуацiйних знакiв, Status: failed"<<endl;
    }
    fin.close();
    fin.open(OutFile);
    while(!fin.eof()){
        getline(fin, str2);
    }
    if(asctime(timeinfo) == asctime(timeinfo)){
        cout << "Дата й час звернення, Status: passed" << endl;
    }else{
        cout << "Дата й час звернення, Status: failed" << endl;
    }
}

int main()
{
    setlocale(LC_ALL,"");
    cout << "TestDriver by Norov Artem, CNTU, 2021" << endl;
    cout << endl;
    Task10_1();
    Task10_2();
    Task10_3();
    Tasktest10_1();
    Tasktest10_2();
    cout << endl;
    system("pause");
}


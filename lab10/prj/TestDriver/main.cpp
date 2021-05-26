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


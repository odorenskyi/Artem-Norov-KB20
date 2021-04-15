#include <iostream>
#include <math.h>
#include <clocale>
#include <stdlib.h>
#include <string>
#include <wchar.h>
#include "ModulesNorov.h"

using namespace std;

float s_calculation(float x, float y, float z){
    const double P = 3.141592653589793;
    float S = 0.5 *((pow(y,2) + 2 * z)/(sqrt(7*P + x))) - sqrt(exp(abs(x)) + (sqrt(abs(y - z))/sin(z*y)));
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
int Helmetsize(int length){
    char sizesh = '        ';
    if (length == 53 || length == 54){
        sizesh = 'XS';
        return (char)sizesh;
    }else if (length == 55 || length == 56){
        sizesh = 'S';
        return (char)sizesh;
    }else if (length == 57 || length == 58){
        sizesh = 'M';
        return (char)sizesh;
    }else if (length == 59 || length == 60){
        sizesh = 'L';
        return (char)sizesh;
    }else if (length == 61 || length == 62){
        sizesh = 'XL';
        return (char)sizesh;
    }else{
        sizesh = 'Wrong size';
        return (char)sizesh;
    }
}

int BinD15(int N){
    int mask_1 = 0b00000000000000000000000000000001;
    int mask_2 = 0b00000000000000000000000000000001;
    int Zerocount = 0;
    int Onecount = 0;
    for(int i = 0; i < (log2(N)); i++){
        if(!(N & mask_1))
            Zerocount++;
        else{
            Onecount++;
            mask_1 <<= 1;
        }
    }
    if(!(N & (mask_2 << 15))){
        cout << "Кiлькiсть двiйкових нулiв = ";
        return Zerocount;
    }else{
        cout << "Кiлькiсть двiйкових одиниць = ";
        return Onecount;
    }
}

#include <iostream>
#include <math.h>
#include <clocale>
#include <stdlib.h>
#include <string>
#include "ModulesNorov.h"

using namespace std;

float s_calculation(float x, float y, float z){
    const double P = 3.141592653589793;
    float S = 0.5 *((pow(y,2) + 2 * z)/(sqrt(7*P + x))) - sqrt(exp(abs(x)) + (sqrt(abs(y - z))/sin(z*y)));
    return S;
}
double wind_speed(double W){
    W = W * 1000;
    return W;
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
string Helmetsize(int s){
    string sizesh;
    int sl = s;
    if (sl == 53 || sl == 54){
        sizesh = "XS";
        return sizesh;
    }else if (sl == 55 || sl == 56){
        sizesh = "S";
        return sizesh;
    }else if (sl == 57 || sl == 58){
        sizesh = "M";
        return sizesh;
    }else if (sl == 59 || sl == 60){
        sizesh = "L";
        return sizesh;
    }else if (sl == 61 || sl == 62){
        sizesh = "XL";
        return sizesh;
    }else{
        sizesh = "Wrong size";
        return sizesh;
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
        return Zerocount;
    }else{
        return Onecount;
    }
}



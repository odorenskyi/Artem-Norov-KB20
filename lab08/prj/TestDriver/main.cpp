#include <iostream>
#include <cmath>
#include "ModulesNorov.h"
using namespace std;

int main()
{
    float x[10] = {1, 6, 0.3, 2, 123, -8, 33, 111, -11, -16};
    float y[10] = {4, 2, 84.23, 9, 526, 23, -682, 111, -11, -44};
    float z[10] = {3, 9, 5, 32.432, 34, 111, 79, 111, -11, -390.32};
    float result = 0;
    const double P = 3.141592653589793;
    for(int i = 0; i < 10; i++){
        result = 0.5 *((y[i] * y[i] + 2 * z[i])/(sqrt(7*P + x[i]))) - sqrt(exp(abs(x[i])) + (sqrt(abs(y[i] - z[i]))/sin(z[i]*y[i])));
        if(s_calculation(x[i], y[i], z[i]) == result){
            cout << "Status: passed = " << result << endl;
        }
        else{
            cout << "Status: failed = " << result << endl;
        }
    }
    return 0;
}

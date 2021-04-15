#include <iostream>
#include <ModulesNorov.h>
using namespace std;

int main()
{
    cout << "Task 9.1:" << endl;
    float W[] = {0.2, 1.3, 2.5, 4.4, 7.8, 9.7, 12.3, 15.6, 18.8, 23.3, 27.1, 31.7, 32.8};
    float expected1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for(int i = 0; i < 12; i++){
        if((W[i]) == expected1[i]){
            cout << "Status: passed = " << endl;
        }
        if((W[i]) != expected1[i]){
            cout << "Status: failed =" << endl;
        }
    }
}

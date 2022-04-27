#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

int HashFuction (int k) {
    int N = 13;
    double A = 0.618033;
    int h = N * fmod(k * A, 1);
    return h;
}

int main()
{
    int key;
    cout <<"Key > ";
    cin >>key;
    cout << "HashFunction("<<key<<")="<<HashFuction(key)<<endl;
    getch();
    return 0;
}

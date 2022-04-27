#include <iostream>
#include <conio.h>

using namespace std;

int HashFuction (int k) {
    return (k%10);
}

int main(){
    int key;
    cout <<"Key > ";
    cin >>key;
    cout << "HashFunction("<<key<<")="<<HashFuction(key)<<endl;
    getch();
    return 0;
}

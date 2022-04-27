#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

int main()
{
    time_t timer;
    timer = time(NULL);
    cout<<&timer<<endl;
    cout<<timer<<endl;
    printf("Date: %s\n", ctime(&timer));
    getch();
    return 0;

}

#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

int main()
{
    time_t seconds;
    seconds = time(NULL);
    cout<<"The number of hours since January 1, 1970 = "<<seconds/3600<<endl;
    _getch();
    return 0;
}

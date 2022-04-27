#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    const int array_size = 200000;
    int array1[array_size];
    for(int counter = 0; counter < array_size; counter++)
    {
        array1[counter] = rand() % 50 - rand() % 50;
        cout<<array1[counter]<<" ";
    }

    int min = array1[0];

    for(int counter = 1; counter < array_size; counter++)
    {
        if(min > array1[counter])
            min = array1[counter];
    }

    cout<<"\nmin = "<<min<<endl;
    cout<<"runtime = "<<clock()/CLOCKS_PER_SEC<<"cek."<<endl;
    system("pause");
    return 0;
}

#include <iostream>
#include <conio.h>

using namespace std;
void tower(int, int, int, int);

int count1 = 1;

int main()
{
    cout << "Enter of number of disks: ";
    int number;
    cin >> number;

    cout << "Enter the number of basic rod: ";
    int basic_rod;
    cin >> basic_rod;

    cout << "Enter the number of final rod: ";
    int final_rod;
    cin >> final_rod;

    int help_rod;

    if(basic_rod != 2 && final_rod != 2){
        help_rod = 2;
    }
    else{
        if(basic_rod != 1 && final_rod != 1) help_rod = 1;
        else{
            if(basic_rod != 3 && final_rod != 3) help_rod = 3;
        }
    }

    tower(number, basic_rod, help_rod, final_rod);
    getch();
    return 0;
}

void tower(int count_disk, int baza, int help_baza, int new_baza)
{
    if(count_disk == 1)
    {
        cout <<count1<<") "<< baza << " " << "->" << " " << new_baza << endl;
        count1++;
    }
    else
    {
        tower(count_disk - 1, baza, new_baza, help_baza);
        tower(1, baza, help_baza, new_baza);
        tower(count_disk - 1, help_baza, baza, new_baza);
    }
}

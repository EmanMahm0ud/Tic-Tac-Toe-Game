#include <iostream>
#include <stdlib.h>

using namespace std;

void print_arr(char a[])                       //To build XO board
{
    system("cls");                             //To clear past screen
    for (int i=0 ; i<9 ; i+=3)
    {
        cout << '|' << a[i] << '|' << a[i+1] << '|' << a[i+2] << '|' << endl;
    }
}

bool check_arr(char a[], char xo)              //To check who won
{
    if ((a[0]==xo && a[1]==xo && a[2]==xo) ||
        (a[3]==xo && a[4]==xo && a[5]==xo) ||
        (a[6]==xo && a[7]==xo && a[8]==xo) ||
        (a[0]==xo && a[3]==xo && a[6]==xo) ||
        (a[1]==xo && a[4]==xo && a[7]==xo) ||
        (a[2]==xo && a[5]==xo && a[8]==xo) ||
        (a[0]==xo && a[4]==xo && a[8]==xo) ||
        (a[2]==xo && a[4]==xo && a[6]==xo)
        )
            return true;                       //If there is a winner
    else
        return false;
}

void take_in(char a[], char xo)                //This function to initialize x or y to the array
{
    char x;
    cin>>x;                                    //The user enters the number of the cell he wants to put his x/y
    switch (x)
    {
        case '1': a[0] = xo; break;
        case '2': a[1] = xo; break;
        case '3': a[2] = xo; break;
        case '4': a[3] = xo; break;
        case '5': a[4] = xo; break;
        case '6': a[5] = xo; break;
        case '7': a[6] = xo; break;
        case '8': a[7] = xo; break;
        case '9': a[8] = xo; break;
    }
}

int main()
{
    char c = '0';
    int i, j;
    char arr[9];
    char xo;

    for (i = 0 ; i < 9 ; i++)      //To fill the cells with 1, 2, ..9
        arr[i] = char(++c);

    for (i = 0 ; i < 9 ; i++)      //To take turns between x player and y player
    {
        if (i%2 == 0)
            xo = 'X';
        else
            xo = 'O';

        print_arr(arr);
        cout << endl << xo << "'s turn" << endl;

        take_in(arr, xo);
        print_arr(arr);

        if (check_arr(arr, xo))
        {
            cout << endl << xo << " WON" << endl;
            return 0;
        }
    }

    cout << endl << "NO ONE WON :'(" << endl;

    return 0;
}

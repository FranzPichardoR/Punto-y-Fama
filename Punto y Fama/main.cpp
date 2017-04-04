#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int getRandom()
{
    int random, x1, x2, x3, x4;

    srand (time(NULL));

    x1 = rand() % 9+1;

    do
    {
        x2 = rand() % 9+1;
        if(x2 == x1)
            x2 = rand() % 9+1;
    }

    while(x2 == x1);

    do
    {
        x3 = rand() % 9+1;
        if(x3 == x1 || x3 == x2)
            x3 = rand() % 9+1;
    }
    while(x3 == x1 || x3 == x2);

    do
    {
        x4 = rand() % 9+1;
        if(x4 == x1 || x4 == x2 || x4 == x3)
            x4 = rand() % 9+1;
    }
    while(x4 == x1 || x4 == x2 || x4 == x3);

    random = (x1*1000) + (x2*100) + (x3*10) + x4;

    return random;
}

int main()
{
    int x, arrayx[4], randomNum, randomarray[4];

    randomNum = getRandom();

    cout << randomNum << endl;

    cout << "Digite el numero de 4 digitos: " << endl;
    while(x<1000 || x>9999)
    {
        cin >> x;
        if(x<1000 || x>9999)
            cout << "El numero debe ser de 4 digitos." << endl;
    }

    arrayx[0] = x/1000;
    arrayx[1] = (x/100)%10;
    arrayx[2] = (x/10)%10;
    arrayx[3] = x%10;

    cout << endl;

}

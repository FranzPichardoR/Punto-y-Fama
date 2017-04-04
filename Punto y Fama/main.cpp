#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int random;

    srand (time(NULL));

    random = rand() % 1000 + 8999;

    cout << random << endl;

    int randomarray[4];

    randomarray[0] = random/1000;
    randomarray[1] = (random/100)%10;
    randomarray[2] = (random/10)%10;
    randomarray[3] = random%10;

    cout << endl;

    int x, arrayx[4];

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

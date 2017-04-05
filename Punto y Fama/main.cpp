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

int checkNum(int x)
{
    int arrayx[4];

    arrayx[0] = x/1000;
    arrayx[1] = (x/100)%10;
    arrayx[2] = (x/10)%10;
    arrayx[3] = x%10;

    for(int i=0; i<4; i++){
        for(int k=0; k<4; k++)
        {
            if(i==k)
                continue;
            else if(arrayx[i] == arrayx[k])
            {
                return 0;
            }
        }
    }
    return x;
}

int main()
{
    int x, arrayx[4], randomNum, randomarray[4], counter=0, newx;
    char answers[4];

    randomNum = getRandom();

    randomarray[0] = randomNum/1000;
    randomarray[1] = (randomNum/100)%10;
    randomarray[2] = (randomNum/10)%10;
    randomarray[3] = randomNum%10;

    for(counter=0; counter<10; counter++)
    {
        do
        {
            cout << "Digite un numero de 4 digitos: " << endl;
            cin >> x;
            if(x<1000 || x>9999)
                cout << "El numero debe ser de 4 digitos." << endl;

            newx = checkNum(x);

            if(newx!=x)
                x=newx;

            if(x==0)
                cout << "El numero tiene digitos repetidos." << endl;
        }
        while(x<1000 || x>9999 || x==0);

        arrayx[0] = x/1000;
        arrayx[1] = (x/100)%10;
        arrayx[2] = (x/10)%10;
        arrayx[3] = x%10;

        for(int i=0; i<4; i++)
            for(int k=0; k<4; k++)
            {
                if(arrayx[i] == randomarray[k] && i!=k)
                {
                    for(int j=0; j<4; j++)
                    {
                        if(answers[j]=='P' || answers[j]=='F')
                            continue;
                        else
                        {
                            answers[j] = 'P';
                            break;
                        }
                    }
                }

                else if(arrayx[i] == randomarray[k] && i==k)
                {
                    for(int j=0; j<4; j++)
                    {
                        if(answers[j]=='P' || answers[j]=='F')
                            continue;
                        else
                        {
                            answers[j] = 'F';
                            break;
                        }
                    }
                }
            }

        system("CLS");

        cout << "El ultimo numero que digito fue: " << x << endl;

        cout << "Punto y Fama: ";
        for(int i=0; i<4; i++)
        {
            if(answers[i]=='P' || answers[i]=='F')
                cout << answers[i];
        }
        cout << endl;

        cout << endl << "Intento #" << counter+2;

        if(answers[0]=='F' && answers[1]=='F' && answers[2]=='F' && answers[3]=='F')
        {
            cout << endl << "Ha ganado el juego de Punto y Fama!" << endl << "El numero aleatorio era: " << randomNum << endl;
            break;
        }

        for(int i=0; i<4; i++)
            answers[i] = ' ';

        cout << endl;
    }
    cout << "El numero total de intentos fue: " << counter+1 << endl;


}

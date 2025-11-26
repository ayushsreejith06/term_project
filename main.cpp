
#include <stdlib.h>
#include <iostream>
using namespace std;

void cleanStandardInputStreamm(void);

void cleanStandardInputStream(void) 
{
    int leftover;
    do 
    {
        leftover = cin.get();
    } while (leftover != '\n' && leftover != EOF);
}


void pressEnter()
{
    cout << "\n<<<Press Return to continue";

}
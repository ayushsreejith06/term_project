
#include <stdlib.h>
using namespace std;

void cleanStandardInputStreamm(void);




void cleanStandardInputStream(void) 
{
    int leftover;
    do 
    {
        leftover = cin.get();
    } while (leftover != '\n' && leftover != EOF)
}



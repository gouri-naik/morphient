#include <stdio.h>
#include <unistd.h> //for sleep()
#include <stdlib.h>
#include <time.h>


void printRandoms()
{
    int rd_num = rand() % 201;
    printf("%d\n", rd_num);
    fflush(stdout);
    
}

int main() 
{
    //printf("Printing nos in range 0 to 100 at an interval of 1 sec: \n\n");
    while (1)
    {
        printRandoms();
        sleep(1); //1sec sleep

    }
}



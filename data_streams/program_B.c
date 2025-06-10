#include <stdio.h>
#include <unistd.h> //for sleep()
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main()
{
    int num;
    int buffer[5];
    char filename[50];
    while(1)
    {
        //empty buffer
        for(int i=0; i<5; i++)
            buffer[i]=0;

        time_t time_now = time(NULL);//get curr time
        printf("********TIME*******: %ld\n", time_now);
        printf("Storing values to buffer...\n");
        sprintf(filename, "%ld.txt", time_now);

        for(int i=0; i<5 && scanf("%d", &num) == 1; i++)
        {
            buffer[i] = num;
        }

        printf("Content stored:\n");
        for(int i=0; i<5; i++)
        {
            printf("%d\t", buffer[i]);
        }
        int size = sizeof(buffer) / sizeof(buffer[0]);
        FILE *fp;

        fp = fopen(filename, "w"); //w: write mode

        if (fp == NULL)
        {
            perror("Error opening file\n");
            return 1;
        }

        for (int i = 0; i < size; i++)
        {
            fprintf(fp, "%d\n", buffer[i]);
        }
        printf("\n");
        fclose(fp);
        printf("Data written to %s\n", filename);
    }
   
}

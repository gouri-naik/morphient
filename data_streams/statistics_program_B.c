#include <stdio.h>
#include <unistd.h> //for sleep()
#include <stdlib.h>
#include <time.h>
#include <string.h>

int sum(int arr[])
{
    int sum=0;
    for(int i=0; i<5; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int average(int arr[])
{
    int arr_sum = sum(arr);
    int avg = arr_sum/5;
    return avg;
}

int maximum(int arr[])
{
    int max=arr[0];
    for(int i=0; i<5; i++)
    {
        if(arr[i] > max)
            max=arr[i];
    }
    return max;
}

int minimum(int arr[])
{
    int min = arr[0];
    for(int i=0; i<5; i++)
    {
        if(arr[i] < min)
            min=arr[i];
    }
    return min;
}

int main()
{
    int num;
    int buffer[5];
    char filename[50], stat_filename[100];
    while(1)
    {
        //empty buffer
        for(int i=0; i<5; i++)
            buffer[i]=0;

        time_t time_now = time(NULL);//get curr time
        printf("********TIME*******: %ld\n", time_now);
        printf("Storing values to buffer...\n");
        sprintf(filename, "%ld.txt", time_now);
        sprintf(stat_filename, "%ld_statistics.txt", time_now);

        for(int i=0; i<5 && scanf("%d", &num) == 1; i++)
        {
            buffer[i] = num;
        }

        printf("Content stored:\n");
        for(int i=0; i<5; i++)
        {
            printf("%d\t", buffer[i]);
        }
        
        //file handling
        int size = sizeof(buffer) / sizeof(buffer[0]);
        FILE *fp, *f_stat_file;

        fp = fopen(filename, "w"); //w: write mode
        f_stat_file = fopen(stat_filename, "w");

        if (fp == NULL || f_stat_file == NULL)
        {
            perror("Error opening file\n");
            return 1;
        }

        //to data file
        for (int i = 0; i < size; i++)
        {
            fprintf(fp, "%d\n", buffer[i]);
        }

        //to stats file
        fprintf(f_stat_file, "Count: %d\n", 5);
        fprintf(f_stat_file, "Sum: %d\n", sum(buffer));
        fprintf(f_stat_file, "Average: %d\n", average(buffer));
        fprintf(f_stat_file, "Max: %d\n", maximum(buffer));
        fprintf(f_stat_file, "Min: %d\n", minimum(buffer));

        printf("\n");
        fclose(fp);
        fclose(f_stat_file);
        printf("Data written to %s and %s\n", filename, stat_filename);
    }
   
}

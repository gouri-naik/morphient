#include<stdio.h>
#include<string.h>
#define TOTAL_FILES 5

int read_number(char *directory) {

    static FILE *file = NULL;
    static int current_file = 1;
    static int initialized = 0;
    static char path[100];
    int num;

    while (current_file <= TOTAL_FILES) {
        if (!initialized)
        {
            snprintf(path, sizeof(path), "%s/p%d.txt", directory, current_file); //constructs path name
            file = fopen(path, "r");

            if (file == NULL)
            {
                printf("Could not open file: %s\n", path);
                current_file++; //goto next file
                continue;
            }

            initialized = 1; //opened
        }

        
        if (fscanf(file, "%d", &num) == 1)
        {
            return num;
        }
        else
        {
            fclose(file); //close current file
            file = NULL;
            initialized = 0;
            current_file++;
        }
    }

    return -1;
}

int main()
{
    char directory[100];
    int num;
    int sum = 0;

    printf("Enter name of directory to read: ");
    scanf("%s", directory);
    for(int i=0; i<25; i++)
    {
        num = read_number(directory);
        sum += num;
        printf("\nNum is: %d\n", num);
    }
    printf("\nSum is: %d\n", sum);

}


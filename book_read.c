#include<stdio.h>

int read_number(char filename[100])
{
    static FILE *file = NULL;
    static int init = 0;
    int num;

    if(!init)
    {
        file = fopen(filename, "r"); //to open only once
        if (file == NULL) {
            printf("Could not open file\n");
            return -1;
        }
        init = 1;
    }

    // Read one number
    if (fscanf(file, "%d", &num) == 1) {
        return num;
    } else {
        fclose(file);     // Close file at EOF
        init = 0;  // Reset for reuse if needed
        return -1;        // Indicate end of file
    }
}

int main()
{
    char filename[100];
    int num;
    int sum = 0;

    printf("Enter name of file to read: ");
    scanf("%s", filename);
    for(int i=0; i<5; i++)
    {
        num = read_number(filename);
        sum += num;
        printf("\nNum is: %d\n", num);
    }
    printf("Sum is: %d\n", sum);

}
    

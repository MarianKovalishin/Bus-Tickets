#include "Input.h"
#include "Header.h"

void write_data()
{
    int i = 0;
    memset(msg, 0, 100);
    scanf("%s", msg);
    while (msg[i] != 0)
        i++;
    msg[i] = '\n';
    fprintf(fptr, "%s", msg);
}

void input() 
{
    fptr = fopen("tickets.bin","ab");
    check_file(fptr);

    while (true) // breaking is in cycle
    {
        memset(msg, 0, 100); // clear string
        printf("Enter 'any key', if you want to add trip. Enter '0', if you want to exit.\n");
        scanf("%s", msg);
        if (msg[0] == '0') break;

        printf("Destination\n");
        write_data();

        printf("Bus\n");
        write_data();

        printf("Date\n");
        write_data();

        printf("Time\n");
        write_data();

        printf("Price\n");
        write_data();

        printf("Availability\n");
        write_data();

        count_trips++; 
    }

    clear_screen;
    fclose(fptr);
}



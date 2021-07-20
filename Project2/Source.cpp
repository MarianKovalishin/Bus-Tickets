#include "Header.h"

int count_trips = 0, temp_ind = 0;
char msg[100]{};
char temp[100]{};

FILE* fptr = fopen("tickets.bin", "wb");

void check_file(FILE* fptr)
{
    if (fptr == NULL) // check if file was open correctly
    {
        printf("Error!");
        exit(1);
    }
}
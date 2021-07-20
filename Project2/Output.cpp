#include "Header.h"

char print[100]{};

void output()
{
    fptr= fopen("tickets.bin", "rb");
    check_file(fptr);

    print[0] = 0;
	printf("%4s", "|ID|");
    printf("%20s", "|Destination|");
	printf("%20s", "|Bus|");
	printf("%10s", "|Date|");
	printf("%10s", "|Time|");
	printf("%10s", "|Price|");
	printf("%16s", "|Available|\n");

    for (int i = 0; i < count_trips; i++)
    {
        printf("%4d", i);

        fscanf(fptr, "%s", &print);
        printf("%20s", print);

        fscanf(fptr, "%s", &print);
        printf("%20s", print);

        fscanf(fptr, "%s", &print);
        printf("%10s", print);

        fscanf(fptr, "%s", &print);
        printf("%10s", print);

        fscanf(fptr, "%s", &print);
        printf("%10s", print);

        fscanf(fptr, "%s", &print);
        printf("%15s", print);

        cout << endl;
    }

    fclose(fptr);
}
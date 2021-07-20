#include "Header.h"
#include "Input.h"
#include "Output.h"
#include "Edit.h"
#include "Sort.h"
#include "Select.h"
#include "Def.h"



int main()
{
	fclose(fptr); // because after initialization file was open
	remove("tickets.bin");

	int choice = 1;
	while (choice != 0)
	{
		printf("\n\n\nEnter '1', to input data\n");
		printf("Enter '2', to read data\n");
		printf("Enter '3', to edit data\n");
		printf("Enter '4', to sort data\n");
		printf("Enter '5', to select data\n");
		printf("Enter '6', to select 2 cheapest trip in the next week\n");
		printf("Enter '0', to quit\n");

		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			clear_screen;
			input();
			break;
		case 2:
			clear_screen;
			output();
			break;
		case 3:
			clear_screen;
			output();
			edit();
			break;
		case 4:
			clear_screen;
			sort();
			break;
		case 5:
			clear_screen;
			select();
			break;
		case 6:
			clear_screen;
			def();
			break;
		default:
			clear_screen;
			choice = 0;
			break;
		}
	}

	return 0;
}


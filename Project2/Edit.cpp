#include "Edit.h"

char trips[10][100]{};
char edited[100]{}, new_categorie[100]{};
int categorie_to_edit = 0, ID = 0, counter = 0, num = 0, index = 0, trips_ind = 0;
bool was_edit = false;

void edit_categorie(int& i)
{
	while ((i % 7) < (categorie_to_edit - 1)) // -1 because index
	{
		fscanf(fptr, "%s", &edited);

		index = 0;
		while (edited[index] != 0)
			index++;
		edited[index] = '\n';

		num = 0;
		while(edited[num] != 0)
		{
			temp[temp_ind] = edited[num];
			num++;
			temp_ind++;
		}
		i++;
	}

	num = 0;
	while (new_categorie[num] != 0)
	{
		temp[temp_ind] = new_categorie[num];
		num++;
		temp_ind++;
	}
	fscanf(fptr, "%s", &edited); // to skip edited element
}

void edit()
{
	fptr = fopen("tickets.bin", "rb");
	check_file(fptr);
	for (int i = 0; i < 10; i++)	memset(trips[i], 0, 100);
	memset(temp, 0, 100);

	was_edit = false; // reset
	counter = 0;

	printf("Enter 'ID', that you want to edit\n");
	scanf("%d", &ID); // number of trip, that will be edited

	trips_ind = 0, temp_ind = 0, index = 0;
	for (int i = 0; i < count_trips * 6; i++)
	{
		if (counter == ID and was_edit != true) // if it is our ID
		{
			was_edit = true; // mark that categorie was edited
			printf("Write the number of categorie (1-6), that you want to edit\n");
			scanf("%d", &categorie_to_edit);

			switch (categorie_to_edit)
			{
			case 1:
				printf("Enter another Destination\n");
				scanf("%s", &new_categorie);

				index = 0;
				while (new_categorie[index] != 0)
					index++;
				new_categorie[index] = '\n';

				edit_categorie(i);
				break;
			case 2:
				printf("Enter another Bus\n");
				scanf("%s", &new_categorie);

				index = 0;
				while (new_categorie[index] != 0)
					index++;
				new_categorie[index] = '\n';

				edit_categorie(i);
				break;
			case 3:
				printf("Enter another Date\n");
				scanf("%s", &new_categorie);

				index = 0;
				while (new_categorie[index] != 0)
					index++;
				new_categorie[index] = '\n';

				edit_categorie(i);
				break;
			case 4:
				printf("Enter another Time\n");
				scanf("%s", &new_categorie);

				index = 0;
				while (new_categorie[index] != 0)
					index++;
				new_categorie[index] = '\n';

				edit_categorie(i);
				break;
			case 5:
				printf("Enter another Price\n");
				scanf("%s", &new_categorie);

				index = 0;
				while (new_categorie[index] != 0)
					index++;
				new_categorie[index] = '\n';

				edit_categorie(i);
				break;
			case 6:
				printf("Enter another Availability\n");
				scanf("%s", new_categorie);

				index = 0;
				while (new_categorie[index] != 0)
					index++;
				new_categorie[index] = '\n';

				edit_categorie(i);
				goto skip_last_element;
				break;
			default:
				break;
			}
		}

		if ((i % 6) == 0 and i != 0) // if it is beginning of info about one trip
		{
			num = 0;
			while (temp[num] != 0)
			{
				trips[trips_ind][num] = temp[num];
				num++;
			}
			temp_ind = 0;
			trips_ind++;
			memset(temp, 0, 100); // clear info about one trip
			counter++;
			continue;
		}

		fscanf(fptr, "%s", &edited);
		index = 0;
		while (edited[index] != 0)
			index++;
		edited[index] = '\n';

		num = 0;
		while (edited[num] != 0) // add trip to all trips
		{
			temp[temp_ind] = edited[num];
			temp_ind++;
			num++;
		}

	skip_last_element:
		memset(edited, 0, 100);
	}

	num = 0;
	while (temp[num] != 0) // add trip to all trips
	{
		trips[trips_ind][num] = temp[num];
		num++;
	}
	memset(temp, 0, 100); // clear info about one trip

	fclose(fptr);


	fptr = fopen("tickets.bin", "wb");
	check_file(fptr);
	for (int i = 0; i < trips_ind + 1; i++)
			fprintf(fptr, "%s", &trips[i]);
	fclose(fptr);
}

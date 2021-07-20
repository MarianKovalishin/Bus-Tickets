#include "Select.h"

char selected[10][100]{}, time[100]{};
int selected_ind = 0, select_count = 0;

void select()
{
	memset(msg, 0, 100);
	memset(temp, 0, 100);
	for (int i = 0; i < 10; i++)	memset(selected[i], 0, 100);
	int num = 0;
	temp_ind = 0, selected_ind = 0, select_count = 0;

	fptr = fopen("tickets.bin", "rb");
	check_file(fptr);

	for (int i = 0; i < count_trips; i++) // add all trips
	{
		memset(time, 0, 100);
		for (int j = 0; j < 6; j++)
		{
			memset(msg, 0, 100);
			fscanf(fptr, "%s", &msg);

			num = 0;
			while (msg[num] != 0)
				num++;
			msg[num] = '\n';

			if (j == 3) // write time separately
			{
				num = 0;
				while (msg[num] != 0)
				{
					time[num] = msg[num];
					num++;
				}
			}

			num = 0;
			while (msg[num] != 0) // add each categorie of trip
			{
				temp[temp_ind] = msg[num];
				temp_ind++;
				num++;
			}
		}

		// if Destination is Kyiv and time is between 10:00 - 13:00
		if (temp[0] == 'K' and temp[1] == 'y' and temp[2] == 'i' and temp[3] == 'v' and time[0] == '1' and time[1] >= '0' and time[3] >= '0' and time[4] >= '0' and time[1] <= '2')
		{
			num = 0;
			while (temp[num] != 0) // add the whole trip
			{
				selected[selected_ind][num] = temp[num];
				num++;
			}
			selected_ind++;
			select_count++;
		}

		memset(temp, 0, 100); // clear to add new categories of trip
		temp_ind = 0;
	}

	fclose(fptr);


	fptr = fopen("tickets.bin", "wb");
	check_file(fptr);

	count_trips = select_count; // skip elements that were not selected
	for (int i = 0; i < select_count; i++)
		fprintf(fptr, "%s", &selected[i]);
	fclose(fptr);
}


#include "Def.h"

char cheapest[10][100]{}, date[100]{}, printing[100]{};
int cheapest_size = 0, cheapest_ind = 0, price = 0, min_1 = 1000000, min_2 = 1000000, min_1_ind = 0, min_2_ind = 0;

void def()
{
	fptr = fopen("tickets.bin", "rb");
	check_file(fptr);

	cheapest_size = 0, cheapest_ind = 0;
	for (int i = 0; i < 10; i++)	memset(cheapest[i], 0, 100);

	for (int i = 0; i < count_trips; i++) // add all trips
	{
		temp_ind = 0;
		memset(date, 0, 100);
		for (int j = 0; j < 6; j++)
		{
			memset(msg, 0, 100);
			fscanf(fptr, "%s", &msg);

			int num = 0;
			while (msg[num] != 0)
				num++;
			msg[num] = '\n';


			if (j == 2) // write Date separately
			{
				num = 0;
				while (msg[num] != 0)
				{
					date[num] = msg[num];
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


		// if Date is between 31.05 - 06.06 (week)
		if ((date[0] == '31' and date[1] == '1' and date[3] == '0' and date[4] == '5') or (date[0] == '0' and date[1] >= '1' and date[3] == '0' and date[4] == '6' and date[1] <= '6'))
		{
			int num = 0;
			while (temp[num] != 0) // add the whole trip
			{
				cheapest[cheapest_ind][num] = temp[num];
				num++;
			}
			cheapest_ind++;
			cheapest_size++;
		}

		memset(temp, 0, 100); // clear to add new categories of trip
		temp_ind = 0;
	}


	for (int i = 0; i < cheapest_size; i++)
	{
		temp_ind = 0;
		int num = 0;
		memset(temp, 0, 100); // clear to add new price
		for (int j = 0; j < 6; j++)
		{
			if (j == 4) // convert price into int
			{
				
				while (cheapest[i][num] != '\n') 
				{
					temp[temp_ind] = cheapest[i][num];
					temp_ind++;
					num++;
				}

				price = atoi(temp);
			}
			else
			{
				while (cheapest[i][num] != '\n')
					num++;
			}

			num++;
		}

		if (price < min_1)
		{
			min_1 = price;
			min_1_ind = i;
		}
	}

	for (int i = 0; i < cheapest_size; i++)
	{
		temp_ind = 0;
		int num = 0;
		memset(temp, 0, 100); // clear to add new price
		for (int j = 0; j < 6; j++)
		{
			if (j == 4) // convert price into int
			{

				while (cheapest[i][num] != '\n')
				{
					temp[temp_ind] = cheapest[i][num];
					temp_ind++;
					num++;
				}

				price = atoi(temp);
			}
			else
			{
				while (cheapest[i][num] != '\n')
					num++;
			}

			num++;
		}

		if (price < min_2 and price > min_1)
		{
			min_2 = price;
			min_2_ind = i;
		}
	}

	
	printf("The cheapest trips are\n");
	printf("%20s", "|Destination|");
	printf("%20s", "|Bus|");
	printf("%10s", "|Date|");
	printf("%10s", "|Time|");
	printf("%10s", "|Price|");
	printf("%16s", "|Available|\n");

	int num = 0, print_ind = 0;
	for (int i = 0; i < 6; i++)
	{
		memset(printing, 0, 100);
		print_ind = 0;

		while (cheapest[min_1_ind][num] != '\n')
		{
			printing[print_ind] = cheapest[min_1_ind][num];
			num++;
			print_ind++;
		}
		num++;

		if (i == 0)
			printf("%20s", printing);
		else if (i == 1)
			printf("%20s", printing);
		else if (i == 2)
			printf("%10s", printing);
		else if (i == 3)
			printf("%10s", printing);
		else if (i == 4)
			printf("%10s", printing);
		else if (i == 5)
			printf("%15s", printing);
	}
	

	printf("\n");

	num = 0;
	for (int i = 0; i < 6; i++)
	{
		memset(printing, 0, 100);
		print_ind = 0;

		while (cheapest[min_2_ind][num] != '\n')
		{
			printing[print_ind] = cheapest[min_2_ind][num];
			num++;
			print_ind++;
		}
		num++;

		if (i == 0)
			printf("%20s", printing);
		else if (i == 1)
			printf("%20s", printing);
		else if (i == 2)
			printf("%10s", printing);
		else if (i == 3)
			printf("%10s", printing);
		else if (i == 4)
			printf("%10s", printing);
		else if (i == 5)
			printf("%15s", printing);
	}

	fclose(fptr);
}

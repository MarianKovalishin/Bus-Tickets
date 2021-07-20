#include "Sort.h"

char sorted[10][100]{};
int sorted_size = 0;

void QuickSort(int left, int right)
{
	memset(temp, 0, 100);

	int i = left, j = right, num = 0;
	char pivot = sorted[left + ((right - left + 1) >> 1)][0];

	while (i <= j)
	{
		while (sorted[i][0] < pivot) ++i;
		while (sorted[j][0] > pivot) --j;

		if (i <= j)
		{
			num = 0;
			while (sorted[i][num] != 0)
			{
				temp[num] = sorted[i][num];
				num++;
			}
			num = 0;
			memset(sorted[i], 0, 100);
			while (sorted[j][num] != 0)
			{
				sorted[i][num] = sorted[j][num];
				num++;
			}
			num = 0;
			while (temp[num] != 0)
			{
				sorted[j][num] = temp[num];
				num++;
			}
			++i;
			--j;
		}
	}
	if (j > left)
		QuickSort(left, j);
	if (i < right)
		QuickSort(i, right);
}

void sort()
{
	memset(msg, 0, 100);
	memset(temp, 0, 100);
	for (int i = 0; i < 10; i++)	memset(sorted[i], 0, 100);
	int index = 0, temp_ind = 0;
	sorted_size = 0;

	fptr = fopen("tickets.bin", "rb");
	check_file(fptr);

	for (int i = 0; i < count_trips; i++) // add all trips to vector
	{
		temp_ind = 0;
		for (int j = 0; j < 6; j++)
		{
			memset(msg, 0, 100);
			fscanf(fptr, "%s", &msg);
			index = 0;
			while (msg[index] != 0)
				index++;
			msg[index] = '\n';
			int num = 0;
			while (msg[num] != '\n')
			{
				temp[temp_ind] = msg[num]; // add each categorie of trip
				temp_ind++;
				num++;
			}
			temp[temp_ind] = msg[num];
			temp_ind++;
			num++;
		}

		int num = 0;
		while (temp[num] != 0)
		{
			sorted[i][num] = temp[num]; // add the whole trip
			num++;
		}
		
		sorted_size++;
		memset(temp, 0, 100); // clear to add new categories of trip
		temp_ind = 0;
	}	

	QuickSort(0, sorted_size - 1);
	fclose(fptr);


	fptr = fopen("tickets.bin", "wb");
	check_file(fptr);
	for (int i = 0; i < sorted_size; i++)
			fprintf(fptr, "%s", &sorted[i]);
	fclose(fptr);
}
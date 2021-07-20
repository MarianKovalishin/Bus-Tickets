#include "Delete.h"

vector<vector<string>> data_to_save{};

void to_delete() 
{
	msg = "";
	data_to_save.clear();
	temp.clear();

	fptr.open("tickets.bin", ios::in | ios::binary);

	for (int i = 0; i < count_trips; i++) // add all trips to vector
	{
		for (int j = 0; j < 6; j++)
		{
			msg = "";
			fptr >> msg;
			msg += "\n";
			temp.push_back(msg); // add each categorie of trip
		}

		// if Date >= current date
		// current date is 28.05
		if ((((temp[2][0] == '2' and temp[2][1] >= '8') or (temp[2][0] > '2')) and (temp[2][3] == '0' and temp[2][4] == '5')) or temp[2][4] > '5')
			data_to_save.push_back(temp); // add the whole trip

		temp.clear(); // clear to add new categories of trip
	}

	fptr.close();

	remove("tickets.bin");

	fptr.open("tickets.bin", ios::out | ios::binary);

	count_trips = data_to_save.size(); // skip elements that were not saved
	for (int i = 0; i < data_to_save.size(); i++)
		for (int j = 0; j < 6; j++)
			fptr << data_to_save[i][j];

	fptr.close();
}
#include "Select.h"

vector<vector<string>> selected_to_file{};

void select_to_file()
{
	msg = "";
	selected_to_file.clear();
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

		// if Destination is Vilnius and Date is in the next 10 days 
		// current date is 28.05
		if (temp[0] == "Vilnius\n" and (((temp[2][0] == '2' and temp[2][1] >= '8') or (temp[2][0] == '3' and temp[2][1] >= '0') and temp[2][3] == '0' and temp[2][4] == '5') or (temp[2][0] >= '0' and temp[2][1] >= '1' and temp[2][3] == '0' and temp[2][4] == '6' and temp[2][1] <= '6')))
			selected_to_file.push_back(temp); // add the whole trip

		temp.clear(); // clear to add new categories of trip
	}

	fptr.close();


	fptr.open("tickets.txt", ios::out);

	for (int i = 0; i < selected_to_file.size(); i++)
		for (int j = 0; j < 6; j++)
			fptr << selected_to_file[i][j];

	fptr.close();
}

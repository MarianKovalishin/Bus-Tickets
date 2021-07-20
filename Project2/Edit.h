#pragma once
#include "Header.h"

void edit_categorie(int& i);
void edit();

extern char trips[10][100];
extern char edited[100], new_categorie[100];
extern int ID, categorie_to_edit, counter, num, index, trips_ind;
extern bool was_edit;
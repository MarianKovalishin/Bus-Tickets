#pragma once
#pragma warning(disable : 4996)
#include <stdio.h>
#include <iostream>
#define clear_screen for (int i = 0; i < 30; i++)	printf("\n")
using namespace std;

extern FILE* fptr;
extern int count_trips, temp_ind;
extern char msg[100];
extern char temp[100];

void check_file(FILE* fptr);
#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <bits/stdc++.h>
#include <set>
#include <iostream>
#include <math.h>
#include <time.h>
#include <unistd.h>

const char file[64] = {"../dataset.csv"};
const char config[64] = {"../config.txt"};

using namespace std;

struct dataMakanan
{
	int harga;
	int rasa;
	int porsi;
	double distance;
	int target;
};

struct Classing
{
	int counter;
	double distance;
	int index;
};

void readCSV(const char link[], dataMakanan dataSet[]);
void loadParam(const char link[]);

void proceed(dataMakanan dataSet[], string line, int index);
int genRandom(int batasAtas, int batasBawah);
int classify(dataMakanan setData[], dataMakanan testData, int myVarian[]);
int validate(int myTarget, int myVarian[]);

bool getMinDistance(dataMakanan A, dataMakanan B);
bool getMaxCounter(Classing A, Classing B);

extern int K;
extern int VARIAN;
extern int MAX_DATA;

#endif
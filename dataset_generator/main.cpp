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

int MAX_DATASET;

struct dataMakanan
{
	int harga;
	int rasa;
	int porsi;
	int target;
};

int getMaxData(const char link[])
{
	int MAX_DATA;
    ifstream buka(config);
    if(buka.is_open())
    {
        while(!buka.eof())
        {
            static int index = 0;
            string temp;
            buka >> temp;

            int j = 0;
            int comma = 0;
            int buf = 0;

            char buffer[50] = {};
            for(int i = 0; i < temp.length(); i++)
            {
                buffer[j] = temp[i];
                if(temp[i]==',')
                {
                    j = 0;
                    buf = atoi(buffer);
                    memset(buffer, 0, sizeof(buffer));
                    switch(comma)
                    {
                        case 2 : MAX_DATA = buf; break;
                    }
                    comma++;
                    continue;
                }
                j++;
            }
        }
    }
    else
    {
        cout << "cant load config, please re-check the link" << endl;
        exit(1);
    }
    return MAX_DATA;
}

void writeCSV(const char link[], dataMakanan input[], int MAX_DATASET)
{
	ofstream output (file);
	if(output.is_open())
	{
		for(int i = 0; i < MAX_DATASET; i++)
		{
			output << input[i].harga << "," << input[i].rasa << ",";
			output << input[i].porsi << "," << input[i].target<< "," << endl;
		}
	}
	else
		cout << "cant write to CSV, please re-check the link" << endl;
	output.close();
}

int genRandom(int batasAtas, int batasBawah)
{
	int temp = rand() * time(0) % (batasAtas - batasBawah + 1);
	return temp + batasBawah;
}

int main()
{
	int MAX_DATASET = getMaxData(config);
	dataMakanan dataSet[MAX_DATASET];

	for(int i = 0; i < MAX_DATASET; i++)
	{
		dataSet[i].harga = genRandom(10, 0);
		dataSet[i].rasa  = genRandom(10, 0);
		dataSet[i].porsi = genRandom(10, 0);
		dataSet[i].target= genRandom(4, 0);
		usleep(500);
	}

	writeCSV(file, dataSet, MAX_DATASET);
}
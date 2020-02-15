#include "main.h"

void proceed(dataMakanan dataSet[], string line, int index)
{
    int j = 0;
    int comma = 0;
    int buf = 0;

    char buffer[50] = {};
    for(int i = 0; i < line.length(); i++)
    {
        buffer[j] = line[i];
        if(line[i]==',')
        {
            j = 0;
            buf = atoi(buffer);
            memset(buffer, 0, sizeof(buffer));
            switch(comma)
            {
                case 0 : dataSet[index].harga = buf; break;
                case 1 : dataSet[index].rasa  = buf; break;
                case 2 : dataSet[index].porsi = buf; break;
                case 3 : dataSet[index].target= buf; break;
            }
            comma++;
            continue;
        }
        j++;
    }
}

int genRandom(int batasAtas, int batasBawah)
{
	int temp = rand() * time(0) % (batasAtas - batasBawah + 1);
	return temp + batasBawah;
}

void readCSV(const char link[], dataMakanan dataSet[])
{
    ifstream buka(file);
    if(buka.is_open())
    {
        while(!buka.eof())
        {
            static int index = 0;
            string temp;
            buka >> temp;
            proceed(dataSet, temp, index++);
        }
    }
    else
    {
        cout << "cant load CSV, please re-check the link" << endl;
        exit(1);
    }
}

void loadParam(const char link[])
{
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
                        case 0 : K        = buf; break;
                        case 1 : VARIAN   = buf; break;
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
}

bool getMinDistance(dataMakanan A, dataMakanan B)
{
    return A.distance < B.distance;
}

bool getMaxCounter(Classing A, Classing B)
{
    return A.counter > B.counter;
}
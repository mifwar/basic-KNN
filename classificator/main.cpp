#include "main.h"

int K;
int VARIAN;
int MAX_DATA;

int main()
{
	loadParam(config);

	dataMakanan dataSet[MAX_DATA];

	readCSV(file, dataSet);
	int myVarian[VARIAN];

	cout << K << endl;
	cout << MAX_DATA << endl;
	cout <<VARIAN << endl;

	for(int i = 0; i < VARIAN; i++)
		myVarian[i] = i;

	int loop = 0;
	while(loop++ < 300)
	{
		cout << "================== TRIAL " << loop << " ================== " << endl << endl;
		dataMakanan dataTest;
		dataTest.harga	= genRandom(10, 0);
		dataTest.rasa	= genRandom(10, 0);
		dataTest.porsi	= genRandom(10, 0);

		int output = classify(dataSet, dataTest, myVarian);

		cout << "index anda : " << output << endl;

		switch(output)
		{
			case 0 : cout << "makanan anda : tidak sehat" << endl;break;
			case 1 : cout << "makanan anda : kurang sehat" << endl;break;
			case 2 : cout << "makanan anda : cukup sehat" << endl;break;
			case 3 : cout << "makanan anda : sangat sehat" << endl;break;
			case 4 : cout << "makanan anda : sehat banget" << endl;break;
		}
		usleep(500);
	}
}
#include "main.h"

int validate(int myTarget, int myVarian[])
{
	for(int i = 0; i < VARIAN; i++)
		if(myTarget == myVarian[i])
			return i;
}

int classify(dataMakanan setData[], dataMakanan testData, int myVarian[])
{
	for(int i = 0; i < MAX_DATA; i++)
	{
		int del_pow_harga = pow(setData[i].harga - testData.harga,2);
		int del_pow_rasa  = pow(setData[i].rasa  - testData.rasa ,2);
		int del_pow_porsi = pow(setData[i].porsi - testData.porsi,2);

		setData[i].distance = sqrt(del_pow_harga + del_pow_rasa + del_pow_porsi);
	}

	sort(setData, setData + MAX_DATA, getMinDistance);

	Classing kelas[VARIAN];
	memset(&kelas, 0, sizeof(kelas));

	cout << "testData.harga 	:" << testData.harga << endl;
	cout << "testData.rasa 	:" << testData.rasa << endl;
	cout << "testData.porsi 	:" << testData.porsi << endl;
	cout << endl;

	for(int i = 0; i < K; i++)
	{
		int indexBenar = validate(setData[i].target, myVarian);
		kelas[indexBenar].counter++;
		kelas[indexBenar].distance += setData[i].distance;
		kelas[indexBenar].index = indexBenar;

		cout << "tingkat kesehatan : " << indexBenar << endl;
		cout << "setData[" << i << "].harga 	:" << setData[i].harga << endl;
		cout << "setData[" << i << "].rasa 	:" << setData[i].rasa << endl;
		cout << "setData[" << i << "].porsi 	:" << setData[i].porsi << endl;
		cout << "setData[" << i << "].distance 	:" << setData[i].distance << endl;
		cout << "setData[" << i << "].target 	:" << setData[i].target << endl;
		// cout << "c : " << kelas[indexBenar].counter << endl;
		// cout << "d : " << kelas[indexBenar].distance << endl;
		// cout << "i : " << kelas[indexBenar].index << endl;

		cout << endl;
	}
	sort(kelas, kelas + VARIAN, getMaxCounter);

	int index = kelas[0].index;

	cout << "============= kelas[0] =============" << endl;
	cout << "counter 	: " << kelas[0].counter  << endl;
	cout << "index 		: " << kelas[0].index    << endl;
	cout << "distance 	: " << kelas[0].distance << endl;
	cout << endl;

	cout << "============= kelas[1] =============" << endl;
	cout << "counter 	: " << kelas[1].counter  << endl;
	cout << "index 		: " << kelas[1].index    << endl;
	cout << "distance 	: " << kelas[1].distance << endl;
	cout << endl;

	if(kelas[0].counter == kelas[1].counter)
	{
		if(kelas[0].distance < kelas[1].distance)
			index = kelas[0].index;
		else
			index = kelas[1].index;
	}

	return index;
}

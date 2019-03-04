
/*
	Hector Mauricio Gonzalez Coello
	A01328258
	ITC
*/
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <cmath>
#include <string>
#include <map>

using namespace std;

int main()
{
	int precio = 0;
	int random = 0;
	int rounds = 9999999;
	srand (time(NULL));
	for(int i = 0; i <rounds; i++)
	{
		random = rand() % 100;
			//North
			if (random >= 20)
				precio += 99;
			//South
			else
				precio += 100;
	}
	float res = (float)precio/(float)rounds;
	cout<<"Precio promedio: "<<res<<endl;
	return 0;

}
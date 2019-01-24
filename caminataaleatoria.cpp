
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
	int posX = 0;
	int posY = 0;
	int isAround = 0;
	int random = 0;
	int rounds = 100000;
	srand (time(NULL));
	int commonCoordinateNum = 0;
	string commonCoordinateSt;
	 map<std::string, int> coordinates;
	for(int i = 0; i <rounds; i++)
	{
		posX = 0;
		posY = 0;
		for(int j = 0; j<10; j++)
		{
			random = rand() % 100;
			//North
			if (random>=0 && random <24)
				posX++;
			//South
			else if(random>=25 && random < 50)
				posX--;
			//East
			else if(random>=50 && random < 75)
				posY++;
			else if(random>=75 && random <100)
				posY--;
		}
		if(abs(posY)+abs(posX) <=2)
			isAround++;
		string coordinate = to_string(posX) + "," + to_string(posY); 
		std::pair<std::map<string,int>::iterator,bool> ret;
		ret = coordinates.insert ( std::pair<string,int>(coordinate,1));
		if (ret.second==false) 
		{
			coordinates[coordinate]++;
		}
	}
	map<string, int>::iterator it;
	for ( it = coordinates.begin(); it != coordinates.end(); it++ )
	{
		//cout<<it->first<<" "<<it->second<<endl;
		if(it->second > commonCoordinateNum)
		{
			commonCoordinateNum = it->second;
			commonCoordinateSt = it->first;
		}
	}

	double rtn = (double)isAround/(double)rounds;
	cout<<"Probability: "<< rtn <<endl;
	cout<<"Most common coordinate: "<<commonCoordinateSt<<endl;
	return 0;

}
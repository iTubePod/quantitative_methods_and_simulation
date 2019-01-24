
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
#include <vector>
#include <algorithm>

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
	map<int, int> seventy;
	map<int, int> twentyfive;
	pair<std::map<int,int>::iterator,bool> ret;
	vector<pair<int,int>>vec;
	vector<pair<int,int>>vec1;
	for(int i = 0; i <rounds; i++)
	{
		random = rand() % 70+1;
		ret = seventy.insert ( std::pair<int,int>(random,1));
		if (ret.second==false) 
		{
			seventy[random]++;
		}
		random = rand() % 25+1;
		ret = twentyfive.insert ( std::pair<int,int>(random,1));
		if (ret.second==false) 
		{
			twentyfive[random]++;
		}
	}
	for(auto x=seventy.begin();x!=seventy.end();x++)vec.push_back(*x);
	sort(vec.begin(),vec.end(),[](pair<int,int>elem1,pair<int,int>elem2){return elem1.second > elem2.second;});
	for(auto x=twentyfive.begin();x!=twentyfive.end();x++)vec1.push_back(*x);
	sort(vec1.begin(),vec1.end(),[](pair<int,int>elem1,pair<int,int>elem2){return elem1.second > elem2.second;});
	cout<<"____1 to 70____"<<endl;
	for(int i = 0; i<5; i++)
	{
		cout<<"NUM: "<<vec[i].first<<":"<<vec[i].second<<endl;
	}
	cout<<"____1 to 25____"<<endl;
	cout<<"NUM: "<<vec1[0].first<<":"<<vec1[0].second<<endl;
	return 0;

}
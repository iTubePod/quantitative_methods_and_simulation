
/*
	Hector Mauricio Gonzalez Coello
	A01328258
	ITC
	
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
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
	long int rounds1 = 999999999;
	srand (time(NULL));
	map<int, int> seventy;
	map<int, int> twentyfive;
	pair<std::map<int,int>::iterator,bool> ret;
	vector<pair<int,int>>vec;
	vector<pair<int,int>>vec1;
	cout<<"________MUST COMMON PAIR________"<<endl;
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
	map<int, int> seventyGlobal;
	map<int, int> twentyfiveGlobal;
	map<int, int> seventy1;
	map<int, int> twentyfive1;
	map<int,int>::iterator it;
	pair<std::map<int,int>::iterator,bool> ret1;
	bool firstmatch = false;
	bool secondmatch = false;
	for(int i = 1; i <= rounds1; i++)
	{
		twentyfive1 = twentyfiveGlobal;
		seventy1 = seventyGlobal;
		if(i==1)
		{
			cout<<"____CHECKING WITH NUMS:____"<<endl;
			for(int j = 0; j < 5; j++)
			{
				random = rand() % 70+1;
				ret = seventy1.insert ( std::pair<int,int>(random,1));
				if (ret.second==false) 
				{
					seventy1[random]++;
				}
				if(i==4)
				{
					cout<<random;
				}
				else
				{
					cout<<random<<", ";
				}
			}
			cout<<random<<" & ";
			random = rand() % 25+1;
			ret1 = twentyfive1.insert ( std::pair<int,int>(random,1));
			cout<<random<<endl;
			seventyGlobal = seventy1;
			twentyfiveGlobal = twentyfive1;			
		}
		for(int j = 0; j < 5; j++)
		{
			random = rand() % 70+1;
			it = seventy1.find(random);
			if(it!=seventy1.end())
			{
				if(seventy1[random]>1)
				{
					seventy1[random]--;
				}
				else
				{
					it = seventy1.find(random);
					seventy1.erase(it);
				}
			}
		}
		random = rand() % 25+1;
		it = twentyfive1.find(random);
		if(it!=twentyfive1.end())
		{
			if(twentyfive1[random]>1)
			{
				twentyfive1[random]--;
			}
			else
			{
				it = twentyfive1.find(random);
				twentyfive1.erase(it);
			}
		}
		if(seventy1.empty() && twentyfive1.empty())
		{
			cout<<"--FOUND MATCH AFTER "<<i<<" ITERATIONS!"<<endl;
			i = rounds1+1;
		}
	}
	return 0;

}
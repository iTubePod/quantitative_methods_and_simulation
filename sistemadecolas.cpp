
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
#include <utility> 
#include <vector> 
 

using namespace std;

class Truck
{
    public:
        pair<int,int> arrivalTime;
        int serviceTime;
        pair<int,int> startOfServiceTime;
        pair<int,int> endOfServiceTime;
        pair<int,int> waitingTime;
        pair<int, int> nothingTime;
        int queuesize;
};

int getTrucksToArrive(int probability)
{
    switch(probability)
    {
        case 0 ... 50:
            return 0;
        case 51 ... 75:
            return 1;
        case 76 ... 90:
            return 2;
        case 91 ... 100:
            return 3;
        default:
            return -1;
    }
}

int getMinsBetweenArrivals(int probability)
{
    switch(probability)
    {
        case 0 ... 2:
            return 20;
        case 3 ... 10:
            return 25;
        case 11 ... 22:
            return 30;
        case 23 ... 47:
            return 35;
        case 48 ... 67:
            return 40;
        case 68 ... 82:
            return 45;
        case 83 ... 92:
            return 50;
        case 93 ... 97:
            return 55;
        case 98 ... 100:
            return 60;
        default:
            return -1;
    }
}

int getServiceTime(int probability, int numOfEmployees)
{
    if(numOfEmployees==3)
    {
        switch(probability)
        {
            case 0 ... 5:
                return 20;
            case 6 ... 15:
                return 25;
            case 16 ... 35:
                return 30;
            case 36 ... 60:
                return 35;
            case 61 ... 72:
                return 40;
            case 73 ... 82:
                return 45;
            case 83 ... 90:
                return 50;
            case 91 ... 96:
                return 55;
            case 97 ... 100:
                return 60;
            default:
                return -1;
        }
    }
    else if(numOfEmployees==4)
    {
        switch(probability)
        {
            case 0 ... 5:
                return 15;
            case 6 ... 20:
                return 20;
            case 21 ... 40:
                return 25;
            case 41 ... 60:
                return 30;
            case 61 ... 75:
                return 35;
            case 76 ... 87:
                return 40;
            case 88 ... 95:
                return 45;
            case 96 ... 99:
                return 50;
            case 100:
                return 55;
            default:
                return -1;
        }
    }
    else if(numOfEmployees==5)
    {
        switch(probability)
        {
            case 0 ... 10:
                return 10;
            case 11 ... 28:
                return 15;
            case 29 ... 50:
                return 20;
            case 51 ... 68:
                return 25;
            case 69 ... 78:
                return 30;
            case 79 ... 86:
                return 35;
            case 87 ... 92:
                return 40;
            case 93 ... 97:
                return 45;
            case 98 ... 100:
                return 50;
            default:
                return -1;
        }
    }
    else if(numOfEmployees == 6)
    {
        switch(probability)
        {
            case 0 ... 12:
                return 5;
            case 13 ... 27:
                return 10;
            case 28 ... 53:
                return 15;
            case 54 ... 68:
                return 20;
            case 69 ... 80:
                return 25;
            case 81 ... 88:
                return 30;
            case 89 ... 94:
                return 35;
            case 95 ... 98:
                return 40;
            case 99 ... 100:
                return 45;
            default:
                return -1;
        }
    }
    else
    {
        return -1;
    }
}
pair<int,int> getNewTime(pair<int, int> time, int minsAdd)
{
    if(minsAdd<=0)
    {
        return time;
    }
    int hour = time.first;
    int minutes = time.second;
    pair<int,int> newTime;
    if(minsAdd>=60)
    {

        newTime.first = hour+(minsAdd/60);
        newTime.second = minutes+(minsAdd%60);
    }
    else
    {
        newTime.first = hour;
        newTime.second = minutes + minsAdd;
    }
    if(newTime.second>=60)
    {
        newTime.first++;
        newTime.second-=60;
    }
    if(newTime.first>23)
    {
        newTime.first=0+(newTime.first-24);
    }
    //cout<<"returning new time: "<<newTime.first<<":"<<newTime.second<<endl;
    return newTime;
}
pair<int, int> getTimeDifference(pair<int,int> time1, pair<int,int> time2)
{
    pair<int,int> newTime;
    int hour = time2.first - time1.first;
    int mins = time2.second - time1.second;
    if(hour<0)
    {
        hour=23-(hour+1);
    }
    if(mins<0)
    {
        hour--;
        mins*=-1;
    }
    newTime.first = hour;
    newTime.second = mins;
    return newTime;
}

bool checkifTruckIsWaiting (pair<int,int> arrivalTime, pair<int,int> startTime)
{
    if(startTime.first > arrivalTime.first)
    {
        return true;
    }
    else if (startTime.first == arrivalTime.first)
    {
        if(startTime.second > arrivalTime.second)
        {
            return true;
        }
    }
    return false;
}
bool checkIfNothingTime(pair<int,int> time, pair<int,int> arrivalTime)
{
    if(arrivalTime.first > time.first)
    {
        return true;
    }
    else if (arrivalTime.first == time.first)
    {
        if(arrivalTime.second > time.second)
        {
            return true;
        }
    }
    return false;
}

string printTime(pair<int, int> time)
{
    if(time.second<10)
    {
        return ""+to_string(time.first)+":0"+to_string(time.second);
    }
    else
    {
        return ""+to_string(time.first)+":"+to_string(time.second);
    }    
}
bool checkTimeLimit(pair <int, int> time)
{
    if(time.first==7&&time.second>=30)
    {
        return false;
    }
    return true;
}
bool checkLunchTime(pair <int, int> time)
{
    if(time.first>=3)
    {
        return true;
    }
    return false;
}
void printTruckQueue(vector<Truck> trucks)
{
    for(int i = 0; i<trucks.size(); i++)
    {
        cout<<"Truck "<<i+1<<", Arrival: "<<printTime(trucks.at(i).arrivalTime)<<", Start of Service Time: "<<printTime(trucks.at(i).startOfServiceTime)<<", Service Time "<<trucks.at(i).serviceTime<<", End of service "<<printTime(trucks.at(i).endOfServiceTime)<<", Waiting Time: "<<printTime(trucks.at(i).waitingTime)<<", Nothing Time: "<<printTime(trucks.at(i).nothingTime)<<endl;
    }
}
float getPayrollCost(int numOfEmployees, Truck lastTruck)
{
    float perHourFee = 25;
    float extraHourFee = 37.5;
    float cost = 0;
    pair<int, int> lastHour, extraTime;
    lastHour.first = 7;
    lastHour.second = 30;
    cost = perHourFee * 8.5;
    if(checkIfNothingTime(lastHour,lastTruck.endOfServiceTime))
    {
        extraTime = getTimeDifference(lastHour, lastTruck.endOfServiceTime);
        if(extraTime.first!=0)
        {
            cost += extraHourFee * extraTime.first;
        }
        cost += extraHourFee * (60/extraTime.second);
    }
    cost*=numOfEmployees;
    return cost;
}
float getTotalCost(int numOfEmployees, pair<int, int>waitingTime, pair<int, int>wastedTime, Truck lastTruck)
{
    float totalCost = 500;
    float waitingTimeCost = 100;
    totalCost += getPayrollCost(numOfEmployees, lastTruck);
    if(waitingTime.first!=0)
    {
        totalCost += waitingTimeCost * waitingTime.first;
    }
    if(waitingTime.second!=0)
    {
        totalCost += waitingTimeCost * (60/waitingTime.second);
    }
    return totalCost;
}
float getWastedPayrollCost(int numOfEmployees, pair<int, int>wastedTime)
{
    return 0;
}
float runSimulation(int numofEmployees, int round)
{
    bool hadLunch = false;
    bool runExperiment = true;
    int rand0, rand1, rand2, numOfTrucks = 0;
	srand (time(NULL));
    pair<int, int> time;
    time.first=23;
    time.second=0;
    vector<Truck> truckQueue;
    rand0 = 63;
    int trucks = getTrucksToArrive(rand0);
    for(int i = 0; i<trucks; i++)
    {
        rand2  = rand() % 100+1; 
        Truck tr = Truck();
        int serviceTime = getServiceTime(rand2,numofEmployees);
        tr.arrivalTime = time;
        tr.serviceTime = serviceTime;
        truckQueue.push_back(tr);
    }
    while(checkTimeLimit(time))
    {
        //cout<<printTime(time)<<endl;
        rand1  = rand() % 100+1;
        rand2  = rand() % 100+1; 
        Truck tr = Truck();
        int minsBetweenArrival = getMinsBetweenArrivals(rand1);
        int serviceTime = getServiceTime(rand2,numofEmployees);
        tr.arrivalTime = getNewTime(time, minsBetweenArrival);
        time = tr.arrivalTime;
        tr.queuesize = 0;        
        tr.serviceTime = serviceTime;
        truckQueue.push_back(tr);
    }
    time.first=23;
    time.second=0;
    pair<int, int> nothingTime, waitingTime;
    for(int i = 0; i<truckQueue.size(); i++)
    {
        if(checkIfNothingTime(time, truckQueue.at(i).arrivalTime))
        {
            truckQueue.at(i).nothingTime = getTimeDifference(time, truckQueue.at(i).arrivalTime);
            pair<int, int> diff = getTimeDifference(time, truckQueue.at(i).arrivalTime);
            int mins = diff.first*60;
            mins += diff.second;
            nothingTime = getNewTime(nothingTime, mins);
            time = truckQueue.at(i).arrivalTime;
            truckQueue.at(i).startOfServiceTime = time;
            time = getNewTime(time, truckQueue.at(i).serviceTime);
            truckQueue.at(i).endOfServiceTime = time;            
        }
        else
        {           
        
            if(checkifTruckIsWaiting(truckQueue.at(i).arrivalTime, time))
            {
                truckQueue.at(i).waitingTime = getTimeDifference(truckQueue.at(i).arrivalTime, time);
                pair<int, int> diff = getTimeDifference(truckQueue.at(i).arrivalTime, time);
                int mins = diff.first*60;
                mins += diff.second;
                waitingTime = getNewTime(nothingTime, mins);
            }
            truckQueue.at(i).startOfServiceTime = time;
            time = getNewTime(time, truckQueue.at(i).serviceTime);
            truckQueue.at(i).endOfServiceTime = time; 
        }
    }
    float cost = getTotalCost(numofEmployees, waitingTime, nothingTime, truckQueue.at(truckQueue.size()-1));
    if(round==0)
    {
        printTruckQueue(truckQueue);
        cout<<"Experiment with: "<<numofEmployees<<" employees ended at: "<<printTime(time)<<", with "<<truckQueue.size()<<" trucks and nothing time from personel of "<<printTime(nothingTime)<<" and a total cost of operation of $"<<cost<<endl;
    }    
    return cost;
}

int main()
{
    float cost3, cost4, cost5, cost6 = 0;
    int rounds = 10000;
    for(int i = 0; i<rounds; i++)
    {
        cost3 += runSimulation(3,i);
        cost4 += runSimulation(4,i);
        cost5 += runSimulation(5,i);
        cost6 += runSimulation(6,i);
    }
    cout<<"Average cost with 3 employees $"<<cost3/(float)10000<<endl;
    cout<<"Average cost with 4 employees $"<<cost4/(float)10000<<endl;
    cout<<"Average cost with 5 employees $"<<cost5/(float)10000<<endl;
    cout<<"Average cost with 6 employees $"<<cost6/(float)10000<<endl;

    return 0;
}
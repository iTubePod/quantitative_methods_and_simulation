
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

class Car
{
    public:
        int carType;
        int replacementPartCost;
        int carReplacementPart;
};

int getCarsToArrive(int probability)
{
    switch(probability)
    {
        case 0 ... 5:
            return 3;
        case 6 ... 20:
            return 4;
        case 21 ... 50:
            return 5;
        case 51 ... 75:
            return 6;
        case 76 ... 90:
            return 7;
        case 91 ... 100:
            return 8;
        default:
            return -1;
    }
}

int getReplacementPartsCost(int probability, Car* car)
{
    switch(car->carType)
    {
        //small
        case 0:
            switch(probability)
            {
                case 0 ... 45:
                    car->carReplacementPart = 0;
                    return 350;
                case 46 ... 60:
                    car->carReplacementPart = 1;
                    return 1575;
                case 61 ... 80:
                    car->carReplacementPart = 2;
                    return 1925;
                case 81 ... 90:
                    car->carReplacementPart = 3;
                    return 2540;
                case 91 ... 100:
                    car->carReplacementPart = 4;
                    return 700;
                default:
                    return -1;
            }
        //medium
        case 1:
            switch(probability)
            {
                case 0 ... 25:
                    car->carReplacementPart = 0;
                    return 550;
                case 26 ... 50:
                    car->carReplacementPart = 1;
                    return 1975;
                case 51 ... 65:
                    car->carReplacementPart = 2;
                    return 2545;
                case 66 ... 85:
                    car->carReplacementPart = 3;
                    return 2925;
                case 86 ... 100:
                    car->carReplacementPart = 4;
                    return 700;
                default:
                    return -1;
            }
        //big
        case 2:
            switch(probability)
            {
                case 0 ... 10:
                    car->carReplacementPart = 0;
                    return 750;
                case 11 ... 25:
                    car->carReplacementPart = 1;
                    return 2275;
                case 26 ... 55:
                    car->carReplacementPart = 2;
                    return 2845;
                case 56 ... 95:
                    car->carReplacementPart = 3;
                    return 3415;
                case 96 ... 100:
                    car->carReplacementPart = 4;
                    return 700;
                default:
                    return -1;
            }
        default:
            return -1;
    }
}

int getCarType(int probability)
{
    switch(probability)
    {
        case 0 ... 45:
            return 0;
        case 46 ... 80:
            return 1;
        case 81 ... 100:
            return 2;
        default:
            return -1;
    }
}

void printCarInWorkshopList(vector<Car> cars)
{
    for(int i = 0; i < cars.size(); i++)
    {
        cout<<"Car Type: "<<cars.at(i).carType<<", CarServiceCost: "<<cars.at(i).replacementPartCost<<", CarServiceType: "<<cars.at(i).carReplacementPart<<endl;
    }
}

int main()
{
    float smallVehiculesP = 0;
    float mediumVehiclesP = 0;
    float bigVehiclesP = 0;
    float totalCost = 0;
    float ayfTotal = 0;
    float balTotal = 0;
    float afybTotal = 0;
    float verTotal = 0;
    int rounds = 10000000;
    srand (time(NULL));
    for(int i = 0; i < rounds; i++)
    {
        int randNumOfCars = 0;
        int randCarType = 0;
        int randCarService = 0;
        int totalCostOfCar = 0;
        int ayf = 0;
        int bal = 0;
        int afyb = 0;
        int ver = 0;
        randNumOfCars = rand() % 100+1;
        int numOfCars = getCarsToArrive(randNumOfCars);
        vector<Car> carsInWorkshop;
        for(int i = 0; i<numOfCars; i++)
        {
            Car car = Car();
            randCarType = rand() % 100+1;
            car.carType = getCarType(randCarType);
            randCarService = rand() % 100+1;
            carsInWorkshop.push_back(car);
            carsInWorkshop.at(i).replacementPartCost = getReplacementPartsCost(randCarService, &carsInWorkshop.back());

        }
        for(int i = 0; i < carsInWorkshop.size(); i++)
        {
            switch(carsInWorkshop.at(i).carReplacementPart)
            {
                case 0:
                    ayf++;
                    break;
                case 1:
                    bal++;
                    break;
                case 2:
                    afyb++;
                    break;
                case 3:
                    ver++;
                    break;
                default:
                    break;
            }
            totalCostOfCar += carsInWorkshop.at(i).replacementPartCost;
        }
        totalCost += (float)totalCostOfCar/(float)carsInWorkshop.size();
        ayfTotal += (float)ayf/(float)carsInWorkshop.size();
        balTotal += (float)bal/(float)carsInWorkshop.size();
        afybTotal += (float)afyb/(float)carsInWorkshop.size();
        verTotal += (float)ver/(float)carsInWorkshop.size();        
        //printCarInWorkshopList(carsInWorkshop);
    }
    cout<<"Porcentage of Repairs by Type: Aceite y filtro:"<<(float)ayfTotal/(float)rounds<<", Balatas: "<<(float)balTotal/(float)rounds<<", Aceite, filtro y balatas: "<<(float)afybTotal/(float)rounds<<", Verificacion: "<<(float)verTotal/(float)rounds<<endl;
    cout<<"Porcentage of money needed per day: $"<<(float)totalCost/(float)rounds<<endl;
    
    
}
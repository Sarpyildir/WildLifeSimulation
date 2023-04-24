#include "Food.h"
#include <iostream>
using namespace std;
/**
* Author : Sarp Yıldırım
* id: 22003330
* Section : 1
* Homework : 3
* Description : This is the implementations of the food class which are defined in the header file.
*/

Food::Food()
{
    quality = -1;
    id = -1;
    spawnTime = -1;
    x = -1.0;
    y = -1.0;
}

Food::Food(int ID, double xCoordinate, double yCoordinate, int qualityVal, int timingOfSpawn)
{
    quality  = qualityVal;
    id = ID;
    x = xCoordinate;
    y = yCoordinate;
    spawnTime = timingOfSpawn;
    
}
Food::~Food(){

}

int Food::getQuality()
{
    return quality;
}

int Food::getId()
{
    return id;
}
int Food::getSpawnTime(){
    return spawnTime;
}
double Food::getX(){
    return x;
}
double Food::getY(){
    return y;
}

void Food::setQuality(int q){
    quality = q;
}
void Food::setId(int i){
    id = i;
}
void Food::setX(double xCoordinate){
    x = xCoordinate;
}
void Food::setY(double yCoordinate){
    y = yCoordinate;
}
void Food::setSpawnTime(int t){
    spawnTime = t;
}

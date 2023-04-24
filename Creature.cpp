#include "Creature.h"
#include <iostream>
#include "cmath"
using namespace std;
/**
* Author : Sarp Yıldırım
* id: 22003330
* Section : 1
* Homework : 3
* Description : This is the implementations of the functions defined in the header file of the creature class.
*/
Creature::Creature()
{
    id = -1;
    x = -1.0;
    y = -1.0;
    hp = -1;
    speed = -1;
}
Creature::Creature(int ID, double xCoordinate, double yCoordinate, int health)
{
    id = ID;
    x = xCoordinate;
    y = yCoordinate;
    hp = health;
    setSpeed();
}
Creature::~Creature()
{
}
int Creature::getId()const{
    return id;
}
double Creature::getX()const{
    return x;
}
double Creature::getY()const{
    return y;
}
int Creature::getHealth()const{
    return hp;
}
double Creature::getSpeed()const{
    return speed;
}

void Creature::setId(int i){
    id = i;
}
void Creature::setX(double xCoordinate){
    x = xCoordinate;
}
void Creature::setY(double yCoordinate){
    y = yCoordinate;
}
void Creature::setHealth(int health){
    hp = health;
}
double Creature::euclideanDistance(const Creature& other){
        double diffX = abs( x - other.getX());
        double diffY = abs(y - other.getY());
        return sqrt(diffX*diffX + diffY*diffY);
}
void Creature::decreaseHealth(){
    hp--;
    setSpeed();
}
void Creature::eat(int foodQuality){
    hp = hp + foodQuality;
    setSpeed();
}
void Creature::setSpeed(){
    if(0<hp && hp<=10){
        speed = 1.0;
    }
    else if(hp<=0){
        speed = 0.0;
    }
    else{
        speed = 10.0 / hp;
    }
}
bool Creature::isAlive(){
    return hp>0;
}

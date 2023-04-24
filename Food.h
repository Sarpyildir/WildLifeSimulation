#ifndef __FOOD_H
#define __FOOD_H
/**
* Author : Sarp Yıldırım
* id: 22003330
* Section : 1
* Homework : 3
* Description : This is the header file of the food class.
*/
class Food
{
private:
    int quality; // quality of the food
    int id; // unique id of the food
    int spawnTime; // spawn time of the food in terms of iteration in loop
    double x; // x coordinate of the food
    double y; // y coordinate of the food
    
public:
    //default constructor of the food
    Food();
    // constructor of the food with the given arguments
    Food(int ID, double xCoordinate, double yCoordinate, int qualityVal, int timingOfSpawn);
    //destructor of the food object
    ~Food();
    // returns the quality of the food object
    int getQuality();
    //returns the id of the food object
    int getId();
    // returns the spawn time of the food object
    int getSpawnTime();
    // returns the x coordinate of the food object
    double getX();
    // returns the y coordinate of the food object
    double getY();
    // sets the quality of the food object to given integer
    void setQuality(int q);
    // sets the id of the food object to the given integer
    void setId(int i);
    // sets the x coordinate of the food object to the given double
    void setX(double xCoordinate);
    // sets the y coordinate of the food object to the given double
    void setY(double yCoordinate);
    // sets the spawn time of the food object to the given integer
    void setSpawnTime(int t);
};

#endif
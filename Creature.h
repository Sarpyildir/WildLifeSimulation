#ifndef __CREATURE_H
#define __CREATURE_H
/**
* Author : Sarp Yıldırım
* id: 22003330
* Section : 1
* Homework : 3
* Description : This is the header file of the creature class.
*/
class Creature
{
private:
    double x; // x coordinate of the creature
    double y; // y coordiante of the creature
    int hp; // health of the creature
    int id; // unique id of creature
    double speed; // speed of the creatures.
public:
    //default constructor
    Creature();
    //constructor
    Creature(int ID, double xCoordinate, double yCoordinate, int health);
    //destructor
    ~Creature();

    //returns the id of the creature
    int getId()const;
    // returns the x coordinate of the creature
    double getX()const;
    //returns the y coordinate of the creature
    double getY()const;
    // returns the health of the creature
    int getHealth()const;
    // returns the speed of the creature
    double getSpeed()const;
    // sets the id of the creature to the given integer
    void setId(int i);
    // sets the x coordinate of the creature to given double
    void setX(double xCoordinate);
    // sets the Y coordinate of the creature to given double
    void setY(double yCoordinate);
    // sets the health of the creature to given int
    void setHealth(int health);
    // sets the speed of the creature to given int
    void setSpeed();
    // finds an returns the distance between two creatures
    double euclideanDistance(const Creature& other);
    // decreases the health of the creature by 1 hp
    void decreaseHealth();
    // increases the health of the creature by the quality of the food which is given as argument
    void eat(int foodQuality);
    // returns true ifcreature is still alive (health > 0) else false
    bool isAlive();
};


#endif
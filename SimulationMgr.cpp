#include <iostream>
#include <fstream>
#include "Food.h"
#include "Creature.h"
#include "PriorityQueue.h"
#include <algorithm>
#include "cmath"
#include <vector>
/**
* Author : Sarp Yıldırım
* id: 22003330
* Section : 1
* Homework : 3
* Description : This is the main function.
*/

using namespace std;
// This function is used to sort the creatures (vector) in ascending order in terms of their id.
bool compareById(Creature& c1, Creature& c2) {
    return c1.getId() < c2.getId();
}

int main(int argc, char *argv[])
{
   const string foodFile = argv[1];
   ifstream inputFile;
   string line;
   int numOfCreatures;
   vector<Creature> creatures;
   PriorityQueue notAddedFoods(30);//30 = max number of foods capacity - these are foods that are not in the game but will be added.
   PriorityQueue foods(30);//30 = max number of foods capacity - these are foods in the game
   inputFile.open(foodFile.c_str(), ios_base::in);
   if (inputFile.is_open()) {
      // reading the first line of the txt file which is the number of creatures.
      getline(inputFile, line);
      numOfCreatures = stoi(line);
      string val1;
      string val2;
      string val3;
      string val4;
      string val5;
      string val6;
      int creatureId;
      double creatureX;
      double creatureY;
      int creatureHp;
      for(int i =0; i < numOfCreatures; i++){
         getline(inputFile, line);
         // reading the creatures' data from the txt file.
         size_t pos = line.find(',');
         val1 = line.substr(0,pos);
         val2 = line.substr(pos+1, line.length()-pos);

         pos = val2.find(',');
         val3 = val2.substr(0,pos);
         val4 = val2.substr(pos+1, val2.length()-pos);
         
         pos = val4.find(',');
         val5 = val4.substr(0,pos);
         val6 = val4.substr(pos+1, val4.length()-pos);
         creatureId = stoi(val1);
         creatureX = stod(val3);
         creatureY = stod(val5);
         creatureHp = stoi(val6);
         creatures.push_back(Creature(creatureId, creatureX, creatureY, creatureHp));

      }
      // reading data of foods.
      string val7;
      string val8;
      int foodQuality;
      int foodId;
      double foodX;
      double foodY;
      int foodSpawnTime;
      
      while(getline(inputFile, line)){

         size_t pos = line.find(',');
         val1 = line.substr(0,pos);
         val2 = line.substr(pos+1, line.length()-pos);

         pos = val2.find(',');
         val3 = val2.substr(0,pos);
         val4 = val2.substr(pos+1, val2.length()-pos);
         
         pos = val4.find(',');
         val5 = val4.substr(0,pos);
         val6 = val4.substr(pos+1, val4.length()-pos);

         pos = val6.find(',');
         val7 = val6.substr(0,pos);
         val8 = val6.substr(pos+1, val6.length()-pos);
         foodId = stoi(val1);
         foodX = stod(val3);
         foodY = stod(val5);
         foodQuality = stoi(val7);
         foodSpawnTime = stoi(val8);
         notAddedFoods.addBySpawnTime(Food(foodId,foodX,foodY,foodQuality,foodSpawnTime));
      }
   }
   else{
      cout<<"Could not open the file."<<endl;
   }
   sort(creatures.begin(), creatures.end(), compareById); // sorts the creatures with ascending id's.

   int loopTime = 0;
   bool allDead = false;
   while(!allDead){
      // break condition: all creatures are dead or not.
      allDead = true;
      
      //PHASE-1
      //Current locations of creatures are printed
      for (int i = 0; i < creatures.size(); i++) {
         printf("Creature %d: %.2f, %.2f\n", creatures[i].getId(), creatures[i].getX(), creatures[i].getY());
      }
      //PHASE-2
      //New food resources if any are added
      while(!notAddedFoods.isEmpty() && loopTime == notAddedFoods.peekTop().getSpawnTime()){
      
         foods.addByQuality(Food(notAddedFoods.peekTop().getId(),notAddedFoods.peekTop().getX(),notAddedFoods.peekTop().getY(),notAddedFoods.peekTop().getQuality(),notAddedFoods.peekTop().getSpawnTime()));//BURAYI DEĞİŞTİRMEN GEREKEBİLİR YENİ FOOD OLUŞTURUP DENEMEK
         notAddedFoods.removeBySpawnTime();
      }
      //PHASE-3
      //Creatures fight
      for(int i=0; i < creatures.size(); i++){
         //check if creature is alive
         if(creatures[i].isAlive()){
            for(int j = 0; j < creatures.size(); j++){
               //Check if the possible target is alive and both creatures are not same.
               if(creatures[j].isAlive() && i!=j){
                  double dist = creatures[i].euclideanDistance(creatures[j]);
                  
                  if(dist < 2 && creatures[i].getHealth()>= creatures[j].getHealth()){// it will attack
                     creatures[j].setHealth(0); // creature died from attack.
                  }
               }
            }
         }
      }
      //PHASE-4
      //Consuming best food
      //checking if there is a possible consuming food action for any of the creatures without moving.
      for(int i =0; i<creatures.size(); i++){
         //check if there is food to consume
         if(foods.isEmpty()){
            break;
         }
         //check if creature is alive or not
         if(creatures[i].isAlive()){
            Food temp = foods.peekTop();
            double xDist = abs(temp.getX()-creatures[i].getX());
            double yDist = abs(temp.getY()-creatures[i].getY());
            double dist = sqrt(xDist*xDist + yDist*yDist);
            //there best food is within a distance less than 1 unit
            if(dist<1){
               creatures[i].eat(foods.peekTop().getQuality());
               foods.removeByQuality();             
            }
         }
      }
      // after feeding phase, every creatures moves towards best quality food.
      for(int i =0; i < creatures.size(); i++){
         //check if there is a food
         if(foods.isEmpty()){
            break;
         }
         //check if current creature is alive or not
         if(creatures[i].isAlive()){
            //every alive creature moves.
            double directionX = foods.peekTop().getX() - creatures[i].getX();
            double directionY = foods.peekTop().getY() - creatures[i].getY();
            double magnitude = sqrt(directionX*directionX + directionY*directionY);
            double unitX = directionX/magnitude;
            double unitY = directionY/magnitude;
            double movementDistance = creatures[i].getSpeed();
            creatures[i].setX(creatures[i].getX()+unitX*movementDistance);
            creatures[i].setY(creatures[i].getY()+unitY*movementDistance);
         }
      }

      //PHASE-5
      //Health of creatures decrease by 1
      for(int i= 0; i < creatures.size(); i++){
         //check if creature is dead (dead creatures hp are 0)
         if(creatures[i].isAlive()){
            creatures[i].decreaseHealth();
         }
      }
      //checking if game is going on or not.
      for(int i = 0; i < creatures.size();i++){
         if(creatures[i].isAlive()){
            allDead = false;
         }
      }
      loopTime++;
   }
   return 0;
}

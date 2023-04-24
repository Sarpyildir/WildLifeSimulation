# WildLifeSimulation

This is a game that is developed to have a better understanding of heaps and priority queues in C++. 

The game will start with a number of creatures and food that spawn at various locations. Each creature will know the location of the food with the best quality, and they all will march towards it. The first creature to arrive at the location with food will consume it. At different times during the simulation, we will introduce additional food supplies to the region. The creatures will race and fight against each other to survive by consuming the food resources scattered
around.

There are 5 phases in the game:
1) Locations of the creatures are printed to console.
2) If any, new foods are added from the file.
3) If any, creatures fight with each other. 
4) If possible, creatures consume the best quality food.
5) Creatures move towards the new food.
6) All creatures lose 1 health point.

Time is implemented as one tick of a loop and during that time tick, all of the 6 phases take place.
Creatures have a unique id, health point, speed, x and y coordinates. Foods have a unique id, quality which is key for the priority queue, x and y coordinates. Both creatures and foods are read from a file. First line of the file is number of creatures, following that number of lines are creatures' data which should be in the format of id, x, y, health. After that, all the other lines are the data of food in the format of id, x, y, quality, spawnTime.

In phase 1, all creatures' x and y coordinates are printed (including dead creatures).
In phase 2, if there is any food that has a spawn time of current time, they are added into the game.
In phase 3, from starting the creature with the lowest id to the highest, all alive creatures try to fight with others. The conditions for fight are having more or equal health and having maximum distance of 2 units. If a creature can fight with another creature, than the second one dies.
In phase 4, creatures look around of them with 1 unit of radius if there is the best quality food, if there is then they eat it and gain health that is equal to the quality of the food.
In phase 5, all creatures move towards the best quality food according to their speed values.
In phase 6, all creatures lose 1 health point.

Game finishes when all creatures die.

There is a sample input file named "data.txt" and an utput file named "out.txt". Additionally, for that sample input, there is a gif named "sim.gif" which shows the movements of the creatures and foods' positions.

To run the game type the following to the console:
g++ SimulationMgr.cpp Food.cpp Creature.cpp PriorityQueue.cpp -o a
./a data.txt

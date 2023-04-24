#include "PriorityQueue.h"
#include <cmath>
#include <iostream>
/**
* Author : Sarp Yıldırım
* id: 22003330
* Section : 1
* Homework : 3
* Description : This is the implementation of the methods that are defined in the header file..
*/
using namespace std;
PriorityQueue::PriorityQueue(int maxNoOfItems){
    maxItems = maxNoOfItems;
    itemCount = 0;
    items = new Food[maxItems];
}
PriorityQueue::~PriorityQueue(){
    delete[] items;
}
// the implementation in the class : root = i, left child = 2*i +1, right child = 2*i + 2
int PriorityQueue::getLeftChildIndex(int nodeIndex)const{
    return ( 2*nodeIndex) + 1;
}
int PriorityQueue::getRightChildIndex(int nodeIndex)const{
    return (2*nodeIndex) + 2;
}
int PriorityQueue::getParentIndex( int nodeIndex)const{
    int parent = (nodeIndex-1) /2;
    return parent;
}
bool PriorityQueue::isEmpty()const{
    return (itemCount==0);
}
bool PriorityQueue::isLeaf(int nodeIndex)const{
    if(nodeIndex*2 + 1 >= itemCount && nodeIndex*2 + 2>= itemCount){
        return true;
    }
    else{
        return false;
    }
}
Food PriorityQueue::peekTop()const{
    return items[0];
}
int PriorityQueue::getNumberOfNodes()const{
    return itemCount;
}
void PriorityQueue::clear(){
    while(itemCount>0){
        removeByQuality();
    }
}
int PriorityQueue::getHeight()const{
    // height is 1 if there is only root (in Uğur hoca's class implementation)
    if(itemCount == 0){
        return 0;
    }
    else{
        return (static_cast<int>(floor(log2(itemCount)))+1);
    }
}
void PriorityQueue::addByQuality(const Food& newFood) {
    items[itemCount] = newFood;
    int newFoodIndex = itemCount;
    bool inPlace = false;
    if (itemCount == 0) {
        itemCount++;
    } else {
        int parentIndex = getParentIndex(newFoodIndex);
        while ((newFoodIndex > 0) && !inPlace) {

            if (items[newFoodIndex].getQuality() < items[parentIndex].getQuality()) {
                inPlace = true;
            } else if (items[newFoodIndex].getQuality() == items[parentIndex].getQuality()) {
                if (items[newFoodIndex].getId() > items[parentIndex].getId()) {
                    inPlace = true; // checking for having same quality and low id is better.
                }
            }

            if (!inPlace) {
                Food temp = items[newFoodIndex];
                items[newFoodIndex] = items[parentIndex];
                items[parentIndex] = temp;
                newFoodIndex = parentIndex;
                parentIndex = getParentIndex(newFoodIndex);
            }
        }
        itemCount++;
    }
}
void PriorityQueue::addBySpawnTime(const Food& newFood){
    items[itemCount] = newFood;
    int newFoodIndex = itemCount;
    bool inPlace = false;
    if(itemCount ==0 ){
        itemCount++;
    }
    else{
    int parentIndex = getParentIndex(newFoodIndex);
    while((newFoodIndex > 0) && !inPlace){
        if(items[newFoodIndex].getSpawnTime() > items[parentIndex].getSpawnTime()){
            inPlace = true;
        }
        else{
            Food temp = items[newFoodIndex];
            items[newFoodIndex] = items[parentIndex];
            items[parentIndex] = temp;
            newFoodIndex = parentIndex;
            parentIndex = getParentIndex(newFoodIndex);
        }
    }
    itemCount++;
    }
}
void PriorityQueue::removeByQuality(){
    items[0] = items[itemCount -1];
    itemCount--;
    heapRebuildByQuality(0,items, itemCount);
}
void PriorityQueue::removeBySpawnTime(){
    items[0] = items[itemCount -1];
    itemCount--;
    heapRebuildBySpawnTime(0,items, itemCount);
}
void PriorityQueue::heapRebuildByQuality(int targetRootIndex, Food* targetItems, int targetItemCount){
    int largeChild;
    if ( 2* targetRootIndex +1 < targetItemCount){
        largeChild = 2*targetRootIndex + 1;
        if( 2* targetRootIndex +2 < targetItemCount){
            if(targetItems[largeChild].getQuality() < targetItems[2*targetRootIndex+2].getQuality()){
                largeChild = 2* targetRootIndex + 2;
            }
            else if(targetItems[largeChild].getQuality() == targetItems[2*targetRootIndex+2].getQuality()){
                if(targetItems[largeChild].getId() > targetItems[2*targetRootIndex+2].getId()){
                    largeChild = 2*targetRootIndex + 2;
                }
            }
        }

        if(targetItems[targetRootIndex].getQuality() < targetItems[largeChild].getQuality()){
            Food temp = targetItems[targetRootIndex];
            targetItems[targetRootIndex] = targetItems[largeChild];
            targetItems[largeChild] = temp;
            heapRebuildByQuality(largeChild, targetItems, targetItemCount);
        }
        else if(targetItems[targetRootIndex].getQuality() == targetItems[largeChild].getQuality()){
            if(targetItems[targetRootIndex].getId() > targetItems[largeChild].getId()){
                // it is checked that having same quality and lower id is better than other.
                Food temp = targetItems[targetRootIndex];
                targetItems[targetRootIndex] = targetItems[largeChild];
                targetItems[largeChild] = temp;
                heapRebuildByQuality(largeChild, targetItems, targetItemCount);
            }
        }
    }
}

void PriorityQueue::heapRebuildBySpawnTime(int targetRootIndex, Food* targetItems, int targetItemCount){
    int largeChild;
    if ( 2* targetRootIndex +1 < targetItemCount){
        largeChild = 2*targetRootIndex + 1;
        if( 2* targetRootIndex +2 < targetItemCount){
            if(targetItems[largeChild].getSpawnTime() > targetItems[2*targetRootIndex+2].getSpawnTime()){
                largeChild = 2* targetRootIndex + 2;
            }
        }

        if(targetItems[targetRootIndex].getSpawnTime() > targetItems[largeChild].getSpawnTime()){
            Food temp = targetItems[targetRootIndex];
            targetItems[targetRootIndex] = targetItems[largeChild];
            targetItems[largeChild] = temp;
            heapRebuildBySpawnTime(largeChild, targetItems, targetItemCount);
        }
    }
}
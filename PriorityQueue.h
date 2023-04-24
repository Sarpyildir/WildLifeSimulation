#ifndef __PRIORITYQUEUE_H
#define __PRIORITYQUEUE_H
#include "Food.h"
/**
* Author : Sarp Yıldırım
* id: 22003330
* Section : 1
* Homework : 3
* Description : This is the header file of the priority queue.
*/
class PriorityQueue
{
private:
    Food* items; // array based implementation of max heap which creates the priority queues
    int itemCount; // number of items that the priority queue has currently
    int maxItems; // number of maximum items that the priority queue can have.
    
    // returns the parent index of a given node
    int getParentIndex(int nodeIndex)const;
    // return true if the given node has no children else false.
    bool isLeaf(int nodeIndex)const;
    // used for rebuilding the heap properties. This is used by removeByQuality
    void heapRebuildByQuality(int targetRootIndex, Food* targetItems, int targetItemCount);
    //used for rebuilding the heap properties. This is used by removeBySpawnTime
    void heapRebuildBySpawnTime(int targetRootIndex, Food* targetItems, int targetItemCount);
public:
    //constructor of the priority queue
    PriorityQueue(int maxNoOfItems);
    //destructor of the priority queue
    ~PriorityQueue();
    //returns true if priority queue is empty else false
    bool isEmpty()const;
    // return total number of nodes that are currently in the priority queue
    int getNumberOfNodes()const;
    // returns the height of the priority queue's max heap. In the implementation of Uğur Hoca's root is at level 1 and height is 1 if there is only root.
    int getHeight() const;
    // returns the element at the root of the priority queue.
    Food peekTop()const;

    /* There are two different add and remove functions because one of them used
    * for priority queue w.r.t quality while other is considering spawn time
    * and also in quality, the lowest id has more priority than higher ids.
    * */

    //used for adding to a priority queue whose priority key is foods' quality.
    void addByQuality(const Food& newFood);
    //used for adding to a priority queue whose priority key is foods' spawn times.
    void addBySpawnTime(const Food& newFood);
    //used for removing from a priority queue whose priority key is foods' quality
    void removeByQuality();
    //used for removing from a priority queue whose priority key is foods' spawn times. 
    void removeBySpawnTime();
    // removes every node from the priority queue
    void clear();
    // returns the left child's index of a given node index
    int getLeftChildIndex(int nodeIndex)const;
    // returns the right child's index of a given node index 
    int getRightChildIndex(int nodeIndex) const;
};

#endif
#include <iostream>
#include <queue>

class MyQueue{
    private:
      std::queue<int> q;

    public:
      //Function to insert an element at the rear of the queue 
      void enqueue(int x){
        q.push(x);
      }

      //Function to remove the front element of the queue and return its value
      int dequeue(){
        //Check if the queue is empty before attempting to dequeue 
        if(isEmpty()){
          std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
          return-1;
        }
        int front = q.front();
        q.pop();
        return front;
      }      

      //Function to check if the queue is empty
      bool isEmpty(){
        return q.empty();
      }

      //Function to return the front element present in the queue without removing it
      int peek(){
        //Check if the queue is empty before attempting to peek
        int front = q.front();
        return front;
        if(isEmpty()){
          std::cerr << "Queue is empty. Cannot peek." << std::endl;
          return -1;
        }

      }

      //Function to return the total number of elements present in the queue
      size_t size(){
        return q.size();
      }

    
};

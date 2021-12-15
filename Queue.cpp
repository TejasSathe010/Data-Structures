#include<iostream>
using namespace std;

#define MAX 100

class Queue{
    private:
        int A[MAX];
        int front, rear;

    public:

        Queue(){
            front = -1;
            rear = -1;
        }
    
    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    bool isFull(){
        return (rear+1)%MAX == front ? true: false;
    }

    void Enqueue(int data){

        cout << "Enqueueing..." << endl;
        if(isFull()){
            cout << "Error: Queue is full!" << endl;
        }

        if(isEmpty()){
            rear = front = 0;
        }else{
            rear = rear+1%MAX;
        }
        A[rear] = data;
    }

    void Dequeue(){

        cout << "Dequeueing..." << endl;
        if(isEmpty()){
            cout << "Error: Queue is empty!" << endl;
        }

        if(front == rear){
            rear = front = -1;
        }else{
            front = (front+1)%MAX;
        }
    }

    int Front(){
        if(front == -1){
            cout<<"Error: cannot return front from empty queue\n";
			return -1;
        }
        return A[front];
    }

    void Print()
	{
		// Finding number of elements in queue
		int count = (rear+MAX-front)%MAX + 1;
		cout<<"Queue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % MAX; // Index of element while travesing circularly from front
			cout<<A[index]<<" ";
		}
		cout<<"\n\n";
	}
};

int main()
{
	/*Driver Code to test the implementation
	  Printing the elements in Queue after each Enqueue or Dequeue 
	*/
   Queue Q; // creating an instance of Queue. 
   Q.Enqueue(2);  Q.Print();  
   Q.Enqueue(4);  Q.Print();  
   Q.Enqueue(6);  Q.Print();
   Q.Dequeue();	  Q.Print();
   Q.Enqueue(8);  Q.Print();

   return 0;
}
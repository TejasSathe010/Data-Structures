// bool push(int x);
// int pop();
// int peek();
// bool isEmpty();

#include<iostream>
using namespace std;

#define MAX 100

class Stack{
    int top;

    public:
        int arr[MAX];
        Stack(){
            top = -1;
        }

    bool push(int x){
        if(top >= MAX-1){
            cout << "Error: Stack overflow";
            return false;
        }else{
            arr[++top] = x;
            cout << x << " pushed into stack\n";
            return true;
        }
    }

    int pop(){
        if(top == -1){
            cout << "Error: Stack underflow";
            return -1;
        }
        int x = arr[top--];
        return x;
    }

    int peek(){
        if(top < 0){
            cout << "Error: List is empty";
        }
        int x = arr[top];
        return x;
    }

    void display(){
        if(!isEmpty()){
            cout << "Stack is" << endl;
            for(int i=top; i >= 0; i--){
                cout << arr[i] << "\t";
            }
            cout << endl;
        }
    }

    bool isEmpty(){
        return (top < 0);
    }
 
};

int main(){
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    //print all elements in stack :
    cout<<"Elements present in stack : ";
    s.display();
    // while(!s.isEmpty())
    // {
    //     // print top element in stack
    //     cout<<s.peek()<<" ";
    //     // remove top element in stack
    //     s.pop();
    // }
    return 0;
}
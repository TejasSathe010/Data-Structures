// bool push(int x);
// int pop();
// int peek();
// bool isEmpty();

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{

    public:
        Node* top;
        Stack(){
            top = NULL;
        }

    bool push(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
        cout << temp->data << " Pushed" << endl;
        return true;
    }

    int pop(){
        if(top == NULL){
            cout << "Error: List is empty" << endl;
            return 0;
        }
        Node* temp;
        temp = top ->next;
        int val = temp ->data;
        delete temp;
        return val;
    }

    int peek(){
        if(top == NULL){
            cout << "Error: List is empty" << endl;
        }
        int x = top->data;
        return x;
    }

    void display(){
        if(!isEmpty()){
            cout << "Stack is" << endl;
            Node* temp = top;
            while(temp != NULL){
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    bool isEmpty(){
        return (top != NULL);
    }
 
};

int main(){
    class Stack s;

    // s.push(10);
    // s.push(20);
    // s.push(30);
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
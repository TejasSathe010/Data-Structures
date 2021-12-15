#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*  next;
    Node* prev;
};

class doublyLL{

    Node* head;

    public: doublyLL(){
        head = NULL;
    }

    void insertFront(int data){
        Node* temp = new Node();
        temp->data = data;
        temp->next = head;
        temp->prev = NULL;

        if(head != NULL){
            head->prev = temp;
        }
        head = temp;
    }

    void insertEnd(int data){
        Node* temp = new Node();
        temp -> data = data;
        temp -> next = NULL;

        if(head == NULL){
            temp -> prev = NULL;
            head = temp;
            return;
        }
        Node* last = head;
        while(last->next != NULL){
            last = last->next;
        }

        last->next = temp;
        temp->prev = last;
        return;
    }

    void display(){
        Node* temp = head;
        cout << "Linked List" << endl;
        while(temp != NULL){
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverseDisplay(){
        Node* temp = head;
        
        while(temp->next != NULL){
            temp = temp->next;
        }

        cout << "Reversed Linked List" << endl;
        while(temp != NULL){
            cout << temp->data << "\t";
            temp = temp->prev;
        }
        cout << endl;

    }

};




int main(){

    doublyLL l;

    l.insertFront(10);
    l.display();
    l.insertFront(90);
    l.display();
    l.insertFront(20);
    l.display();
    l.insertEnd(100);
    l.display();
    l.insertFront(80);
    l.display();
    
    l.insertEnd(1000);
    l.display();
    l.insertEnd(10001);
    l.display();
    l.insertEnd(100002);
    l.display();

    l.reverseDisplay();

    return 0;
}
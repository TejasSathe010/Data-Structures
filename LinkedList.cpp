#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList{
    Node* head;
    int size;

    public:
    LinkedList(){
        head = NULL;
        size = 0;
    }

    void insert(int data){
        // Insertion at the begining of the linked list.
        size++;
        Node* temp = new Node();
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    int deletionAtStart(){
        // Deletion at the begining of the linked list.
        if(head == NULL){
            cout << "Error: Linked list is empty" << endl;
            return 0;
        }
        size--;
        int data = head->data;
        Node* temp = head;
        head = temp->next;
        delete temp;
        return data;
    }

    void insertAtEnd(int data){
        // Insertion at the end of the linked list.
        size++;
        Node* temp = new Node();
        temp->data = data;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
            return;
        }
        Node* last = head;
        while (last ->next != NULL)
        {
            last = last ->next;
        }
        last ->next = temp;
        return;
    }

    int deletionAtEnd(){
        // Delete at the end of the linked list.
        Node* temp = head;
        int data;

        if(head == NULL){
            cout << "Error: Linked list is empty" << endl;
            return 0;
        }
        size--;
        Node* last = head;
        while (last -> next -> next != NULL)
        {
            last = last ->next;
        }
        data = last -> next -> data;
        last -> next = NULL;
        delete last -> next;
        return data;
    }

    // Insertion at nth position
    void insertAtNth(int data, int pos){
        if(pos > size){
            cout << "#####Error: Size of linked list is smaller than Position#####" << endl;
            cout << "Current size is " << size << endl;
            cout << "#####Suggestion: Try between 1 and " << size << ".#####" << endl;
            return;
        }
        size++;
        Node* temp =  new Node();
        temp->data = data;
        temp->next = NULL;

        if(pos == 1){
            temp->next = head;
            head = temp;
            return;
        }

        Node* temp1 = head;
        for(int i = 1; i <pos - 1; i++){
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
        return;
    }

    // Delete node at n'th position
    int deleteAtNth(int pos){
        if(pos > size || size == 0 || head == NULL){
            cout << "#####Error: Size of linked list is smaller than Position #####" << endl;
            cout << "Current size is " << size << endl;
            cout << "#####Suggestion: Maybe linked list is empty? #####" << endl;
            return 0;
        }
        size--;
        Node* temp =  head;
        int data;

        if(pos == 1){
            head = temp -> next;
            data = temp -> data;
            delete temp;
            return data;
        }

        for(int i = 1; i < pos-1; i++){
           temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        data = temp -> next -> data;
        return data;
    }
    

    int search(int data){
        // Searching linked list for pos of data
        Node* temp = head;
        int pos = 1;

        if(head == NULL){
            cout << "Error: Linked list is empty" << endl;
            return 0;
        }
        while(temp != NULL){
            if(temp ->data == data){
                return pos;
            }
            temp = temp -> next;
            pos++;
        }
        cout << "Error: Not found" << endl;
        return -1;
    }


    
    void display(){
        // Traversing the linked list
        Node* temp = head;
        cout << "\n" << "Linked list --> " << endl;
        while(temp != NULL){
            cout << temp->data<< "\t";
            temp = temp->next;
        }
        cout << "\t Size " << size << endl;
    }
};

int main(){

    LinkedList l;

    l.insertAtEnd(5);
    l.display();
    l.insertAtEnd(6);
    l.display();
    l.insertAtEnd(10);
    l.display();
    l.insertAtEnd(20);
    l.display();
    l.insertAtNth(90, 14);
    l.display();
    l.insertAtEnd(30);
    l.display();
    l.insertAtEnd(50);
    l.display();
    l.insertAtNth(90, 14);

    int first = l.deletionAtStart();
    cout << "Deleted Node: " << first << endl;
    l.display();

    int last = l.deletionAtEnd();
    cout << "Deleted Node: " << last << endl;
    l.display();

    int pos = l.search(20);
    cout << "\n Node found at: " << pos << endl;
    l.display();
    
    return 0;
}
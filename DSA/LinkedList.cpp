#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node *next;

        node(int v){
            data = v;
            next = NULL;
        }
};

class List {
    node *head; 
    node *tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int v) {        // insert at the beginning
        node *newnode = new node(v);
        if(head == NULL) {
            head = tail = newnode;
            return;
        } else {
            newnode -> next = head;
            head = newnode;
        }
    }

    void push_back(int v) {             // insert at the end
        node *newnode = new node(v);
        if(head == NULL) {
            head = tail = newnode;
            return;
        } else {
            tail -> next = newnode;
            tail = newnode;
        }
    }

    void pop_front() {              // remove first element
        if(head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        node *tem = head;
        head = head -> next;
        delete tem;
    }

    void pop_back() {                       // remove last element
        if(head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        node *tem = head;
        while(tem -> next != tail)
            tem = tem -> next;
        
        tem -> next = NULL;
        delete tail;
        tail = tem;
    }

    void insert(int v, int pos) {           // insert value v at position pos
        if(pos < 0) {
            cout << "Invalid position." << endl;
            return;
        }

        if(pos == 0) {
            push_front(v);
            return;
        }

        node *newnode = new node(v);
        node *tem = head;
        for(int i=0; i<pos-1; i++) {
            if(tem == NULL){
                cout << "Invalid position." << endl;
                return;
            }
            tem = tem -> next;
        }

        newnode -> next = tem -> next;
        tem -> next = newnode;
    }

    int search(int v){
        node *tem = head;
        int pos = 0;

        while(tem != NULL) {
            if(tem -> data == v){
                cout << "Value found at position: " << pos << endl;
                return pos;
            }
            pos++;
            tem = tem -> next;
        }

        return -1;
    }

    void print() {             // print the linked list
        node *tem = head;
        while(tem != NULL) {
            cout << tem -> data << " -> ";
            tem = tem -> next;
        }
        cout << "NULL" << endl;
    }   
};

int main() 
{
    List l;
    l.push_front(4);
    l.push_front(5);
    l.push_front(6);

    l.print();

    l.push_back(11);
    l.push_back(12);
    l.push_back(13);

    l.print();

    l.pop_front();
    l.pop_front();

    l.print();
        
    l.pop_back();
    l.pop_back();

    l.print();

    List ll;
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(9);
    ll.push_back(11);

    ll.print();

    ll.insert(10, 3);

    ll.print();

    ll.search(10);
    l.search(15);
    ll.search(16);

    return 0;
}
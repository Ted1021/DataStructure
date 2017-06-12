//
//  main.cpp
//  LinkedList
//
//  Created by Ted on 2017. 6. 12..
//  Copyright © 2017년 Ted. All rights reserved.
//

#include <iostream>

using namespace std;

class Node{
    
public:
    
    int data;
    Node* next;
    
    Node(int num){
        data = num;
        next = NULL;
    };
    
    ~Node(){};
    
};

class LinkedList{
    
public:
    
    Node *head;
    Node *tail;
    
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void insertNode(Node *newNode){
        
        if(head == NULL)
            head = newNode;
        else
            tail->next = newNode;
        
        tail = newNode;
        
    };
    
    void insertNode(Node *newNode, int position){
        
        Node *front = findNode(position);
        Node *back = findNode(position-1);
        
        newNode->next = front;
        back->next = newNode;
        
    }
    
    void deleteNode(){
        
        Node *pointer = head;
        
        while(pointer->next != tail)
            pointer = pointer->next;
        
        cout << tail->data << " is deleted !!" << endl;
        tail->~Node();
        
        pointer->next = NULL;
        tail = pointer;
        
        cout << "Now, tail is " << tail->data << endl;
        
    }
    
    void deleteNode(int position){
        
        Node *front = findNode(position+1);
        Node *target = findNode(position);
        Node *back = findNode(position-1);
        
        back->next = front;
        target->next = NULL;
        target->~Node();
        
    };
    
    Node* findNode(int position){
        
        Node *pointer = head;
        
        for(int i=0; i<position-1; i++){
            pointer = pointer->next;
        }
        
        return pointer;
    };
    
    int listCount(){
        
        Node *pointer = head;
        int count=0;
        
        while(pointer != NULL)
            count++;
        
        return count;
    };
    
    void showList(){
        cout << "----------------------------" << endl;
        
        Node *pointer = head;
        
        while(pointer != NULL){
            cout << pointer->data << " ";
            pointer = pointer->next;
        }
        
        cout << endl << "----------------------------" << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    LinkedList list = LinkedList();
    
    for(int i=0; i<10; i++){
        
        Node *newNode = new Node(i);
        list.insertNode(newNode);
        
    }
    
    list.showList();
    
    list.deleteNode();
    list.showList();
    
    Node *newNode = new Node(71);
    list.insertNode(newNode, 8);
    list.showList();
    
    return 0;
}


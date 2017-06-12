//
//  main.cpp
//  LinkedList
//
//  Created by Ted on 2017. 6. 12..
//  Copyright © 2017년 Ted. All rights reserved.
//

#include <iostream>

using namespace std;

// Linked List 의 Node Class 를 구현
class Node{
    
public:
    
    int data;
    Node* next;
    
    // 1. 생성자 정의
    // 1.1 매개변수가 없을 때에는 값은 0, 포인터는 Null 로!
    Node(){
        data = 0;
        next = NULL;
    }
    
    // 1.2 매개변수가 있을 때에는 전달받은 값으로 초기화 해 준다.
    Node(int num){
        data = num;
        next = NULL;
    };
    
    // 2. 소멸자 정의
    ~Node(){
        cout << "Node is deleted" << endl;

    };
    
};

// Linked List Class 구현
// 리스트의 생성과 노드의 조회, 삽입, 삭제를 구현
class LinkedList{
    
public:
    
    /***** 1. 첫 노드와 마지막 노드를 선언 *****/
    Node *head;
    Node *tail;
    
    /***** 2. 생성자 & 소멸자 정의 *****/
    // 2.1 생성자 정의
    LinkedList(){
        
        // 2.1.1 최초로 생성 될 때에는 첫 노드와 마지막 노드를 NULL 로 초기화
        // 어떠한 것도 가리키는것이 없는 상태
        head = NULL;
        tail = NULL;
    }
    
    // 2.2 소멸자 정의
    ~LinkedList(){
        cout << "Linked List is deleted" << endl;
    };

    
    /***** 3. Position 을 이용한 Node 조회 *****/
    Node* findNode(int position){
        
        // 3.1 첫 노드부터 순차적으로 조회
        Node *pointer = head;
        // 3.2 전달받은 매개 변수만큼 다음 노드로 이동
        for(int i=0; i<position-1; i++)
            pointer = pointer->next;
        // 3.3 조회 된 노드를 리턴
        return pointer;
    };
    
    /***** 4. 노드 삽입 *****/
    // 4.1 리스트의 맨 끝에 노드를 삽입하는 경우,
    void insertNode(Node *newNode){
        // 4.1.1 첫 노드를 삽입 할 때,
        if(head == NULL)
            // Head 는 새로운 노드를 가리킨다.
            head = newNode;
        // 4.1.2 두번째 노드 부터는
        // 마지막 노드가 새로운 노드를 가리키게 한다.
        else
            tail->next = newNode;
        
        // 4.1.3 새로이 삽입 되는 노드는 무조건 Tail 이 가리키게 한다.
        tail = newNode;
    };
    
    // 4.2 리스트의 중간에 노드를 삽입하는 경우,
    // '새로운 노드'와 '삽입하길 원하는 위치'를 전달받는다.
    void insertNode(Node *newNode, int position){
        
        // 4.2.1 중간 삽입을 위한 노드를 가져오는 작업
        Node *front = findNode(position);   // 기존 위치의 노드를 가져온다.
        Node *back = findNode(position-1);  // 직전 위치의 노드를 가져온다.
        
        // 4.2.2 포인팅을 재정의한다.
        newNode->next = front;  // 우선, 새로운 노드가 기존 위치의 노드를 가리키게 한다.
        back->next = newNode;   // 이후, 직전 위치의 노드가 새로운 노드를 가리키게 한다.
    }
    
    /***** 5. 노드 삭제 *****/
    // 5.1 리스트의 맨 끝에 위치한 노드 삭제 구현
    void deleteNode(){
        
        // 5.1.1 Head 에서 부터 Tail 직전까지의 노드를 순차적으로 검색한다.
        Node *pointer = head;
        while(pointer->next != tail)
            pointer = pointer->next;
        
        // 5.1.2 마지막 노드를 소멸시킨다.
        cout << tail->data << " is deleted !!" << endl;
        tail->~Node();
        
        // 5.1.3 기존 Tail 의 직전 노드를 Tail 로 변환
        pointer->next = NULL;   // 다음 노드를 NULL 로 변환
        tail = pointer;         // 해당 노드를 Tail 이 가리키게 함
        cout << "Now, tail is " << tail->data << endl;
        
    }
    
    // 5.2 특정 위치에 있는 노드 삭제 구현
    void deleteNode(int position){
        
        // 5.2.1 삭제하길 원하는 노드와 그 앞뒤 노드 정보를 한꺼번에 받아온다.
        Node *front = findNode(position+1); // target 직후 노드
        Node *target = findNode(position);  // target 노드
        Node *back = findNode(position-1);  // target 직전 노드
        
        // 5.2.2 직전 노드가 바로 직후 노드를 가리키게 한다.
        back->next = front;
        
        // 5.2.3 target 노드를 삭제한다.
//        target->next = NULL;
        target->~Node();
        
    };
    
    /***** 6. 리스트 길이 *****/
    // 6.1 리스트의 길이를 반환하는 메소드 구현
    int listCount(){
        
        // 6.1.1 첫 노드부터 끝노드까지 이동하면서 갯수를 카운팅 한다.
        Node *pointer = head;
        int count=0;
        
        while(pointer != NULL)
            count++;
        
        return count;
    };
    
    /****** 7. 전체 리스트 조회 ******/
    // 7.1 현재 리스트내에 존재 하는 노드들을 보여주는 메소드 구현
    void showList(){
        
        cout << "----------------------------" << endl;
        
        // 7.1.1 Head 부터 순차적으로 노드 데이터에 접근
        Node *pointer = head;
        while(pointer != NULL){
            // 7.1.2 현재 노드 데이터 출력
            cout << pointer->data << " ";
            // 7.1.3 다음 노드 데이터로 이동
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
    
    list.deleteNode(8);
    list.showList();
    
    return 0;
}


#include <iostream>

using namespace std;

struct Node{
    char data;
    Node* next;
    Node(char data){
        this->data = data;
        next = NULL;
    }
};

struct LinkedList{
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void reverse(){
        Node *current = head, *prev = NULL, *next = NULL;

        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;

        }
        head = prev;
    }
    void push(char data){
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main(){

    return 0;

}

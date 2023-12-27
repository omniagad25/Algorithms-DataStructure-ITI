#include <iostream>

using namespace std;
template <class T>

class doublyLinkedList
{
private:
    struct Node
    {
        T data;
        Node*next;
        Node*prev;
    };

    Node*head;
    Node*tail;
    int length;

public:
    doublyLinkedList()
    {
        head=NULL;
        tail=NULL;
        length=0;
    }

    doublyLinkedList(doublyLinkedList &_list)
    {
        head = tail = NULL;
        length = 0;
        Node* current = head;
        while (current != NULL)
        {
            this->insertLast(current->data);
            current = current->next;
        }
    }

    bool isEmpty()
    {
        return(head==NULL);
    }

    void insertFirst(T data)
    {
        Node*newNode= new Node;
        newNode->data=data;
        if(isEmpty())
        {
            head=tail=newNode;
            newNode->next=newNode->prev= NULL;
        }
        else
        {
            newNode->next=head;
            newNode->prev=NULL;
            head->prev=newNode;
            head=newNode;
        }
        length++;
    }

    void insertLast(T data)
    {
        Node*newNode= new Node;
        newNode->data=data;
        if(isEmpty())
        {
            head=tail=newNode;
            newNode->next=newNode->prev= NULL;
        }
        else
        {
            newNode->next=NULL;
            newNode->prev=tail;
            tail->next=newNode;
            tail=newNode;
        }
        length++;
    }

    void insertNode(int pos, T data)
    {

        if(pos<0 || pos>length)
        {
            cout<<"Position doesn't exist"<<endl;
        }
        else
        {
            Node*newNode= new Node;
            newNode->data=data; // insert the value itself
            if(pos==0){
                insertFirst(data);
            }
            else if(pos==length){
                insertLast(data);
            }
            else{
            Node*current= head;
            for(int i=1;i<pos;i++){
                current=current->next;
            }
            newNode->next=current->next; //tshawr 3l ablha wl b3dha
            newNode->prev=current;
            current->next->prev=newNode;
            current->next=newNode; // insert the node itself in the position
            length++;
            }

        }

    }

    void deleteFirst(T data){
        if(isEmpty()){
            cout<<"The list is Empty"<<endl;
        }
        else if(length==1){
            delete head;
            tail=head=NULL;
            length--;
        }
        else{
            Node*current= head;
            head=head->next;
            head->prev=NULL;
            delete current;
            length--;
        }
    }

    void deleteLast(T data){
        if(isEmpty()){
            cout<<"The list is Empty"<<endl;
        }
        else if(length==1){
            delete head;
            tail=head=NULL;
            length--;
        }
        else{
            Node*current= tail;
            tail=tail->prev;
            tail->next=NULL;
            delete current;
            length--;
        }
    }

    void deleteNode(T data)
    {

        if(isEmpty()){
            cout<<"The list is empty"<<endl;
        }
        else
        {
            if(head->data==data){
                deleteFirst(data);
            }
            else if(tail->data==data){
                deleteLast(data);
            }

            else{
            Node*current= head;
            while(current!=NULL && current->data!=data){
                current=current->next;
            }
            if(current==NULL){
                cout<<"The node doesn't exist"<<endl;
            }
            else{
            current->prev->next=current->next;
            current->next->prev=current->prev;
            }
            delete current;
            length--;

            }

        }

    }

    void display(doublyLinkedList &_list){
        Node*current=head;
        int countElement=0;
        while(current!=NULL){
            countElement++;
            cout<<"Element number "<< countElement <<" in the list is " <<current->data<<endl;
            current=current->next;
        }

    }
    void clearList(doublyLinkedList &list){
        Node*current=head;
        Node*temp;
        while(current!=NULL){
            temp=current;
            delete temp;
            current=current->next;
        }
        head=tail=NULL;
    }

    void searchList(T data)
    {
        Node* current = head;
        while (current != NULL)
        {
            if (current->data == data)
            {
                cout<<"Found "<< current->data<<endl;
                break;
            }
            else
            {
                current = current->next;
            }
        }
        if(current==NULL){
            cout<<"Not Found"<<endl;
            delete current;
        }
    }


};




int main()
{
    doublyLinkedList <int> list1;
    list1.insertFirst(10);
    list1.insertNode(1,6);
    list1.display(list1);
    list1.searchList(10);
    return 0;
}


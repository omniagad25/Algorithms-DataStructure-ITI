#include <iostream>

using namespace std;
template <class T>

class linkedQueue
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
    linkedQueue()
    {
        head=NULL;
        tail=NULL;
        length=0;
    }

    linkedQueue(linkedQueue &_queue)
    {
        head = tail = NULL;
        length = 0;
        Node* current = _queue.tail;
        while (current != NULL)
        {
            this->enqueue(current->data);
            current = current->prev;
        }
    }

    bool isEmpty()
    {
        return(head==NULL);
    }

    void enqueue(T data)
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





    void dequeue(){
        if(isEmpty()){
            cout<<"The list is Empty"<<endl;
        }
        else if(length==1){
            delete tail;
            tail=head=NULL;
            length--;
            cout<<"deleted successfully"<<endl;
        }
        else{
            Node*current= tail;
            tail=tail->prev;
            tail->next=NULL;
            delete current;
            length--;
            cout<<"deleted successfully"<<endl;
        }
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }
        else{
        Node*current=tail;
        int countElement=0;
        while(current!=NULL){
            countElement++;
            cout<<"Element number "<< countElement <<" in the list is " <<current->data<<endl;
            current=current->prev;
        }
        }
    }
    void clearList(linkedQueue &list){
        Node*temp;
        while(head!=NULL){
            temp=head;
            delete temp;
            head=head->next;
        }
        head=tail=NULL;
        length=0;
    }


};




int main()
{
    linkedQueue <int> list1;
    list1.enqueue(10);
    list1.enqueue(6);
    list1.display();
    list1.dequeue();
    list1.display();
    return 0;
}



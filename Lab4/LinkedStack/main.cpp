#include <iostream>

using namespace std;
template <class T>

class linkedStack
{
private:
    struct Node
    {
        T data;
        Node*next;
    };

    Node*head;
    int length;

public:
    linkedStack()
    {
        head=NULL;
        length=0;
    }

    linkedStack(linkedStack &_stack)
    {
        head = NULL;
        length = 0;
        Node* current = _stack.head;
        while (current != NULL)
        {
            this->insertFirst(current->data);
            current = current->next;
        }
    }

    bool isEmpty()
    {
        return(head==NULL);
    }

    void push(T data)
    {
        Node*newNode= new Node;
        //newNode->data=data;
       /* if(isEmpty())
        {
            head=newNode;
        }
        else
        {
            newNode->next=head;
            head=newNode;
        }*/
        if (isEmpty())
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"The Stack is Empty"<<endl;
        }
        else if(length==1)
        {
            delete head;
            head=NULL;
            length--;
            cout<<"Deleted successfully"<<endl;
        }
        else
        {
            Node*current= head;
            head=head->next;
            delete current;
            length--;
            cout<<"Deleted successfully"<<endl;

        }
    }

    void display(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
        }
        else{
        Node*current=head;
        int countElement=0;
        while(current!=NULL){
            countElement++;
            cout<<"Element number "<< countElement <<" in the list is " <<current->data<<endl;
            current=current->next;
        }
        }
    }


    void clearStack()
    {
        Node*temp;
        while(head!=NULL)
        {
            temp=head;
            delete temp;
            head=head->next;
        }
        length=0;
    }

~linkedStack(){
    Node*temp;
        while(head!=NULL)
        {
            temp=head;
            delete temp;
            head=head->next;
        }
        length=0;
}

};




int main()
{
    linkedStack <int> list1;
    list1.push(10);
    list1.push(10);
    list1.push(5);
    list1.pop();
    return 0;
}


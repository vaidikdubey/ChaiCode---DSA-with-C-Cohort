#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class doublyLL
{
    Node *head = NULL;

public:

    void printLL() {
        if(head == NULL) {
            cout << "Empty List" << endl;
            return;
        }
        Node *temp = head;

        while(temp != NULL) {
            cout << temp->data;
            if(temp-> next != NULL){
                cout << "<->";
            }
            temp = temp->next;
        }
    }
    void insert_at_beg(int value)
    {
        Node *temp = new Node(value);

        if (head == NULL)
        {
            head = temp;
            return;
        }

        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void insert_at_pos(int value, int pos)
    {
        if (head == NULL)
        {
            insert_at_beg(value);
            return;
        }

        if(pos == 1) {
            insert_at_beg(value);
            return;
        }

        Node *temp = new Node(value);

        Node *itr = head;

        while (pos - 2 != 0)
        {
            if (itr->next == NULL)
            {
                insert_at_end(value);
                return;
            }
            itr = itr->next;
            pos--;
        }

        temp->next = itr->next;
        temp->prev = itr;

        temp->next->prev = temp;
        itr->next = temp;
    }

    void insert_at_end(int value)
    {
        if (head == NULL)
        {
            insert_at_beg(value);
            return;
        }

        Node *temp = new Node(value);

        Node *t = head;

        while (t->next != NULL)
        {
            t = t->next;
        }

        t->next = temp;
        temp->prev = t;
    }

    void delete_at_beg() {
        if(head == NULL) {
            cout << "Empty List" << endl;
            return;
        }
        
        Node *temp = head;
        head = head->next;
        head->prev = NULL;

        delete temp;
    }

    void delete_at_end() {
        if(head == NULL) {
            cout << "Empty List" << endl;
            return;
        }

        Node *temp = head;

        while(temp -> next != NULL) {
            temp = temp->next;
        }
        
        //Only 1 node
        if(temp -> prev == NULL) {
            head = NULL;
        }
        else {
            temp->prev->next = NULL;
        }

        delete temp;
    }

    void delete_at_pos(int pos) {
        if(head == NULL) {
            cout << "Empty List" << endl;
            return;
        }

        if(pos == 1) {
            delete_at_beg();
            return;
        }

        Node *temp = head;

        while(pos - 1 != 0) {
            if(temp -> next == NULL) {
                delete_at_end();
                return;
            }
            temp = temp->next;
            pos--;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }
};

int main() {
    doublyLL dll;

    dll.insert_at_beg(50);
    dll.insert_at_beg(30);
    dll.insert_at_beg(10);

    dll.insert_at_end(70);
    dll.insert_at_end(80);
    dll.insert_at_end(90);

    dll.insert_at_pos(20, 2);
    dll.insert_at_pos(40, 4);
    dll.insert_at_pos(60, 6);

    dll.delete_at_beg();
    dll.delete_at_end();
    dll.delete_at_pos(2);

    dll.printLL();

    return 0;
}
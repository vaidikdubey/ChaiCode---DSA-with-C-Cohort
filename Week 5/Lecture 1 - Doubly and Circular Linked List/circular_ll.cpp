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

class circularLL
{
    Node *head = NULL;
    Node *tail = NULL;

public:

    void printLL() {
        if(head == NULL) {
            cout << "Empty List" << endl;
            return;
        }
        Node *temp = head;

        while(temp != tail) {
            cout << temp->data;
            if(temp-> next != NULL){
                cout << "<->";
            }
            temp = temp->next;
        }

        cout << temp->data;
    }
    void insert_at_beg(int value)
    {
        Node *temp = new Node(value);

        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }

        temp->next = head;
        head->prev = temp;
        head = temp;
        head->prev = tail;
        tail->next = head;
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
            if (itr->next == head)
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

        tail->next = temp;
        temp->prev = tail;
        tail = temp;

        tail->next = head;
        head->prev = tail;
    }

    void delete_at_beg() {
        if(head == NULL) {
            cout << "Empty List" << endl;
            return;
        }
        
        //Single node
        if(head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;

        delete temp;
    }

    void delete_at_end() {
        if(head == NULL) {
            cout << "Empty List" << endl;
            return;
        }

        Node *temp = tail;
        
        if(tail == head) {
            delete tail;
            tail = NULL;
            head = NULL;
            return;
        }

        tail = tail->prev;
        tail->next = head;
        head->prev = tail;

        delete temp;
    }

    void delete_at_pos(int pos) {
        if(head == NULL) {
            cout << "Empty List" << endl;
            return;
        }

        if(pos <= 0) {
            cout << "Enter valid position starting from 1" << endl;
            return;
        }

        if(pos == 1) {
            delete_at_beg();
            return;
        }

        Node *temp = head;

        while(pos - 1 != 0) {
            if(temp -> next == head) {
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
    circularLL cll;

    cll.insert_at_beg(30);
    cll.insert_at_beg(20);
    cll.insert_at_beg(10);

    cll.insert_at_end(70);
    cll.insert_at_end(80);
    cll.insert_at_end(90);
    
    cll.insert_at_pos(40, 4);
    cll.insert_at_pos(50, 5);

    cll.printLL();

    cout << endl;

    cll.delete_at_beg();
    cll.delete_at_end();
    cll.delete_at_pos(2);

    cll.printLL();

    return 0;
}
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *temp = head;

            while (temp != NULL)
            {
                cout << temp->data;
                if (temp->next != NULL)
                {
                    cout << " -> ";
                }
                temp = temp->next;
            }
        }
    }

    void insert_at_beg(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void insert_in_mid(int value, int position)
    {
        int pos = 1;

        if (head == NULL || position == pos)
        {
            insert_at_beg(value);
        }

        else
        {
            Node *temp = new Node();
            temp->data = value;

            Node *itr = head;

            while (pos < position - 1)
            {
                if (itr->next != NULL)
                {
                    itr = itr->next;
                    pos++;
                }
                else
                {
                    insert_at_end(value);
                    return;
                }
            }

            temp->next = itr->next;
            itr->next = temp;
        }
    }

    void insert_at_end(int value)
    {
        if (head == NULL)
        {
            insert_at_beg(value);
        }
        else
        {
            Node *temp = new Node();
            temp->data = value;

            Node *itr = head;

            while (itr->next != NULL)
            {
                itr = itr->next;
            }

            itr->next = temp;
        }
    }

    void delete_at_beg() {
        if(head == NULL) {
            cout << "Empty List" << endl;
            return;
        }

        Node *temp = head;

        head = head -> next;

        delete temp;
    }

    void delete_at_end() {
        if(head == NULL) {
            cout << "Empty List" << endl;
        }
        else if(head -> next == NULL) {
            delete head;
        }
        else {
            Node *temp = head;

            while(temp -> next -> next != NULL) {
                temp = temp->next;
            }

            delete temp -> next;

            temp->next = NULL;
        }
    }

    void delete_at_position(int position) {
        if(head == NULL) {
            cout << "Empyt List" << endl;
        }
        else if(position == 1) {
            delete_at_beg();
        }
        else {
            Node *itr = head;

            while(position - 2 != 0 && itr -> next != NULL) {
                itr = itr->next;
                position--;
            }

            Node *temp = itr->next;

            itr->next = temp->next;

            delete temp;
        }
    }
};

int main()
{
    LinkedList ll;

    ll.insert_at_beg(10);
    ll.insert_at_beg(20);
    ll.insert_at_beg(30);
    ll.insert_at_beg(40);
    ll.insert_at_beg(50);

    ll.insert_at_end(100);
    ll.insert_at_end(90);
    ll.insert_at_end(80);

    ll.insert_in_mid(132, 3);
    ll.insert_in_mid(176, 5);

    ll.delete_at_beg();

    ll.delete_at_end();

    ll.delete_at_position(3);

    ll.print();

    return 0;
}
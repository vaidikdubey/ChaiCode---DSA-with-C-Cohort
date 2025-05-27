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

            Node *locationCopy = itr->next;

            itr->next = temp;
            temp->next = locationCopy;
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

    ll.print();

    return 0;
}
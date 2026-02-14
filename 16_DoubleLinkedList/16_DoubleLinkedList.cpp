#include <iostream>
using namespace std;


struct Node
{
    Node* prev;
    int value;
    Node* next;
    Node(Node *prev,int value, Node* next) :prev(prev),value(value), next(next) {}

};
class List
{
private:
    Node* head;
    Node* tail;
public:
    List()
    {
        head=tail = nullptr;
    }
    void AddToHead(int value)
    {
        Node* newNode = new Node(nullptr,value, head);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
        }
       
    }
    void PrintList()
    {
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
        }
        //Node* current = head;//int i = 0
        //while (current != nullptr)//i < size;
        //{
        //    cout << current->value << " ";
        //    current = current->next;//i++;
        //}
        cout << endl;
    }
    ~List()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }
    void AddToTail(int value)
    {
        Node* newNode = new Node(tail,value, nullptr);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int getElement(int pos)
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i)return current->value;
            current = current->next;
            i++;
        }
    }
    int operator[](int pos)
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i)return current->value;
            current = current->next;
            i++;
        }
    }
    void DeleteFromTail()
    {
        if (head == nullptr) return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }
};

struct Point
{
    int x;
    int y;

};
class Vector
{
    List l;//Point* point;
    int size;
    void AddPontToHead(Point p)
    {
        l.AddToHead(p);
    }

};
int main()
{
    List l;
    l.AddToHead(1);
    l.AddToHead(2);
    l.AddToHead(3);
    l.PrintList();
    l.AddToTail(20);
    l.AddToTail(30);
    l.AddToTail(40);
    l.PrintList();
    l.DeleteFromTail();
    l.PrintList();
}


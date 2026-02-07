#include <iostream>
using namespace std;


class Queue
{
    struct Element
    {
        //public
        char value;
        int priority;
    };


    Element* arr;
    int size;

public:
    Queue(): arr(nullptr), size(0){}
    ~Queue()
    {
        if (arr != nullptr) delete[]arr;
    }
    void Enqueue(char letter , int priority)
    {
        int index = 0;
        while (index < size && arr[index].priority < priority)
        {
            index++;
        }

        size++;
        Element* temp = new Element[size];
        for (int i = 0; i < index; i++)
        {
            temp[i] = arr[i];
        }
        temp[index] = Element{letter,priority};
        for (int i = index + 1; i < size; i++)
        {
            temp[i] = arr[i - 1];
        }
        if (arr != nullptr) delete[]arr;
        arr = temp;
    }
    bool IsEmpty()
    {
        return size == 0;
    }
    Element Dequeue()
    {
        if (!IsEmpty())
        {
            Element first = arr[0];
            for (int i = 0; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
            return first;
        }
        return Element();            
    }
    void Print()
    {
        cout << "---------------- Queue ---------------------" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i].value << " --- " << arr[i].priority << endl;
        }
    }  
};

int main()
{
    Queue q;

    q.Enqueue('A', 1);
    q.Enqueue('K',12);
    q.Enqueue('B',2 );
    q.Enqueue('N',17);
    q.Enqueue('G',5 );
    q.Enqueue('C',3);

    q.Print();
    q.Enqueue('D',4 );
    q.Print();
    while (!q.IsEmpty())
    {
        cout << "Element : " << q.Dequeue().value << endl;
    }
    
}


#include <iostream>
#include <conio.h>
using namespace std;

class Queue
{
    enum {EMPTY = 0};
    int* arr;
    int maxSize;
    int topIndex;
public:
    Queue() = default;
    Queue(int size) : maxSize(size)
    {
        arr = new int[maxSize];
        topIndex = EMPTY;
    }
    bool IsEmpty()
    {
        return topIndex == EMPTY;
    }
    bool IsFull()
    {
        return topIndex == maxSize - 1;
    }
    void Enqueue(int element)
    {
        if (!IsFull())
            arr[topIndex++] = element;//arr[topIndex] = element;  topIndex++;      
    }
  /*  int Dequeue()
    {
    
        if (!IsEmpty())
        {
            int first = arr[0];
            for (int i = 0; i < topIndex; i++)
            {
                arr[i] = arr[i + 1];
            }
            topIndex--;
            return first;
        }
    }*/
    int Dequeue()
    {
        // cycle queue
        if (!IsEmpty())
        {
            int first = arr[0];
            for (int i = 0; i < topIndex; i++)
            {
                arr[i] = arr[i + 1];
            }
            //topIndex--;
            arr[topIndex-1] = first;
            return first;
        }
    }
    int GetCount()
    {
        return topIndex;
    }
    int Clear()
    {
        topIndex = 0;
    }
    void Print()
    {
        for (int i = 0; i < topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Queue()
    {
        if (arr != nullptr)delete[]arr;
    }
};

int main()
{
    Queue q(15);
    for (int i = 0; i < 10; i++)
    {
        q.Enqueue(rand() % 25);
    }
    q.Print();

    while (!q.IsEmpty())
    {
        cout << q.Dequeue() << endl;
        q.Print();
        _getch();
    }
    
}


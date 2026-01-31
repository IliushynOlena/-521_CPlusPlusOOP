
#include <iostream>
using namespace std;

class Stack
{
    enum {EMPTY = -1, FULL = 9};
    int arr[FULL + 1];
    int topIndex;
public:
    Stack()
    {
        topIndex = EMPTY;
    }
    bool ISFULL()
    {
        return topIndex == FULL;
    }
    bool IsEmpty()
    {
        return topIndex == EMPTY;
    }
    bool Push(int elem)
    {
        if(!ISFULL())
        { 
            topIndex++;
            arr[topIndex] = elem;
            return true;
        }
        return false;
    }
    int Pop()
    {
        if (!IsEmpty())
        {
            return arr[topIndex--];
        }
    }
    int GetCount()
    {
        return topIndex + 1;
    }
    void Clear()
    {
        topIndex = EMPTY;
    }
    int Peek()
    {
        if (!IsEmpty())
        {
            return arr[topIndex];
        }
    }
    void Print()
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    Stack st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Print();
    cout << "Last element : " << st.Peek() << endl;

    while (!st.IsEmpty())
    {
        cout << "Element : " << st.Pop() << endl;
    }   
    cout << "Size : " << st.GetCount() << endl;

}


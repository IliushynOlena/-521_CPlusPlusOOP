
#include <iostream>
using namespace std;

//class Stack
//{
//    enum {EMPTY = -1, FULL = 9};
//    int arr[FULL + 1];
//    int topIndex;
//public:
//    Stack()
//    {
//        topIndex = EMPTY;
//    }
//    bool ISFULL()
//    {
//        return topIndex == FULL;
//    }
//    bool IsEmpty()
//    {
//        return topIndex == EMPTY;
//    }
//    bool Push(int elem)
//    {
//        if(!ISFULL())
//        { 
//            topIndex++;
//            arr[topIndex] = elem;
//            return true;
//        }
//        return false;
//    }
//    int Pop()
//    {
//        if (!IsEmpty())
//        {
//            return arr[topIndex--];
//        }
//    }
//    int GetCount()
//    {
//        return topIndex + 1;
//    }
//    void Clear()
//    {
//        topIndex = EMPTY;
//    }
//    int Peek()
//    {
//        if (!IsEmpty())
//        {
//            return arr[topIndex];
//        }
//    }
//    void Print()
//    {
//        for (int i = 0; i <= topIndex; i++)
//        {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//
//};

class Stack
{
    enum {EMPTY = -1};
    int* arr;
    int size;
    int topIndex;
public:
    //delete  default
    Stack() = default; //Stack(){}
    Stack(const Stack &other) = delete; //Stack(){}
    Stack(int size): size(size)//5
    {
        arr = new int[size];
        topIndex = EMPTY;
    }
    bool IsFull()const
    {
        return topIndex == size - 1;
    }
    bool Push(int element)
    {
        if (!IsFull())
        {
          
            arr[++topIndex] = element;//++topIndex;  arr[topIndex] = element <----
            return true;
        }
        return false;
    }
    bool IsEmpty()
    {
        return topIndex == EMPTY;
    }
    int Pop()
    {
        if (!IsEmpty())
        {
            return arr[topIndex--];//---> return arr[topIndex]; topIndex--;          
        }
    }
    int Peek()
    {
        if (!IsEmpty())
        {
            return arr[topIndex];        
        }
    }
    int GetCount()
    {
        return topIndex + 1;
    }
    void Print()
    {
        for (int i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    ~Stack()
    {
        delete[]arr;
    }
};


int main()
{
    Stack st(10);


    st.Push(11);
    st.Push(20);
    st.Push(31);
    st.Push(14);
    st.Print();
    cout << "Last element : " << st.Peek() << endl;

    while (!st.IsEmpty())
    {
        cout << "Element : " << st.Pop() << endl;
    }   
    cout << "Size : " << st.GetCount() << endl;

}


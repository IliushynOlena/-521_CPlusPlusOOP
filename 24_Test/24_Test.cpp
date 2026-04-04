#include <iostream>
#include <fstream>
using namespace std;

template<typename T_stack>

class Stack
{
    enum { EMPTY = -1 };
    T_stack* arr;
    int size;
    int topIndex;
public:
    Stack() : arr(nullptr), size(0), topIndex(EMPTY) {}
    Stack(const Stack& other) = default;
    Stack(int size) : size(size)
    {
        arr = new T_stack[size];
        topIndex = EMPTY;
    }
    bool IsFull()const
    {
        return topIndex == size - 1;
    }
    bool Push(T_stack element)
    {
        if (!IsFull())
        {
            arr[++topIndex] = element;
            return true;
        }
        return false;
    }
    bool IsEmpty()const
    {
        return topIndex == EMPTY;
    }
    T_stack Pop()
    {
        if (!IsEmpty())
            return arr[topIndex--];
        return T_stack();
    }
    T_stack Peek()
    {
        if (!IsEmpty())
            return arr[topIndex];
        return T_stack();
    }
    int GetCount()
    {
        return topIndex + 1;
    }
    void Print()
    {
        for (size_t i = 0; i <= topIndex; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Stack()
    {
        delete[]arr;
    }
    friend ofstream& operator <<(ofstream& out, Stack& st);
    friend ifstream& operator >>(ifstream& in, Stack& st);
};

ofstream& operator <<(ofstream& out, Stack<int>& st)
{
    out << st.size << endl;
    out << st.topIndex << endl;
    for (int i = 0; i <= st.topIndex; i++)
    {
        out << st.arr[i] << " ";
    }
    return out;
}

ifstream& operator >>(ifstream& in, Stack<int>& st)
{
    in >> st.size;
    in >> st.topIndex;
    for (int i = 0; i <= st.topIndex; i++)
    {
        in >> st.arr[i];
    }
    return in;
}

int main()
{
    Stack<int> st(10);

    st.Push(11);
    st.Push(20);
    st.Push(31);
    st.Push(14);
    st.Print();
    cout << "Last element : " << st.Peek() << endl;

    /*while (!st.IsEmpty())
    {
        cout << "Element : " << st.Pop() << endl;
    }
    cout << "Size : " << st.GetCount() << endl;*/

    /*Stack<char> st2(10);

    st2.Push('g');
    st2.Push('o');
    st2.Push('o');
    st2.Push('d');
    st2.Push('!');
    st2.Print();
    cout << "Last element : " << st2.Peek() << endl;

    while (!st2.IsEmpty())
    {
        cout << "Element : " << st2.Pop() << endl;
    }
    cout << "Size : " << st2.GetCount() << endl;*/

    ofstream fileOut("stack.txt", ios_base::out);
    fileOut << st;
    fileOut.close();

    Stack<int> st3(10);
    ifstream fileIn("stack.txt");
    fileIn >> st3;
    fileIn.close();

    st3.Print();

}

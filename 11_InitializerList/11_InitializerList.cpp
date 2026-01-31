#include <iostream>
using namespace std;

class Array
{
    int* arr;
    int size;
public:
    Array() : arr(nullptr), size(0){}
    Array(int size)
    {
        this->size = size; 
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }      
    }
    Array(const initializer_list<int> &list)
    {
        this->size = list.size();
        arr = new int[size];
        int i = 0;
        for (int element : list)
        {
            arr[i++] = element;
        }
    }
    void FillArray(const initializer_list<int>& list)
    {
        if (arr != nullptr)delete[]arr;
        this->size = list.size();//20   --->  3
        arr = new int[size];    //arr = 0x145x5  ---> 0x3x66z
        int i = 0;
        for (int element : list)
        {
            arr[i++] = element;
        }
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Array()
    {
        delete[]arr;
    }
};
int main()
{
    int static_arr[5] = { 1,2,3,4,5 };
    int* dynam_arr = new int[5] {1, 2, 3, 4, 5};

    Array arr;//default constructor {1,2,3,5}
    arr.Print();
    //initializer list
    Array arr2({ 10,9,8,7,6,5,4,3,2,1,-5,-6,15,47,20 });
    arr2.Print();

    arr2.FillArray({ 1,2,3 });
    arr2.Print();
    delete[]dynam_arr;
}

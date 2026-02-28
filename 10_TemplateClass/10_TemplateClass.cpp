#include <iostream>
using namespace std;

int Multy(int a, int b) { return a * b; }
int Multy(int a, int b, int c) { return a * b*c; }
//int getMax(int* arr, int size)
//{
//    int max = arr[0];
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] > max)max = arr[i];
//    }
//    return max;
//}
//long getMax(long* arr, int size)
//{
//    long max = arr[0];
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] > max)max = arr[i];
//    }
//    return max;
//}
//float getMax(float* arr, int size)
//{
//    float max = arr[0];
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] > max)max = arr[i];
//    }
//    return max;
//}
template<typename T_arr>
T_arr getMax(T_arr* arr, int size)
{
    T_arr max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)max = arr[i];
    }
    return max;
}


//template<typename T_coll, typename T_value>
template<class T_coll, class T_value>
class MyClass
{
    T_coll* collection;
    int size;
    T_value point;
public:
    MyClass()
    {
        collection = nullptr;
        size = 0;
        //point = nullptr;
    }
    MyClass(T_coll* coll, T_value value);

    void setCollection(T_coll* coll);

    void setPoint(T_value value);
    void Print()
    {
        cout << "Collection : " << collection << endl;
        for (int i = 0; i < size; i++)
        {
            cout << collection[i] << " ";
        }
        cout << "\nPoint : " << point << endl;
    }
    ~MyClass()
    {
        if (collection != nullptr)
            delete[]collection;
    }
};
template<class T_coll, class T_value>
MyClass<T_coll, T_value>::MyClass(T_coll* coll, T_value value) :collection(coll), point(value) {}

template<class T_coll, class T_value>
void MyClass<T_coll,T_value>::setCollection(T_coll* coll) 
{ collection = coll; }

template<class T_coll, class T_value>
void MyClass<T_coll, T_value>::setPoint(T_value value) { point = value; }


template<typename T_coord>
class Point
{
    T_coord x;
    T_coord y;
public:
    Point()
    {
        x = y = 0;
    }
    Point(T_coord x, T_coord y):x(x),y(y){}
    void Print()
    {
        cout << "X : " << x << ". Y : " << y << endl;
    }
    void setNewCoord(T_coord newX, T_coord newY)
    {
        this->x = newX;
        this->y = newY;
    }
};

template<typename T_X, typename T_Y>
class NewPoint
{
    T_X x;
    T_Y y;
public:
    NewPoint()
    {
        x = y = 0;
    }
    NewPoint(T_X x, T_Y y) :x(x), y(y) {}
    void Print()
    {
        cout << "X : " << x << ". Y : " << y << endl;
    }
    void setNewCoord(T_X newX, T_Y newY)
    {
        this->x = newX;
        this->y = newY;
    }
};
int main()
{
    NewPoint<int, float> p3(100, 99.99);
    p3.Print();

    Point<int> p(5, 10);
    p.Print();
    p.setNewCoord(3, 9);
    p.Print();

    Point<double> p2(3.33, 9.98);
    p2.Print();




    int size = 4;
    long* long_arr = new long[size];
    char* char_arr = new char[size];

    for (int i = 0; i < size; i++)
    {
        long_arr[i] = i + 1;
        cout << long_arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        char_arr[i] = i + 'a';
        cout << char_arr[i] << " ";
    }

    MyClass<long,string> cl1(long_arr, "Class with long arr");
    MyClass<char,string> cl2(char_arr, "Class with char arr");

    cl1.Print();
    cl2.Print();



 /*   delete[]long_arr;
    delete[]char_arr;*/







  /*  const int size = 10;
    int numbers[size] = { 5,7,4,6,3,12,8,9,10,5 };
    cout << "Max element : " << getMax(numbers, size);

    long numbers1[size] = { 5,7,4,6,3,12,8,9,10,5 };
    cout << "Max element : " << getMax(numbers1, size);


    float numbers2[size] = { 5,7,4,6,3,12,8,9,10,5 };
    cout << "Max element : " << getMax(numbers2, size);

    string words[4] = {"A" , "AA","AAA", "AAAA"};
    cout << "Max element : " << getMax(words, 4);*/

   






}


#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
#pragma region Constructor
    Point()
    {
        x = y = 0;//<-----------------
    }
    Point(int value)
    {
        x = y = value;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
#pragma endregion   
    void Print()
    {
        cout << "X : " << x << ". Y : " << y << endl;
    }
    Point Plus(Point& other)
    {
        //this
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point Minus(Point& other)
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    //Перезавантажені операторів
    //create method witn name operator [type] ()

#pragma region Binary operator + , -, * , /
    Point operator + (const Point& other)
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point operator + (int value)
    {
        Point res(this->x + value, this->y + value);
        return res;
    }
    Point operator - (const Point& other)
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    Point operator * (const Point& other)
    {
        Point res(this->x * other.x, this->y * other.y);
        return res;
    }
    Point operator / (const Point& other)
    {
        Point res(this->x / other.x, this->y / other.y);
        return res;
    }

    //+=
    Point operator +=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    Point operator =(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

#pragma endregion

#pragma region Uno opertors  -    +  ++  --
    Point operator -()
    {
        return Point(-this->x, this->y*-1);
    }
#pragma endregion

#pragma region Binary operators == != > < >= <=
    bool operator >(const Point& other)
    {
      /*  if ((this->x + this->y) > (other.x + other.y))
            return true;
        else
            return false;*/

        return ((this->x + this->y) > (other.x + other.y));
    }
    bool operator <(const Point& other)
    {
        return ((this->x + this->y) < (other.x + other.y));
    }
    bool operator >=(const Point& other)
    {
        return ((this->x + this->y) >= (other.x + other.y));
    }
    bool operator <=(const Point& other)
    {
        return ((this->x + this->y) <= (other.x + other.y));
    }
    bool operator ==(const Point& other)
    {
        return ((this->x == other.x) && (this->y == other.y));
    }
    bool operator !=(const Point& other)
    {
        return ((this->x != other.x) || (this->y != other.y));
    }

#pragma endregion



};
class MyClass
{
    //ctor
    //destructor
    //copy ctor
    //operator =
};
int main()
{
    int a = 5;
    a += 7;//a = a + 7
    cout << 5 + 7 << endl;
    cout << 5 - 7 << endl;
    cout << 5 * 7 << endl;
    cout << 5 / 7 << endl;
    Point p1(5, 2);//this
    Point p2(7, 4);//other

    cout << "Point 1 "; p1.Print();
    cout << "Point 2 "; p2.Print();

    Point res = p1.Plus(p2); 
    cout << "Summa p1 + p2 : "; res.Print();

    res = p1.Minus(p2);
    cout << "Minus p1 + p2 : "; res.Print();

    res = p1 + p2; //res = p1.operator+(p2);
    cout << "Summa p1 + p2 : "; res.Print();

    res = p1 - p2; //res = p1.operator-(p2);
    cout << "Minus p1 - p2 : "; res.Print();

    res = p1 * p2; //res = p1.operator*(p2);
    cout << "Multy p1 * p2 : "; res.Print();

    res = p1 / p2; //res = p1.operator/(p2);
    cout << "Minus p1 / p2 : "; res.Print();

    res = p1 + 100;
    cout << " p1 + 100 : "; res.Print();
    cout << "Before ............." << endl;
    cout << "Point 1 "; p1.Print();
    cout << "Point 2 "; p2.Print();
    cout << "After ............." << endl;
    p1 += p2;
    cout << "Point 1 "; p1.Print();
    cout << "Point 2 "; p2.Print();
    res = -p1;
    cout << " -p1  : "; res.Print();

    //res = p1 = p2;
   /* cout << "Point 1 "; p1.Print();
    cout << "Point 2 "; p2.Print();
    cout << "Res ";res.Print();*/
    cout << "Point 1 "; p1.Print();
    cout << "Point 2 "; p2.Print();
    if (p1 > p2)
        cout << "p1 > p2" << endl;
    else
        cout << "p1 < p2" << endl;

    //5555/ 3600 = h
    //5555/60%60

    12:57:59
    05:12:12
    17:79:71



   /* cout << p1 + p2 << en;dl;
    cout << p1 - p2 << endl;
    cout << p1 * p2 << endl;
    cout << p1 / p2 << endl;*/
}


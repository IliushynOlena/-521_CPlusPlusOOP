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
    void setX(int x) { this->x = x; }
    int getX()const {  return x; }
    void setY(int y) { this->y = y; }
    int getY() const { return y; }
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
    Point operator + ( const Point& other)
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
    //Point operator ++()//prefix form 
    //{
    //    ++this->x;
    //    ++this->y;
    //    return *this;
    //}
    Point operator --()//prefix form 
    {
        --this->x;
        --this->y;
        return *this;
    }
    Point operator ++(int a)//postfix form 
    {
        this->x++;
        this->y++;
        return *this;
    }
    Point operator --(int)//postfix form 
    {
        this->x--;
        this->y--;
        return *this;
    }

#pragma endregion
#pragma region Binary operators == != > < >= <=
  
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
    friend Point operator ++(Point& point);
    friend ostream& operator << (ostream& out, const Point& other);
    friend istream& operator >> (istream& in,  Point& other);
};
bool operator >(const Point& p1 ,const Point& p2)
{
    return ((p1.getX() + p1.getY()) > (p2.getX() + p2.getY()));
}
//Point operator ++(Point &point)//prefix form 
//{
//    point.setX(point.getX() + 1);
//    point.setY(point.getY() + 1);
//    return point;
//}
Point operator ++(Point& point)//prefix form 
{
    point.x++;
    point.y++;
    return point;
}
ostream& operator << (ostream& out, const Point& other)
{
    out << "X - " << other.x << ". Y -  " << other.y<<endl;
    return out;
}
istream& operator >> (istream& in, Point& other)
{
    in >> other.x;
    in >> other.y;
    return in;
}
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
    a++;//postfix form
    ++a;//prefix form
    a += 7;//a = a + 7
    cout << 5 + 7 << endl;
    cout << 5 - 7 << endl;
    cout << 5 * 7 << endl;
    cout << 5 / 7 << endl;
    Point p1(5, 2);//this
    Point p2(7, 4);//other
   //ostream cout;
    cout << 5 << 8 << 10 << 15;
    cout << p1 << p2<< p1<<p2;
    //istream cin;
    cin >> p1;
    cout << p1;


    cout << "Point 1 "; p1.Print();
    cout << "Point 2 "; p2.Print();
    ++p1;
    cout << "Point 1 "; p1.Print();
    --p1;
    cout << "Point 1 "; p1.Print();

    p1++;
    cout << "Point 1 "; p1.Print();
    p1--;
    cout << "Point 1 "; p1.Print();

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

    //12:57:59
    //05:12:12
    //17:79:71



   /* cout << p1 + p2 << en;dl;
    cout << p1 - p2 << endl;
    cout << p1 * p2 << endl;
    cout << p1 / p2 << endl;*/
}


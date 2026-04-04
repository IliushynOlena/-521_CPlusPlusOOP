
#include <iostream>
using namespace std;

class Car {
public:
    void Drive()
    {
        cout << "I can drive" << endl;
    }
    void Use()
    {
        cout << "I can drive" << endl;
    }
};
class Airplane {
public:
    void Fly()
    {
        cout << "I can fly" << endl;
    }
    void Use()
    {
        cout << "I can fly" << endl;
    }
};
class FlyCar : public Car, public Airplane
{

};
class A {
public:
    int a;
};
class B : public A
{

};
class C : public A
{

};
class D : public B, public C {

};
int main()
{
    D d;
    d.a = 5;
    D::a = 5;
    D::C::a = 5;
    D::C::A c = 10;
    D::B::A  r = 7;
    Airplane air;
    air.Fly();

    Car car;
    car.Drive();
    FlyCar flyCar;
    flyCar.Drive();
    flyCar.Fly();
    ((Car)flyCar).Use();
    ((Airplane)flyCar).Use();
}


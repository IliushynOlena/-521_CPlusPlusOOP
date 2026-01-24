#include <iostream>
using namespace std;
class Recnangle;

class Square {
	int a;
public:
	Square() :a(0) {}
	Square(int a) :a(a) {}
	void Print()const { cout << "Width : " << a << "Height : " << a << endl; }
	operator Recnangle();
};
class Recnangle
{
	int w, h;
public:
	Recnangle() :w(0), h(0) {}
	Recnangle(int v) :w(v), h(v) {}
	Recnangle(int height, int width) :w(width), h(height) {}
	void Print()const { cout << "Width : " << w << "Height : " << h << endl; }
	operator int()
	{
		return w * h;
	}
	operator Square()
	{
		return Square(w + h);
	}
};
inline Square::operator Recnangle()
{
	return Recnangle(a, a + 100);
}



int main()
{
   
	int intValue = 9;
	double valueDouble = intValue;//int --> double //з стандартного до стандартного

	Square s(5);//int ---> Square //з стандартного до абстрактний
	Recnangle r(5, 7);//int ---> Square //з стандартного до абстрактний

	intValue = r;// Recnangle --> int з абстрактний до стандартного
	cout << r << endl;

	r = s;//Square --> Recnangle// з абстрактний до абстрактний
	r.Print();
	s = r;
	s.Print();


}


#include <iostream>
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;

class Car
{
protected:
	string mark;
	string model;
	float volume;
	float maxSpeed;
public:
	Car():mark("none"),model("none"),volume(0),maxSpeed(0){}
	Car(string mark, string model, float v):mark(mark),model(model),volume(v),maxSpeed(0){}
	virtual void Drive()const
	{
		cout << "I am a Car. I can drive with speed : " << maxSpeed << "km/h" << endl;
	}
	virtual void Print()const
	{
		cout << "Mark : " << mark << endl;
		cout << "Model : " << model << endl;
		cout << "Volume : " << volume << endl;
		cout << "MaxSpeed : " << maxSpeed << endl;
	}
	void setSpeed(int s)
	{
		if (s > 0)
			maxSpeed = s;
	}	
};
class ToyotaSequoia : public Car//private Car, protected Car, public Car
{
	int nitroSpeed;
public:
	ToyotaSequoia():nitroSpeed(0), Car(){}
	ToyotaSequoia(string m, string mod, float v, int nitro):nitroSpeed(nitro), Car(m,mod,v){}

	void Print()const override
	{
		Car::Print();
		cout << "nitroSpeed : " << nitroSpeed << endl;
	}
	void Drive()const override
	{
		cout << "I am a ToyotaSequoia. I can drive with speed : " << maxSpeed + nitroSpeed << "km/h" << endl;
	}
};
class PoliceCar : public Car
{
	int sound_volume;
public:
	PoliceCar():sound_volume(0),Car(){}
	PoliceCar(string m, string mod, float v, int s) :sound_volume(s), Car(m, mod, v) {}

	void Print()const
	{
		Car::Print();
		cout << "sound_volume : " << sound_volume << endl;
	}
	void Drive()const
	{
		cout << "I am a PoliceCar. I can drive with speed : " << maxSpeed << "km/h" << endl;
	}
	void BeepBeep()
	{/*
		Beep(500, 500);
		Beep(300, 500);
		Beep(800, 500);
		Beep(500, 500);*/
		PlaySound(TEXT("beep.wav"), NULL, SND_FILENAME | SND_SYNC);
	}

};
void Test(int a)
{
	cout << a << endl;
}
void TestDrive(Car& car)
{
	car.setSpeed(60);
	car.Drive();
}

int main()
{
	/*Test(5);
	Test(3.14);
	Test(bool);
	Test("hello");*/
	Car car("Volkswagen", "Passat", 1.6);
	car.setSpeed(150);
	car.Drive();
	car.Print();

	ToyotaSequoia t("Toyota", "Sequoia",3.5,50);
	t.setSpeed(220);
	t.Drive();
	t.Print();

	PoliceCar police("Toyota", "Prius", 2.2, 500);
	police.setSpeed(200);
	police.Drive();
	police.Print();
	//police.BeepBeep();
	cout << "-------------------------------" << endl;
	TestDrive(car);
	TestDrive(t);
	TestDrive(police);

	Car* cars[3]
	{ 
		new Car("Volkswagen", "Passat", 1.6),
		new ToyotaSequoia("Toyota", "Sequoia",3.5,50),
		new PoliceCar("Toyota", "Prius", 2.2, 500)
	};
	cout << "-------------------------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cars[i]->Drive();
		cout << endl;
		cars[i]->Print();
	}



	for (int i = 0; i < 3; i++)
	{
		delete cars[i];
	}




}

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Product
{
public:
	string name;
	float price;
	bool IsInStoke;
};
class Animal
{
	string name;
	string place;
	float weight;
public:
	Animal() :name("no name"), place("no place"), weight(0) {}
	Animal(string n, string p,float w) :name(n), place(p) 
	{
		this->weight = w > 0 ? w : 0;
	}
	void Move()const
	{
		cout << "I am moving......." << endl;
	}
	void ShowInfo()const
	{
		cout << "Name : " << name << endl;
		cout << "Place : " << place << endl;
		cout << "Weight : " << weight << "kg"<< endl;
	}
	friend ofstream& operator <<(ofstream& out, Animal& an);
	friend ifstream& operator >> (ifstream& in, Animal& an);
};
ofstream& operator <<(ofstream& out, Animal& an)
{
	out << an.name << " " << an.place << " " << an.weight;
	return out;
}
ifstream& operator >> (ifstream& in, Animal& an)
{
	in >> an.name >> an.place >> an.weight;
	return in;
}
class Zoo
{
	string name;
	Animal* animals;
	int countAnimals;
public:
	Zoo(string name):name(name),animals(nullptr),countAnimals(0){}
	void AddAnimal(Animal a)
	{
		countAnimals++;
		Animal* temp = new Animal[countAnimals];
		for (int i = 0; i < countAnimals-1; i++)
		{
			temp[i] = animals[i];
		}
		temp[countAnimals-1] = a;
		if (animals != nullptr)
			delete[]animals;

		animals = temp;
	}
	void ShowZoo()const
	{
		cout << "Name Zoo : " << name << endl;
		cout << "Count animal : " << countAnimals << endl;
		for (int i = 0; i < countAnimals; i++)
		{
			animals[i].ShowInfo();
			cout << endl;
		}
	}
	void SaveToFile()
	{
		ofstream out("Zoo.txt", ios_base::out);
		out << name << endl;
		out << countAnimals << endl;
		for (int i = 0; i < countAnimals; i++)
		{
			out << animals[i] << endl;
		}
		out.close();
		cout << "Information saved" << endl;
	}
	void ReadFromFile()
	{
		ifstream in("Zoo.txt", ios_base::in);
		getline(in, name);//in >> name;
		in >> countAnimals;
		animals = new Animal[countAnimals];//4
		for (int i = 0; i < countAnimals; i++)
		{
			in >> animals[i];
		}
		in.close();

	}
	void SaveBinary()
	{
		ofstream out("Zoo.bin", ios_base::out | ios_base::binary);
		out.write((char *)&name, sizeof(name));
		out.write((char *)&countAnimals, sizeof(countAnimals));
		for (int i = 0; i < countAnimals; i++)
		{
			out.write((char*)&animals[i], sizeof(animals[i]));
		}
		out.close();
		cout << "Information saved" << endl;

	}
	void ReadBinaryFromFile()
	{
		ifstream in("Zoo.bin", ios_base::in | ios_base::binary);
		in.read((char*)&name, sizeof(name));
		in.read((char*)&countAnimals, sizeof(countAnimals));	
		if (animals != nullptr)
			delete[]animals;
		animals = new Animal[countAnimals];//4
		for (int i = 0; i < countAnimals; i++)
		{
			in.read((char*)&animals[i], sizeof(animals[i]));
		}
		in.close();
	}
	~Zoo()
	{
		if (animals != nullptr)
			delete[]animals;

	}

};
int main()
{
	Animal cat("Tom", "Flat", 5);
	//cat.ShowInfo();
	/*Zoo zoo("Zoo Rivne");
	zoo.AddAnimal(cat);
	zoo.AddAnimal(Animal("Lion","Africa",150));
	zoo.AddAnimal(Animal("Bear","Forest",300));
	zoo.AddAnimal(Animal("Turtle","Ocean",900));*/

	//zoo.ShowZoo();
	//zoo.SaveToFile();
	//zoo.SaveBinary();

	Zoo zooRead("no name");
	//zooRead.ReadFromFile();
	zooRead.ReadBinaryFromFile();
	zooRead.ShowZoo();
	//Stream
	

#pragma region Text Write to File



	//ofstream fileOut;
	//fileOut.open("new_file.txt", ios_base::out);
	//ofstream fileOut("new_file.txt", ios_base::out);
	////fileOut.open("D:\\new_file.txt", ios_base::out);
	//if (fileOut.is_open())
	//{
	//	cout << "File is opened." << endl;
	//}
	//else
	//{
	//	cout << "File error" << endl;
	//}
	//char c_str[] = "Hello world !";
	//fileOut << "First line" << endl;
	//fileOut << "Second line" << endl;
	//fileOut.write(c_str, sizeof(c_str));
	//fileOut.write(c_str+2, sizeof(c_str)-2);

	//fileOut.close();
	//ifstream fileIn("new_file.txt", ios_base::in);
	//string str;

	//while (!fileIn.eof())
	//{
	//	//fileIn >> str;//read text until space
	//	getline(fileIn, str);//real all line
	//	cout << str << endl;
	//}

	//fileIn.close();
#pragma endregion
#pragma region Binary Write/Read
	/*ofstream fileOut("binary.bin", ios_base::out | ios_base::binary);
	Product pr{ "Bread",35.55, true };
	fileOut.write((char*)&pr, sizeof(pr));
	fileOut.close();

	Product read;
	ifstream fileIn("binary.bin", ios_base::in | ios_base::binary);
	fileIn.read((char*)&read, sizeof(read));
	cout << read.name << " " << read.price << " " << read.IsInStoke << endl;
	fileIn.close();*/
#pragma endregion






}


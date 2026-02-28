#include <iostream>
using namespace std;
class Animal//abstract
{
    string name;
    string place;
    float weight;
public:
    Animal():name("no name"),place("no place"),weight(0){}
    Animal(string n, string p, float w):name(n),place(p)
    {
        this->weight = w > 0 ? w : 0;
    }
    void Print()
    {
        cout << "Name : " << name << endl;
        cout << "Place : " << place << endl;
        cout << "Weight : " << weight << endl;
    }
    virtual void MakeSound()const = 0;//pure virtual method    
    virtual void Move()
    {
        cout << "I am moving......." << endl;
    }
   
};
class Lion : public Animal
{
    float runSpeed;
public:
    Lion():runSpeed(0),Animal(){}
    Lion(string n, string p, float w, float r):runSpeed(r),Animal(n,p,w){}
   
    void Print()
    {
        Animal::Print();
        cout << "Run speed : " << runSpeed << "km/h" << endl;
    }
    void Move()
    {
        cout << "I am running with speed "<< runSpeed <<" ......." << endl;
    }
    void MakeSound()const override
    {
        cout << "Rrrrrrrrrr-rrrrrrr-rrrrrr" << endl;
    }
};
class Duck: public Animal
{
    float flyHeight;
public:
    Duck():flyHeight(0),Animal(){}
    Duck(string n, string p, float w, float f):flyHeight(f),Animal(n,p,w){}
    void Print()
    {
        Animal::Print();
        cout << "Fly Height : " << flyHeight << "km/h" << endl;
    }
    void Move()
    {
        cout << "I am swimming and flying up to " << flyHeight << " ......." << endl;
    }
    void MakeSound()const override
    {
        cout << "Kra-kra-kra-kra" << endl;
    }
};

class Reptile: public Animal//Abstact class 
{
    float swimDeep;
public:
    Reptile() :swimDeep(0), Animal() {}
    Reptile(string n, string p, float w, float s) :swimDeep(s), Animal(n,p,w) {}
    void Print()
    {
        Animal::Print();
        cout << "Swim deep " << swimDeep << "m" << endl;
    }
    void Move()
    {
        cout << "I am crowling  and swimming down to " << swimDeep << " ......." << endl;
    }
};
class Frog : public Reptile
{
public:
    Frog() : Reptile() {}
    Frog(string n, string p, float w, float s) : Reptile(n, p, w,s) {}
    void MakeSound()
        const override {
        cout << "Kva-kva-kva" << endl;
    }
};
void RollCAll(Animal& an)
{
    an.MakeSound();
    an.Move();
}
int main()
{
   /* Animal cat("Tom", "Flat", 8);
    cat.Move();
    cat.MakeSound();
    cat.Print();*/

    Lion lion("Simba", "Africa", 200,70);
    lion.Move();
    lion.MakeSound();
    lion.Print();

    Duck duck("Donnald Dack","Lake",2,5);
    duck.MakeSound();
    duck.Move();
    duck.Print();
    Frog frog("Crazy Frog", "swamp", 0.2, 2);
    frog.MakeSound();
    frog.Move();
    frog.Print();
    cout << "------------- Roll call-------------------" << endl;
    RollCAll(lion);
    RollCAll(duck);
    RollCAll(frog);
}


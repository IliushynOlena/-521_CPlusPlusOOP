#include <iostream>
using namespace std;

class Cartridge
{
    float volume;
    string color;
public:
    Cartridge():volume(0),color("no color"){}
    Cartridge(float v, string c):volume(v),color(c){}
    void Print()const {
        cout << "Volume : " << volume << endl;
        cout << "Color : " << color << endl;
    }    
};

class Scanner
{
    float scanResolution;
    float height, width;
public:
    Scanner():scanResolution(0),height(0),width(0){}
    Scanner(float s, float h, float w):scanResolution(s),height(h),width(w){}
    void Print()const
    {
        cout << "Scan resolution : " << scanResolution << " dpi " << endl;
        cout << "Height " << height <<  endl;
        cout << "Width " << width <<  endl;
    }
   
};
class Document
{
    string name;
    string format;
    int pages;
public:
    Document():name("no name"), format("format"),pages(0){}
    Document(string n, string f, int p):name(n), format(f),pages(p){}
    void Print()const
    {
        cout << "Name : " << name << endl;
        cout << "Format : " << format << endl;
        cout << "Pages : " << pages << endl;
    }   
};

class Printer
{
    string model;
    //composition
    Cartridge *cartridges;
    int countCartridges;

    Scanner scanner;////default constructor

    //aggregation  
    Document *doc;//nullptr

public:
    Printer() :model("none"), cartridges(nullptr), countCartridges(0),doc(nullptr) {}
    Printer(string m, float scanRes, float h, float w ) :model(m), doc(nullptr)
    {

        countCartridges = 4;
        cartridges = new Cartridge[countCartridges];
        cartridges[0] = Cartridge(100, "Black");
        cartridges[1] = Cartridge(100, "Blue");
        cartridges[2] = Cartridge(100, "Red");
        cartridges[3] = Cartridge(100, "Green");

        scanner = Scanner(300, 30, 50);
    }
    ~Printer()
    {
        if (cartridges != nullptr)
            delete[]cartridges;
    }
    void ScanDocument()const
    {
        cout << "Scanning........" << endl;
        scanner.Print();
    }
    void PrintDocument()const
    {
        cout << "printing......" << endl;
        if (doc == nullptr)
            cout << "No documents to print" << endl;
        else
            doc->Print();
        
    }
    void PrintSettings()const
    {
        for (int i = 0; i < countCartridges; i++)
        {
            cartridges[i].Print();
        }
    }
    void AddDoc(Document *d)
    {
        doc = d;
    }
    void Cancel()
    {
        cout << "Canceled" << endl;
        doc = nullptr;
    }
};

int main()
{
    Printer printer("Samsung",300,30,50);//default constructor
    printer.PrintDocument();
    printer.ScanDocument();
    printer.PrintSettings();

    Scanner sc;

    Document document1("C+ for beginners", "A5", 1521);
    Document document2("Passport", "A5", 2);
    document1.Print();
    document2.Print();
    cout << "-----------------Printing---------------------" << endl;
    printer.AddDoc(&document1);
    printer.Cancel();
    printer.PrintDocument();//
    printer.AddDoc(&document2);
    printer.PrintDocument();

}

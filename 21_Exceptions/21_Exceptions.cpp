#include <iostream>
using namespace std;

float Divide(float a, float b)
{
	float res = 0;
	if (b == 0)
	{
		cout << "Can't divide by zero" << endl;
		throw exception("Study Math. Can't divide by zero!!!!");
	}
	if (b == 5)
	{
		throw 404;
	}
	if (b == 1)
	{
		throw "Divide by 1";
	}
	else
	{
		res = a / b;
		cout << "Res = " << res << endl;
		return res;
	}
	
}
class PasswordInvalidExeption : public exception
{
public:
	PasswordInvalidExeption(const char * mess):exception(mess){}
};
class PasswordSmallException : public exception
{
	int length;
public:
	PasswordSmallException(const char* mess, int lenght) :length(lenght), exception(mess)
	{
	}
	void Message()
	{
		cout << what() << endl;
		cout << "Actual length : " << length << endl;
	}
};
void Login(const char* login, const char* password)
{
	if (strlen(password) < 6)
		//cout << "To small password" << endl;
		throw PasswordSmallException("To small password", strlen(password));
	if (!isalpha(login[0]) || !isupper(login[0]))
		//cout << "login is invalid" << endl;
		throw exception("login is invalid");
	if (!isalpha(password[0]) || !islower(password[0]))
		//cout << "Passworrd invalid" << endl;
		throw PasswordInvalidExeption("Passworrd invalid");

	cout << "Loading..........." << endl;

}
int main()
{
	char login[100];
	char password[100];
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter login : "; cin >> login;
		cout << "Enter password : "; cin >> password;
		try
		{
			Login(login, password);
		}
		catch (PasswordSmallException ex)
		{
			cout << "Password length must be more than 6 letter" << endl;
			cout << ex.what() << endl;
		}
		catch (PasswordInvalidExeption ex)
		{
			cout << "First letter must be small" << endl;
			cout << ex.what() << endl;
		}
		catch (exception ex)
		{
			cout << ex.what() << endl;
		}
		
	}
	//exception try except finaly raise
	//exception try catch finally throw
	/*float a, b;
	cout << "Enter a and b : ";
	cin >> a >> b;
	try
	{
		float res = Divide(a, b);
		cout << "Res = " << res << endl;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	catch (int ex)
	{
		cout << ex << endl;
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}
	catch (...)
	{
		cout << "Unknown exeption" << endl;
	}*/





}


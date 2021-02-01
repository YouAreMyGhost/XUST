#include<iostream>	
using namespace std;

void Func(int a = 11, int b = 22, int c = 33)
{
	cout << "a=" << a <<" " ;
	cout << "b=" << b <<" " ;
	cout << "c=" << c <<" " ;
	cout << endl;
}
//int add(int a, int b)
//{
//	//cout<<a + b<<endl;
//	return a + b;
//}


int add(int a, int b, int c)
{
	return a + b + c;
}

double add(double a, double b, double c)
{
	return a + b + c;
}
int main()
{
	cout << add(1, 2, 3) << endl;
	cout << add(1.1, 2.2, 3.3) << endl;
	return 0;
}                                                                                         
#include<iostream>
using namespace std;
//class Date
//{
//public:
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//
//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 以下测试函数能通过编译吗？
//void Test()
//{
//	Date d1;
//}
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//	p->Show();
//}
//int main()
//{
//	Date d1, d2;
//	d1.SetDate(2020, 5, 1);
//	d2.SetDate(2021, 7, 1);
//	d1.Display();
//	d2.Display();
//	return 0;
//}
class A
{
public:
	~A()
	{
		cout << "~A()" << endl;

	}
	void PrintA()
	{
		cout << _a << endl;
	}

	void Show()
	{
		cout << "Show" << endl;
	}
private:
	int _a;
};
class Date
{
public:
	/*Date(int year, int month, int day)
	{
		cout << "Date(int year, int month, int day)" << endl;
		_year = year;
		_month = month;
		_day = day;
	}*/
	/*Date()
	{
		cout << "Date()" << endl;
		_year = 2020;
		_month = 3;
		_day = 3;
	}*/
	~Date()
	{
		cout << "~Date()" << endl;
	}
	void SetDate(int year, int month, int day)
	{
		cout << "SetDate(int year, int month, int day)" << endl;

		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	A _a;
	int _year; // 年
	int _month; // 月
	int _day; // 日
};

int main()
{
	Date d1;
	return 0;
}
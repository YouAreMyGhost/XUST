#include <iostream>
using namespace std;

class Date
{
public:
	int* GetMonthDay()
	{
		static int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (_year % 4 == 0 || (_year % 400 == 0 && !(_year % 100==0)))
		{
			a[2]=29;
		}
		return a;
	}
	Date(int year = 2000, int month = 1, int day = 1)
	{
		cout << "Date()" << endl;
		_year = year;
		_month = month;
		_day = day;
	}
	Date(Date& d)
	{
		cout << "Date(const)" << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	bool operator>(Date &d) 
	{
		// return _year > d._year || _month > d._month || _day > d._day;
		if (_year > d._year)
		{

		}
	}
	Date operator+(int day)
	{
		int a[13] = ;
		while (_day <= a[_year])
		{

		}
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	Date d2(2000, 2, 3);
	cout<<d1.operator>(d2)<<endl;

	return 0;
}
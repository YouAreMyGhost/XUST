#include <iostream>
using namespace std;

class Date
{
public:
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl ;
	}
	int GetMonthDay(int year,int month)
	{
		static int dayArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int days = dayArr[month];
		if (month==2 && (year % 4 == 0 && year % 100 == 0) || year % 400 == 0 )
		{
			dayArr[2]=29;
		}
		return days;
	}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	
	//判断两个日期是否同一天
	bool operator==(Date& d)
	{
		return d._year == _year && d._month == _month && d._day == _day;
	}
	bool operator!=(Date& d)
	{
		return !(*this==d);
	}
	//判断两个日期的先后
	bool operator>(Date &d) 
	{
		//return _year > d._year || _month > d._month || _day > d._day;
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
				return true;
		}
		else if (_year == d._year&& _month == d._month)
		{
			if (_day > d._day)
				return true;
		}

		return false;
	}
	bool operator<(Date& d)
	{
		//return _year > d._year || _month > d._month || _day > d._day;
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month < d._month)
				return true;
		}
		else if (_year == d._year && _month == d._month)
		{
			if (_day < d._day)
				return true;
		}

		return false;
	}
	//某日期在某天后的日期
	Date operator+=(int day)
	{
		//cout << "这一天" << day << "天后的日期为";
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		
		return *this;
	}
	//某日期在某天后的日期
	Date operator-=(int day)
	{
		_day -= day;
		_month -= 1;
		while (_day < 1)
		{
			_day+= GetMonthDay(_year, _month);
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 12;
			}
		}
		_month += 1;
		return *this;
	}
	int operator-(Date& d)
	{
		Date max = *this, min = d;
		//cout << *this << "与" << min << "相差";
		int flag = 1;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int n = 0;
		while (min != max)
		{
			++n;
			min+=1;
		}
		return n * flag;
	}
private:
	int _year;
	int _month; 
	int _day;
};
int main()
{
	Date d1(2021,2,4);
	d1.Print();
	d1 += 100;
	d1.Print();
	Date d2(2021, 2, 4);
	d2 -= 200;
	d2.Print();
	cout << d1 - d2 << endl;
	return 0;
}
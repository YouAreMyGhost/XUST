#pragma once 
#include <iostream>
using namespace std;

class Date
{
public:
	//打印日期
	void Print();
	//获取每个月的天数
	int GetMonthDay(int year, int month);
	//构造函数
	Date(int year, int month, int day);
	//拷贝构造函数
	Date(const Date& d);

	//判断两个日期是否同一天
	bool operator==(Date& d);
	bool operator!=(Date& d);

	//判断两个日期的先后
	bool operator>(Date& d);
	bool operator<(Date& d);
	bool operator<=(Date& d);
	bool operator>=(Date& d);


	//某日期在某天后的日期
	Date operator+=(int day);
	//某日期在某天后的日期
	Date operator-=(int day);
	//日期减日期所得天数
	int operator-(Date& d);
	
private:
	int _year;
	int _month;
	int _day;
};
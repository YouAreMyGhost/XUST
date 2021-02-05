#pragma once 
#include <iostream>
using namespace std;

class Date
{
public:
	//��ӡ����
	void Print();
	//��ȡÿ���µ�����
	int GetMonthDay(int year, int month);
	//���캯��
	Date(int year, int month, int day);
	//�������캯��
	Date(const Date& d);

	//�ж����������Ƿ�ͬһ��
	bool operator==(Date& d);
	bool operator!=(Date& d);

	//�ж��������ڵ��Ⱥ�
	bool operator>(Date& d);
	bool operator<(Date& d);
	bool operator<=(Date& d);
	bool operator>=(Date& d);


	//ĳ������ĳ��������
	Date operator+=(int day);
	//ĳ������ĳ��������
	Date operator-=(int day);
	//���ڼ�������������
	int operator-(Date& d);
	
private:
	int _year;
	int _month;
	int _day;
};
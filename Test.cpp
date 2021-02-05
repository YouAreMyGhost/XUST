#include"Date.h"
int main()
{
	Date d1(2000, 3, 30);
	d1.Print();
	cout << "该日期10000天后为";
	d1 += 10000;
	d1.Print();
	Date d2(2021, 2, 5);
	d2.Print();
	cout << "该日期200天前为";
	d2 -= 200;
	d2.Print();
	putchar('\n');

	Date d3(2000, 3, 30);
	Date d4(2021, 2, 5);
	d3.Print();
	d4.Print();
	cout << "上面两天相差"<< d4 - d3 << "天" << endl;
}
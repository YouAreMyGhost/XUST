#include "string.h"

int main()
{
	mbf::string s1("1234");

	//bit::string::iterator it = s.begin();
	auto it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
 ///
 /// @file    lotto.cpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-10 07:45:48
 ///
 
#include <iostream>
using std::cout;
using std::endl;
double probability(unsigned numbers, unsigned picks);

int main()
{
	using namespace std;
	double total, choices;
	cout << "enter the number of choices on the game card and\n"
		"the number picks allowed:\n";
	while((cin >> total >>choices ) && choices <=total)
	{
		cout << "you have one chance in";
		cout << probability(total,choices);
		cout << "of winning.\n";
		cout << "Next two numbers (q to quit):";
	}
	cout << "bye\n";
	return 0;
}

// the following function calculates the probability of picking picks
// numbers correctly from number choices

double probability (unsigned numbers, unsigned picks)
{
	double result=1.0; //here comes some local variables

	double n;
	unsigned p;

	for (n=numbers, p=picks; p>0;n--, p--)
		result =result*n/p;
	return result;
}

#include <iostream>
#include "Pile.h"

void main()
{
	Pile<int> myNumbers;
	myNumbers.Toss(8);
	myNumbers.Toss(8);
	myNumbers.Toss(8);
	myNumbers.Toss(8);
	myNumbers.Toss(8);
	myNumbers.Toss(8);

	while (myNumbers.getCount() > 0)
	{
		std::cout << myNumbers.Burn() << std::endl;
	}

	Pile<double> myNumbers2;
	Pile<Pile<int>> stuff;
	stuff.Toss(myNumbers);
	stuff.Toss(myNumbers);
}
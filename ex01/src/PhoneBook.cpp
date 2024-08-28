#include "../include/PhoneBook.hpp"
#include <iostream>

using namespace std;
void	displayMain()
{
	cout << "Choose one of the numbers below: " << endl;
	cout << "1 - ADD" << endl;
	cout << "2 - SEARCH" << endl;
	cout << "3 - EXIT" << endl;
}

int	main()
{
	int	option = 0;
	while (1)
	{
		displayMain();
		cin >> option;
		if (option == 3)
			break;
	}
	return (0);
}

#include "class.hpp"
int main()
{
	int cntrl = 1;
	int ch = 0;
	cout << "Create massive with N elements - 1" << endl;
	cout << "Add element to the end of massive - 2" << endl;
	cout << "Add element to the position with i index - 3" << endl;
	cout << "Get the pointer of element with i index - 4" << endl;
	cout << "Delete element of massive by its index - 5" << endl;
	cout << "Get the number of elements of massive - 6" << endl;
	cout << "Set new length of massive - 7" << endl;
	cout << "Get index of element by its value - 8" << endl;
	cout << "Sort massive in ascending order - 9" << endl;
	cout << "Sort massive in descending order - 10" << endl;
	cout << "Quit - 0" << endl;
	while (cntrl != 0)
	{
		cout << "Enter the command:";
		cin >> cntrl;
		if (cntrl == 1)
		{
			ch = 1;
		}
		if (ch == 0)
		{
			cout << "You haven't created a massive yet!" << endl;
		}
		else
		{
			if (cntrl == 2)
			{
			}
			if (cntrl == 3)
			{
			}
			if (cntrl == 4)
			{

			}
			if (cntrl == 5)
			{
			}
			if (cntrl == 6)
			{
			}
			if (cntrl == 7)
			{
			}
			if (cntrl == 8)
			{
			}
			if (cntrl == 9)
			{
			}
			if (cntrl == 10)
			{
			}
		}
		if ((cntrl < 0) || (cntrl > 10))
		{
			cout << "Wrong command!" << endl;
		}
	}
}
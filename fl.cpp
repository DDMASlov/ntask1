#include "class.hpp"
int main()
{
	if (autotest() == 0)
	{

		int cntrl = 1;
		size_t N;
		cout << "Enter the number N of elements of massive:";
		cin >> N;
		MasList l(N);
		cout << "Add element to the end of massive - 1" << endl;
		cout << "Add element to the position with i index - 2" << endl;
		cout << "Get the pointer of element with i index - 3" << endl;
		cout << "Delete element of massive by its index - 4" << endl;
		cout << "Get the number of elements of massive - 5" << endl;
		cout << "Set new length of massive - 6" << endl;
		cout << "Get index of element by its value - 7" << endl;
		cout << "Sort massive in ascending order - 8" << endl;
		cout << "Get the massive - 9" << endl;
		cout << "Show commands again - 10" << endl;
		cout << "Quit - 0" << endl;
		while (cntrl != 0)
		{
			cout << "Enter the command:";
			cin >> cntrl;
			if (cntrl == 1)
			{
				double chislo;
				cout << "Enter the number:";
				cin >> chislo;
				l.pushback(chislo);
			}
			if (cntrl == 2)
			{
				double chislo;
				size_t ind;
				cout << "Enter element:";
				cin >> chislo;
				cout << "Enter index(starts form 0):";
				cin >> ind;
				l.pushind(chislo, ind);
			}
			if (cntrl == 3)
			{
				size_t ind;
				cout << "Enter the index of element:";
				cin >> ind;
				double* adr = l.getadr(ind);
				if (adr == nullptr)
					cout << "Wrong index!!" << endl;
				else
					cout << "Adr = " << adr << endl;
			}
			if (cntrl == 4)
			{
				size_t ind;
				cout << "Enter the index(starts form 0):";
				cin >> ind;
				l.delbyind(ind);
			}
			if (cntrl == 5)
			{
				cout << "Kolvo elementov: " << l.klel() << endl;
			}
			if (cntrl == 6)
			{
				size_t lng;
				cout << "Enter new length:";
				cin >> lng;
				if (lng == 0)
					cout << "Wrong length" << endl;
				else
					l.setnewl(lng);
			}
			if (cntrl == 7)
			{
				double ch;
				cout << "Enter the element:";
				cin >> ch;
				cout << "First adress of number :" << l.findchislo(ch) << endl;
			}
			if (cntrl == 8)
			{
				l.sort();
			}
			if (cntrl == 9)
			{
				cout << l;
			}
			if (cntrl == 10)
			{
				cout << "Add element to the end of massive - 1" << endl;
				cout << "Add element to the position with i index - 2" << endl;
				cout << "Get the pointer of element with i index - 3" << endl;
				cout << "Delete element of massive by its index - 4" << endl;
				cout << "Get the number of elements of massive - 5" << endl;
				cout << "Set new length of massive - 6" << endl;
				cout << "Get index of element by its value - 7" << endl;
				cout << "Sort massive in ascending order - 8" << endl;
				cout << "Get the massive - 9" << endl;
				cout << "Show commands again - 10" << endl;
				cout << "Quit - 0" << endl;
			}
			if ((cntrl < 0) || (cntrl > 10))
			{
				cout << "Wrong command!" << endl;
			}
		}
		return 0;
	}
	else
		return 1;
}
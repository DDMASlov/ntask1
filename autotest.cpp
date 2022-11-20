#include "autotest.hpp"
int autotest()
{
	if (autotest1() && autotest2() && autotest3() == 1)
	{
		cout << "Autotest passed!!" << endl;
		return 0;
	}
	else
	{
		cout << "Autotest failed!!!" << endl;
		return 1;
	}
}
int autotest1()
{
	double* p = new double[3];
	size_t N = 2;
	p[0] = 4;
	p[1] = 5;
	p[2] = 4;
	MasList l(N);
	l.pushback(p[0]);
	l.pushback(p[1]);
	l.pushback(p[2]);
	l.sort();
	p[1] = 4;
	p[2] = 5;
	if (l.compare(p, 3))
	{
		cout << "Autotest1 passed!!" << endl;
		delete[] p;
		return 1;
	}
	else
	{
		cout << "Autotest1 failed!!" << endl;
		delete[] p;
		return 0;
	}
}
int autotest2()
{
	double* p = new double[3];
	size_t N = 2;
	p[0] = 4;
	p[1] = 5;
	p[2] = 4;
	MasList l(N);
	l.pushback(p[0]);
	l.pushback(p[1]);
	l.pushback(p[2]);
	l.delbyind(2);
	if (l.compare(p, 2))
	{
		cout << "Autotest1 passed!!" << endl;
		delete[] p;
		return 1;
	}
	else
	{
		cout << "Autotest1 failed!!" << endl;
		delete[] p;
		return 0;
	}

}
int autotest3()
{
	double* p = new double[3];
	size_t N = 2;
	p[0] = 4;
	p[1] = 5;
	p[2] = 4;
	MasList l(N);
	l.pushback(p[0]);
	l.pushback(p[1]);
	l.pushback(p[2]);
	p[1] = 8;
	l.pushind(p[1], 1);
	if (l.compare(p, 3))
	{
		cout << "Autotest1 passed!!" << endl;
		delete[] p;
		return 1;
	}
	else
	{
		cout << "Autotest1 failed!!" << endl;
		delete[] p;
		return 0;
	}
}
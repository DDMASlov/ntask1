#include "class.hpp"
MasList::MasList(size_t sz)
{
	t.el = new double[sz];
	t.emp = new int[sz];
	for (size_t i = 0; i < sz; i++)
		t.emp[i] = 0;
	t.size = sz;
	cur = &t;
}
MasList::~MasList()
{
	GoToBegin();
	while (!IsEmpty())
		DelNext();
}
void MasList::DelNext()
{
	if (cur->next != nullptr)
	{
		ElList* p = cur->next;
		delete[] p->el;
		delete[] p->emp;
		cur->next = cur->next->next;
		delete p;
	}
}
void MasList::GoToBegin()
{
	cur = &t;
}
void MasList::GoToLast()
{
	while (cur->next != nullptr)
		cur = cur->next;
}
void MasList::AddEl()
{
	GoToLast();
	ElList* p = new ElList;
	p->size = cur->size;
	p->el = new double[p->size];
	p->emp = new int[p->size];
	for (size_t i = 0; i < p->size; i++)
		p->emp[i] = 0;
	cur->next = p;
	p->next = nullptr;
}
void MasList::GoToNext()
{
	if (cur->next != nullptr)
	{
		cur = cur->next;
	}
}
size_t MasList::kolvoel()
{
	size_t shet = 0;
	for (size_t i = 0; i < cur->size; i++)
	{
		if (cur->emp[i] == 1)
			shet++;
	}
	return shet;
}
size_t MasList::klel()
{
	size_t shet = 0;
	size_t dl = dlinasp();
	GoToBegin();
	for (size_t i = 0; i < dl; i++)
	{
		shet += kolvoel();
		GoToNext();
	}
	return shet;
}
void MasList::setnewl(size_t lngth)
{
	if (lngth != cur->size)
	{
		size_t dl = dlinasp();
		size_t kolvo = 0;
		GoToBegin();
		for (size_t i = 0; i < dl; i++)
		{
			kolvo += kolvoel();
			GoToNext();
		}
		double* p = new double[kolvo];
		GoToBegin();
		size_t shet = 0;
		for (size_t i = 0; i < dl; i++)
		{
			for (size_t j = 0; j < cur->size; j++)
			{
				if (cur->emp[j] == 1)
				{
					p[shet] = cur->el[j];
					shet++;
				}
			}
			GoToNext();
		}
		remake(lngth, kolvo, p);
	}
}
void MasList::remake(size_t lngth, size_t kolvo, double* p)
{
	size_t dl = dlinasp();
	GoToBegin();
	for (size_t i = 0; i < dl; i++)
	{
		double* t = new double[lngth];
		int* mpty = new int[lngth];
		cur->size = lngth;
		for (size_t j = 0; j < lngth; j++)
			mpty[j] = 0;
		delete[] cur->emp;
		delete[] cur->el;
		cur->el = t;
		cur->emp = mpty;
		GoToNext();
	}
	if (kolvo >= dl * lngth)
	{
		size_t razn = kolvo / lngth - dl;
		for (size_t i = 0; i < razn + 1; i++)
		{
			AddEl();
		}
		size_t dl = dlinasp();
		GoToBegin();
		for (size_t i = 0; i < dl - 1; i++)
		{
			for (size_t j = 0; j < lngth; j++)
			{
				cur->el[j] = p[i * lngth + j];
				cur->emp[j] = 1;
			}
			GoToNext();
		}
		for (size_t i = 0; i < kolvo - (dl - 1) * lngth; i++)
		{
			cur->el[i] = p[(dl - 1) * lngth + i];
			cur->emp[i] = 1;
		}
	}
	else
	{
		size_t dl = dlinasp();
		size_t ch = 0;
		if (kolvo % lngth != 0)
		{
			ch = 1;
		}
		size_t razm = dl - (kolvo / lngth + ch);
		if (razm != 0)
		{
			GoToBegin();
			for (size_t i = 0; i < razm; i++)
			{
				DelNext();
			}
		}
		dl = dlinasp();
		GoToBegin();
		for (size_t i = 0; i < dl - 1; i++)
		{
			for (size_t j = 0; j < lngth; j++)
			{
				cur->el[j] = p[i * lngth + j];
				cur->emp[j] = 1;
			}
			GoToNext();
		}
		for (size_t i = 0; i < kolvo - (dl - 1) * lngth; i++)
		{
			cur->el[i] = p[(dl - 1) * lngth + i];
			cur->emp[i] = 1;
		}
	}
}
void MasList::delbyind(size_t ind)
{
	size_t dl = dlinasp();
	size_t kl = cur->size * dl;
	if (ind >= kl)
	{
		cout << "Index is greater than the number of elemets!" << endl;
	}
	else
	{
		GoToBegin();
		for (size_t i = 0; i < ind / cur->size; i++)
		{
			GoToNext();
		}
		cur->emp[ind % cur->size] = 0;
		if (cur != &t)
		{
			if (cur->next == nullptr)
			{
				if (kolvoel() == 0)
				{
					ElList* p = cur;
					GoToBegin();
					while (cur->next != p)
						GoToNext();
					DelNext();
				}
			}
		}
	}
}
size_t MasList::firstfree()
{
	size_t shet = 0;
	for (size_t i = 0; i < cur->size; i++)
	{
		if (cur->emp[i] == 1)
			shet++;
		else
		{
			i = cur->size;
		}
	}
	return shet;
}
void MasList::pushback(const double ch)
{
	size_t dl = dlinasp();
	size_t check = 0;
	GoToBegin();
	for (size_t i = 0; i < dl; i++)
	{
		if (kolvoel() != cur->size)
		{
			cur->el[firstfree()] = ch;
			cur->emp[firstfree()] = 1;
			i = dl;
			check = 1;
		}
		GoToNext();
	}
	if (check == 0)
	{
		AddEl();
		GoToLast();
		cur->el[firstfree()] = ch;
		cur->emp[firstfree()] = 1;
	}
}
void MasList::pushind(const double ch, size_t ind)
{
	size_t dl = dlinasp();
	GoToBegin();
	if (ind < cur->size)
	{
		cur->el[ind] = ch;
		cur->emp[ind] = 1;
	}
	else
	{
		if (ind < cur->size * dl)
		{
			size_t cloe = ind / cur->size;
			GoToBegin();
			for (size_t i = 0; i < cloe; i++)
				GoToNext();
			cur->el[ind % cur->size] = ch;
			cur->emp[ind % cur->size] = 1;
		}
		else
		{
			int sm = ind / cur->size + 1;
			sm = sm - dl;
			GoToLast();
			for (int i = 0; i < sm; i++)
			{
				AddEl();
			}
			GoToBegin();
			sm = ind / cur->size;
			for (int i = 0; i < sm; i++)
			{
				GoToNext();
			}
			cur->el[ind % cur->size] = ch;
			cur->emp[ind % cur->size] = 1;
		}
	}
}
size_t MasList::dlinasp()
{
	size_t shet = 1;
	GoToBegin();
	while (cur->next != nullptr)
	{
		shet++;
		GoToNext();
	}
	return shet;
}
double* MasList::getadr(size_t ind)
{
	size_t dl = dlinasp();
	if (ind >= dl * cur->size)
	{
		return nullptr;
	}
	else
	{
		if (ind > cur->size * dlinasp())
		{
			cout << "The index is greater than the number of massive elements!!";
			return nullptr;
		}
		else
		{
			size_t cloe = ind / cur->size;
			GoToBegin();
			for (size_t i = 0; i < cloe; i++)
				GoToNext();
			double* adr = &cur->el[ind % cur->size];
			return adr;
		}
	}
}
int MasList::IsEmpty()
{
	return t.next == nullptr;
}
int MasList::findchislo(double ch)
{
	int ind = 0;
	GoToBegin();
	size_t dl = dlinasp();
	for (size_t j = 0; j < dl; j++)
	{
		for (size_t i = 0; i < cur->size; i++)
		{
			if (cur->emp[i] != 0)
			{
				if (fabs(cur->el[i] - ch) < numeric_limits<double>::epsilon())
				{
					return ind;
				}
			}
			ind++;
		}
		GoToNext();
	}
	return -1;
}
ostream& operator<<(ostream& cout, MasList& other)
{
	size_t dl = other.dlinasp();
	other.GoToBegin();
	for (size_t i = 0; i < dl; i++)
	{
		cout << i + 1 << " element of list:" << endl;
		for (size_t j = 0; j < other.cur->size; j++)
		{
			if (other.cur->emp[j] == 0)
				cout << "emp ";
			else
				cout << other.cur->el[j] << " ";
		}
		cout << endl;
		other.GoToNext();
	}
	cout << endl;
	return cout;
}
void MasList::sort()
{
	size_t kl = klel();
	size_t dl = dlinasp();
	size_t shet = 0;
	double* p = new double[kl];
	GoToBegin();
	for (size_t i = 0; i < dl; i++)
	{
		for (size_t j = 0; j < cur->size; j++)
		{
			if (cur->emp[j] == 1)
			{
				p[shet] = cur->el[j];
				shet++;
			}
		}
		GoToNext();
	}
	for (size_t i = 0; i < kl; i++)
	{
		double max = (-1) * (DBL_MAX);
		size_t ind = 0;
		for (size_t j = 0; j < kl - i; j++)
		{
			if (p[j] > max)
			{
				max = p[j];
				ind = j;
			}
		}
		p[ind] = p[kl - 1 - i];
		p[kl - 1 - i] = max;
	}
	GoToBegin();
	shet = 0;
	for (size_t i = 0; i < dl; i++)
	{
		for (size_t j = 0; j < cur->size; j++)
		{
			if (shet < kl)
			{
				cur->el[j] = p[shet];
				cur->emp[j] = 1;
				shet++;
			}
			else
			{
				cur->emp[j] = 0;
			}
		}
		GoToNext();
	}
	delete[] p;
}
bool MasList::compare(double* p, size_t N)
{
	size_t kl = klel();
	if (N == kl)
	{
		size_t shet = 0;
		size_t dl = dlinasp();
		double* t = new double[kl];
		GoToBegin();
		for (size_t i = 0; i < dl; i++)
		{
			for (size_t j = 0; j < cur->size; j++)
			{
				if (cur->emp[j] == 1)
				{
					t[shet] = cur->el[j];
					shet++;
				}
			}
			GoToNext();
		}
		shet = 0;
		for (size_t i = 0; i < N; i++)
		{
			if (fabs(t[i] - p[i]) < numeric_limits<double>::epsilon())
				shet++;
		}
		delete[] t;
		if (shet == N)
			return true;
		else
			return false;
	}
	else
		return false;
}
void MasList::testsort(int rng, size_t kl)
{
	for (size_t i = 0; i < kl; i++)
	{
		srand(time(NULL));
		pushback(pow(-1, rand() % 2) * (rand() % rng));
	}
	unsigned int start, finish;
	start = clock();
	sort();
	finish = clock();
	cout << "Sort time:" << finish - start << endl;
	delete[] cur->el;
	delete[] cur->emp;
	cur->el = nullptr;
	cur->emp = nullptr;
}
void MasList::chempty(size_t ind)
{
	size_t sz = cur->size;
	GoToBegin();
	for (size_t i = 0; i < ind / sz; i++)
	{
		GoToNext();
	}
	cur->emp[ind % cur->size] = 1;
}
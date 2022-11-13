#include "fl.hpp"
class ElList
{
public:
	double* el;
	int* emp;
	size_t size;
	ElList* next;
	ElList()
	{
		el = nullptr;
		emp = nullptr;
		size = 0;
		next = nullptr;
	}
};
class MasList
{
private:
	
	ElList t;
	ElList* cur;
	MasList();
public:
	MasList(size_t sz);
	~MasList();
	friend ostream& operator<<(ostream& cout, MasList& other);
	void DelNext();
	void GoToBegin();
	void GoToLast();
	int IsEmpty();
	void AddEl();
	void GoToNext();
	void pushback(const double ch);
	void pushind(const double ch, size_t ind);
	void delbyind(size_t ind);
	void setnewl(size_t lngth);
	void remake(size_t lngth,size_t kolvo,double* p);
	void sort();
	size_t kolvoel();
	size_t klel();
	size_t firstfree();
	size_t dlinasp();
	bool compare(double* p, size_t N);
	double* getadr(size_t ind);
	int findchislo(double ch);
};
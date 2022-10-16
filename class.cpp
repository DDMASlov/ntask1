#include "class.hpp"
MasList::MasList()
{
	msv = NULL;
	size = 0;
	frst = NULL;
	next = NULL;
}
MasList::MasList(size_t sz)
{
	size = sz;
	msv = new double[size];

}
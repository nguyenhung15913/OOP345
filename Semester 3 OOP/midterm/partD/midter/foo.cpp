// foo.cpp
#include "foo.h"

Foo::Foo(int size, double val)
{

	++(++Foo::m_cntInst);
	m_values = new double[size];
	for (int i = 0u; i < size; ++i)
		this->m_values[i] = val;
	m_size = size;
}
double Foo::getValue(int idx) const
{
	return m_values[idx];
}
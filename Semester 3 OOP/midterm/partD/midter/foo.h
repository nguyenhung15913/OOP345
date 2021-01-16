struct Foo
{
	int m_size;
	double* m_values;
	char m_str[32];
	// counts the number of
	// instances of type Foo
	// that were created
	int m_cntInst  = 0u;
	Foo* xyz;
	Foo(int, double);
	double getValue(int idx) const;
	~Foo()
	{
		delete m_values;
		m_values = nullptr;
		m_size = 0;
		delete m_str;
	}
};

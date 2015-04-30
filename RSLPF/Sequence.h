#ifndef SEQUENCE_H
#define SEQUENCE_H 42

#include <vector>


#ifndef NULL
#define NULL 0
#endif

template<typename T> class Sequence
{
	//array di d vettori
	std::vector<T> data;

public:
	Sequence()
	{
	}
	Sequence& operator =(Sequence& s)
	{
		data.clear();
		unsigned int l = s.getLength();
		for (unsigned int i = 0; i < l; i++)
			data.push_back(s[i]);
		return(*this);
	}
	Sequence(Sequence& s)
	{
		unsigned int l = s.getLength();
		for (unsigned int i = 0; i < l; i++)
			data.push_back(s[i]);
	}
	~Sequence()
	{
		if (data.size() != 0)
			data.clear();
	}


	//Aggiunge un elemento alla sequenza (in fondo) 
	Sequence& operator << (T lvalue)
	{
		data.push_back(lvalue);
		return(*this);
	}

	///Accede ad un membro specifico della sequenza
	T& operator []  (unsigned int i)
	{
		return(data[i]);
	}

	///Ottiene la dimensione della sequenza
	unsigned int getLength()
	{
		return(data.size());
	}
};

#endif
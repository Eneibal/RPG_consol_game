#pragma once
template< typename T>
class dArr
{
private:
	unsigned cap;
	unsigned initialCap;
	unsigned nrOfel;
	T* *arr;

	void expand();
	void initialize(unsigned from_);

public:
	dArr(unsigned size_ = 5);
	dArr(const dArr& obj);
	~dArr();

	T& operator[](const unsigned index_);
	void operator = (const dArr& obj);

	unsigned maxCap();
	unsigned size();
	void push(const T elements_);
	void remove(const unsigned index_, bool ordered_ = false);

};

 template< typename T>
 dArr<T>::dArr(unsigned size_)
 {
	 initialCap = size_;
	 cap = size_;
	 nrOfel = 0;
	 arr = new T * [cap];
	 initialize(0);
 }
template< typename T>
dArr<T>::dArr(const dArr& obj)
{
	initialCap = obj.initialCap;
	cap = obj.cap;
	nrOfel = obj.nrOfel;
	arr = new T * [cap];

	for (size_t i = 0; i < nrOfel; i++)
	{
		arr[i] = new T(*obj.arr[i]);
	}
	initialize(0);
}
template< typename T>
dArr<T>::~dArr()
{
	for (size_t i = 0; i < nrOfel; i++)
	{
		delete arr[i];
	}
	delete[]arr;
}

template< typename T>
T& dArr<T>::operator[](const unsigned index_)
{
	if (index_ <0 || index_ >= nrOfel)
	{
		throw "OUT OF BOUNDS INDEX OPERATOR";
	}
	return *this->arr[index_];
}
template< typename T>
void dArr<T>::operator = (const dArr& obj)
{
	for (size_t i = 0; i < nrOfel; i++)
	{
		delete arr[i];
	}
	delete[]arr;

	initialCap = obj.initialCap;
	cap = obj.cap;
	nrOfel = obj.nrOfel;
	arr = new T * [cap];

	for (size_t i = 0; i < nrOfel; i++)
	{
		arr[i] = new T(*obj.arr[i]);
	}
	initialize(0);
}

template< typename T>
void dArr<T>::expand()
{
	cap *= 2;
	T** tempArra = new T * [cap];
	for (size_t i = 0; i < nrOfel; i++)
	{
		tempArra[i] = arr[i];
	}

	delete[]arr;

	arr = tempArra;

	initialize(nrOfel);

}
template< typename T>
void dArr<T>::initialize(unsigned from_)
{
	for (size_t i = from_; i < cap; i++)
	{
		arr[i] = nullptr;
	}
}

template< typename T>
unsigned dArr<T>::maxCap()
{
	return cap;
}
template< typename T>
unsigned dArr<T>::size()
{
	return nrOfel;
}
template< typename T>
void dArr<T>::push(const T elements_)
{
	if (nrOfel >= cap)
	{
		expand();
	}
	arr[nrOfel++] = new T(elements_);
}
template< typename T>
void dArr<T>::remove(const unsigned index_, bool ordered_ )
{
	if (index_ < 0 || index_ >= nrOfel)
	{
		throw " OUT OF BOUNDS REMOVE";
	}
	if (ordered_)
	{
		delete arr[index_];
		for (size_t i = 0; i < nrOfel-1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[--nrOfel] = nullptr;
	}
	else
	{
		delete arr[index_];

		arr[index_] = arr[nrOfel - 1];
		 
		arr[--nrOfel] = nullptr;
	}
}
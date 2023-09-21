#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include<cstdlib>

template <typename T>
class Array
{
	private:
		T*				mArr;
		unsigned int	mSize;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array&	operator=(const Array& rhs);
		virtual ~Array();

		T&	operator[](const unsigned int idx) const;
		unsigned int	size() const;
};

template <typename T>
Array<T>::Array()
	: mSize(0)
{
	mArr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
	: mSize(n)
{
	mArr = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other)
	: mSize(other.mSize)
{
	mArr = new T[mSize];

	for (unsigned int i = 0; i < mSize; i++) {
		mArr[i] = other.mArr[i];
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& rhs)
{
	if (this == &rhs)
		return *this;

	delete[] mArr;
	mArr = new T[rhs.mSize];
	mSize = rhs.mSize;

	for (unsigned int i = 0; i < mSize; i++) {
		mArr[i] = rhs.mArr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] mArr;
}

template <typename T>
T&	Array<T>::operator[](const unsigned int idx) const
{
	if (idx < 0 || idx > mSize - 1)
		throw std::out_of_range("Out of range!");
	return mArr[idx];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return mSize;
}

#endif

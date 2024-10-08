
#include "Array.hpp"

template<typename T>
Array<T>::Array::Array()
{
	array_size = 0;
	array = NULL;
}

template<typename T>
Array<T>::Array::Array(unsigned int n)
{
	this->array_size = n; 
	if (array_size == 0)
		array = NULL;
	else
		array = new T[n];
}

template<typename T>
Array<T>::Array::~Array()
{
	if (array)
		delete [] array;
}

template<typename T>
Array<T>::Array::Array(const Array& copy)
{
    *this = copy;
}

template<typename T> 
Array<T> &Array<T>::operator=(const Array& copy)
{
    if (this != &copy)
    {
		this->array_size = copy.array_size;
		if (copy.array)
		{
			this->array = new T[array_size];
			for (unsigned int i = 0; i < copy.array_size; i++)
				this->array[i] = copy.array[i];
		}
		else
			this->array = NULL;
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->array_size)
		throw std::out_of_range("Index out of array bounds\n");
	return this->array[index];
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return this->array_size;
}

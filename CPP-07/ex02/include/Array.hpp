#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template<typename T>
class Array
{
	private:
		T				*array;
		unsigned int	array_size;
	public:
		Array();
		~Array();
		Array(const Array& copy);
		Array &operator=(const Array& copy);
		Array(unsigned int n);
		T &operator[](unsigned int n);
		unsigned int	size(const Array) const;
};

#endif

template<typename T>
Array<T>::Array::Array()
{
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
			this->array = new T[array_size];
		else
			this->array = NULL;
		if (copy.array)
			for (unsigned int i = 0; i < copy.array_size; i++)
				this->array[i] = copy.array[i];
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->array_size)
		throw std::out_of_bounds("Index out of array bounds\n");
	return this->array[index];
}

template<typename T>
unsigned int	Array<T>::size(const Array) const
{
	return this->array_size;
}

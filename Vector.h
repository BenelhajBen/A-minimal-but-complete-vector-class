#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template<class T>
class Vector
{
	public:
	
		Vector(); // default constructor
		~Vector(); // destructor
		Vector(const Vector&); // copy constructor
		Vector<T>& operator=(const Vector& other); //assignment operator
		unsigned int GetSize() const; // returns the number of elements in the vector
		unsigned int GetCapacity() const; // returns the capacity of the vector
		bool push_back(const T&); // push back
		void pop(); // remove last element

		T& at(unsigned index) const; // returns the value at the index and does not allow the caller to modify the return value.
		T& at(unsigned index); // returns the value at the index and allows the caller to modify the return value.
		T& operator[](unsigned index); // operator overloading for [] operator allows caller to modify value
		T& operator[](unsigned index) const; // operator overloading for [] operator does not allow the caller to modify the value.

		T& begin() const; // returns the first element in the vector does not modify it.
		T& end() const; // returns the last element in the vector does not modify it.

	
	private:
		T* vect;
        	void copyVector(const Vector<T>& other); // copy vector
		unsigned int capacity; // capacity of vector
		unsigned int size; // number of elements in the vector
		bool grow(); // double the capacity of the vector when full
};
#endif //Vector_h


template<class T>
Vector<T>::Vector()
{
    vect = new T[1];
    capacity = 1;
    size = 0;
}

template <class T>
Vector<T>::~Vector()
{
    delete[] vect;
    vect = nullptr;
}

template <class T>
void Vector<T>::copyVector(const Vector<T>& other) {
    // Delete the memory used by the current vector
    delete[] vect;
    // Allocate new memory for the vector with the capacity of the other vector
    if (T* newVec = new T[other.capacity]) 
    {
        // Copy the elements from the other vector to the new vector
        for (unsigned int i = 0; i < other.size; i++) {
            newVec[i] = other.vect[i];
        }
        // Set the new vector as the current vector
        vect = newVec;
        // Update the capacity and size variables to match the other vector
        capacity = other.capacity;
        size = other.size;
    }
    else
    {
        // If the new operator fails to allocate memory, set the capacity and size to 0
        // and set the vector to nullptr to indicate that the vector is empty
        capacity = 0;
        size = 0;
        vect = nullptr;
    }   
}


template <class T>
Vector<T>::Vector(const Vector<T>& other) {
    copyVector(other);
}


template<class T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if(this == &other)
    {
        return *this;
    }
    copyVector(other);
    return *this;
}

template <class T>
bool Vector<T>::push_back(const T& data)
{
    try
    {
        if(size >= capacity)
        {
            if(!grow())
            {
                delete[] vect;
                capacity = capacity/2;
                vect = new T[capacity];
                return false;
            }
        }
        vect[size] = data;
        size++;
        return true;
    }catch(...)
    {
        return false;
    }
}

template <class T>
void Vector<T>::pop()
{
    if(size == 0)
    {
        return;
    }
    size--;
}

template <class T>
bool Vector<T>::grow()
{

    bool success = false;

    capacity *= 2;
    if(T* newVec = new T[capacity])
    {
        for(std::size_t i =0; i < size; i++)
        {
            newVec[i] = vect[i];
        }

        delete [] vect;
        vect = newVec;

        success = true;
    }
    return success;
}

template <class T>
T& Vector<T>::at(unsigned index) const
{
    if(index < size)
    {
        return vect[index];
    }else
    {
        throw std::out_of_range("Index out of range");
    }
}

template <class T>
T& Vector<T>::at(unsigned index)
{
    if(index < size)
    {
        return vect[index];
    }else
    {
        throw std::out_of_range("Index out of range");
    }
}

template <class T>
unsigned int Vector<T>::GetSize() const
{
    return size;
}

template <class T>
unsigned int Vector<T>::GetCapacity() const
{
    return capacity;
}

template <class T>
T& Vector<T>::operator[](unsigned index) const
{
    if(index < size)
    {
        return vect[index];
    }else
    {
        throw std::out_of_range("Index out of range");
    }
}

template <class T>
T& Vector<T>::operator[](unsigned index)
{
    if(index < size)
    {
        return vect[index];
    }else
    {
        throw std::out_of_range("Index out of range");
    }
}

template <class T>
T& Vector<T>::begin() const
{
    return vect[0];
}

template <class T>
T& Vector<T>::end() const
{
    return vect[size - 1];
}

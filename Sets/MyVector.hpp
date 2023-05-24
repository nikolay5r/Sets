#pragma once
#include <iostream>
#include "Constants.h"

template <typename T>
class MyVector
{
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void resize(size_t capacity);
	void moveFrom(MyVector&& other) noexcept;
	void copyFrom(const MyVector& other);
	void free();

	void upsizeIfNeeded();
	void downsizeIfNeeded();

public:

	MyVector();
	MyVector(size_t capacity);
	MyVector(const MyVector& other);
	MyVector(MyVector&& other) noexcept;

	MyVector& operator=(const MyVector& other);
	MyVector& operator=(MyVector&& other);

	explicit MyVector(size_t capacity);
	void push_back(const T& element);
	void push_back(T&& element);
	T pop_back();
	void erase();
	void clear();
	T pop_at(size_t index);
	void push_at(const T& element, size_t index);
	void push_at(T&& element, size_t index);

	size_t size() const;
	size_t capacity() const;

	bool isEmpty() const;

	T& operator[](size_t index);
	T operator[](size_t index) const;

	~MyVector();
};

template <typename T>
void MyVector<T>::resize(size_t capacity)
{
	this->capacity = capacity;
	T* newData = new T[capacity];

	for (size_t i = 0; i < size; i++)
	{
		newData[i] = std::move(data[i]);
	}

	delete[] data;
	data = newData;
}

template <typename T>
void MyVector<T>::moveFrom(MyVector&& other) noexcept
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;
	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template <typename T>
void MyVector<T>::copyFrom(const MyVector& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];

	for (data i = 0; i < size; i++)
	{
		data[i] = new T(other.data[i]);
	}
}

template <typename T>
void MyVector<T>::free()
{
	if (data)
	{
		delete[] data;
		data = nullptr;
	}
}

template <typename T>
MyVector<T>::MyVector(size_t capacity)
{
	this->capacity = capacity;
	data = new T[capacity];
}


template <typename T>
MyVector<T>::MyVector() : MyVector(constants::INITIAL_CAPACITY) {}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
MyVector<T>::MyVector(size_t capacity)
{
	this->capacity = capacity;
	data = new T[capacity];
}

template <typename T>
void MyVector<T>::push_back(const T& element)
{
	upsizeIfNeeded();
	data[size] = element;
}

template <typename T>
void MyVector<T>::push_back(T&& element)
{
	downsizeIfNeeded();
	data[size] = std::move(element);
}

template <typename T>
T MyVector<T>::pop_back()
{
	if (isEmpty())
	{
		throw std::logic_error("Vector is empty!");
	}

	return data[--size];
}

template <typename T>
void MyVector<T>::erase()
{
	size = 0;
}

template <typename T>
void MyVector<T>::clear()
{
	free();
}

template <typename T>
T MyVector<T>::pop_at(size_t index)
{

}

template <typename T>
void MyVector<T>::push_at(const T& element, size_t index)
{

}

template <typename T>
size_t MyVector<T>::size() const
{
	return size;
}

template <typename T>
size_t MyVector<T>::capacity() const
{
	return capacity;
}

template <typename T>
bool MyVector<T>::isEmpty() const
{
	return size == 0;
}

template <typename T>
T& MyVector<T>::operator[](size_t index)
{
	return data[index];
}

template <typename T>
T MyVector<T>::operator[](size_t index) const
{
	return data[index];
}

template <typename T>
MyVector<T>::~MyVector()
{
	free();
}

template <typename T>
void MyVector<T>::upsizeIfNeeded()
{
	if (size == capacity)
	{
		resize(capacity * constants::RESIZE_COEF);
	}
}

template <typename T>
void MyVector<T>::downsizeIfNeeded()
{

}
#pragma once
#include <iostream>

template <typename DataType>
class MyVector
{
public:
	MyVector();
	MyVector(size_t InitialSize);
	MyVector(const MyVector<DataType>& other);
	MyVector(MyVector<DataType>&& other) noexcept;
	MyVector<DataType>& operator=(const MyVector<DataType>& other);
	MyVector<DataType>& operator=(MyVector<DataType>&& other) noexcept;
	
	void push_back(const DataType& elem);
	void pop_back();
	void clear();

	size_t size() const;
	size_t capacity() const;

	const DataType& back() const;
	DataType& back();
	

	bool empty() const;

	const DataType& operator[](size_t index) const;
	DataType& operator[](size_t index);

	~MyVector();
private:
	char* data;
	size_t _size;
	size_t _capacity;

	void resize();
	void free();
	void CopyFrom(const MyVector<DataType>& other); 
	void MoveFrom(MyVector<DataType>&& other);
};

template <typename DataType>
void MyVector<DataType>::resize()
{
	size_t newCap = (_capacity == 0) ? 1 : _capacity * 2;
	char* newData = new (std::nothrow) char[newCap * sizeof(DataType)];
	if (newData == nullptr) throw std::bad_alloc();
	for (size_t i = 0; i < _size; i++)
	{
		new (newData + i * sizeof(DataType)) DataType(std::move(*reinterpret_cast<DataType*>(data + i *sizeof(DataType))));
		reinterpret_cast<DataType*>(data + i * sizeof(DataType))->~DataType();
	}
	delete[] data;
	this->data = newData;
	this->_capacity = newCap;
}

template <typename DataType>
void MyVector<DataType>::free()
{
	if (data != nullptr)
	{
		for (size_t i = 0; i < _size; i++)
		{
			reinterpret_cast<DataType*>(data + i * sizeof(DataType))->~DataType();
		}
		delete[] data;
	}
	data = nullptr;
	_size = 0;
	_capacity = 0;
}

template <typename DataType>
void MyVector<DataType>::CopyFrom(const MyVector<DataType>& other)
{
	this->data = new (std::nothrow) char[other._capacity * sizeof(DataType)];
	if (data == nullptr) throw std::bad_alloc();

	for (size_t i = 0; i < other._size; i++)
	{
		new (this->data + i * sizeof(DataType)) DataType(*reinterpret_cast<DataType*>(other.data + i * sizeof(DataType)));
	}

	this->_capacity = other._capacity;
	this->_size = other._size;
}

template <typename DataType>
void MyVector<DataType>::MoveFrom(MyVector<DataType>&& other)
{
	this->data = other.data;
	this->_size = other._size;
	this->_capacity = other._capacity;

	other.data = nullptr;
	other._size = 0;
	other._capacity = 0;

}


template <typename DataType>
MyVector<DataType>::MyVector() : data(nullptr), _size(0), _capacity(0) 
{

}

template <typename DataType>
MyVector<DataType>::MyVector(size_t InitialSize) : _size(InitialSize), _capacity(InitialSize)
{
	data = new char[InitialSize * sizeof(DataType)];
}

template <typename DataType>
MyVector<DataType>::MyVector(const MyVector<DataType>& other)
{
	CopyFrom(other);
}

template <typename DataType>
MyVector<DataType>::MyVector(MyVector<DataType>&& other) noexcept
{
	MoveFrom(std::move(other));
}

template <typename DataType>
MyVector<DataType>& MyVector<DataType>::operator=(const MyVector<DataType>& other)
{
	if (this != &other)
	{
		free();
		CopyFrom(other);
	}
	return *this;
}

template <typename DataType>
MyVector<DataType>& MyVector<DataType>::operator=(MyVector<DataType>&& other) noexcept
{
	if (this != &other)
	{
		free();
		MoveFrom(std::move(other));
	}
	return *this;

}

template <typename DataType>
void MyVector<DataType>::push_back(const DataType& elem)
{
	if (_size == _capacity) resize();
	new (data + _size * sizeof(DataType)) DataType(elem);
	_size++;
}

template <typename DataType>
void MyVector<DataType>::pop_back()
{
	if (_size == 0) throw std::underflow_error("Vector is empty. ");
	_size--;
	reinterpret_cast<DataType*>(data + _size * sizeof(DataType))->~DataType();
}

template <typename DataType>
const DataType& MyVector<DataType>::operator[](size_t index) const
{
	if (index >= _size) throw std::out_of_range("Index out of range");
	return *reinterpret_cast<const DataType*>(data + index * sizeof(DataType));
}

template <typename DataType>
DataType& MyVector<DataType>::operator[](size_t index)
{
	if (index >= _size) throw std::out_of_range("Index out of range");
	return *reinterpret_cast<DataType*>(data + index * sizeof(DataType));
}


template <typename DataType>
MyVector<DataType>::~MyVector() 
{
	free();
}

template <typename DataType>
size_t MyVector<DataType>::size() const
{
	return _size;
}

template <typename DataType>
size_t MyVector<DataType>::capacity() const
{
	return _capacity;
}

template <typename DataType>
void MyVector<DataType>::clear()
{
	free();
}

template <typename DataType>
bool MyVector<DataType>::empty() const{
	return _size == 0;
}

template <typename DataType>
DataType& MyVector<DataType>::back() {
    if (_size == 0)
        throw std::underflow_error("Vector is empty.");
    return *reinterpret_cast<DataType*>(data + (_size - 1) * sizeof(DataType));
}

template <typename DataType>
const DataType& MyVector<DataType>::back() const {
    if (_size == 0)
        throw std::underflow_error("Vector is empty.");
    return *reinterpret_cast<const DataType*>(data + (_size - 1) * sizeof(DataType));
}
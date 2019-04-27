#pragma once
#include <iostream>
#include <string>

using namespace std;
template<typename Type>

class Vector
{
private:
	Type* ptr;
	int size;
public:
	Vector()
	{
		ptr = NULL;
		size = 0;
	}
	Vector(int size, Type num)
	{
		ptr = new Type[size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = num;
		}
		this->size = size;
	}
	int VGetSize()
	{
		return size;
	}
	int VGetElementByIndex(int index)
	{
		if (index < size && size >= 0)
		{
			return ptr[index];
		}
		else
		{
			throw("Error");
		}
	}
	void VShowAllElements()
	{
		cout << "{";
		for (int i = 0; i < size; i++)
		{
			cout << ptr[i] << ",";
		}
		cout << "}"<<endl;
	}
	void VSetElementByIndex(Type num, int index)
	{
		
		if (index < size && size >= 0)
		{
			ptr[index] = num;
		}
		else
		{
			throw("Error");
		}
		
	}
	void VSort()
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (ptr[j] > ptr[j + 1])
				{
					swap(ptr[j], ptr[j + 1]);
				}
			}
		}
	}
	bool VSearchValue(Type value)
	{
		for (int i = 0; i < size; i++)
		{
			if (ptr[i] == value)
			{
				return true;
			}
		}
		return false;
	}
	void VAddNewElement(Type element)
	{
		Type *ptr_buf = new Type[size + 1];
		for (int i = 0; i < size; i++)
		{
			ptr_buf[i] = ptr[i];
		}
		ptr_buf[size] = element;
		delete[] ptr;
		ptr = ptr_buf;
		size++;
	}
	void VRemoveLastElement()
	{
		Type *ptr_buf = new Type[size - 1];
		for (int i = 0; i < size - 1; i++)
		{
			ptr_buf[i] = ptr[i];
		}
		delete[] ptr;
		ptr = ptr_buf;
		size--;
	}
	void VRemoveElementByIndex(int index)
	{
		Type *ptr_buf = new Type[size - 1];
		for (int i = 0; i < index; i++)
		{
			ptr_buf[i] = ptr[i];
		}
		for (int i = index; i < size - 1; i++)
		{
			ptr_buf[i] = ptr[i + 1];
		}
		delete[] ptr;
		ptr = ptr_buf;
		size--;
	}  
	void VInsertElementbyIndex(int index, Type value)
	{
		Type *ptr_buf = new Type[size + 1];
		for (int i = 0; i < index; i++)
		{
			ptr_buf[i] = ptr[i];
		}
		ptr_buf[index] = value;
		for (int i = index+1; i < size + 1; i++)
		{
			ptr_buf[i] = ptr[i-1];
		}
		delete[] ptr;
		ptr = ptr_buf;
		size++;
	}
	void operator++ ()
	{
		for (int i = 0; i < size; i++)
		{
			ptr[i]++;
		}
	}
	int& operator[] (Type i)
	{
		return ptr[i];
	}
	~Vector()
	{
		delete[] ptr;
	}
};
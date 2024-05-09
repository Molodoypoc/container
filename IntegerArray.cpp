#include "IntegerArray.h"

IntegerArray::IntegerArray(size_t length) {
    array = new int[length] {};
    size = length;
}

IntegerArray::IntegerArray(const IntegerArray& other) {
    array = new int[other.size] {};
    size = other.size;
    for (int i = 0; i < size; i++) {
        array[i] = other.array[i];
    }
}


IntegerArray::~IntegerArray() {
    delete[] array;
    size = 0;
}

int IntegerArray::getSize() const {
    return size;
}

const int& IntegerArray::getElement(size_t index) const {
    if (index >= size)
    {
        throw bad_range();
    }

    return array[index];
}

int& IntegerArray::getElement(size_t index) {
    if (index >= size)
    {
        throw bad_range();
    }

    return array[index];
}

int& IntegerArray::operator[](size_t index) {
    return getElement(index);
}

const int& IntegerArray::operator[](size_t index) const {
    return getElement(index);
}

IntegerArray& IntegerArray::operator=(const IntegerArray& other) {
    delete[] array;
    size = 0;
    array = new int[other.size] {};
    size = other.size;
    for (int i = 0; i < size; i++) {
        array[i] = other.array[i];
    }
    return *this;
}

void IntegerArray::insert(size_t index, int value) {
    if (index >= size)
    {
        throw bad_range();
    }
    int* newmassiv = new int[size+1] {};
    for (int i = 0; i < index; ++i) {
        newmassiv[i] = array[i];
    }
    newmassiv[index] = value;
    for (int i = index; i < size; ++i) {
        newmassiv[i+1] = array[i];
    }
    delete[] array;
    array = newmassiv;
    ++size;
}

void IntegerArray::inserts(int value) {
    int* newmassiv = new int[size+1] {};
    newmassiv[0] = value;
    for (int i = 0; i < size; ++i) {
        newmassiv[i+1] = array[i];
    }
    delete[] array;
    array = newmassiv;
    ++size;
}

void IntegerArray::inserte(int value) {
    int* newmassiv = new int[size+1] {};
    newmassiv[size] = value;
    for (int i = 0; i < size; ++i) {
        newmassiv[i] = array[i];
    }
    delete[] array;
    array = newmassiv;
    ++size;
}

void IntegerArray::resize(size_t new_size) {
    int* temp = new int[new_size] {};
    int num = size;
    if (num > new_size){
        num = new_size;
    }
    for (int i = 0; i < num; i++) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    size = new_size;
}

void IntegerArray::remove(size_t index) {
    if (index >= size || size == 0)
    {
        throw bad_length();
    }
    int* newmassiv = new int[size-1] {};
    for (int i = 0; i < index; ++i) {
        newmassiv[i] = array[i];
    }
    for (int i = index+1; i < size; ++i) {
        newmassiv[i-1] = array[i];
    }
    delete[] array;
    array = newmassiv;
    --size;
}



#ifndef CLAB3_DYNAMICARRAY_H
#define CLAB3_DYNAMICARRAY_H

#include <iostream>

template <typename T>
class DynamicArray
{
private:
    T* data;
    int size = 0;

public:

    DynamicArray();
    explicit DynamicArray(int);
    DynamicArray(T* items, int count);
    DynamicArray(const DynamicArray<T>& arr);
    ~DynamicArray();


    T &operator[](int i);
    T get(int i);
    int getSize();

    void set(int index, T value);
    void resize(int newSize);
    void insert(int index, T value);
    DynamicArray<T> &operator=(const DynamicArray<T>&);

};

template<typename T>
DynamicArray<T>::DynamicArray() {
    data = new T[1];
    size = 0;
}
template<typename T>
DynamicArray<T>::DynamicArray(int sz) {
    if (sz < 0){
        throw std::out_of_range{"DynamicArray::DynamicArray size < 0"};
    }

    this->size = sz;
    this->data = new T[sz];
}

template<typename T>
DynamicArray<T>::DynamicArray(T *items, int count) {
    if (count < 0){
        throw std::out_of_range{"DynamicArray::DynamicArray"};
    }
    this->size = count;
    this->data = new T[count];

    for(size_t i = 0; i < count; i++){
        this->data[i] = items[i];
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &arr) {
    this->data = new T[arr.size];
    this->size = arr.size;

    for(int i = 0; i < arr.size; i++){
        this->data[i] = arr.data[i];
    }
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] this->data;
}

template<typename T>
T &DynamicArray<T>::operator[](int i) {
    return this->data[i];
}

template<typename T>
T DynamicArray<T>::get(int i) {
    return this->data[i];
}

template<typename T>
int DynamicArray<T>::getSize() {
    return this->size;
}

template<typename T>
void DynamicArray<T>::set(int index, T value) {
    if (index < 0 || this->size < index){
        throw std::out_of_range{"DynamicArray::set"};
    }
    data[index] = value;
}

template<typename T>
void DynamicArray<T>::resize(int newSize) {
    if (newSize < 0 ){
        throw std::out_of_range{"DynamicArray::resize"};
    }
    T *newData = new T[newSize];

    if (newSize > 0) {
        std::memcpy(newData, data, sizeof(T) * newSize);
    } else {
        newData = new T[0];
    }
    data = newData;
    size = newSize;
}

template<typename T>
void DynamicArray<T>::insert(int index, T value) {

    if (index > size){
        throw std::out_of_range{"index > size"};
    }
    data[index] = value;

}


template<typename T>
DynamicArray<T> &DynamicArray<T>::operator=( const DynamicArray<T> &arr) {
    this->~DynamicArray();
    if (arr.size > 0){
        data = new T[arr.size];
        std::memcpy(data, arr.data, sizeof(T) * arr.size);
    } else {
        data = new T[0];
    }
    size = arr.size;
    return *this;
}


#endif //CLAB3_DYNAMICARRAY_H

//
// Created by Jinx on 24-12-25.
//
#include "myc0.h"

int MyContainer::_count = 0;

MyContainer::MyContainer(int size) : _size(size) {
    _count++;
    _data=new int[size];
}

MyContainer::~MyContainer() {
    _count--;
}

MyContainer::MyContainer(const MyContainer &Other) : _size(Other._size) {
    _count++;
    _data=new int[_size];
    std::move(Other._data,Other._data+_size,_data);
}

MyContainer& MyContainer::operator=(const MyContainer &Other) {
    if(&Other!=this){

    }
    return *this;
}

int MyContainer::size() const {
    return _size;
}

int* MyContainer::data() const {
    return _data;
}

int MyContainer::count() {
    return _count;
}
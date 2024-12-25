#include "MyContainer.h"

int MyContainer::_count = 0;

MyContainer::MyContainer(int size) : _size(size) {
    // ODO: finish me
    _data=new int[size];
    _count++;
}

MyContainer::~MyContainer() {
    // ODO: finish me
    delete[]_data;
    _count--;
}

MyContainer::MyContainer(const MyContainer &Other) : _size(Other._size) {
    _data=new int [_size];
    for(int i=0;i<_size;i++)
        _data[i]=Other._data[i];
    _count++;
    // DO: finish me
}

MyContainer& MyContainer::operator=(const MyContainer &Other) {
    if(this!=&Other){
        delete[]_data;
        _size=Other._size;
        _data=new int[_size];
        for(int i=0;i<_size;i++)
            _data[i]=Other._data[i];
    }
    return *this;
    // ODO: finish me
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
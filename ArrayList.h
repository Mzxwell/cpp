#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <optional>
#include <cstring>
#include <iostream>
#include "algorithm"

template<typename T>
class ArrayList {
public:
    int c = 10, size = 0;
    T *arr = new T[c];

    void add(T a) {
        if (size == c) {
            T *t = new T[c = (c + (c >> 1))];
            std::move(arr, arr + size, t);
            arr = t;
        }
        arr[size++] = a;
    }

    void remove(T a) {
        auto it = std::find(arr, arr + size, a);
        if (it != arr + size)std::move(it + 1, arr + (size--), it);
    }

    std::optional<T> get(int a) {
        if (a < 0 || a >= size)return std::nullopt;
        return arr[a];
    }

    int getSize() { return size; }

    int getCapacity() { return c; }
};

#endif // ARRAYLIST_H
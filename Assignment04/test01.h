#pragma once
template <typename T>
int find(T val, T *list, int size) {
    for (int i = 0; i < size; i++) {
        if (list[i] == val)
            return i;
    }
    return -1;
}
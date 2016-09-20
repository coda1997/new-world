#include<iostream>
#include"Joseph.h"
Joseph::Joseph(int n) {
    people = new int[n];
    for (int i = 0; i < n; i++) {
        people[i] = i + 1;
    }
    length = n;
}
Joseph::~Joseph() {
    delete[] people;
}
bool Joseph::removePeople(int n){//0-length-1
    int i = n;
    if (n<0 || n>length - 1)
        return false;

    std::cout << "the "<<people[n] <<"th people leaves "<< std::endl;

    while (i < length) {
        people[i ] = people[i+1];
        i++;
    }
    length--;
    if (length == 0) {
        std::cout << "all people have left the ring." << std::endl;
        return true;
    }
    return true;
}
int Joseph::getLength() {
    return length;
}
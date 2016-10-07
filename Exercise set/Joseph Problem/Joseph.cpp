#include<iostream>
#include"Joseph.h"
Joseph::Joseph(int r) {
    people = new int[r];
    for (int i = 0; i < r; i++) {
        people[i] = i + 1;
    }
    length = r;
}
Joseph::~Joseph() {
    delete[] people;
}
int Joseph::removePeople(int temp){//0-length-1
    int r = temp;
    while (length!=0)
    {
        r += temp;
        r %= length;
        std::cout << "the No." << people[r] << " people leaves" << std::endl;
        for (int i = r; i < length-1; i++)
            people[i] = people[i + 1];
        length--;
    }
    std::cout << "All people has left. " << std::endl;
    return 0;

}
int Joseph::getLength() {
    return length;
}
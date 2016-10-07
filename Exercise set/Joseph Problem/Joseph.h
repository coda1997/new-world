#pragma once
class Joseph {
public:
    Joseph(int n = 0);
    int removePeople( int n);
    ~Joseph();
    int getLength();
private:
    int *people;
    int length;
};
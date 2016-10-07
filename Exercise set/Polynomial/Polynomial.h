#pragma once
#include"Monomial.h"
#include<iostream>
using namespace std;
class Polynomial {
    friend Monomial;
public:
    Polynomial();
    Monomial* first, *last;
    void inputPoly(int ,float);//do insert operation in the last
    void outputPoly();//display all the monomial
    void copy(Polynomial&);//not used
    void makeEmpty();
    friend Polynomial & operator + (Polynomial &, Polynomial &);
    friend Polynomial & operator * (Polynomial &, Polynomial &);
};
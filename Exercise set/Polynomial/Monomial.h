#pragma once
class Monomial {
public:
    Monomial(int exp,float coef);
    int exp, coef;
    Monomial* link;

};
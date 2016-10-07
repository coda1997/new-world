#include "Monomial.h";

Monomial::Monomial(int exp, float coef) :exp(exp), coef(coef) {
    link = nullptr;
}
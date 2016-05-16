#pragma once
template <class T>
class employes {
    T scores, days;


public:
    employes(T score, T day) {
        scores = score;
        days = day;
    }
    T sumscore() {
        return scores*days;
    }
};
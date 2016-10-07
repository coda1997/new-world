#include"Polynomial.h"
using namespace std;
Polynomial::Polynomial() {
    //生成头结点
    Monomial* p = new Monomial(0, 0);
    first = p;//first指向头结点，last也指向头结点
    last = p;

}

void Polynomial::inputPoly(int exp, float coef) {
    Monomial* p = new Monomial(exp, coef);//创建一个新结点，并赋值
    last->link = p;//将新节点插入最后一位
    last = p;
    return;
}

void Polynomial::outputPoly() {
    Monomial*p;//工作指针p
    p = first;
    if (p->link == nullptr) {
        cout << "the polynomial is empty." << endl;;
    }
    while (p->link!=nullptr){//打印从第一个到最后的所有exp和coef
        p = p->link;
        cout << "coef:"<<p->coef << " exp:"<<p->exp << endl;
    }
}

void Polynomial::makeEmpty() {
    first->link = nullptr;
    last = first;
}



Polynomial & operator + (Polynomial & ch, Polynomial &temph) {
    Monomial*p, *q, *temp;//工作指针
    p = ch.first;
    q = temph.first;
    temp = ch.first;
    if (p->link == nullptr&&q->link == nullptr)
        return ch;
    p = p->link;
    q = q->link;//第一项
    while (p != nullptr&&q != nullptr) {

        if (p->exp < q->exp) { temp->link = p; p = p->link; temp = temp->link; }
        else if (p->exp > q->exp) { temp->link = q; q = q->link; temp = temp->link;}
        else if (p->coef + q->coef != 0) {
            p->coef += q->coef;
            q = q->link;
            temp->link = p;
            p = p->link;
            temp = temp->link;
        }
        else {
            p = p->link;
            q = q->link;
        }
    }
    if (p == nullptr) {
        while (q != nullptr) {
            temp->link = q;
            q = q->link;
            temp = temp->link;
        }
    }
    else{
        while (p != nullptr) {
            temp->link = p;
            p = p->link;
            temp = temp->link;
        }
    }
    return ch;
}
void  Polynomial::copy(Polynomial& h) {//not used
    Monomial*p,*q;
    p = first;
    q = h.first;
    while (q->link != nullptr) {
        p = p->link;
        q = q->link;
        this->inputPoly(q->exp, q->coef);
    }

}


Polynomial & operator * ( Polynomial & ah, Polynomial &bh) {
    Polynomial ch, temp;//ch 为最后的结果，tah，tbh为临时对象
    Monomial*p, *q;//工作指针
    //先进行深拷贝，保留ah和bh or 不拷贝，取出ah与bh中的值，进行赋值
    //tah.copy(ah);
    //tbh.copy(bh);
    //p = tah.first;
    //q = tbh.first;
    p = ah.first;
    while (p->link!=nullptr){
        p=p->link;
        q = bh.first;
        temp.makeEmpty();
        while (q->link!=nullptr) {
            q = q->link;
            temp.inputPoly(p->exp+q->exp,p->coef*q->coef);
        }
       ch = ch+temp;

    }

    return ch;

}



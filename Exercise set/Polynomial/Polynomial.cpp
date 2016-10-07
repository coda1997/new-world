#include"Polynomial.h"
using namespace std;
Polynomial::Polynomial() {
    //����ͷ���
    Monomial* p = new Monomial(0, 0);
    first = p;//firstָ��ͷ��㣬lastҲָ��ͷ���
    last = p;

}

void Polynomial::inputPoly(int exp, float coef) {
    Monomial* p = new Monomial(exp, coef);//����һ���½�㣬����ֵ
    last->link = p;//���½ڵ�������һλ
    last = p;
    return;
}

void Polynomial::outputPoly() {
    Monomial*p;//����ָ��p
    p = first;
    if (p->link == nullptr) {
        cout << "the polynomial is empty." << endl;;
    }
    while (p->link!=nullptr){//��ӡ�ӵ�һ������������exp��coef
        p = p->link;
        cout << "coef:"<<p->coef << " exp:"<<p->exp << endl;
    }
}

void Polynomial::makeEmpty() {
    first->link = nullptr;
    last = first;
}



Polynomial & operator + (Polynomial & ch, Polynomial &temph) {
    Monomial*p, *q, *temp;//����ָ��
    p = ch.first;
    q = temph.first;
    temp = ch.first;
    if (p->link == nullptr&&q->link == nullptr)
        return ch;
    p = p->link;
    q = q->link;//��һ��
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
    Polynomial ch, temp;//ch Ϊ���Ľ����tah��tbhΪ��ʱ����
    Monomial*p, *q;//����ָ��
    //�Ƚ������������ah��bh or ��������ȡ��ah��bh�е�ֵ�����и�ֵ
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



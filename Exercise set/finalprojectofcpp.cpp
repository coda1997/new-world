#include <iostream>
using std::cout;
using std::endl;
class String{
    static int nCharArray;

    size_t _len;
public:
    char* str;
    String();
    String(char *p);
    String(const String &s);
    char& operator[](unsigned int idx);
    String& operator=(const String &s);
    ~String();        
    const char* c_str(){
        return str+1;
    }
};
int String::nCharArray;
String::String(){
    str=NULL;
    _len=0;
    cout << "in constructor,nCharArray=" << nCharArray << endl;
}
String::String(char *p){
    _len = strlen(p);
    str = new char[_len+1+1];
    strcpy(str+1,p);
    str[0]=1;
    nCharArray++;
    cout << "in constructor,nCharArray=" << nCharArray << endl;
}

String::String(const String &s){
    str = s.str;
    _len = s._len;
    str[0]++;
    cout << "in constructor,nCharArray=" << nCharArray << endl;
}

char& String::operator[](unsigned int idx){
    if(idx<0 || idx>_len || str==NULL){
        static char nullchar = 0;
        return nullchar;
    }
    if(str[0]>1){
        char *buf=new char[_len+1+1];
        strcpy(buf+1,str+1);
        str[0]--;
        str=buf;
        str[0]=1;
         nCharArray++;
    }
    cout << "in oprator[],nCharArray=" << nCharArray << endl;
    return str[1+idx];
}

String& String::operator=(const String &s){
    if(!str){
        _len=s._len;
        str=s.str;
        s.str[0]++;
    }
    else{
        str[0]--;
        if(!str[0]){
             delete[] str;
             nCharArray--;
        }
        _len=s._len;
        str=s.str;
        str[0]++;
    }
    cout << "in operator=,nCharArray=" << nCharArray << endl;
    return *this;
}

String::~String(){
    if(str){
        str[0]--;
        if(!str[0]){
             delete[] str;
             nCharArray--;
        }
    }
    cout << "in destructor,nCharArray=" << nCharArray << endl;
}


int main(){
    String s1;//str[0] not exist
    String s2="abc";//str[0] == 1
    String s3=s2;//str[0] == 1
    s3[0]='p';//str[0] == 1
    cout << s2.c_str() << endl;//
    cout << s3.c_str() << endl;
    s1=s3;
    s2=s3;
    cout << s1.c_str() << endl;
    cout << s2.c_str() << endl;
    system("pause");
}

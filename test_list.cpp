#include <iostream>
#include <string>

using namespace std;

#define USE_STL

#ifndef USE_STL
#include "list.h"
#else
#include <list>
#endif

template <typename T>
void print(list<T>& l){
#ifndef USE_STL
    typename list<T>::Iter iter = l.begin();
    typename list<T>::Iter e = l.end();
#else
    typename list<T>::iterator iter = l.begin();
    typename list<T>::iterator e = l.end();
#endif
    while(iter != e){
        cout<< *iter << endl;
        iter++;
    }
}

class Test
{
public:
    static int i;
    Test(){
        cout << "construct..."<<endl;
    }
    Test(const Test& t){
        *this = t;
        cout << "copy construct..." << endl;
    }
    ~Test(){
        i++;
        cout << "deconstruct..."<<endl;
    }
};

int Test::i = 0;

int main() {
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    l.push_front(4);

    print(l);

    l.pop_back();
    l.pop_front();

    print(l);

    list<int>::iterator loc = l.end();
    l.insert(loc,33);
    cout << "---------------"<<endl;
    print(l);

    Test t1;
    list<Test> ll;
    ll.push_back(t1);

    list<string> ls;
    ls.push_back(string("sdfsd"));
    ls.push_back(string("sdfsdf"));
    ls.push_back(string("sdfsdsdsd"));

    print(ls);
}
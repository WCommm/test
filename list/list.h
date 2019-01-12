//
// Created by Administrator on 2019/1/11.
//

#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "ListNode.h"
#include <iostream>

template <typename T>
struct ListIterator{
    typedef ListIterator<T> Iter;
    typedef ListIterator<T> Self;
    typedef ListNode<T> Node;

    Node* node;

    ListIterator(Node* x = nullptr):node(x){}
    ListIterator(){}
    ListIterator(const Iter& x):node(x.node){}

    T& operator*(){return node->data;}
    T* operator->(){ return &(operator*());}
    Self& operator++(){node = node->succ; return *this;}
    Self operator++(int){Self t = *this; ++*this; return t;}
    Self& operator--(){node = node->pre; return *this;}
    Self operator--(int){Self t = *this; --*this; return t;}
    bool operator==(const Self& iter) const { return node == iter.node;}
    bool operator!=(const Self& iter) const {return node != iter.node;}
};

template<typename T>
class list {
public:
    typedef ListNode<T> Node;
    typedef ListNode<T>& Ref;
    typedef int size_t;
    typedef ListIterator<T> Iter;

    list(){init_list();}
    list(const list<T>& l){ //拷贝复制构造
        init_list();
        for(Iter loc= l.begin();loc!=l.end();++loc){
            T v = *loc;
            push_back(v);
        }
    }
    ~list(){
        clear();
        delete(header);
        delete(trailer);
    }

    Iter begin() const{ return header->succ;}
    Iter end() const {return trailer;}
    Ref front(){return (*begin());}
    Ref back(){return *(--end());}
    
    size_t size(){return _size;}
    bool empty(){return _size == 0;}
    Iter insert(Iter loc,size_t num,const T& v){
        while(num-- > 0){
            loc.node->insert_as_pre(v);
            ++_size;
        }
        return loc;
    }
    Iter insert(Iter loc,const T& v){
        return insert(loc,1,v);
    }
    void push_back(const T& v){
        insert(end(),v);
    }
    void push_front(const T& v){
        insert(begin(),v);
    }
    void pop_back(){
        erase((--end()));
    }
    void pop_front(){
        erase(begin());
    }
    void clear(){
        erase(begin(),end());
    }
    Iter erase(Iter start,Iter end){
        Iter loc = start;
        while(++start != end) {
            erase(loc);
            loc = start;
        }
        erase(loc);
        return end;
    }
    Iter erase(Iter loc){
        Node* node_pre = (Node*)(loc.node->pre);
        Node* node_succ = (Node*)(loc.node->succ);
        node_pre->succ = node_succ;
        node_succ->pre = node_pre;
        delete(loc.node);
        --_size;
        return Iter(node_succ);
    }
    void remove(const T& v);

protected:
    Node* header,*trailer;
    size_t _size;
    void init_list(){
        header = new Node();
        trailer = new Node();
        header->succ = trailer;
        trailer->pre = header;
        _size = 0;
    }
};
#endif //TEST_LIST_H

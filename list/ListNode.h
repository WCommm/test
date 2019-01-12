//
// Created by Administrator on 2019/1/11.
//

#ifndef TEST_LISTNODE_H
#define TEST_LISTNODE_H

template<typename T>
struct ListNode{
    typedef ListNode<T> Node;
    Node* pre,*succ;
    T data;
    ListNode():pre(nullptr),succ(nullptr){}
    ListNode(T v,Node* p= nullptr,Node* s= nullptr):pre(p),succ(s),data(v){}

    Node* insert_as_pre(const T& v){
        Node* node = new ListNode(v,this->pre,this);
        this->pre->succ = node;
        this->pre = node;
        return node;
    }

    Node* insert_as_succ(const T& v){
        Node* node = new ListNode(v,this,this->succ);
        this->succ->pre = node;
        this->succ = node;
        return node;
    }
};

#endif //TEST_LISTNODE_H

//
// Created by Administrator on 2019/1/11.
//

#ifndef TEST_VECTOR_H
#define TEST_VECTOR_H

template <typename T>
class vector {
public:
    typedef T           ValueType;
    typedef ValueType*  Ptr;
    typedef ValueType*  Iter;
    typedef ValueType&  Ref;
    typedef int size_t;

protected:
    Iter start; //头
    Iter finish;//尾
    Iter end_of_storage;
    void expand(){
        const size_t old_size = size();
        const size_t _len = old_size != 0 ? old_size*2 : 1;

        Iter new_start = new ValueType[_len];
        Iter new_finish = new_start;
        try{
            for(Iter it=start;it != finish;++it){
                new_finish = *it;
                new_finish ++;
            }
        }
        catch(...){
            delete[] new_start;
            throw;
        }

        delete[] start;
        start = new_start;
        finish = new_finish;
        end_of_storage = start+_len;
    }

public:
    vector():start(0),finish(0),end_of_storage(0){}
    vector(const vector& c);
    vector(size_t num,const ValueType& val);
    ~vector();

    void assign(size_t num,const ValueType& val);
    void assign(Iter start,Iter end);
    Iter begin() {return start;}
    Iter end() {return finish;}
    Ref front() const{return *begin();}
    Ref back() const{ return *(end()-1);}
    size_t capacity(){return size_t(end_of_storage - start);}
    bool empty(){return start == finish;}
    size_t size(){return size_t(finish - start);}
    void clear(){erase(begin(),end());}
    Iter erase(Iter loc){
        for(Iter it = loc;it != finish;++it){
            *it = *(it+1);
        }
        --finish;
        return loc;
    }
    Iter erase(Iter start,Iter end){
        Iter t = start;
        for(Iter it = end;it != finish;++it){
            *t = *it;
            t ++;
        }
        finish = t;
        return t;
    }
    void insert(Iter loc,size_t num,const ValueType& val){
        if()
    }
    void insert(Iter loc,const ValueType& val);
    void push_back(const ValueType& val){
        if(finish == end_of_storage){//还有空余空间
            expand();
        }
        start[finish-start] = val;
        finish++;
    }
    void pop_back(){
        --finish;
    }
};


#endif //TEST_VECTOR_H

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include<exception>
using namespace std ;


template<class T>
class my_vector
{

public:
    class Iterator;
    my_vector(const my_vector& arg);
    my_vector();
    my_vector(int& n);
    ~my_vector();

    void push_back(T);
    T pop_back();
    int size();
    bool empty() const;

    Iterator begin();
    Iterator end();


private:
    T* array;
    T& at(int);
    T& operator[](int);

    int cur_size;
    int max_size;

    void alloc_mem(int&);
};

template<class T> class my_vector<T>::Iterator
{
    T* cur;
public:
    Iterator(T* p):cur(p){}
    T& operator+ (int n) {return *(cur+n);}
    T& operator- (int n) {return *(cur-n);}

    T& operator++ (int) {return *cur++;}
    T& operator-- (int) {return *cur--;}
    T& operator++ () {return *++cur;}
    T& operator-- () {return *--cur;}

    bool operator!= (const Iterator& it){return *cur!=*it.cur;}
    bool operator== (const Iterator& it){return *cur==*it.cur;}
    T& operator* () {return *cur;}

};

template<class T>
typename my_vector<T>::Iterator my_vector<T>::begin()
{
    return my_vector<T>::Iterator(&array[0]);
}

template<class T>
typename my_vector<T>::Iterator my_vector<T>::end()
{
    return my_vector<T>::Iterator(&array[cur_size]);
}

template<class T>
my_vector<T>::my_vector()
{
    max_size = 20;
    array = new T[max_size];
    cur_size = 0;
}

template<class T>
my_vector<T>::my_vector(int& n)
{
    max_size = n;
    array = new T[];
    cur_size = 0;
}

template<class T>
my_vector<T>::~my_vector()
{
    delete[] array;
}

template<class T>
void my_vector<T>::push_back(T val)
{
    if (cur_size+1>max_size/2)
    {
        alloc_mem(cur_size);
    }
    array[cur_size] = val;
    cur_size++;
}

template<class T>
inline my_vector<T>::my_vector(const my_vector & arg)
    :cur_size(arg.size())
{
    for (int i = 0; i < arg.size(); ++i)
        array[i] = arg.array[i];
}

template<class T>
bool my_vector<T>::empty() const
{
    return (cur_size == 0);
}

template<class T>
T& my_vector<T>::operator[](int i)
{
    return array[i];
}

template<class T>
T& my_vector<T>::at(int i)
{
    if (i < cur_size)
        return array[i];
    else
        throw 10;
}

template<class T>
void my_vector<T>::alloc_mem(int& num)
{
    max_size = cur_size * 2;
    T* tmp = new T[max_size];
    for (int i = 0; i < cur_size; ++i)
        tmp[i] = array[i];

    delete[] array;
    array = tmp;
}

template<class T>
T my_vector<T>::pop_back()
{
    T tmp = array[cur_size];
    cur_size--;
    return tmp;
}
#endif // MY_VECTOR_H

#ifndef VEC_H
#define VEC_H

# include<iostream>


template <class T> class Vec {
public:
    typedef T* iterator; // iterator type
    typedef const T* const_iterator; // const iterator type
    typedef size_t size_type; // type of size(because we use array)
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T& reference;
    typedef const T& const_reference;
    
    Vec() { create(); }
    explicit Vec(size_t n, const T& val=T()) { create(n, val); }

    size_type size() const { return limit - data;}
    reference operator[] (size_type i) { return data[i]; } 
    const_reference operator[] (size_type i) const { return data[i]; } 

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return limit; }
    const_iterator end() const { return limit; }
private:
    // implementation
    iterator data; // first element in the Vec
    iterator limit; // one past the last element in the Vec
};

#endif

# Using associative containers

## Overview

## typename

```cpp
template<class T>
T median(vector<T> v) {
    typedef typename vector<T>::size_type vec_sz;
    
    vec_sz size = v.size();
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }

    sort(v.begin(), v.end());

    vec_sz mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1] / 2 : v[mid]);
}
```

The next novelty is the use of **typename** in the definition of `vec_sz`. It is there to tell the
implementation that `vector<T>::size_type` is the name of a type, even though the
implementation doesn't yet know what type `T` represents. Whenever you have a type, such
as `vector<T>`, that depends on a template parameter, and you want to use a member of
that type, such as `size_type`, that is itself a type, you must precede the entire name by
typename to let the implementation know to treat the name as a type. Although the
standard library ensures that `vector<T>::size_type` is the name of a type for any T, the
implementation, having no special knowledge of the standard-library types, has no way of
knowing this fact.

## C++ standard syas nothing about how implementations manage template

The C++ standard says nothing about how implementations should manage template iinstantiation,
so every implementation handles instantiation in its own particular way. 

## C++ iterator categories


Instead of being defined by specific types, each category of iterator is defined by the operations that can be performed on it. This definition means that any type that supports the necessary operations can be used as an iterator -- for example, a pointer supports all of the operations required by LegacyRandomAccessIterator, so a pointer can be used anywhere a LegacyRandomAccessIterator is expected.

迭代器的分类的依据并不是迭代器的类型，而是迭代器所支持的操作。换句话说，某个类型只要支持相应的操作，就可以作为迭代器使用。例如，完整对象类型指针支持所有老式随机访问迭代器 (LegacyRandomAccessIterator) 要求的操作，于是任何需要老式随机访问迭代器 (LegacyRandomAccessIterator) 的地方都可以使用指针。

### Reference

[cppreference.com iterator library](https://en.cppreference.com/w/cpp/iterator)

## Iterator ranges and off-the-end values


One reason is that if the **range had no elements at all**, there would be no last element to 
mark the end. We would then be in the curious position of having to designate an empty
range by an iterator that refers to where the element before the beginning of the range
would be. With that strategy, we would have to handle empty ranges differently from all 
others, which would make our programs harder to understand and less reliable. We saw in
§6.1.1/103 that treating empty ranges the same as any others simplified our program.

The second reason is that marking the end of a range by an iterator that is one past the end
lets us get away with comparing iterators only for equality and inequality, and makes i
tunnecessary to define what it means for one iterator to be less than another. The point is
that we can tell immediately if the range is empty by comparing the two iterators; the range
is empty if and only if the iterators are equal. If they are unequal, then we know that the
beginning iterator refers to an element, so we can do something and then increment that
iterator to reduce the size of the range. In other words, marking ranges by the beginning
and one past the end allows us to use loops of the form

```cpp
// invariant: we must still process the elements in the range [begin, end)
while (begin != end) {
    // do something with the element to which begin refers
    begin++;
}
```

## Input and output iterators

Why are input and output iterators separate categories from forward iterators if no standard
container requires the distinction? One reason is that not all iterators are associated with
containers. For example, if c is a container that supports push_back, then
back_inserter(c) is an output iterator that meets no other iterator requirements.

## Using iterators for flexibility

We can be more flexible by rewriting split to take an output iterator instead of returning a
value. In this version of the function, we'll use that iterator to write the words that we find
Our caller will have bound the iterator to the output location where the values should be
placed:

```cpp
template<class Out>
void split(const string& str, Out os) {
    typedef string:const_iterator iter;

    iter i = str.begin();
    while (i != str.end()) {
            // ignore leading blanks
            i = find_if(i, str.end(), not_space);

            // find end of next word
            iter j = find_if(i, str.end(), space);

            // copy the character in [i, j)
            if (i != str.end()) {
                *os++ = string(i, j);
            }

            i = j;
        }
}
```

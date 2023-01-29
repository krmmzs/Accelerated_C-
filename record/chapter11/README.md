# Defining abstract data types

这一章的阅读是一个循序渐进的过程，从中抓取一个小节反而会破坏完整性。

## designd order

- When we design a class, we normally start by specifying the interface that we want to provide.
    - One way to determine the right interface is to look at the kind of programs we want our users to be able to write.
- Having determined our operations, we next need to think about how to represent this class.
    - template class
    - normally class
- public: interface, private: implementation
- what data we will store
- write interface first, ignore implementation now(many design thinking)

## Type definitions

Following the convention used by the standard template classes, we want to provide type
names that our users can use, and that will hide the implementation details of how we
implement our class. Specifically, we need to provide **typedef** s for the **const** and
non**const** iterator types, and for the type that we use to denote the size of a **Vec** .

Library containers also define four other types:
- `value_type`, the type of each objectthat the container stores
- `reference` and `const_reference`, which are synonyms for value_type& and const value_type&, respectively.
- `different types`, the type of the result of subtracting one iterator from another.

## the subtracting two pointers yields type: `ptrdiff_t`

just title

## overload the index([]) operator

It may be surprising that we can overload the index operator, because it appears that both argument lists
are the same; each appears to take a single parameter of type `size_type`. However, every member function, including each of these operators, takes
an implicit parameter, which is the object on which it operates. Because the operations
deffer regarding whether that object is const, we can overload the operation.

```cpp
template <class T> class Vec {
public:
    ...
    reference operator[] (size_type i) { return data[i]; } 
    const_reference operator[] (size_type i) const { return data[i]; } 
    ...
private:
    ...
};
```

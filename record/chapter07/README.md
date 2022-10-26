# Using associative containers

## Overview

## sequence containers vs associative containers

Another important difference between associative and sequential containers is that, because
associative containers are self-ordering, our own programs must not do anything tha
changes the order of the elements.

For that reason, **algorithms that change the contents of**
**containers often don't work for associative containers**. In exchange for that restriction,
associative containers offer a variety of useful operations that are impossible to implement
implementefficiently for sequential containers.

## map's key is const

Note that the **pair** associated with a **map** has a key type that is **const**. 
key is **const**, we are prevented from changing the value of an element's key. If the key
were not **const**, we might implicitly change the element's position within the **map**.
Accordingly, the key is always **const**, so that if we dereference a `map<string, int>`
iterator, we get a `pair<const string, int>`.

## high order function let function be a interface

Rather than using **split** directly, we're going to make it a parameter to the cross-reference
function. That way, we leave open the possibility of changing the way we find the words on a
line. For example, we could pass the **find_urls** function from §6.1.3/105, and use the
cross-reference function to see where URLs appear in the input.

## rand function

More see [codeforces: dont use rand():...](https://codeforces.com/blog/entry/61587)

```cpp
// return a random integer in the rang [0, n)
int nrand(int n) {
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");

    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);

    return r;
}
```

for example:
assume that n is 3. Then bucket_size will be 10922. In this case,
values of rand() in the range [0, 10922) will yield 0, values in the range [10922,
21844) will yield 1, values in the range [21844, 32766) will yield 2, and values of 32766
or 32767 will be discarded.

## [] access operator will create a new element in map

Indexes the **map** using a key, **k**, of type **K**, and returns an **lvalue** of type **V**. If there is no
entry for the given key, a new value-initialized element is created and inserted into the
**map** with this key. 
Because using **[]** to access a **map** might create a new element, **[]** is
not allowed on a **const map**.

[std::map<Key,T,Compare,Allocator>::operator[] in cppreference.com](https://zh.cppreference.com/w/cpp/container/map/operator_at)

> Returns a reference to the value that is mapped to a key equivalent to key, performing an insertion if such key does not already exist.

**a reference to the value obviously is a lvalue.**

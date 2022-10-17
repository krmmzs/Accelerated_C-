# chapter 03 Working with batches of data

## Overview

## while (cin >> x)

```cpp
while (cin >> x) {
    // do something with x
}
```

is equal to

```cpp
cin >> x
while (cin) {
    // do something with x
}
```

## size_type in vector

```cpp
typedef vector<double>::size_type vec_sz;
vec_sz size = homework.size();
```

The `vector` type defines a type named `vector<double>::size_type`, and a functionnamed `size`. These members operate analogously to the ones in `string:` The type definedby `size_type` is an `unsigned` type guaranteed sufficient to hold the size of the largestpossible `vector`, and `size()` returns a size_type value that represents the number ofelements in `the` `vector.`

Because we need to know the size in two places, we will remember the value in a localvariable. Different implementations use different types to represent sizes, so we cannotwrite the appropriate type directly and remain implementation-independent. For that reason,it is good programming practice to use the `size_type` that the library defines to represent
container sizes, which we do in naming the type of `size`.

## unsigned integral type

The next important observation is that `vector<double>::size_type`, like all standard-library size types, is an **unsigned integral type**. Such types are incapable of storingnegative values at all; instead, they store values modulo 2n, where n depends on the implementation. So, for example, there would never be any point in checking whether `homework.size() < 0`, because that comparison would always yield false

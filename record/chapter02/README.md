# Looping and counting

## Overview

- [i ++ vs i = i + 1](#i-vs-i-i-1)
- [designing a while statement](#designing-a-while-statement)
- [String class size](#string-class-size)
- [Abbreviating repeated uses of std:: ](#abbreviating-repeated-uses-of-std)
- [off-the-end value](#off-the-end-value)
- [statement vs expression](#statement-vs-expression)

## i ++ vs i = i + 1

possible values of type bool are true and false, with the obvious meanings.

The other new facility in this program is the last statement in the while body, which is

```
++r;
```

The ++ is the increment operator, which has the effect of incrementing-adding 1 to-the

variable r. We could have written

```
r = r + 1;
```

instead, but incrementing an object is so common that a special notation for doing so is
useful. Moreover, as we shall see in §5.1.2/79, the idea of transforming a value into its
immediate successor, in contrast with computing an arbitrary value, is so fundamental to
abstract data structures that it deserves a special notation for that reason alone.

## Designing a while statement

There is a useful technique for writing and understanding `while` statements that relies on

two key ideas-one about the definition of a `while` statement, and the other about the

behavior of programs in general.

The first idea is that when a `while` finishes, its condition must be `false`-otherwise the

`while` wouldn't have finished. So, for example, when the while in §2.3/19 finishes, we

know that `r != rows` is false and, therefore, that `r` is equal to `rows`.

The second idea is that of a **loop invariant**, which is a property that we assert will be true

about a `while` each time it is about to test its condition. We choose an invariant that we

can use to convince ourselves that the program behaves as we intend, and we write the
program so as to make the invariant true at the proper times. Although the invariant is not
part of the program text, it is a valuable intellectual tool for designing programs. Every

useful `while` statement that we can imagine has an invariant associated with it. Stating the

invariant in a comment can make a `while` much easier to understand.

## String class size

```c++
const std::string::size_type cols = greeting.size() + pad * 2 + 2;
```

The second :: similarly says that we want the name `size_type`
from the class `string`.
Like namespaces and blocks, classes define their own scopes.
The `std::string` type defines `size_type` to be the name of the
appropriate type for holding the number of characters ina string.
Whenever we need a local variable to contain the size of a `string`,
we should use `std::string::size_type` as the type of that variable.

The reason that we have given `cols` a type of `std::string::size_type`
is to ensure that cols is capable of containing the number
of characters in `greeting`, no matter howlarge that number
might be. We could simply have said that `cols` has type int,
andindeed, doing so would probably work. However, the value
of `cols` depends on the size ofthe input to our program, and
we have no control over how long that input might be.
It is conceivable that someone might give our program a
string so long that an `int` is insufficientto contain its length.

more read [Stack overflow string::size_type instead of int](https://stackoverflow.com/questions/1181079/stringsize-type-instead-of-int)

_The important idea_:
**Nevertheless, whenever we define avariable that contains the size of a particular data structure, it is a good habit to use the type that the library defines as being appropriate for that specific purpose**

## Abbreviating repeated uses of std::

```c++
using std::cout;
```

we can say that we intend to use the name cout to mean std::cout
exclusively, and thatwe do not intend to define anything named
cout ourselves. Once we have done so, we cansay cout instead
of `std::cout`

The name that itmentions behaves similarly to other names.
For example, if a using-declaration appearswithin braces,
the name that it defines has its given meaning from where
it is defined to theclosing brace.

## off-the-end value

We can think of 0 as being the beginning of a range,
androws as being the off-the-end value for the range.
Such a range is called a half-openrange, and is often written
as [begin, off-the-end).

## statement vs expression

```c++
for (init-statement  condition; expression)
    statement
```

statement often have their own semicolon.

## [0, rows) vs [1, rows]

Asymmetric ranges are usually easier to use than symmetric ones
because of an important property: A range of the form `[m, n)`
has `n - m` elements, and a range of the form `[m,n]` has `n - m + 1`
elements. So, for example, the number of elements in `[0, rows)`
is obvious (i.e., `rows - 0`, or `rows`) but the number in `[1, rows]`
is less so.

This behavioral difference between asymmetric and symmetric
ranges is particularly evident in the case of empty ranges:
If we use asymmetric ranges, we can express an empty rangeas
`[n, n)`, in contrast to `[n, n-1]` for symmetric ranges.
The possibility that the end of arange could ever be less than
**the beginning can cause no end of trouble in designingprograms**

Another reason to count from `0` is that doing so makes loop
invariants easier to express. Inour example, counting from `0`
makes the invariant straightforward: We have written r rowsof
output so far. What would be the invariant if we counted from `1`?

# Book Details quick search

## Overview

- [Chapter 00 Getting Started](#chapter-00-getting-started)
- [Chapter 01 Working with strings](#chapter-01-working-with-strings)
- [Chapter 02 Looping and Counting](#chapter-02-looping-and-counting)
- [Chapter 03 working with batches of data](#chapter-03-working-with-batches-of-data)

### Chapter 00 Getting Started

Although the program we've written is simple, we've covered a lot of ground in this chapter.
We intend to build on what we've introduced here, so it is important for you to be sure that
you understand this chapter fully before you continue.

To help you do so, this chapter-and every chapter except Chapter 16-ends with a section
called Details and a set of exercises. The Details sections summarize and occasionally
expand on the information in the text. It is worth looking at each Details section as a
reminder of the ideas that the chapter introduced.

Program structure: C++ programs are usually in free form, meaning that spaces are
required only when they keep adjacent symbols from running together. In particular,
newlines (i.e., the way in which the implementation represents the change from one line of
the program to the next) are just another kind of space, and usually have no additional
special meaning. Where you choose to put spaces in a program can make it much easier-or
harder-to read. Programs are normally indented to improve readability.
There are three entities that are not free-form:

#### string literals

```
characters enclosed in double quotes; may not span lines
```
#### #include name

```
must appear on a line by themselves (except for comments)
```
#### // comments

#### // followed by anything; ends at the end of the current line

#### A comment that begins with /* is free-form; it ends with the first subsequent */ and can

span multiple lines.

Types define data structures and operations on those data structures. C++ has two kinds of

#### types: those built into the core language, such as int, and those that are defined outside

#### the core language, such as std::ostream.

Namespaces are a mechanism for grouping related names. Names from the standard

#### library are defined in the namespace called std.

#### String literals begin and end with double quotes ("); each string literal must appear

entirely on one line of the program. Some characters in string literals have special meaning

#### when preceded by a backslash (\):

#### \n newline character

#### \t tab character


#### \b backspace character

#### \" treats this symbol as part of the string rather than as the string terminator

#### \' same meaning as ' in string literals, for consistency with character literals (§1.2/14)

#### \\ includes a \ in the string, treating the next character as an ordinary character

We'll see more about string literals in §10.2/176 and §A.2.1.3/302.

Definitions and headers: Every name that a C++ program uses must have a
corresponding definition. The standard library defines its names in headers, which programs

#### access through #include. Names must be defined before they are used; hence, a

#### #include must precede the use of any name from that header. The <iostream> header

defines the library's input-output facilities.

#### The main function: Every C++ program must define exactly one function, named main,

#### that returns an int. The implementation runs the program by calling main. A zero return

#### from main indicates success; a nonzero return indicates failure. In general, functions must

#### include at least one return statement and are not permitted to fall off the end of the

#### function. The main function is special: It may omit the return; if it does so, the

implementation will assume a zero return value. However, explicitly including a return from

#### main is good practice.

Braces and semicolons: These inconspicuous symbols are important in C++ programs.
They are easy to overlook because they are small, and they are important because
forgetting one typically evokes compiler diagnostic messages that may be hard to
understand.

A sequence of zero or more statements enclosed in braces is a statement, called a block,
which is a request to execute the constituent statements in the order in which they appear.
The body of a function must be enclosed in braces, even if it is only a single statement. The
statements between a pair of matching braces constitute a scope.

An expression followed by a semicolon is a statement, called an expression statement,
which is a request to execute the expression for its side effects and discard its result. The
expression is optional; omitting it results in a null statement, which has no effect.

#### Output: Evaluating std::cout << e writes the value of e on the standard-output stream,

#### and yields std::cout, which has type ostream, as its value in order to allow chained

output operations.

### Chapter 01 Working with strings

Types:

#### char

```
Built-in type that holds ordinary characters as defined by the implementation.
```
#### wchar_t

```
Built-in type intended to hold "wide characters," which are big enough to
hold characters for languages such as Japanese.
```
#### The string type is defined in the standard header <string&gt ;. An object of type

#### string contains a sequence of zero or more characters. If n is an integer, c is a char, is

#### is an input stream, and os is an output stream, then the string operations include

#### std::string s;

#### Defines s as a variable of type std::string that is initially empty.

#### std::string t = s;

#### Defines t as a variable of type std::string that initially contains a copy

#### of the characters in s , where s can be either a string or a string literal.

#### std::string z(n, c);

#### Defines z as a variable of type std::string that initially contains n copies

#### of the character c. Here, c must be a char , not a string or a string literal.

#### os << s

#### Writes the characters contained in s , without any formatting changes, on the

#### output stream denoted by os. The result of the expression is os.

#### is >> s

#### Reads and discards characters from the stream denoted by is until encountering

```
a character that is not whitespace. Then reads successive characters
```
#### from is into s , overwriting whatever value s might have had, until the next

#### character read would be whitespace. The result is is.

#### s + t

#### The result of this expression is an std::string that contains a copy of the

#### characters in s followed by a copy of the characters in t. Either s or t , but

#### not both, may be a string literal or a value of type char.

#### s.size()

#### The number of characters in s.


Variables can be defined in one of three ways:

```
std::string hello = "Hello"; // define the variable with an explicit initial value
```
```
std::string stars(100, '*'); // construct the variable
// according to its type and the given expressions
```
```
std::string name; // define the variable with an implicit initialization,
// which depends on its type
```
Variables defined inside a pair of curly braces are local variables/which exist only while
executing the part of the program within the braces. When the implementation reaches the

#### } , it destroys the variables, and returns any memory that they occupied to the system.

#### Defining a variable as const promises that the variable's value, will not change during its

lifetime. Such a variable must be initialized as part of its definition, because there is no way
to do so later.

#### Input: Executing std::cin >> v discards any whitespace characters in the standard

#### input stream, then reads from the standard input into variable v. It returns std::cin ,

#### which has type istream , in order to allow chained input operations.

### Chapter 02 Looping and counting

expressions: c++ inherits a rich set of operators from c, several of which we have already
used. in addition, as we've already seen with the input and output operators, c++ programs
can extend the core language by defining what it means to apply built-in operators to
objects of class type. correctly understanding complicated expressions is a fundamental
prerequisite to effective programming in c++. understanding such expressions requires
understanding

```
how the operands group, which is controlled by the precedence and associativity of the
operators used in the expression
how the operands will be converted to other types, if at all
the order in which the operands are evaluated
```
different operators have different precedence. most of the operators are left-associative,
although the assignment operators and the operators taking a single argument are right-
associative. we list the most common operators here-regardless of whether we've used
them in this chapter. we've ordered them by precedence from highest to lowest, with a
double line separating groupings with the same precedence.
x.y

#### the member y of object x

x[y]

#### the element in object x indexed by y

x++

#### increments x , returning the original value of x

x--

#### decrements x , returning the original value of x

++x

#### increments x , returning the incremented value

--x

#### decrements x , returning the decremented value

!x

#### logical negation. if x is true then !x is false.

x * y

#### product of x and y

x / y

#### quotient of x and y. if both operands are integers,

the implementation chooses whether to round toward zero or - 8
x % y

#### remainder of x divided by y , equivalent to x - ((x / y) * y)

x + y

#### sum of x and y


x - y

#### result of subtracting y from x

x >> y

#### for integral x and y, x shifted right by y bits; y must be non-negative.

#### if x is an istream , reads from x into y

x << y

#### for integral x and y, x shifted left by y bits; y must be non-negative.

#### if x is an ostream , writes y onto x.

x relop y

#### relational operators yield a bool indicating the truth of the relation.

#### the operators (<, >, <= , and >= ) have their obvious meanings.

x == y

#### yields a bool indicating whether x equals y

x != y

#### yields a bool indicating whether x is not equal to y

x && y

#### yields a bool indicating whether both x and y are true.

#### evaluates y only if x is true.

x || y

#### yields a bool indicating whether either x or y is true.

#### evaluates y only if x is false.

x = y

#### assign the value of y to x , yielding x as its result.

x op= y

#### compound assignment operators; equivalent to x = x op y ,

where op is an arithmetic or shift operator.

x? y1 : y2

#### yields y1 if x is true ; y2 otherwise.

#### evaluates only one of y1 and y2.

there is usually no guarantee as to the order in which an expression's operands are
evaluated. because the order of evaluation is not fixed, it is important to avoid writing a
single expression in which one operand depends on the value of another operand. we'll see
an example in §4.1.5/60.

operands will be converted to the appropriate type when possible. numeric operands in
expressions or relational expressions are converted by the usual arithmetic conversions
described in detail in §a.2.4.4/304. basically, the usual arithmetic conversions attempt to
preserve precision. smaller types are converted to larger types, and signed types are

#### converted to unsigned. arithmetic values may be converted to bool : a value of 0 is

#### considered false ; any other value is true. operands of class type are converted as

specified by the type. we'll see in chapter 12 how to control such conversions.

types:


#### bool

#### built-in type representing truth values; may be either true or false

#### unsigned

```
integral type that contains only non-negative values
```
#### short

```
integral type that must hold at least 16 bits
```
#### long

```
integral type that must hold at least 32 bits
```
#### size_t

#### unsigned integral type (from <cstddef> ) that can hold any object's size

#### string::size_type

#### unsigned integral type that can hold the size of any string

#### half-open ranges include one but not both of their endpoints. for example, [1, 3)

#### includes 1 and 2 , but not 3.

condition: an expression that yields a truth value. arithmetic values used in conditions are

#### converted to bool : nonzero values convert to true ; zero values convert to false.

statements:

#### using namespace-name::name ;

#### defines name as a synonym for namespace-name::name.

#### type-name name;

#### defines name with type type-name.

#### type-name name = value;

#### defines name with type type-name initialized as a copy of value.

#### type-name name(args) ;

#### defines name with type type-name constructed as appropriate for the given arguments

#### in args.

#### expression ;

#### executes expression for its side effects.

#### { statement(s) }

#### called a block. executes the sequence of zero or more statement(s) in order. may

#### be used wherever a statement is expected. variables defined inside the braces have

```
scope limited to the block.
```

#### while (condition) statement

#### if condition is false , do nothing; otherwise, execute statement and then repeat the

#### entire while.

#### for(init-statement condition; expression) statement

#### equivalent to { init-statement while (condition ) {statement expression

#### ; } }.

#### if (condition) statement

#### executes statement if condition is true.

#### if (condition) statement else statement2

#### executes statement if condition is true , otherwise executes statement2.

#### each else is associated with the nearest matching if.

#### return val ;

#### exits the function and returns val to its caller.

### Chapter 03 working with batches of data

Local variables are default-initialized if they are defined without an explicit initializer.
Default-initialization of a built-in type means that the value is undefined. Undefined values
may be used only as the left-hand side of an assignment.

Type definitions:

#### typedef type name; Defines name as a synonym for type.

#### The vector type, defined in <vector>, is a library type that is a container that holds a

sequence of values of a specified type, vectors grow dynamically. Some important
operations are:

#### vector<T>::size_type

```
A type guaranteed to be able to hold the number of elements in the
```
#### largest possible vector.

#### v.begin()

#### Returns a value that denotes the first element in v.

#### v.end()

#### Returns a value that denotes (one past) the last element in v.

#### vector<T> v;

#### Creates an empty vector that can hold elements of type T.

#### v.push_back(e)

#### Grows the vector by one element initialized to e.

#### v[i]

#### Returns the value stored in position i.

#### v.size()

#### Returns the number of elements in v.

Other library facilities

#### sort(b, e)

#### Rearranges the elements defined by the range [b, e) into nondecreasing order. Defined

#### in <algorithm>.

#### max(el, e2)

#### Returns the larger of the expressions e1 and e2; e1 and e2 must have exactly the same


#### type. Defined in <algorithm>.

#### while (cin >> x)

```
Reads a value of an appropriate type into x and tests the state of the stream. If the stream
```
#### is in an error state, the test fails; otherwise, the test succeeds, and the body of the while

```
is executed.
```
#### s.precision(n)

#### Sets the precision of stream s to n for future output (or leaves it unchanged if n is

```
omitted). Returns the previous precision.
```
#### setprecision(n)

#### Returns a value that, when written on an output stream s, has the effect of calling

#### s.precision(n). Defined in <iomanip>.

#### streamsize

#### The type of the value expected by setprecision and returned by precision. Defined

#### in <ios>.

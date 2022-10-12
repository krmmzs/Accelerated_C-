# chapter01 string

- A variable is an **object** that has a name

In order to read input, we must have a place to put it.
Such a place is called a **variable**.
A variable is an **object** that has a name. **An object,
in turn, is apart of the computer's memory that has a type**.
The distinction between objects andvariables is important
because, as we'll see in §3.2.2/45, §4.2.3/65, and §10.6.1/183,
it ispossible to have objects that do not have names.

- strings not equal to string literals

One idea is that we can give a variable a value as we
define it. We do so by placing, betweenthe variable's
name and the semicolon that follows it, an = symbol
followed by the value thatwe wish the variable to have.
If the variable and value have different types-as
§10.2/176shows that strings and string literals do-the
implementation will convert the initial valueto the type
of the variable.

strings is a class type
string literals is `const char[] + '\0'`

- operator **overloaded**(different type of operands)

Here we have an example in which + means something
completely different. In each case, we can determine
what the + operator does by examining the typesof its operands. When an operator has different meanings for operands of different types, wesay that the operator is overloaded

- left-associative: << >> +

One property of an operator that never changes is its
associativity.
We learned in Chapter 0 that << is left-associative,
so that std::cout << s << t means the same as(std::cout << s)
<< t. Similarly, the + operator (and, for that matter,
the >>operator) is also left-associative. Accordingly,
the value of "Hello, " + name + "!" isthe result of
concatenating "Hello, " with name, and concatenating
the result of thatconcatenation with "!". So, for example,
if the variable name contains Estragon, then thevalue of
"Hello, " + name + "!" is Hello, Estragon!

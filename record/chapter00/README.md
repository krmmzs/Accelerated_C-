# chapter00 begin

## operand and operator

Every operand has a type.
We shall have much more to say about types,
but essentially, atype denotes a data structure and
the meanings of operations that make sense for that datastructure.
The effect of an operator depends on the types of its operands

Types often have names.
For example, the core language defines int as
the name of a typethat represents integers,
and the library defines std::ostream as the type
that providesstream-based output. In our program,
std::cout has type std::ostream.

- the `<<` operator's effects

The << operator takes two operands,
and yet we have written two << operators and threeoperands.

The left operand of the second << is therefore an
expression that yields std::cout, whichhas type std::ostream;
the right operand is std::endl, which is a manipulator.
Thekey property of manipulators is that writing a manipulator
on a stream manipulates thestream, by doing something other
than just writing characters to it. When the left operandof 
<< has type std::ostream and the right operand is a manipulator,
<< does whateverthe manipulator says to do to the given stream,
and returns the stream as its result. In thecase of std::endl,
that action is to end the current line of output.The entire
expression therefore yields std::cout as its value, and,
as a side effect, itwrites Hello, world! on the standard output
stream and ends the output line. When wefollow the expression by
a semicolon, we are asking the implementation to discard thevalue-which
action is appropriate, because we are interested only in the side
effects

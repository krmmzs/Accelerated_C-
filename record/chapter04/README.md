# chapter 04 Organizing programs and data

## Overview

## Handling of empty vectors in function

The most significant change is what we do if the `vector` is empty. In §3.2.2/46, we knew that we would have to complain to whoever was running our program, and we also knew who that person would be and what kind of complaint would make sense. In this revised version, on the other hand, we don't know who is going to be using it, or for what purpose, so we need a more general way of complaining. That more general way is to **throw** an *exceptionif* the `vector` is empty

The third point is that we check whether `homework.size()` is zero, even though we know that `median` will do so for us. The reason is that if `median` discovers that we are asking for the **median of an empty vector** , it throws an exception that includes the message median of an empty vector . This message is not directly useful to someone who is computing student grades. Therefore, we throw our own exception, which we hope will give the user more of a clue as to what has gone wrong.

## cin in function

```cpp
istream& read_hw(istream& in, vector<double>& hw)
{
    double x;
    while (in >> x)
        hw.push_back(x);
    return in;
}
```
This strategy doesn't quite work, for two reasons. The first reason is that we haven't defined hw —our caller defined it for us. Because we didn't define it, we don't know what data might be there already. For all we know, our caller might be using our function to process homework for lots of students, in which case `hw` might contain the previous student's grades. We can solve this problem by calling `hw.clear()` before we begin our work.

The second reason that our strategy fails is that we don't quite know when to stop. We can keep reading grades until we can no longer do so, but at that point we have a problem. There are two reasons why we might no longer be able to read a grade: We might have reached end-of-file, or we might have encountered something that is not a grade.

get final code:
```cpp
istream& read_hw(istream& in, vector<double>& hw)
{
    // get rid of previous contents
    hw.clear();
    if (in) {
        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}
```

## lvalue error

```cpp
❯ g++ -std=c++17 lvalue_test.cpp -o lvalue_test
lvalue_test.cpp: In function ‘int main()’:
lvalue_test.cpp:50:31: error: cannot bind non-const lvalue reference of type ‘std::vector<double>&’ to an rvalue of type ‘std::vector<double>’
   50 |     read_hw(std::cin, emptyvec());
      |                       ~~~~~~~~^~
lvalue_test.cpp:25:47: note:   initializing argument 2 of ‘std::istream& read_hw(std::istream&, std::vector<double>&)’
   25 | istream& read_hw(istream& in, vector<double>& hw) {
      |                               ~~~~~~~~~~~~~~~~^~
```

## side effects when use exception

A good rule of thumb is to avoid more than one side effect in a single statement. Throwing an exception is a side effect, so a statement that might throw an exception should not cause any other side effects, particularly including input and output.

## header files don't use using

In general, header files should declare only the names that are necessary. By restricting the names contained in a header file, we can preserve maximum flexibility for our users. For example, we use the qualified name for `std::vector` because we have no way of knowing how the user of our **median** function wants to refer to `std::vector`. Users of our code might not want a using-declaration for vector. If we write one in our header, then all programs that `include` our header get a using `std::vector` declaration, regardless of whether they wanted it. Header files should use fully qualified names rather than **using-**declarations.

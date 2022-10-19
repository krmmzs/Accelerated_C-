# chapter 05 Using sequential containers and analyzing strings

## Overview

## side effect case misguided optimization

bad code :

```cpp
vector<Student_info>::size_type size = students.size();
while (i != size) {
    if (fgrade(students[i])) {
        fail.push_back(students[i]);
        students.erase(students.begin() + i);
    } else {
        ++i;
    }
}
```

## iterator Abstraction is selective ignorance

Abstraction is selective ignorance.
The details of what particular type an iterator has may be
complicated, but we don't need to understand these details.
All we need to know is how to refer to the iterator type,
and what operations the iterator allows. We need to know
the type so that we can create variables that are iterators.
We don't need to know anything about that type's implementation.
For example, our definition of **iter**

```cpp
vector<Student_info>::const_iterator iter = students.begin();
```
says that **iter** is of type **vector<Student_info>::const_iterator**. We don't know
the actual type of **iter**—that's an implementation detail of **vector**—nor do we need to
know. All that we need to know is that **vector<student_info>** has a member named
*const_iterator* that defines a type that we can use to obtain read-only access to
elements of the **vector**

## The meaning of students.erase (students.begin () + i)

Now that we understand more about iterators, we can see the real point of

```cpp
students.erase(students.begin() + i);
```

in the program in §5.1.1/77. We've already seen that **students.begin()** is an iterator
that refers to the initial element of **students**, and that **students.begin() + i** refers to
the **i**th element of **students**. What is important to realize is that this latter expression gets
its meaning from the definition of *+* on the types of **students.begin()** and **i**. In other
words, the iterator and index types determine the meaning of *+* in this expression.

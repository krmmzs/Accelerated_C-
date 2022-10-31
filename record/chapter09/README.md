# Defining new types

## Info

Much of the design of C++ rests on the idea of letting programmers create types that are as
easy to use as are the built-in types.

## not member function

```cpp
double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}
```

First, note the call to ::grade. Putting
:: in front of a name insists on using a version of that name that is not a member of
anything. 

## const function and const member function

```cpp
double Student_info::grade() const { ... } //  member-function version 
double grade(const Student_info&) { ... } //  original from §4.2.2/63
```

When we call a member function, the object of which it is a member is not an argument.
Therefore, there is no entry in the parameter list in which we might be able to say that the
object is const. Instead, we qualify the function itself, thereby making it a **const member
function**. Member functions that are const may not change the internal state of the object
on which they are executing: We are guaranteed that if we call s.grade() on behalf of a
**Student_info** object named s, doing so will not change the data members of s.

Because the function guarantees that it will not change the values in the object, we can call
it for const objects. By the same token, we cannot call nonconst functions on const
objects, so, for example, we cannot call the read member on behalf of a const
Student_info object. After all, a function such as read says that it can change the
object's state. Calling such a function on a const object could violate our const promise.

It is important to note that even if a program never creates any const objects directly, it
may create lots of references to const objects through function calls. When we pass a
nonconst object to a function that takes a const reference, then the function treats that
object as if it were const, and the compiler will permit it to call only const members of
such objects

## A rule to judge whether a function should be member function

If the function changes the state of an
object, then it ought to be a member of that object. 

further more

To do so, we should think a bit about what the function does and how users might want to
call it.

## A part of interface should at same file

Because **compare** is 
part of our interface, we should include a declaration for this function in the same header
that defines **Student_info** and we should include this definition in the associated source
file that contains the definitions of the member functions.

see [Studnet_info.h](../../unix-source/chapter09/Student_info.h) and [Student_info.cc](../../unix-source/chapter09/Student_info.cc)

## The synthesized constructor

[C++ default initialization and value initialization: which is which, which is called when and how to reliably initialize a template-type member](https://stackoverflow.com/questions/8106016/c-default-initialization-and-value-initialization-which-is-which-which-is-ca)

The synthesized constructor will initialize the data members to a value that depends on how
the object is being created.
If the object is a local variable, then the data members will be be
default-initialized (§3.1/38).
If the object is used to initialize a container element, either as a
side effect of adding a new element to a map, or as the elements of a container defined to
have a given size, then the members will be value-initialized (§7.2/125).

These rules areslightly complicated, but their essentials are:

- If an object is of a class type that defines one or more constructors, then the
appropriate constructor completely controls initialization of the objects of that class.
- If an object is of built-in type, then value-initializing it sets it to zero, and default-initializing it gives it an undefined value.
- Otherwise, the object can be only of a class type that does not define any constructors.
In that case, value- or default-initializing the object value- or default-initializes each of
its data members. This initialization process will be recursive if any of the data
members is of a class type with its own constructor.

## class write conctructor is a good habit

It is normally good practice to ensure that every data member has a sensible value at all times

For example, it is possible that later we
(or a subsequent maintainer of our code) will add operations that examine these data
members. If we don't initialize them in the constructor, then these new operations might
cause future failures. Moreover, as we'll see in §11.3.5/201, even though we do not
explicitly use midterm or final, there are synthesized operations on the class that could
do so. Any use other than writing to an undefined value is illegal (§3.1/38), and so, strictly
speaking, we must initialize these values.

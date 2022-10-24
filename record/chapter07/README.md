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

## Questions and Solutions

### Q0: Compile, execute, and test the programs in this chapter.

unix-code do make over

### Q1: Are the following definitions valid? Why or why not?
```
const std::string hello = "Hello";
const std::string message = hello + ", world" + "!";
```

valid

The first definition is a generic string definition.

The second definition have at least a string.

### Q2: Are the following definitions valid? Why or why not?
```
const std::string exclam = "!";
const std::string message = "Hello" + ", world" + exclam;
```
The first definition is valid, however, the second one is not. This is due to the addition of two string literals, which is invalid.

### Q3: Is the following program valid? If so, what does it do? If not, why not?
```
#include <iostream>
#include <string>

int main()
{
    { const std::string s = "a string";
      std::cout << s << std::endl; }
    { const std::string s = "another string";
      std::cout << s << std::endl; }
    return 0;
}
```
valid.

### Q4: What about this one? What if we change `}}` to `};}` in the third line from the end?
```
#include <iostream>
#include <string>

int main()
{
    { const std::string s = "a string";
      std::cout << s << std::endl;
    { const std::string s = "another string";
      std::cout << s << std::endl; }}
    return 0;
}
```

valid.

### Q5: Is this program valid? If so, what does it do? If not, say why not, and rewrite it to be valid.
```
#include <iostream>
#include <string>

int main()
{
    { std::string s = "a string";
    { std::string x = s + ", really";
      std::cout << s << std::endl; }
      std::cout << x << std::endl;
    }
    return 0;
}
```

```
g++     05.cpp   -o 05
05.cpp: In function ‘int main()’:
05.cpp:9:20: error: ‘x’ was not declared in this scope
    9 |       std::cout << x << std::endl;
      |                    ^
make: *** [<builtin>: 05] Error 1
```

rewrited code in ./05.cpp

### Q6: What does the following program do if, when it asks you for input, you type two names (for example, `Samuel Beckett`)? Predict the behavior before running the program, then try it.
```
#include <iostream>
#include <string>

int main()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name
              << std::endl << "And what is yours? ";
    std::cin >> name;
    std::cout << "Hello, " << name
              << "; nice to meet you too!" << std::endl;
    return 0;
}
```
This example takes two inputs to greet two people. Typing two names at the same time is the same as typing two names separately, as `std::cin` takes the first input until the whitespace (not before a character), so both inputs will be consumed by the two `std::cin` input streams.

# Managing memory and low-level data structures

## Pointers to functions

Because all that you can do with a function is to take its address or call it, any use of a
function that is not a call is assumed to be taking its address, even without an explicit &.

## Pointer arithmetic

In other words, suppose that **a** is an **n**-element array, that v is a vector, and that we wan
to apply standard-library algorithms to elements of a. Then, wherever we might use
**v.begin()** and **v.end()** to give standard-library algorithms access to elements of *v*, we
should use **a** and **a + n** as arguments when we wish to apply these algorithms to the
elements of **a**.

## char* array and a pointer to a char* array in main function

Because "A+" is char array, and "A" is a pointer to char array.
need char* to catch the return value of "A+".

char* array:
```cpp
static const char* const letters[] = {
    "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"
};
```

## get array size use sizeof

```cpp
static const double numbers[] = {
    1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9
}
std::size_t size = sizeof(numbers) / sizeof(*numbers);
```

this programs show main

```cpp
int main(int argc, char **argv) {
    int fail_count = 0;
    // for each file in the input list
    for (int i = 1; i < argc; i ++) {
        ifstream in(argv[i]);

        // if it exists, write its contents, otherwise generate an error message
        if (in) {
            string s;
            while (getline(in, s)) {
                cout << s << endl;
            }
        } else {
            cerr << "cannot open file " << argv{i] << endl;
            fail_count ++;
        }
    }
    return fail_count;
}
```

## Initializing arrays of character pointers

a string literal is just a convenient way of writing the address of
the initial character of a null-terminated sequence of characters.

## ifstream and ofstream are kind of istream and ostream

The standard library says exactly that, by defining **ifstream** to be a kind of **istream** and **ofstream** to be a kind of **ostream**. 
As a result, it is possible to use an **ifstream** wherever the library
expects an **istream** and an **ofstream** wherever the library expects an **ostream** . 

## file name need a pointer to the initial element of a null-terminated sequence of characters character array

**C++11 could use string as name**
see [std::basic_ifstream](https://zh.cppreference.com/w/cpp/io/basic_ifstream/open)

you could see this overload function
```cpp
void open( const std::string &filename,                                  
           ios_base::openmode mode = ios_base::in );(3)	(C++11 起)
```

When we define an **ifstream** or **ofstream** object, we might expect to have to supply, in
the form of a **string** , the name of the file that we wish to use. In fact, we are required to
supply, not a **string** , but rather a pointer to the initial element of a null- terminated
character array. One reason for this curious requirement is to give programs the option of
using the input-output library without using the **string** facilities. Another reason is
historical: The input-output library predates the string class by several years. A third
reason is that this requirement makes it easier to interface with operating-system input
output facilities, which typically use such pointers to communicate. Whatever the reasons,
the fact is that programs that deal with files must ultimately express the files' names as
pointers to null-terminated character arrays.

## use c_str in string

If we don't want to have to give the name of the
file as a literal, the best alternative is to store the file name in a **string** and then use the
**c_str** member function.

```cpp
string file = "data.txt";
ifstream infile(file.c_str());
```

## new T[] Ex

```cpp
char* duplicate_chars(const char* p) {
    // allocate enough space; remember to add onre for the null
    size_t length = strlen(p) + 1;
    char* result = new char[length];

    // copy into our newly allocated space and return pointer to first element
    copy(p, p + length, result);
    return result;
}
```

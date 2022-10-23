# chapter 06 Using library algorithms

## Overview

## The reason for back_inserter design

Why is **copy** designed this way? Because separating the notions of copying elements and expanding a container allows programmers to choose which operations to use. For example, we might want to copy elements on top of elements that already exist in a container, without changing the container's size. As another example, which we shall see in
§6.2.2/112, we might want to use **back_inserter** to append elements to a container that are not merely copies of another container's elements.

## split with iterators and algorithms functions

```cpp
bool space(char c)
{
	return isspace(c);
}

// `false' if the argument is whitespace, `true' otherwise
bool not_space(char c)
{
	return !isspace(c);
}

vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while (i != str.end()) {

		// ignore leading blanks
		i = find_if(i, str.end(), not_space);

		// find end of next word
		iter j = find_if(i, str.end(), space);

		// copy the characters in `[i,' `j)'
		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}

```

## pass an overloaded function directly as an argument to a template function

It's not easy to pass an overloaded function directly as an argument to a template function.
The trouble is that the compiler doesn't know which version of
the overloaded function we mean,
because we haven't supplied any arguments that the compiler
might use to select a version. Accordingly, we'll write our
own predicates, called **space** and **not_space** ,
that make clear whichversion of **isspace** we intend.

more see [C++ overloaded function as template argument](https://stackoverflow.com/questions/25871381/c-overloaded-function-as-template-argument)

## is_palindrome

```cpp
bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}
```

## find find_if search 

```cpp
bool not_url_char(char c) {
    // characters, in addition to alphanumerics, that can appear in a URL.
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    // see whether c can appear in a URL and return the nagative
    return !(isalnum(c) ||
    find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
    return find_if(b, e, not_url_char);
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {
    static const string sep = "://";

    typedef string::const_iterator iter;

    // i marks where the separatorwas found
    iter i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e) {

        // make sure the separator isn't at the beginning or end of the line
        if (i != b && i + sep.size() != e) {

            // beg marks the beginning of the protocol-name
            iter beg = i;
            while (beg != b && isalpha(beg[-1])) {
                beg --;
            }

            // is there at least one appreciate character before and after the sep
            if (beg != i && !not_url_char(i[sep.size()])) {
                return beg;
            }
        }
        // the separator we found wasn't part of a URL advance i past this separator
        i += sep.size();
    }

    return e;
}

vector<string> find_urls(const string& s) {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    // look through the entire input
    while (b != e) {

        // look for one or more letters followed by ://
        b = url_beg(b, e);

        // if we found it
        if (b != e) {
            // get the rest of the URL
            iter after = url_end(b, e);

            // remember the URL
            ret.push_back(string(b, after));

            // advance b and check for more URLs on this line
            b = after;
        }
    }
    return ret;
}
```

## empty instead of size

It is a better idea to use this function to check for 
an emptycontainer than it is to compare the **size** with 0,
because for some kinds of containers, itmight be more efficient
to check whether the container has any elements than to figure
outexactly how many elements there are.

more see [What is the most efficient way to check if a C++ container is empty?](https://stackoverflow.com/questions/43500633/what-is-the-most-efficient-way-to-check-if-a-c-container-is-empty)

## transform

```cpp
double grade_aux(const Student_indo& s) {
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

// this version works fine
double median_analysis(const vector<Student_info>& students) {
    vector<double> grades;

    transform(students.begin(), students.end(),
            back_inserter(grades), grade_aux);
    return median(grades);
}
```

## accumulate(in <numeric>)

```cpp
double average(const vector<double>& v) {
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}
```

## remove_copy(copy like "remove")

Copies elements from the range [first, last), to another range beginning at d_first,
omitting the elements which satisfy specific criteria. Source and destination ranges cannot overlap.

```cpp
// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s) {
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(),
            back_inserter(nonzero), 0);

    if (nonzero.empty()) {
        return grade(s.midterm, s.final, 0);
    } else {
        return grade(s.midterm, s.final, median(nonzero));
    }
}
```

## copy_if vs remove_copy_if

`copy_if` only copies elements satisfying a given predicate,

`remove_copy_if` **on the other hand** copies only elements that **do not** satisfy a specified predicate.

Thus the two functions complement each other, they do not do the same.



```cpp
// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s) {
    vector<double> nonzero;
    copy_if(s.homework.begin(), s.homework.end(),
            back_inserter(nonzero), [](double x) { return x != 0; });

    if (nonzero.empty()) {
        return grade(s.midterm, s.final, 0);
    } else {
        return grade(s.midterm, s.final, median(nonzero));
    }
}
```

## remove_if

Removes all elements satisfying specific criteria from the
range [first, last) and **returns a past-the-end iterator for
the new end of the range**.(The elements are actually removed,
but the physical size of the container is not changed, which
causes the elements to be "lost".)

```cpp
vector<Student_info>
extract_fails(vector<Student_info>& students) {
    vector<Student_info> fail;
    remove_copy_if(students.begin(), students.end(),
            back_inserter(fail), pgrade);
    students.erase(remove_if(students.begin(), students.end(), fgrade),
            students.end());
    return fail;
}
```

<img src="/images/remove_if01.png" alt="remove_if01.png" style="zoom:70%;" />
<img src="/images/remove_if02.png" alt="remove_if02.png" style="zoom:70%;" />

if call erase after remove_if, the elements will be removed from the container.

<img src="/images/remove_if03.png" alt="remove_if03.png" style="zoom:70%;" />

## partition and stable_partition

```cpp
vector<Student_info>
extract_fails(vector<Student_info>& students) {
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
    vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());
    return fail;
}
```

<img src="/images/partition01.png" alt="partition01.png" style="zoom:60%;" />

## Algorithms and containers

There is a fact that is crucial to understand in using algorithms, iterators, and containers:

**Algorithms act on container elements—they do not act on containers.**

EX:
remove_if is a generic function only move elements to new position,
but does not change the size of the container.

erase is not a generic function, it is a member function of the container.
erase changes the vector by removing the sequence indicated by its arguments

## iterators and container

it is important to be aware of the interaction between iterators and algorithms,
and between iterators and container operations. 

EX:
generic algorithms:
iterators are invalidated by erase or insert operations on the container.

member functions:
can move elements aroundwithin the container, will change which element is denoted by particular iterators.
iterators are invalidated partition or remove_if operations on the container.

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

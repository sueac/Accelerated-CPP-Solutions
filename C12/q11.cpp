#include <iostream>
#include <algorithm>
#include "Vec.h"
#include "MyStr.h"

using std::cout;
using std::endl;
using std::find_if;
using std::copy;
using std::max;

Vec<MyStr> split(const MyStr& s)
{
    Vec<MyStr> ret;
    typedef MyStr::size_type string_size;
    string_size i = 0;

    // invariant: we have processed characters [original value of i, i)
    while (i != s.size()) {
        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
            ++i;

        // find end of next word
        string_size j = i;
        // invariant: none of the characters in range [original j, current j) is a space
        while (j != s.size() && !isspace(s[j]))
            ++j;

        // if we found some nonwhitespace characters
        if (i != j) {
            // copy from s starting at i and taking j - i chars
            ret.push_back(MyStr(s.begin() + i, s.begin() + j));
            i = j;
        }
    }
    return ret;
}

bool not_isspace(char c)
{
    return !isspace(c);
}

Vec<MyStr> other_split(const MyStr& str)
{
    typedef MyStr::const_iterator iter;
    Vec<MyStr> ret;

    iter i = str.begin();
    while (i != str.end()) {

        // ignore leading blanks
        i = find_if(i, str.end(), not_isspace);

        // find end of next word
        iter j = find_if(i, str.end(), isspace);

        // copy the characters in [i, j)
        if (i != str.end())
            ret.push_back(MyStr(i, j));
        i = j;
    }
    return ret;
}

MyStr::size_type width(const Vec<MyStr>& v)
{
    MyStr::size_type maxlen = 0;
    for (Vec<MyStr>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

Vec<MyStr> frame(const Vec<MyStr>& v)
{
    Vec<MyStr> ret;
    MyStr::size_type maxlen = width(v);
    MyStr border(maxlen + 4, '*');

    // write the top border
    ret.push_back(border);

    // write each interior row, bordered by an asterisk and a space
    for (Vec<MyStr>::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] +
                      MyStr(maxlen - v[i].size(), ' ') + " *");
    }

    // write the bottom border
    ret.push_back(border);
    return ret;
}

Vec<MyStr> vcat(const Vec<MyStr>& top, const Vec<MyStr>& bottom)
{
    // copy the top picture
    Vec<MyStr> ret(top);

    // copy entire bottom picture
    for (Vec<MyStr>::const_iterator it = bottom.begin();
         it != bottom.end(); ++it)
        ret.push_back(*it);

    return ret;
}

Vec<MyStr> hcat(const Vec<MyStr>& left, const Vec<MyStr>& right)
{
    Vec<MyStr> ret;

    // add 1 to leave a space between pictures
    MyStr::size_type width1 = width(left) + 1;

    // indices to look at elements from left and right respectively
    Vec<MyStr>::size_type i = 0, j = 0;

    // continue until we've seen all rows from both pictures
    while (i != left.size() || j != right.size()) {
        // construct new MyStr to hold characters from both pictures
        MyStr s;

        // copy a row from the left-hand side, if there is one
        if (i != left.size())
            s = left[i++];
        
        // pad to full width
        s += MyStr(width1 - s.size(), ' ');

        // copy a row from the right-hand side, if there is one
        if (j != right.size())
            s += right[j++];

        // add s to the picture we're creating
        ret.push_back(s);
    }
    return ret;
}

int main()
{
    MyStr s1 = "Hello, world!";
    MyStr s2 = "Goodbye, world!";
    Vec<MyStr> f1 = frame(split(s1));
    Vec<MyStr> f2 = frame(other_split(s2));

    Vec<MyStr> v = vcat(f1, f2);
    Vec<MyStr> h = hcat(f1, f2);

    for (Vec<MyStr>::size_type i = 0; i != v.size(); ++i)
        cout << v[i] << endl;

    for (Vec<MyStr>::size_type i = 0; i != h.size(); ++i)
        cout << h[i] << endl;

    return 0;
}

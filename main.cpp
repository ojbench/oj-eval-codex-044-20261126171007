#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class mystring
{
private:
    char *ch = nullptr;
    int len = 0;

public:
    mystring() = default;

    mystring(int _len, int c) : ch(new char[_len]), len(_len)
    {
        for (int i = 0; i < len; ++i)
            ch[i] = static_cast<char>(c);
    }

    mystring(string &c) : ch(new char[c.length()]), len(c.length())
    {
        for (int i = 0; i < len; ++i)
            ch[i] = c[i];
    }

    mystring(const mystring &other) : ch(new char[other.len]), len(other.len)
    {
        for (int i = 0; i < len; ++i)
            ch[i] = other.ch[i];
    }

    mystring &operator=(const mystring &other)
    {
        if (this == &other)
            return *this;
        char *replacement = new char[other.len];
        for (int i = 0; i < other.len; ++i)
            replacement[i] = other.ch[i];
        delete[] ch;
        ch = replacement;
        len = other.len;
        return *this;
    }

    ~mystring()
    {
        delete[] ch;
    }

    char operator[](int index) const
    {
        return index >= 0 && index < len ? ch[index] : '\0';
    }

    bool operator<(const mystring &other) const
    {
        for (int i = 0; i < len && i < other.len; ++i)
        {
            if (ch[i] != other.ch[i])
                return static_cast<unsigned char>(ch[i]) <
                       static_cast<unsigned char>(other.ch[i]);
        }
        return len < other.len;
    }

    void ADD(const mystring &other)
    {
        const int combined_len = len + other.len;
        char *combined = new char[combined_len];
        for (int i = 0; i < len; ++i)
            combined[i] = ch[i];
        for (int i = 0; i < other.len; ++i)
            combined[len + i] = other.ch[i];
        // Finish both copies before releasing storage, including for self-append.
        delete[] ch;
        ch = combined;
        len = combined_len;
    }

    void out() const
    {
        for (int i = 0; i < len; ++i)
            cout << ch[i];
    }

    int get_len() const
    {
        return len;
    }
};

string str_in1, str_in2;
int n, id;
int main()
{
    cin >> id;
    if (id == 1)
    {
        mystring str1(100,'a');
        str1.out(); puts("");
        // cout << str1 << endl;
    }
    else if (id == 2)
    {
        cin >> str_in1;
        mystring str2 = str_in1;
        cin >> n;
        for (int i = 0, x; i < n; ++ i)
        {
            cin >> x;
            cout << str2[x] << endl;
        }
    }
    else if (id == 3)
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cout << (int)(str2 < str3) << endl;
    }
    else if (id == 4)
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
    }
    else
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cin >> n;
        for (int i = 0, x; i < n; ++ i)
        {
            cin >> x;
            cout << str3[x] << endl;
        }
        cout << str2.get_len() << " " << str3.get_len() << endl;
        cout << (int)(str2 < str3) << endl;
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
        cout << str2.get_len() << endl;
    }
    return 0;
}

//Exercise 2.18:

#include <iostream>
using namespace std;
int main() {
    int x(19), y(2006); 
    int *z(&x); 
    cout << *z << "\t" << z << endl; 
    z = &y; 
    cout << *z << "\t" << z << endl; 
    return 0; 
}

//Exercise 2.20:

#include <iostream>
using namespace std;

int main() {
    int x(19);
    int *y(&x);
    cout << *y << "\t" << y << "\t" << x << endl;
    *y *= *y;
    cout << *y << "\t" << y << "\t" << x << endl;
    return 0;
}

//Exercise 2.22:

#include <iostream>
using namespace std;

int main() {
    int i(19);
    int *x(nullptr);
    if (x)
    {
        cout << "add" << endl;
    }
    if (*x)
    {
        cout << "value" << endl;
    }
    return 0;
}

//Exercise 2.32:

#include <iostream>
using namespace std;

int main() {
    int null(0);
    int *p(&null);
    cout << *p << endl;
    return 0;
}
#include <iostream>
using namespace std;

struct Sales_item {
    unsigned int unitsSold = 0;
    double revenue() {
        return {unitsSold*3.14159};
    };
};

//Exercise 2.40:

#include <iostream>
using namespace std;

struct Sales_item {
    double unitsSold = 0;
    double revenue() {
        return {unitsSold*3.14159};
    };
};

int main() {
    Sales_item books;
    while (true)
    {
        double temp(0);
        cin >> temp;
        books.unitsSold = temp;
        cout << books.revenue() << "\n";
    }
    return 0;
}

//Exercise 3.2:

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef string str;

int main() {
    str s;
    while (getline(cin, s))
    {
        cout << s << endl;
    }
    return 0;
}

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef string str;

int main() {
    str s;
    while (cin >> s)
    {
        cout << s << " ";
    }
    return 0;
}

//Exercise 3.4:

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef string str;

int main() {
    str s0, s1;
    while (true)
    {
        //reading input
        getline(cin, s0);
        getline(cin, s1);

        //logic
        if (s0 == s1)
        {
            cout << "both str are same\n";
        }
        if (s0 < s1)
        {
            cout << "s1 is larger\n";
        }
        else {
            cout << "s0 is larger\n";
        }
    }
    return 0;
}

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef string str;

int main() {
    str s0, s1;
    while (true)
    {
        //reading input
        getline(cin, s0);
        getline(cin, s1);

        //logic
        if (s0.size() == s1.size())
        {
            cout << "both str have same length\n";
        }
        if (s0.size() < s1.size())
        {
            cout << "s1 is longer\n";
        }
        else {
            cout << "s0 is longer\n";
        }
    }
    return 0;
}

//Exercise 3.5:

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef string str;

int main() {
    str s, temp;
    while (cin >> temp)
    {
        s += temp;
    }
    //pres ctrl+d to end file life and print the ouptut.
    cout << s << endl;
    return 0;
}

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef string str;

int main() {
    str s, temp;
    while (cin >> temp)
    {
        s += temp + ' ';
    }
    //pres ctrl+d to end file life and print the ouptut.
    cout << s << endl;
    return 0;
}

//Random:

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef string str;

int main() {
    char tempc;
    str line, templ;
    while (getline(cin, line))
    {
        for (char c : line)
            if (c >= 97 && c <= 122)
            {
                tempc = c - 32;
                templ += tempc;
            }
            else {
                templ += c;
            }
        cout << templ << endl;
        templ.clear();  
    }
    return 0;
}

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef string str;

int main() {
    str line, templ;
    while (getline(cin, line))
    {
        for (auto c : line)
            templ += toupper(c);
        cout << templ << endl;
        templ.clear();  
    }
    return 0;
}

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef string str;

int main() {
    str line;
    while (getline(cin, line))
    {
        for (auto &c : line)
            c = toupper(c);
        cout << line << endl; 
    }
    return 0;
}

//Exercise 3.14:

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

typedef string str;

int main() {
    vector<int> ivec;
    int i;
    while (cin >> i)
    {
        ivec.push_back(i);
        cout << "\n";
        for (int i : ivec)
        {
            cout << i << endl;
        }
        cout << "\n";
    }
    return 0;
}

//Exercise 3.15:

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

typedef string str;

int main() {
    vector<str> ivec;
    str i;
    while (cin >> i)
    {
        ivec.push_back(i);
        cout << "\n";
        for (str i : ivec)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

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

//Exercise 2.32
#include <iostream>
using namespace std;

int main() {
    int null(0);
    int *p(&null);
    cout << *p << endl;
    return 0;
}

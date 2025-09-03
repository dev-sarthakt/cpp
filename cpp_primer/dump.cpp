//Exercise 2.18: Write code to change the value of a pointer. Write code to change the value to which the pointer points.
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

//Exercise 2.20: What does the following program do?
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

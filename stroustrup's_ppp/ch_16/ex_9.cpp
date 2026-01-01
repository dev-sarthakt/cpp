#include <iostream>
#include <string>
using namespace std;

string cat_dot(const char *a, const char *b, string c){
    string str = "";
    for (int i = 0; a[i] != '\0'; i++)
    {
        str += a[i];
    }
    str += c;
    for (int i = 0; b[i] != '\0'; i++)
    {
        str += b[i];
    }
    return str;
}

int main(){
    const char *first = "Sarthak", *last = "Thange";
    cout << cat_dot(first, last, " | ") << endl;
    return 0;
}

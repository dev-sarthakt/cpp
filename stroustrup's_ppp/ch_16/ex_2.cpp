#include <iostream>
using namespace std;

char* str_dup(char *c){
    int sz = 0;
    while (c[sz] != '\0')
    {
        sz++;
    }
    sz++;
    char *arr = new char[sz];
    for (int i = 0; i < sz; i++)
    {
        arr[i] = c[i];
    }
    return arr;
}

int main(){
    char *name = "Sarthak", *name_dup = str_dup(name);
    for (int i = 0; name_dup[i] != '\0'; i++)
    {
        cout << name_dup[i];
    }
    
    return 0;
}

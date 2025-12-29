#include <iostream>
using namespace std;

int main() {
    char c;
    int size = 0, cap = 8;
    char * p = new char[cap];
    scanf("%c", &c);

    while (c != '!')
    {
        if (size != cap)
        {
            p[size] = c;
            size++;
        }
        else{
            char *p_2 = new char[cap*2];
            for (int i = 0; i < size; i++)
            {
                p_2[i] = p[i];
            }
            p_2[size] = c;
            size++, cap *= 2;
            delete[] p;
            p = p_2;
        }
        scanf("%c", &c);
    }
    for (int i = 0; i < size; i++)
    {
        cout << p[i];
    }
    
    return 0;
}

#include <iostream>
using namespace std;

bool strCmp(const char *a, const char *b){
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
        
    }
    return true;
}

char *find(const char *s, const char *x){
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (strCmp(x, s+i))
        {
            return const_cast<char *> (&s[i]);
        }
        
    }
    return nullptr;
}

int main(){
    const char *line = "hi fellow's this is sarthak over and out.", *name = "sarthak";
    char *c = find(line, name);
    for (int i = 0; c[i] != '\0'; i++)
    {
        cout << c[i];
    }
}

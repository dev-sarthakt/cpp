#include <iostream>
using namespace std;

int str_cmp(const char *s1, const char *s2){
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
    {
        if (s1[i] < s2[i])
        {
            return -1;
        }
        else if (s1[i] > s2[i])
        {
            return 1;
        }
    }
    return 0;
}

int main(){
    const char *s1 = "sarthak", *s2 = "Sarthak";
    cout << str_cmp(s1, s2) << endl;
    return 0;
}

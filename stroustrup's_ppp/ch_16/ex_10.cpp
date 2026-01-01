#include <iostream>
using namespace std;

void assign_cstr(char *mem, char *str){
    int i = 0;
    for (; str[i] != '\0'; i++)
    {
        mem[i] = str[i];
    }
    mem[i] = '\0';
}

char *asign_mem(char *str){
    int i = 0;
    for (; str[i] != '\0'; i++)
    {
        ;
    }
    char *s = new char[i];
    assign_cstr(s, str);
    return s;
}

void print_cstr(char *str){
    for (int i = 0; str[i] != '\0'; i++)
    {
        cout << str[i];
    }
    delete [] str;
}

int main(){
    print_cstr(asign_mem(const_cast<char *> ("Sarthak")));
    cout << endl;
    return 0;
}

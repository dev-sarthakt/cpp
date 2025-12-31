#include <iostream>
#include <vector>
using namespace std;

int main(){
    int array[4];
    int *p = array;
    cout << p[0] << endl;
    return 0;
}

#include <iostream>
#include <span>
using namespace std;

void printLower(span<char> s){
    for (char c : s){
        if (c > 64 && c < 91)
        {
            cout << static_cast<char> (c+32);
        }
        else{
            cout << c;
        }
    }
}

int main(){
    char str[] = "SARTHAKT";
    span<char> string{str};
    printLower(string);
    return 0;
}

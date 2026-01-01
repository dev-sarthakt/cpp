#include <iostream>
#include <string>
using namespace std;

string cat_dot(const string &a, const string &b){
    return a+'.'+b;
}

int main(){
    const string first = "Sarthak", last = "Thange";
    cout << cat_dot(first, last) << endl;
    return 0;
}

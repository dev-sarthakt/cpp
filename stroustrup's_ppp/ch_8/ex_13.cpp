#include <iostream>
using namespace std;

class Rational{
    private:
        int numerator, denominator;
    public:
        Rational(int num) : numerator{num}, denominator{1} {}
        Rational(int num, int den) : numerator{num} {
            if (den == 0)
            {
                cerr << "Invalid Rational Number" << endl;
            }
            else {
                denominator = den;
            }
        }
        int get_num() const {
            return numerator;
        }
        int get_den() const {
            return denominator;
        }
        double get_double() const {
            return (1.0*numerator)/denominator;
        }
};

Rational operator+(Rational& a, Rational& b){
    return Rational((a.get_num()*b.get_den())+(b.get_num()*a.get_den()), (a.get_den()*b.get_den()));
}

Rational operator-(Rational& a, Rational& b){
    return Rational((a.get_num()*b.get_den())-(b.get_num()*a.get_den()), (a.get_den()*b.get_den()));
}

Rational operator*(Rational& a, Rational& b){
    return Rational(a.get_num()*b.get_num(), a.get_den()*b.get_den());
}

Rational operator/(Rational& a, Rational& b){
    return Rational(a.get_num()*b.get_den(), a.get_den()*b.get_num());
}

bool operator==(Rational& a, Rational& b){
    return a.get_double()==b.get_double();
}

int main(){
    Rational pi(22, 7);
    cout << pi.get_double() << endl;
    return 0;
}

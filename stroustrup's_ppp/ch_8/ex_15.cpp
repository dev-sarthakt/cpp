#include <iostream>
using namespace std;

class Money{
    private:
        long int cents;
        double factor;
    public:
        Money(double dollars, double fac) : factor{fac} {
            if ((dollars*fac*100-static_cast<int>(dollars*fac*100)) < 0.5)
            {
                cents = (static_cast<int>(dollars*fac*100));
            }
            else{
                cents = (static_cast<int>(dollars*fac*100))+1;
            }
        }
        double get_dollars() const;
};

double Money::get_dollars() const{
    return static_cast<double>(cents)/100;
}

Money operator+(const Money& a, const Money& b){
    return Money(a.get_dollars()+b.get_dollars(), 1);
}

Money operator*(const Money& a, const Money& b) = delete;

ostream& operator<<(ostream& os, const Money& dollars){
    return os << "$" << dollars.get_dollars();
}

int main(){
    Money USD{1, 1}, INR{100, 0.01};
    cout << (USD+INR) << endl;
    return 0;
}

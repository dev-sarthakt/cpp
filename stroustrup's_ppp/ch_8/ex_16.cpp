#include <iostream>
#include <vector>
using namespace std;

class Money{
    private:
        string currency = "USD";
        long int cents = 0;
        double factor = 1;
        void set(string curr, double dollars, double fac) {
        currency = curr;
        factor = fac;
        cents = static_cast<long int>(dollars * fac * 100 + 0.5);
        }
    public:
        Money(){};
        Money(string curr, double dollars, double fac) : currency{curr}, factor{fac} {
            if ((dollars*fac*100-static_cast<int>(dollars*fac*100)) < 0.5)
            {
                cents = (static_cast<int>(dollars*fac*100));
            }
            else{
                cents = (static_cast<int>(dollars*fac*100))+1;
            }
        }
        double get_dollars() const;
        string get_currency() const;
        friend istream& operator>>(istream& is, Money& m);
};

double Money::get_dollars() const{
    return static_cast<double>(cents)/100;
}

string Money::get_currency() const {
    return currency;
}

Money operator+(const Money& a, const Money& b){
    return Money("USD", a.get_dollars()+b.get_dollars(), 1);
}

Money operator*(const Money& a, const Money& b) = delete;

istream& operator>>(istream& is, Money& m){
    string curr;
    double doll, fac;
    is >> curr >> doll >> fac;
    m.set(curr, doll, fac);
    return is;
}

ostream& operator<<(ostream& os, const Money& dollars){
    return os << dollars.get_currency() << dollars.get_dollars();
}

int main(){
    Money bank[2];
    cin >> bank[0] >> bank[1];
    cout << bank[0]+bank[1] << endl;
    return 0;
}

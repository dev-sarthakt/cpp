#include <iostream>
using namespace std;

class Money{
    private:
        long int cents;
    public:
        Money(double dollars){
            if ((dollars*100-static_cast<int>(dollars*100)) < 0.5)
            {
                cents = (static_cast<int>(dollars*100));
            }
            else{
                cents = (static_cast<int>(dollars*100))+1;
            }
        }
        double get_dollars() const;
};

double Money::get_dollars() const{
    return static_cast<double>(cents)/100;
}

ostream& operator<<(ostream& os, Money& dollars){
    return os << "$" << dollars.get_dollars();
}

int main(){
    Money nvidia{3455.275};
    cout << nvidia << endl;
    return 0;
}

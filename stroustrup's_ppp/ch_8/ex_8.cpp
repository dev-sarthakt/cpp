#include <iostream>
using namespace std;

class Patron{
    private:
        bool fee_pending = false;
        string name;
        int card_no, fees;
    public:
        Patron(int c_no, string n, int fee, bool status) : card_no{c_no}, name{n}, fees{fee}, fee_pending{status} {}
        string get_name() const {
            return name;
        }
        int get_card_no() const {
            return card_no;
        }
        bool get_fee_pending() const {
            return fee_pending;
        }
        void set_fees(int fee){
            fees = fee;
        }
        void set_fee_pending(bool b){
            fee_pending = b;
        }
};

int main(){
    Patron costumer_1{1904, "Sarthak", 2006, true};
    return 0;
}

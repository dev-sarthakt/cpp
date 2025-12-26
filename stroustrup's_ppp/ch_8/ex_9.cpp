#include <iostream>
#include <regex>
using namespace std;

struct date{
    int d, m, y;
};

class Book{
    private:
        string ISBN, title, author;
        struct date cpy_date;
        bool checked_in = true;
    public:
        Book(string isbn, string Title, string Author, string date) {
            regex pattern_1(R"(\d+-\d+-\d+-\d+$)");
            if (regex_match(isbn, pattern_1))
            {
                ISBN = isbn;
            }
            regex pattern_2(R"(\d+-\d+-\d+-.+$)");
            if(regex_match(isbn, pattern_2)){
                ISBN = isbn;
            }
            else{
                cerr << "Invalid ISBN" << endl;
            }
            title = Title;
            author = Author;
            regex pattern_3(R"((\d+)/(\d+)/(\d+)$)");
            smatch m;
            if (regex_match(date, m, pattern_3))
            {
                if((stoi(m[1]) > 0 && stoi(m[1]) < 32) && (stoi(m[2]) > 0 && stoi(m[2]) < 13)){
                    cpy_date.d = stoi(m[1]);
                    cpy_date.m = stoi(m[2]);
                    cpy_date.y = stoi(m[3]);
                }
            }
            else{
                cerr << "Invalid Copyright date" << endl;
            }
        }
        string get_isbn() const{
            return ISBN;
        }
        string get_title() const{
            return title;
        }
        string get_author() const{ 
            return author;
        }
        struct date get_cpy_date() const{
            return cpy_date;
        }
        void check_in(){
            checked_in = true;
        }
        void check_out(){
            checked_in = false;
        }
        bool check_status() const{
            return checked_in;
        }
};

ostream& operator<<(ostream& os, Book& b){
    return os << "Title : " << b.get_title() << " | Author : " << b.get_author() << " | ISBN : " << b.get_isbn() << " | Copyright : " << (b.get_cpy_date()).d << "/" << (b.get_cpy_date()).m << "/" << (b.get_cpy_date()).y;
}

class Patron{
    private:
        string name;
        int card_no, fees;
        bool checked_in = false;
    public:
        Patron(int c_no, string n, int fee) : card_no{c_no}, name{n}, fees{fee} {}
        string get_name() const {
            return name;
        }
        int get_card_no() const {
            return card_no;
        }
        bool get_fee_pending() const {
            return fees > 0;
        }
        void set_fees(int fee){
            fees = fee;
        }
        void check_in() {
            checked_in = true;
        }
        void check_out() {
            checked_in = false;
        }
};

ostream& operator<<(ostream& os, Patron& b){
    return os << "Card No : " << b.get_card_no() << " | Name : " << b.get_name();
}

struct transaction{
    Book b;
    Patron p;
    date d;
    transaction(Book book, Patron patron, date dt) : b{book}, p{patron}, d{dt} {}
};

ostream& operator<<(ostream& os, struct transaction& trans){
    return os << "Book ----> " << trans.b << "\n" << "Patron ----> " << trans.p << "\n" << "Transaction Date ----> " << (trans.d).d << "/" << (trans.d).m << "/" << (trans.d).y;
}

class Library{
    private:
        vector<Book> books;
        vector<Patron> paterons;
        vector<transaction> transactions;
    public:
        void print_transactions() const {
            for(auto i : transactions)
            {
                cout << i << endl;
            }
            
        }
        void who_owes() const {
            for(auto& i : paterons)
            {
                if (i.get_fee_pending())
                {
                    cout << i.get_name() << endl;
                }
                else{
                    continue;
                }
            }
            
        }
        void add_books(string isbn, string Title, string Author, string date){
            Book temp_book{isbn, Title, Author, date};
            temp_book.check_in();
            books.push_back(temp_book);
             
        }
        void add_patron(int c_no, string n, int fee){
            Patron temp_patron{c_no, n, fee};
            temp_patron.check_in();
            paterons.push_back(temp_patron);

        }
        void process_transaction(string ISBN, int c_no, string date){
            for(auto& i : books)
            {
                if (i.get_isbn() == ISBN && i.check_status())
                {
                    for(auto& j : paterons)
                    {
                        if (j.get_card_no() == c_no && !(j.get_fee_pending()))
                        {
                            regex pattern_4(R"((\d+)/(\d+)/(\d+)$)");
                            smatch m;
                            if (regex_match(date, m, pattern_4))
                            {
                                if((stoi(m[1]) > 0 && stoi(m[1]) < 32) && (stoi(m[2]) > 0 && stoi(m[2]) < 13)){
                                struct transaction temp_transaction{i, j, {stoi(m[1]), stoi(m[2]), stoi(m[3])}};
                                transactions.push_back(temp_transaction);
                                }
                            }
                            i.check_out();
                            j.check_out();
                            
                        }
                        
                    }
                    
                }
            
            }
            
        }
};

int main(){
    Library collage;
    collage.add_books("19-04-2006-S", "Stranger Things", "Duffer Brothers", "26/12/2016");
    collage.add_patron(2006, "Sarthak", 0);
    collage.add_patron(2010, "Soham", 1000);
    collage.process_transaction("19-04-2006-S", 2006, "26/12/2025");
    collage.who_owes();
    printf("\n");
    collage.print_transactions();
    return 0;
}

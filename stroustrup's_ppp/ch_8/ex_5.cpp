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
        bool checked = true;
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
        string get_isbn(){
            return ISBN;
        }
        string get_title(){
            return title;
        }
        string get_author(){
            return author;
        }
        struct date get_cpy_date(){
            return cpy_date;
        }
        void check_in(){
            checked = true;
        }
        void check_out(){
            checked = false;
        }
        string check_status(){
            if (checked)
            {
                return "True";
            }
            else{
                return "False";
            }
        }
};

ostream& operator<<(ostream& os, Book& b){
    return os << "Title : " << b.get_title() << " | Author : " << b.get_author() << " | ISBN : " << b.get_isbn() << " | Copyright : " << (b.get_cpy_date()).d << "/" << (b.get_cpy_date()).m << "/" << (b.get_cpy_date()).y << " | Status : " << b.check_status();
}

int main(){
    Book stranger_things{"19-04-2006-S", "Stranger Things", "Duffer Brothers", "25/12/2025"};
    cout << stranger_things << endl;
    return 0;
}

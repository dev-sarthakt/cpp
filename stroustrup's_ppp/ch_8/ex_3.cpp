#include <iostream>
#include <vector>
using namespace std;

class Name_pairs{
    private:
        vector<string> name;
        vector<double> age;
    public:
        void read_name();
        void read_age();
        void sort();
        int size();
        const vector<string>& names() const;
        const vector<double>& ages() const;
};

const vector<string>& Name_pairs::names() const{
    return name;
}

const vector<double>& Name_pairs::ages() const{
    return age;
}

int Name_pairs::size(){
    return name.size();
}

ostream& operator<<(ostream& os, Name_pairs& np){
    auto temp_names = np.names();
    auto temp_ages = np.ages();
    for (int i = 0; i < np.size(); i++)
    {
        os << temp_names[i] << '\t' << temp_ages[i] << '\n';
    }
    return os;
}

bool operator==(Name_pairs& a, Name_pairs& b){
    return (a.names() == b.names()) && (a.ages() == b.ages());
}

bool operator!=(Name_pairs& a, Name_pairs& b){
    return !(a == b);
}

void Name_pairs::read_name(){
    string s;
    cin >> s;
    name.push_back(s);
}

void Name_pairs::read_age(){
    double a;
    cin >> a;
    age.push_back(a);
}

void Name_pairs::sort(){
    string temp_name;
    double temp_age;
    for (int i = 0; i < name.size(); i++)
    {
        for (int j = i+1; j < name.size(); j++)
        {
            if (name[i] > name[j])
            {
                temp_name = name[i];
                name[i] = name[j];
                name[j] = temp_name;

                temp_age = age[i];
                age[i] = age[j];
                age[j] = temp_age;
            }
            else{
                continue;
            }
        }
        
    }
    
}

int main(){
    Name_pairs database;
    for (int i = 0; i < 5; i++)
    {
        database.read_name();
        database.read_age();
    }
    printf("\n");
    cout << database << endl;
    database.sort();
    printf("\n");
    cout << database << endl;
    return 0;
}

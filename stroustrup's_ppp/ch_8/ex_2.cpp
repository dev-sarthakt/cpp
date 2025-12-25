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
        void print();
};

void Name_pairs::print(){
    for (int i = 0; i < name.size(); i++)
    {
        printf("%s\t%lf\n", name[i].c_str(), age[i]);
    }
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
    database.print();
    printf("\n");
    database.sort();
    printf("\n");
    database.print();
    return 0;
}

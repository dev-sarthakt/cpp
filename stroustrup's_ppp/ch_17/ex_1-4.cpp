#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Mat{
    private:
        int r = 0, c = 0;
        vector<double> m;
    public:
        Mat(int row, int col) : r{row}, c{col} {
            m.resize(r*c);
        };
        Mat(initializer_list<double> lst) {
            int i = 0;
            r=c=sqrt(lst.size());
            m.resize(lst.size());
            for (double x : lst)
            {
                m[i] = x;
                i++;
            }
            
        }
        ~Mat(){
            ;
        };
        vector<double> row(int r);
        vector<double> col(int c);
        Mat& operator=(const Mat &a);
        double& operator()(int r, int c);
        Mat& operator+=(Mat& a);
        friend bool operator==(const Mat &a, const Mat &b);
        friend Mat operator+(const Mat &a, const Mat &b);
        friend ostream& operator<<(ostream& os, Mat a);
};



Mat& Mat::operator=(const Mat &a){
    if (r != a.r || c != a.c)
    {
        cerr << "Invalid Dim" << endl;
        exit(-1);
    }
    else{
        m.resize(a.r*a.c);
        m = a.m;
        return *this;
    }
}

double& Mat::operator()(int r, int c){
    return m[(this->c*(r-1))+c-1];
}

Mat operator+(const Mat& a, const Mat& b){
    if (a.r != b.r || a.c != b.c)
    {
        cerr << "Invalid Dim" << endl;
        exit(-1);
    }
    else{
        Mat temp(a.r, a.c);
        for (int i = 0; i < a.r*a.c; i++)
        {
            temp.m[i] = a.m[i]+b.m[i];
        }
        return temp;
    }
}

bool operator==(const Mat &a, const Mat &b){
    if (a.r != b.r || a.c != b.c)
    {
        return false;
    }
    else{
        for (int i = 0; i < a.r*a.c; i++)
        {
            if (a.m[i] != b.m[i])
            {
                return false;
            }
            else{
                return true;
            }
        }
        
    }
}

ostream& operator<<(ostream& os,  Mat a){
    for (int i = 0; i < a.r; i++)
    {
        if (i != 0)
        {
            os << "\n";
        }
        
        for (int j = 0; j < a.c; j++)
        {
            os <<  a(i+1, j+1) << "\t";
        }
        
    }
    return os;
}

Mat& Mat::operator+=(Mat& a){
    return *this = *this + a;
}

vector<double> Mat::row(int r){
    vector<double> temp;
    for (int i = 0; i < this->c; i++)
    {
        temp.push_back((*this)(r, i+1));
    }
    return temp;
}

vector<double> Mat::col(int c){
    vector<double> temp;
    for (int i = 0; i < this->r; i++)
    {
        temp.push_back((*this)(i+1, c));
    }
    return temp;
}

int main(){
    Mat m1(3,3), m2(3,3), m3(3,3);
    m1  = {1,2,3,4,5,6,7,8,9};
    m2 = {9,8,7,6,5,4,3,2,1,0};
    m3 = m1+m2;
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            cout << m1(i,j) << "\t" << m2(i,j) << "\t" << m3(i,j) << "\t";
            if (m1(i,j)==m2(i,j))
            {
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        
    }
    cout  << (m1+m2) << endl;
    
    cout << (m1+=m2) << endl;

    for (double x : m2.col(1))
    {
        cout << x << endl;
    }
    
    return 0;
}

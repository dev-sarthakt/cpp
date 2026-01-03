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
        Mat& operator=(const Mat &a);
        double& operator()(int r, int c);
        friend bool operator==(const Mat &a, const Mat &b);
        friend Mat operator+(const Mat &a, const Mat &b);
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
    
    return 0;
}

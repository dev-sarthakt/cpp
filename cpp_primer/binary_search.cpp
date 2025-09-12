#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    int find;
    vector<int> ivec;
    for (int i = 0; i < 100; i++)
    {
        ivec.push_back(i);
    }
    vector<int>::iterator ivecitb(ivec.begin()), ivecite, ivecitm;
    vector<int>::difference_type diff;
    while (cin >> find)
    {
        ivecite = ivec.end();
        ivecitm = (ivecitb + ((ivecite - ivecitb)/2));
        while (ivecitb != ivecite && *ivecitm != find)
        {
            if (*ivecitm < find)
            {
                ivecitb = ivecitm;
            }
            else {
                ivecite = ivecitm - 1;
            }
            ivecitm = ivecitb + ((ivecite - ivecitb)/2);
        }
        ivecitb = ivec.begin();
        diff = ivecitm - ivecitb;
        cout << "Found " << find << " at index " << diff << endl;
    }
    return 0;
}

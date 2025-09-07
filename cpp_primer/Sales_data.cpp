#include "Sales_data.h"

int main() {
    Sales_data data1, data2;
    double price(0);
    //write in data1
    std::cin >> data1.bookNo >> data1.unitSold >> price;
    data1.revenue = data1.unitSold * price;
    //write in data2
    std::cin >> data2.bookNo >> data2.unitSold >> price;
    data2.revenue = data2.unitSold * price;
    //condition
    if (data1.bookNo == data2.bookNo)
    {
        unsigned int totalCnt(data1.unitSold + data2.unitSold);
        double totalRevenue(data1.revenue + data2.revenue);
        if (totalCnt != 0)
        {
            std::cout << "ISBN: " << data1.bookNo << " Sold: " << totalCnt << " Revenue: " << totalRevenue << " Avg: " << totalRevenue / totalCnt << "\n";
        }
        else {
            std::cout << "No Sale!\n";
        }
        return 0;
    }
    else {
        std::cerr << "Data must be for same ISBN.\n";
        return -1;
    }
    return 0;
}
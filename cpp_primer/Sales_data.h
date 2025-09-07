#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned int unitSold = 0;
    double revenue = 0.0;
};

#endif
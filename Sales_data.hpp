#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP
#include <iostream>
#include <string>
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif
#include "class.h"
#include <cstddef>
#include <iostream>
#include <string>

Stock::Stock() :
    tickerSymbol{"GOGL"},
    companyName{"Google"} {};

Stock::Stock(std::string tickerSymbol, std::string companyName) :
    tickerSymbol{tickerSymbol},
    companyName{companyName} {};

std::string Stock::getTickerSymbol() const {
    return this->tickerSymbol;
}

std::string Stock::getCompanyName() const {
    return this->companyName;
}

void Stock::setCompanyName(std::string name) {
    this->companyName = name;
}

double Stock::get_value_prev(size_t day) const {
    if (day >= 5) {
        std::cerr << "Class only stores last 5 days" << std::endl;
    }
    return last5value[day];
}

double Stock::getAverageValue() const {
    double sum;
    for (size_t day = 0; day < 5; ++day) {
        sum += Stock::get_value_prev(day);
    }

    return sum/5.0;
}

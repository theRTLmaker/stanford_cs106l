#include <string>

class Stock {
private:
    std::string tickerSymbol;
    std::string companyName;
    double last5value[5];

    double get_value_prev(size_t day) const;

public:
    Stock();
    Stock(std::string tickerSymbol, std::string companyName);

    std::string getTickerSymbol() const;
    std::string getCompanyName() const;
    void setCompanyName(std::string name);

    double getAverageValue() const;
};
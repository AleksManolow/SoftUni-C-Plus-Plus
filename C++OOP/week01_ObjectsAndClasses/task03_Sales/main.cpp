#include<iostream>
#include<string>
#include<vector>
#include <map>
#include<iomanip>
class Sale
{
private:
    std::string town;
    std::string product;
    double price;
    int quantity;
public:
        Sale(std::string _town, std::string _product, double _price, double _quantity) :
        town(_town), product(_product), price(_price), quantity(_quantity) {}

    std::string getTown()
    {
        return town;
    }

    double calcTotal()
    {
        return price * quantity;
    }

};


int main()
{
    std::vector<Sale> sales;
    
    int numOfInputs;
    std::cin >> numOfInputs;

    std::string town;
    std::string product;
    double price;
    double quantity;
    for (int i = 0; i < numOfInputs; ++i)
    {
        std::cin >> town >> product >> price >> quantity;
        Sale sale(town, product, price, quantity);
        sales.push_back(sale);
    }

    std::map<std::string, double> totalForEachCity;
    for(auto sale : sales)
    {
        totalForEachCity[sale.getTown()] += sale.calcTotal(); 
    }

    for (const std::pair<std::string, double>& p : totalForEachCity)
    {
        std::cout << p.first << " -> " << std::fixed << std::setprecision(2) << p.second << std::endl;
    }
    return 0;
}
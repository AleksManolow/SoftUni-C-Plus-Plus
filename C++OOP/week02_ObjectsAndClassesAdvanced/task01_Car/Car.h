#ifndef __CAR_H
#define __CAR_H

class Car
{
private:
    std::string brand;
    std::string model;
    int year;
public:
    Car(std::string _brand, std::string _model, int _year):brand(_brand), model(_model), year(_year)
    { }

    std::string GetBrand() const
    {
        return brand;
    }
    std::string GetModel() const
    {
        return model;
    }
    int GetYear() const
    {
        return year;
    }
};


#endif
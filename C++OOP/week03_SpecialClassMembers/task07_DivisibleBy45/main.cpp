#include<iostream>
#include"BigInt.h"
size_t digitSum(BigInt num)
{
    size_t sum = 0;
    std::string digits = num.getDigits();
    for (size_t i = 0; i < digits.size(); i++) {
        sum += digits[i] - '0';
    }
    return sum;
}
bool dividesBy9(BigInt num)
{
    return digitSum(num) % 9 == 0;
}
bool dividesBy5(BigInt num)
{
    std::string digits = num.getDigits();
    int lastInd = digits.size() - 1;
    return digits[lastInd] == '0' || digits[lastInd] == '5';
}
int main()
{
    std::string fisrtNum;
    std::string secoundNum;
    std::cin >> fisrtNum;
    std::cin >> secoundNum;

    BigInt beginNum;
    BigInt endNum(secoundNum);
    for (BigInt i = fisrtNum; i < endNum; i+=1)
    {
        if (dividesBy5(i) && dividesBy9(i))
        {
            beginNum = i;
            break;
        }
    }
    
    for (BigInt i = beginNum; i < endNum; i+=45)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
#include"Defines.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
ErrorCode executeCommand(const std::string& command, std::vector<int *>& memory)
{
    ErrorCode errorType;

    if (command == "Idle")
    {
        errorType = (ErrorCode)1; 
        return errorType;
    }
    
    std::istringstream istr(command);
    std::string nameCommand;
    int valueCommand;
    istr >> nameCommand;
    istr >> valueCommand;

    if (valueCommand >= memory.size())
    {
        errorType = (ErrorCode)4;
    }
    else 
    {
        if (nameCommand == "Allocate")
        {
            if (nullptr == memory[valueCommand])
            {
                memory[valueCommand] = new int;
                errorType = (ErrorCode)0;
            }
            else
            {
                errorType = (ErrorCode)2;
            }
        }
        else if (nameCommand == "Deallocate")
        {
            if (nullptr != memory[valueCommand])
            {
                delete memory[valueCommand];
                memory[valueCommand] = nullptr;
                errorType = (ErrorCode)0;
            }
            else
            {
                errorType = (ErrorCode)3;
            }
        }
    }
    return errorType;
}
void printResult(const ErrorCode errorCode, const std::string& command)
{
    int typeErrorCode = (int)errorCode;
    switch (typeErrorCode)
    {
    case 0:
        std::cout << command << " - success" << std::endl;
        break;
    case 1:
        std::cout << command << " - this exam is a piece of cake! Where is the OOP already?!?" << std::endl;
        break;
    case 2:
        std::cout << command << " - memory leak prevented, will not make allocation" << std::endl;
        break;
    case 3:
        std::cout << command << " - system crash prevented, will skip this deallocation" << std::endl;
        break;
    case 4:
        std::cout << command << " - out of bound" << std::endl;
        break;
    default:
        std::cerr << "Warning, received unknown ErrorCode: " << errorCode << std::endl;
        break;
    }

}
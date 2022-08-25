// task04
#include <iostream>
int getSize(const char* s) {
    int counter = 0;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        counter++;
    }
    return counter;
}
bool isDuplicate(int a, int arr[], int length) {
    int counter = 0;
    for (size_t i = 0; i < length; i++)
    {

        if (a == arr[i])
        {
            counter++;
        }
        if (counter == 2)
        {
            return true;
        }
    }
    return false;
}

char* getduplicates(const char* s) {

    int size = getSize(s);
    int* arr = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = int(s[i]);
    }

    char* res = new char[size + 1];
    int resCounter = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (s[i] == ' ')
        {
            res[resCounter] = s[i];
            resCounter++;
        }
        if (isDuplicate(int(s[i]), arr, size))
        {
            res[resCounter] = s[i];
            resCounter++;
        }
    }
    res[resCounter] = '\0';


    delete[] arr;
    return res;
}



int main()
{
    std::cout << "Enter your string: ";
    char str[256];
    std::cin.getline(str, 256);

    std::cout << getduplicates(str);


    return 0;
}

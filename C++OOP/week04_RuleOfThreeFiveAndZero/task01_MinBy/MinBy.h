#ifndef MIN_BY_H
#define MIN_BY_H

std::string minBy(std::vector<std::string>& strings, bool(*lessThan)(const std::string&, const std::string&) )
{
    std::string minString = strings[0];

    for (int i = 1; i < strings.size(); i++)
    {
        if (lessThan(strings[i], minString))
        {
            minString = strings[i];
        }   
    }
    return minString;
}

#endif
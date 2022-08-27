#ifndef __SUMOFVECTORS
#define __SUMOFVECTORS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> operator+(const vector<string>& vec1, const vector<string>& vec2)
{
    vector<string> vec3;
    for( int i = 0; i < vec1.size(); i++ )
    {
        string numberToPush = vec1[i] + " " + vec2[i];
        
        vec3.push_back( numberToPush );
    }
    return vec3;
}
#endif
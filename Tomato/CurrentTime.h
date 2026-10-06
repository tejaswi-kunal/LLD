#pragma once
#include<iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class GetCurrentTime
{
    public:
    string getCurrentTime()
    {
        auto now = chrono::system_clock::now();

        time_t currentTime = chrono::system_clock::to_time_t(now);

        tm localTime = *localtime(&currentTime);

        stringstream ss;

        ss << put_time(&localTime, "%Y-%m-%d %H:%M:%S");

        return ss.str();

    }
};
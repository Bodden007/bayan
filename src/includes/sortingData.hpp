#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <boost/algorithm/cxx11/any_of.hpp>

class sortingData
{
private:
    int quanKey; //исправлю
    std::vector<std::string> keyMap;
    std::vector<std::string> comparMap;
    std::vector<std::string> elementMap;

public:
    void sortDat(std::map<std::string, std::vector<std::string>> dataMap);
};

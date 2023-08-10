#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <boost/filesystem.hpp>
#include <boost/algorithm/cxx11/any_of.hpp>

namespace fs = boost::filesystem;

class parser
{
private:
    bool coinDir;
    int levelScan;
    std::vector<std::string> dataDir;
    std::vector<boost::filesystem::path> dataExc;
    std::vector<boost::filesystem::path> dataBuf;
    std::vector<boost::filesystem::path> dataOut;
    std::map<std::string, std::vector<fs::path>> dataMap;

public:
    void setParser(int levelScan, const std::vector<std::string> &include,
                   const std::vector<std::string> &exclude);
    void parserSort(int levelScan);
    void parserDir(std::string val);
};

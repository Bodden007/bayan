#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <boost/filesystem.hpp>
#include <boost/algorithm/cxx11/any_of.hpp>
#include "sortingData.hpp"

namespace fs = boost::filesystem;

/**
 * @brief Path processing class
 *
 */

class parser
{
private:
    bool coinDir;
    int levelScan;
    std::vector<std::string> dataDir;
    std::vector<boost::filesystem::path> dataExc;
    std::vector<boost::filesystem::path> dataBuf;
    std::vector<boost::filesystem::path> dataOut;
    std::map<std::string, std::vector<std::string>> dataMap;

public:
    /**
     * @brief Set the Parser object
     *
     * @param levelScan Scan level
     * @param include Include patch
     * @param exclude Exclude patch
     */
    void setParser(int levelScan, const std::vector<std::string> &include,
                   const std::vector<std::string> &exclude);
    /**
     * @brief Scanning depth
     *
     * @param levelScan Scan level
     */
    void parserSort(int levelScan);
    /**
     * @brief Sorting paths
     *
     * @param val Patch
     */
    void parserDir(std::string val);
};

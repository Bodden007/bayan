#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <filesystem>
#include <boost/crc.hpp>
#include <boost/algorithm/cxx11/any_of.hpp>
#include "crc.hpp"
#include "compareFile.hpp"

/**
 * @brief The class of the first sorting queue
 *
 *
 */

class sortingData
{
    crc crcDat;
    compareFile compFile;

private:
    int quanKey;
    bool flagCoincide = false;
    std::vector<std::size_t> keyMap;
    std::vector<std::string> elementMap;
    std::map<std::size_t, std::vector<std::string>> mapCrc;

public:
    /**
     * @brief Data processing, getting the hash amount, first sorting.
     *
     * @param dataMap Getting a map, with file names and paths
     */
    void sortDat(std::map<std::string, std::vector<std::string>> dataMap);
};

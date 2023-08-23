#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

/**
 * @brief The class of the second sorting queue, according to the contents of the file.
 *
 */

class compareFile
{
private:
    std::string filePath;
    std::string bufStr;
    std::string fileStr;
    std::map<std::string, std::vector<std::string>> comMap;
    std::vector<std::string> keyMap;
    std::vector<std::string> elementMap;

public:
    /**
     * @brief The method determines the number of occupied cells of the vector
     *
     * @param inFile The vector of matches by hash sum.
     */
    void compare(std::vector<std::string> inFile);
    /**
     * @brief Opening a file by the specified path
     *
     * @param filePath file path
     */

    void openFile(std::string filePath);
};

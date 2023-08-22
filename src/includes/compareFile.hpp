#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

class compareFile
{
private:
    bool flagCoincide;
    std::string filePath;
    std::string bufStr;
    std::string fileStr;
    std::map<std::string, std::vector<std::string>> comMap;
    std::vector<std::string> keyMap;
    std::vector<std::string> buf;
    std::vector<std::string> elementMap;

public:
    void compare(std::vector<std::string> inFile);
    void openFile(std::string filePath);
};

#include "../includes/compareFile.hpp"

void compareFile::compare(std::vector<std::string> inFile)
{
    for (int i = 0; i < inFile.size(); i++)
    {
        if (i == 0)
        {

            filePath = inFile[i] + "/" + inFile[i + 1];
            openFile(filePath);
            comMap[fileStr].push_back(inFile[i]);
            comMap[fileStr].push_back(inFile[i + 1]);
            fileStr.clear();
            filePath.clear();
        }
        else if (i % 2 == 0)
        {
            filePath = inFile[i] + "/" + inFile[i + 1];
            openFile(filePath);
            comMap[fileStr].push_back(inFile[i]);
            comMap[fileStr].push_back(inFile[i + 1]);
            fileStr.clear();
            filePath.clear();
        }
    }

    for (const auto &[key, value] : comMap)
    {
        keyMap.push_back(key);
    }

    for (int i = 0; i < keyMap.size(); i++)
    {
        elementMap = comMap.at(keyMap[i]);
        if (elementMap.size() > 2)
        {
            std::cout << std::endl;
            std::cout << "duplicate detected:" << std::endl;
            std::cout << std::endl;
            for (auto doub : elementMap)
            {
                std::cout << doub << std::endl;
            }
            std::cout << std::endl;
        }
        elementMap.clear();
    }
}

void compareFile::openFile(std::string filePath)
{
    std::ifstream ifs;
    ifs.open(filePath);
    if (ifs.is_open())
    {
        while (getline(ifs, bufStr))
        {
            fileStr += bufStr;
        }
        ifs.close();
        std::cout << "File Str:  " << fileStr << std::endl;
    }
    else
    {
        std::cout << "File not open!!" << std::endl;
    }

    // buf.push_back(fileStr);
    // fileStr.clear();
}
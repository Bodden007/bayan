#include "../includes/sortingData.hpp"

void sortingData::sortDat(std::map<std::string, std::vector<std::string>> dataMap)
{
    for (const auto &[key, vec] : dataMap)
    {
        std::cout << std::endl;
        keyMap.push_back(key);
        // std::cout << "dataMap Key:  " << key << std::endl;
    }
    quanKey = dataMap.size();
    std::cout << "Size:  " << dataMap.size() << std::endl;

    for (int i = 0; i < quanKey - 1; i++)
    {
        comparMap = dataMap.at(keyMap[i]);
        for (int j = i + 1; j < quanKey; j++)
        {
            elementMap = dataMap.at(keyMap[j]);

            for (int p = 0; p < comparMap.size(); p++)
            {
                bool found = boost::algorithm::any_of_equal(elementMap, comparMap[p]);
                if (found)
                {
                    std::cout << "Matches found in the directory:" << std::endl;
                    std::cout << "First catalog: " << keyMap[i] << std::endl;
                    std::cout << "Second catalog: " << keyMap[j] << std::endl;
                    std::cout << "file: " << comparMap[i] << std::endl;
                }
            }
            elementMap.clear();
        }
        comparMap.clear();
    }
}
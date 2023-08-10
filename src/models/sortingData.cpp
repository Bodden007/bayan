#include "../includes/sortingData.hpp"

void sortingData::sortDat(std::map<std::string, std::vector<std::string>> dataMap)
{
    for (const auto &[key, vec] : dataMap)
    {
        std::cout << std::endl;
        std::cout << "-------Key:  " << key << std::endl;

        for (const auto element : vec)
            std::cout << "value:  " << element << std::endl;
    }

    std::cout << "Size:  " << dataMap.size() << std::endl;
}
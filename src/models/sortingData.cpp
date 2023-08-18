#include "../includes/sortingData.hpp"

void sortingData::sortDat(std::map<std::string, std::vector<std::string>> dataMap)
{
    for (const auto &[key, vec] : dataMap)
    {
        for (const auto v : vec)
        {
            std::filesystem::path exten = v;
            if (exten.extension().compare(".txt") == 0)
            {
                std::size_t buff = crcDat.crcHash(exten);
                std::vector<std::string> vecBuf;
                mapCrc[buff].push_back(key);
                mapCrc[buff].push_back(exten.filename().generic_string());
            }
        }
    }

    for (const auto &[key, value] : mapCrc)
    {
        keyMap.push_back(key);
    }

    for (int i = 0; i < keyMap.size(); i++)
    {
        elementMap = mapCrc.at(keyMap[i]);
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
            std::cout << "Sum hash:  " << keyMap[i] << std::endl;
        }
        elementMap.clear();
    }
}
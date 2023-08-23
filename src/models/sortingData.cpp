#include "../includes/sortingData.hpp"

void sortingData::sortDat(std::map<std::string, std::vector<std::string>> dataMap)
{
    for (const auto &[key, vec] : dataMap)
    {
        for (const auto v : vec)
        {
            std::filesystem::path exten = v;

            // FIXME Need will delete After the test
            //  if (exten.extension().compare(".txt") == 0)
            //{
            //   NOTE return hash file
            std::size_t buff = crcDat.crcHash(exten);
            std::vector<std::string> vecBuf;
            mapCrc[buff].push_back(key);
            mapCrc[buff].push_back(exten.filename().generic_string());
            //}
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
            // NOTE class compareFile method compare
            compFile.compare(elementMap);
            std::cout << std::endl;
            std::cout << "Sum hash:  " << std::hex << keyMap[i] << std::endl;
        }
        elementMap.clear();
    }
}
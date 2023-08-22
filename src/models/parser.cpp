#include "..\includes\parser.hpp"

void parser::setParser(int levelScan, const std::vector<std::string> &include,
                       const std::vector<std::string> &exclude)
{

    for (int i = 0; i < include.size(); i++)
    {
        dataDir.push_back(include[i]);
    }
    for (int i = 0; i < exclude.size(); i++)
    {
        dataExc.push_back(exclude[i]);
    }
    parserSort(levelScan);
}

void parser::parserSort(int levelScan)
{
    sortingData sorting;

    if (levelScan == 0)
    {
        std::cout << "level Scan: " << levelScan << std::endl;
        for (int i = 0; i < dataDir.size(); i++)
        {
            parserDir(dataDir[i]);
            for (int j = 0; j < dataBuf.size(); j++)
            {
                if (is_regular_file(dataBuf[j]) && fs::file_size(dataBuf[j]) > 1)
                {
                    dataMap[dataDir[i]].push_back(dataBuf[j].generic_string());
                }
            }
            dataBuf.clear();
        }
    }
    else if (levelScan > 0)
    {
        for (int i = levelScan; i >= 0; i--)
        {
            std::cout << "level Scan: " << i << std::endl;
            for (int i = 0; i < dataDir.size(); i++)
            {
                if (dataExc.size() > 0)
                {
                    fs::path dataDirP(dataDir[i]);
                    coinDir = boost::algorithm::any_of_equal(dataExc.begin(), dataExc.end(), dataDirP);
                }

                if (!coinDir)
                {
                    parserDir(dataDir[i]);
                    for (int j = 0; j < dataBuf.size(); j++)
                    {
                        if (is_regular_file(dataBuf[j]) && fs::file_size(dataBuf[j]) > 1)
                        {
                            dataMap[dataDir[i]].push_back(dataBuf[j].generic_string());
                        }
                        else if (is_directory(dataBuf[j]))
                        {
                            dataOut.push_back(dataBuf[j]);
                        }
                    }
                    dataBuf.clear();
                }
            }
            dataDir.clear();
            for (int i = 0; i < dataOut.size(); i++)
            {
                dataDir.push_back(dataOut[i].generic_string());
            }
            dataOut.clear();
        }
    }
    else
    {
        std::cout << "Invalid format scan level: " << levelScan << std::endl;
    }

    sorting.sortDat(dataMap);
}

void parser::parserDir(std::string val)
{
    fs::path p(val);
    try
    {
        if (fs::exists(p))
        {
            if (is_regular_file(p))
            {
                std::cout << p << " size is " << file_size(p) << '\n';
            }
            else if (is_directory(p))
            {
                std::vector<fs::path> v;

                for (auto &&x : fs::directory_iterator(p))
                    v.push_back(x.path());

                std::sort(v.begin(), v.end());

                for (int i = 0; i < v.size(); i++)
                {
                    dataBuf.push_back(v[i]);
                }
            }
            else
                std::cout << p << " exists, but is not a regular file or directory\n";
        }
        else
            std::cout << p << " does not exist\n";
    }
    catch (fs::filesystem_error &ex)
    {
        std::cout << ex.what() << '\n';
    }
}
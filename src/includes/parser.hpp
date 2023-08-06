#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

class parser
{
private:
    std::vector<std::string> dataDir;
    std::map<std::string, std::vector<std::string>> dataMap;

public:
    void setParser(const std::vector<std::string> &varible)
    {

        for (int j = 0; j < varible.size(); j++)
        {
            fs::path p(varible[j]);
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
                        std::cout << p << " is a directory containing:\n";

                        std::vector<fs::path> v;

                        for (auto &&x : fs::directory_iterator(p))
                            v.push_back(x.path());

                        std::sort(v.begin(), v.end());

                        for (int i = 0; i < v.size(); i++)
                        {
                            dataDir.push_back(v[i].filename().generic_string());
                        }

                        dataMap.insert(std::make_pair(varible[j], dataDir));

                        for (const auto &[key, vec] : dataMap)
                        {
                            std::cout << std::endl;
                            std::cout << "-------Key:  " << key << std::endl;

                            for (const auto element : vec)
                                std::cout << "value:  " << element << std::endl;
                            ;
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
    };
    void parserSort();
};

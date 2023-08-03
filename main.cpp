#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/filesystem.hpp>
#include <boost/algorithm/cxx11/any_of.hpp>

using namespace std;
using namespace boost::filesystem;

int main(int argc, char *argv[])
{
    std::vector<std::string> strPath;
    if (argc < 2)
    {
        cout << "Usage: tut4 path\n";
        return 1;
    }

    path p(argv[1]);

    try
    {
        if (exists(p))
        {
            if (is_regular_file(p))
            {
                cout << p << " size is " << file_size(p) << '\n';
            }
            else if (is_directory(p))
            {
                cout << p << " is a directory containing:\n";

                std::vector<path> v;

                for (auto &&x : directory_iterator(p))
                    v.push_back(x.path());

                std::sort(v.begin(), v.end());

                for (int i = 0; i < v.size(); i++)
                {
                    cout << v[i].filename() << '\n';
                    path target = v[i];

                    bool found = boost::algorithm::any_of_equal(v, target);
                    std::cout << std::boolalpha << found << std::endl;
                }
            }
            else
                cout << p << " exists, but is not a regular file or directory\n";
        }
        else
            cout << p << " does not exist\n";
    }
    catch (filesystem_error &ex)
    {
        cout << ex.what() << '\n';
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/program_options.hpp>
#include "includes/parser.hpp"

namespace po = boost::program_options;

int main(int argc, char *argv[])
{
    parser pars;

    try
    {
        int scanLevel = 0;

        po::options_description desc{"Options"};
        desc.add_options()("help,h",
                           "Help screen")("include,i",
                                          po::value<std::vector<std::string>>()->multitoken()->zero_tokens()->composing(),
                                          "Include")("exclude,e", po::value<std::vector<std::string>>()->default_value(std::vector<std::string>(), " ")->multitoken()->zero_tokens()->composing(),
                                                     "Exclude")("scan,s", po::value<int>()->default_value(0)->multitoken()->zero_tokens()->composing(),
                                                                "Scan level");

        po::command_line_parser parser{argc, argv};
        parser.options(desc).allow_unregistered().style(
            po::command_line_style::default_style |
            po::command_line_style::allow_slash_for_short);
        po::parsed_options parsed_options = parser.run();

        po::variables_map vm;
        store(parsed_options, vm);
        notify(vm);

        if (vm.count("help"))
            std::cout << desc << '\n';
        if (vm.count("include"))
            pars.setParser(vm["scan"].as<int>(),
                           vm["include"].as<std::vector<std::string>>(),
                           vm["exclude"].as<std::vector<std::string>>());        
    }
    catch (const po::error &ex)
    {
        std::cerr << ex.what() << '\n';
    } 

    return 0;
}
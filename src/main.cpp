#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/program_options.hpp>
#include "includes/parser.hpp"

namespace po = boost::program_options;

void to_cout(const std::vector<std::string> &v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>{std::cout, "\n"});
}

int main(int argc, char *argv[])
{
    parser pars;

    try
    {
        int age;

        po::options_description desc{"Options"};
        desc.add_options()("help,h", "Help screen")("include,i", po::value<std::vector<std::string>>()->multitoken()->zero_tokens()->composing(), "Include")("exclude,e", po::value<std::vector<std::string>>()->multitoken()->zero_tokens()->composing(), "Exclude");

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
            pars.setParser(vm["include"].as<std::vector<std::string>>());
        if (vm.count("exclude"))
            to_cout(vm["exclude"].as<std::vector<std::string>>());
    }
    catch (const po::error &ex)
    {
        std::cerr << ex.what() << '\n';
    }
    return 0;
}
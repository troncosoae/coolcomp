#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>
#include <boost/regex.hpp>
#include "lexical_analysis.h"
#include "file_management.h"


int main(int argc, char *argv[])
{

    std::string input_file_path;
    std::string output_file_path;
    std::string input_string;
    std::string input_regex;

    boost::program_options::options_description desc("Options");
    desc.add_options()
        ("help,h", "Help screen")
        ("input,i", boost::program_options::value<std::string>(&input_file_path)->default_value(""), "input file")
        ("output,o", boost::program_options::value<std::string>(&output_file_path)->default_value(""), "output file")
        ("input_string,s", boost::program_options::value<std::string>(&input_string)->default_value(""), "input string")
        ("regex,r", boost::program_options::value<std::string>(&input_regex)->default_value(""), "regex");
    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::command_line_parser(argc, argv).options(desc).run(), vm);
    boost::program_options::notify(vm);

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 0;
    }

    if (!input_string.empty() && !input_regex.empty())
    {
        std::cout << "input_string:" << input_string << ";" << std::endl;
        std::cout << "input_regex:" << input_regex << ";" << std::endl;
        boost::regex regex(input_regex);
        std::cout << std::boolalpha << boost::regex_match(input_string, regex) << std::endl;
    }
    else if (!input_file_path.empty() && !output_file_path.empty())
    {
        LexicalAnalysis::LexicalAnalyzer la(input_file_path, output_file_path);
        la.copyInputToOutput();
    }
    else 
        std::cout << "inputs instuficient" << std::endl;

    LexicalAnalysis::FileManager<std::ifstream> inputFile(input_file_path);



    return 0;    

}
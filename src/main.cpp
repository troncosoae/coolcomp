#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>
#include "lexical_analysis.h"


int main(int argc, char *argv[])
{

    std::string input_file_path;
    std::string output_file_path;

    boost::program_options::options_description desc("Options");
    desc.add_options()
        ("help,h", "Help screen")
        ("input,i", boost::program_options::value<std::string>(&input_file_path)->default_value(""), "input file")
        ("output,o", boost::program_options::value<std::string>(&output_file_path)->default_value(""), "output file");
    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::command_line_parser(argc, argv).options(desc).run(), vm);
    boost::program_options::notify(vm);

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 0;
    }    

    std::cout << "hw" << std::endl;
    
    std::string line;
    std::ifstream infile(input_file_path);
    std::ofstream outfile(output_file_path);
    if (infile.is_open() && outfile.is_open())
    {
        while (std::getline(infile, line))
        {
            outfile << line << std::endl;
        }
        outfile.close();
        infile.close();
    }

    LexicalAnalysis::LexicalAnalyzer la(input_file_path, output_file_path);
    la.copyInputToOutput();

    // std::ofstream outfile;
    // outfile.open(output_file_path);
    // outfile << "this iw written " << std::endl;
    // outfile << input_file_path << std::endl;
    // outfile.close();

    return 0;
}

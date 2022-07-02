#ifndef LEXICAL_ANALYSIS_H
#define LEXICAL_ANALYSIS_H

#include <fstream>
#include <string>
#include <type_traits>
#include <boost/regex.hpp>

#include "file_management.h"

namespace LexicalAnalysis
{

class Token
{
public:
    Token(const std::string& name, const std::string& regex) :
        mName(name),
        mRegex(regex)
    {};

private:
    std::string mName;
    boost::regex mRegex;
};


class Scanner 
{
    Scanner() // probably need to receive a list of tokens
    {};

    void analyzeLine(const std::string& line);    
};


class LexicalAnalyzer
{
public:
    LexicalAnalyzer(const std::string& inputFilePath, const std::string& outputFilePath):
        mInputFilePath(inputFilePath),
        mOutputFilePath(outputFilePath),
        mInputFile(mInputFilePath),
        mOutputFile(mOutputFilePath)
    {};

    ~LexicalAnalyzer()
    {
        mInputFile.close();
        mOutputFile.close();
    };

    bool filesAreOpen();
    void copyInputToOutput();
    
private:
    std::string mInputFilePath;
    std::string mOutputFilePath;
    std::ifstream mInputFile;
    std::ofstream mOutputFile;

};

} // LexicalAnalysis

#endif // LEXICAL_ANALYSIS_H

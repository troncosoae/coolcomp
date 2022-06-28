#ifndef LEXICAL_ANALYSIS_H
#define LEXICAL_ANALYSIS_H

#include <fstream>
#include <string>

namespace LexicalAnalysis
{

class LexicalAnalyzer
{
public:
    LexicalAnalyzer(const std::string& inputFilePath, const std::string& outputFilePath):
        mInputFilePath(inputFilePath),
        mOutputFilePath(outputFilePath),
        mInputFile(mInputFilePath),
        mOutputFile(mOutputFilePath)
    {}

    ~LexicalAnalyzer()
    {
        mInputFile.close();
        mOutputFile.close();
    }

    bool filesAreOpen();
    void copyInputToOutput();
    
private:
    std::string mInputFilePath;
    std::string mOutputFilePath;
    std::ifstream mInputFile;
    std::ofstream mOutputFile;

};

}

#endif

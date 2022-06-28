#include "lexical_analysis.h"
#include <cassert>
#include <string>

namespace LexicalAnalysis
{

bool LexicalAnalyzer::filesAreOpen()
{
    return mInputFile.is_open() && mOutputFile.is_open();
}

void LexicalAnalyzer::copyInputToOutput()
{
    assert(filesAreOpen());
    std::string line;
    while (std::getline(mInputFile, line))
    {
        mOutputFile << line << std::endl << std::endl;
    }
}

}

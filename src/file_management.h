#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include <fstream>
#include <string>

namespace LexicalAnalysis
{

/* To manage opening and closing files easily */
template <typename FileType>
class FileManager
{
    static_assert(std::is_same<FileType, std::ifstream>::value || 
                  std::is_same<FileType, std::ofstream>::value);

public:
    FileManager(const std::string& filePath) :
        mFilePath(filePath),
        mFile(mFilePath)
    {};

    ~FileManager()
    {
        mFile.close();
    };

    std::string mFilePath;
    FileType mFile;
};

} // LexicalAnalysis

#endif // FILE_MANAGEMENT_H

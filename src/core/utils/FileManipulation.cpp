#include "FileManipulation.h"
#include <cstdio>

namespace SPIDERWEBDB
{
    int FileManipulation::removeFile(const std::string &filePath){
        return remove(filePath.c_str());        
    }
}
#pragma once

#include <string>

namespace SPIDERWEBDB
{
    namespace CONSTANTS
    {
        constexpr char COMMA_CHAR = ',';
        constexpr char SLASH_CHAR = '/';
        constexpr char NEWLINE_CHAR = '\n';
        constexpr char BLANK_CHAR = ' ';
        constexpr char UNDERSCORE_CHAR = '_';


        constexpr std::string_view  EMPTY_STR= "";
        constexpr std::string_view  TRUE_STR= "true";
        constexpr std::string_view  FALSE_STR= "false";

        constexpr std::string_view  CSVEXT_STR= ".csv";
        constexpr std::string_view  PROPERTIES_FILENAME_STR= "properties.swdb";
        
        constexpr std::string_view  RELATIONS_PREFIX_STR= "relations_";
    }
}
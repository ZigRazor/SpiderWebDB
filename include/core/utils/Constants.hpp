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

        /*** QUERY KEYWORDS ***/
        /* First Level */
        constexpr std::string_view  QUERY_FROM_KW= "FROM";
        constexpr std::string_view  QUERY_RETURN_KW= "RETURN";
        /* Second Level */
        constexpr std::string_view  QUERY_NODES_KW= "NODES";
        constexpr std::string_view  QUERY_RELATIONS_KW= "RELATIONS";
        constexpr std::string_view  QUERY_FEATURES_KW= "FEATURES";
        /* Conditions */
        constexpr std::string_view  QUERY_WITH_KW= "WITH";
        constexpr std::string_view  QUERY_OF_KW= "OF";
        /* Third Level */
        constexpr std::string_view  QUERY_NODE_KW= "NODE";
        constexpr std::string_view  QUERY_RELATION_KW= "RELATION";
        constexpr std::string_view  QUERY_FEATURE_KW= "FEATURE";
        /* Boolean Operator */
        constexpr std::string_view  QUERY_AND_KW= "AND";
        constexpr std::string_view  QUERY_OR_KW= "OR";
        constexpr std::string_view  QUERY_NOT_KW= "NOT";
        /* Equal Operator */
        constexpr std::string_view  QUERY_EQUALS_KW= "==";
        /* Magic Variable */
        constexpr std::string_view  QUERY_ALL_KW= "*";
        /*** -------------- ***/
    }
}
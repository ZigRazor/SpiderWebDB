#pragma once

#include <string>
#include <list>

namespace SPIDERWEBDB
{

    class QueryParser
    {
    public:
        QueryParser() = delete;
        virtual ~QueryParser() = delete;

        typedef enum ObjectReturnType_Enum
        {
            RETURN_NOT_APPLICABLE = 0,
            NODES,
            RELATIONS,
            FEATURES
        } ObjectReturnType;

        typedef enum ConditionType_Enum
        {
            CONDITION_NOT_APPLICABLE = 0,
            NODE,
            RELATION,
            FEATURE,
            NODE_FEATURE,
            RELATION_FEATURE
        } ConditionType;

        typedef struct ParsedQuery_struct
        {
            std::list<std::string_view> fromDatabases;
            ObjectReturnType objectToReturn;
            ObjectReturnType featuresOf;
        } ParsedQuery;

        static ParsedQuery parseQueryString(std::string_view queryStr);

    private:
        typedef struct FirstLevelSplit_struct
        {
            std::string_view str_from;
            std::string_view str_return;
        } FirstLevelSplit;

        typedef struct ReturnFirstLevelSplit_struct
        {
            ObjectReturnType objectToReturn;
            ObjectReturnType featuresOf;
            std::string_view str_conditions;
        } ReturnFirstLevelSplit;

        static FirstLevelSplit parseFirstLevel(std::string_view queryStr);

        static std::list<std::string_view> parseFrom(std::string_view fromQueryStr);
        static ReturnFirstLevelSplit parseReturnFirstLevel(std::string_view returnQueryStr);

        static void stripKeyword(const std::string_view &keyword, std::string_view &stringToStrip);
        static void stripSingleElement(const std::string_view &elem, std::string_view &stringToStrip);

        // trim from left
        static std::string_view &  ltrim(std::string_view &s, const char *t = " \t\n\r\f\v");

        // trim from right
        static std::string_view & rtrim(std::string_view &s, const char *t = " \t\n\r\f\v");
        
    };
}
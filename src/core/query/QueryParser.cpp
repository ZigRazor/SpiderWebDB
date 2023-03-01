#include "QueryParser.h"
#include "Constants.hpp"
#include <iostream>
#include <string_view>

namespace SPIDERWEBDB
{

    QueryParser::ParsedQuery QueryParser::parseQueryString(std::string_view queryStr)
    {
        ParsedQuery result;
        auto firstLevelSplit = parseFirstLevel(queryStr);

        result.fromDatabases = parseFrom(firstLevelSplit.str_from);

        auto returnFirstLevelSplit = parseReturnFirstLevel(firstLevelSplit.str_return);

        std::cout << "First Level Split :\n from: " << firstLevelSplit.str_from << "\n return: " << firstLevelSplit.str_return << std::endl;

        std::cout << "Return First Level Split :\n Object To Return: " << returnFirstLevelSplit.objectToReturn << "\n Features Of: " << returnFirstLevelSplit.featuresOf << "\n Conditions: " << returnFirstLevelSplit.str_conditions << std::endl;

        std::cout << "From Databases:";
        for(auto elem : result.fromDatabases){
            std::cout << " " << elem;
        }
        std::cout << std::endl;
        return result;
    }

    QueryParser::FirstLevelSplit QueryParser::parseFirstLevel(std::string_view queryStr)
    {

        FirstLevelSplit result;

        auto posFrom = queryStr.find(CONSTANTS::QUERY_FROM_KW);
        auto posReturn = queryStr.find(CONSTANTS::QUERY_RETURN_KW);

        if (posFrom == queryStr.npos)
        {
            std::cout << "FROM not found" << std::endl;
            // ASSUME ALL
            posFrom = posReturn;
        }

        if (posReturn == queryStr.npos)
        {
            std::cout << "RETURN not found" << std::endl;
            // INVALID ( we don't know what the user want retrive)
            return result;
        }

        if (posFrom == posReturn)
        {
            // result.str_from = "";
            result.str_return = queryStr.substr(posReturn);
        }
        else if (posFrom < posReturn)
        {
            result.str_from = queryStr.substr(posFrom, posReturn - posFrom);
            result.str_return = queryStr.substr(posReturn);
        }
        else
        { // posReturn < posFrom
            result.str_return = queryStr.substr(posReturn, posFrom - posReturn);
            result.str_from = queryStr.substr(posFrom);
        }

        stripKeyword(CONSTANTS::QUERY_RETURN_KW, result.str_return);
        stripKeyword(CONSTANTS::QUERY_FROM_KW, result.str_from);

        std::cout << posFrom << " " << posReturn << std::endl;

        return result;
    }

    QueryParser::ReturnFirstLevelSplit QueryParser::parseReturnFirstLevel(std::string_view returnQueryStr)
    {
        ReturnFirstLevelSplit result;
        if (returnQueryStr.find(CONSTANTS::QUERY_NODES_KW) == 0)
        {
            result.objectToReturn = ObjectReturnType::NODES;
            stripKeyword(CONSTANTS::QUERY_NODES_KW, returnQueryStr);
        }
        else if (returnQueryStr.find(CONSTANTS::QUERY_RELATIONS_KW) == 0)
        {
            result.objectToReturn = ObjectReturnType::RELATIONS;
            stripKeyword(CONSTANTS::QUERY_RELATIONS_KW, returnQueryStr);
        }
        else if (returnQueryStr.find(CONSTANTS::QUERY_FEATURES_KW) == 0)
        {
            result.objectToReturn = ObjectReturnType::FEATURES;
            stripKeyword(CONSTANTS::QUERY_FEATURES_KW, returnQueryStr);
            if (returnQueryStr.find(CONSTANTS::QUERY_OF_KW) != 0)
            {
                // WRONG FEATURES STATEMENT
                std::cout << "ERROR: WRONG FEATURES STATEMENT" << std::endl;
                return result;
            }
            else
            {
                stripKeyword(CONSTANTS::QUERY_OF_KW, returnQueryStr);
                if (returnQueryStr.find(CONSTANTS::QUERY_NODES_KW) == 0)
                {
                    result.featuresOf = ObjectReturnType::NODES;
                    stripKeyword(CONSTANTS::QUERY_NODES_KW, returnQueryStr);
                }
                else if (returnQueryStr.find(CONSTANTS::QUERY_RELATIONS_KW) == 0)
                {
                    result.featuresOf = ObjectReturnType::RELATIONS;
                    stripKeyword(CONSTANTS::QUERY_RELATIONS_KW, returnQueryStr);
                }
                else
                { // WRONG FEATURES STATEMENT
                    std::cout << "ERROR: WRONG FEATURES STATEMENT" << std::endl;
                    return result;
                }
            }
        }
        else
        {
            // WRONG RETURN STATEMENT
            std::cout << "ERROR: WRONG RETURN STATEMENT" << std::endl;
            return result;
        }
        // Return Conditions
        if (returnQueryStr.find(CONSTANTS::QUERY_WITH_KW) == 0)
        {
            stripKeyword(CONSTANTS::QUERY_WITH_KW, returnQueryStr);
            result.str_conditions = returnQueryStr;
        }
        else
        {
            // WRONG CONDITIONS STATEMENT
            std::cout << "ERROR: WRONG CONDITIONS STATEMENT" << std::endl;
            return result;
        }
        return result;
    }

    std::list<std::string_view> QueryParser::parseFrom(std::string_view fromQueryStr)
    {
        std::list<std::string_view> result;
        auto andElem = fromQueryStr.find_first_of(CONSTANTS::QUERY_AND_KW);
        while(andElem != fromQueryStr.npos)
        {
            std::string_view elemToAdd = fromQueryStr.substr(0,andElem);
            result.push_back(rtrim(elemToAdd));
            fromQueryStr = fromQueryStr.substr(andElem);
            stripKeyword(CONSTANTS::QUERY_AND_KW,fromQueryStr);
            andElem = fromQueryStr.find_first_of(CONSTANTS::QUERY_AND_KW);
        }
        std::string_view elemToAdd = fromQueryStr.substr(0,andElem);
        result.push_back(rtrim(elemToAdd));
        return result;
    }

    void QueryParser::stripKeyword(const std::string_view &keyword, std::string_view &stringToStrip)
    {
        ltrim(stringToStrip);
        stripSingleElement(keyword, stringToStrip);
        ltrim(stringToStrip);
    }

    void QueryParser::stripSingleElement(const std::string_view &elem, std::string_view &stringToStrip)
    {
        if (stringToStrip.size() != 0)
        {
            auto endOfElem = stringToStrip.find_first_not_of(elem);
            if (endOfElem != stringToStrip.npos)
            {
                stringToStrip = stringToStrip.substr(endOfElem);
            }
        }
    }

    std::string_view &QueryParser::ltrim(std::string_view &s, const char *t)
    {
        s.remove_prefix(std::min(s.find_first_not_of(t), s.size()));
        return s;
    }

    std::string_view &QueryParser::rtrim(std::string_view &s, const char *t)
    {
        s.remove_suffix(s.size() - std::min(s.find_first_of(t), s.size()));
        return s;
    }

}
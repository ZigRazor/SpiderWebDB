#include "QueryParser.h"
#include <iostream>

using namespace SPIDERWEBDB;

int main(){

    std::string_view queryStr1 = "FROM X RETURN Y";
    std::string_view queryStr2 = "RETURN Y";
    std::string_view queryStr3 = "FROM X";
    std::string_view queryStr4 = "RETURN Y FROM X";
    std::string_view queryStr5 = "RETURN NODES FROM X";
    std::string_view queryStr6 = "RETURN RELATIONS FROM Y";
    std::string_view queryStr7 = "FROM X RETURN FEATURES";
    std::string_view queryStr8 = "FROM X RETURN FEATURES OF NODES";
    std::string_view queryStr9 = "FROM X RETURN FEATURES OF RELATIONS WITH NODE";
    std::string_view queryStr10 = "RETURN RELATIONS WITH NODE FEATURE a == b FROM Y";
    std::string_view queryStr11 = "FROM X AND Y AND Z RETURN FEATURES OF RELATIONS WITH NODE";


    std::cout << "----- QUERY 1 ------" << std::endl;
    QueryParser::parseQueryString(queryStr1);
    std::cout << "----- QUERY 2 ------" << std::endl;
    QueryParser::parseQueryString(queryStr2);
    std::cout << "----- QUERY 3 ------" << std::endl;
    QueryParser::parseQueryString(queryStr3);
    std::cout << "----- QUERY 4 ------" << std::endl;
    QueryParser::parseQueryString(queryStr4);
    std::cout << "----- QUERY 5 ------" << std::endl;
    QueryParser::parseQueryString(queryStr5);
    std::cout << "----- QUERY 6 ------" << std::endl;
    QueryParser::parseQueryString(queryStr6);
    std::cout << "----- QUERY 7 ------" << std::endl;
    QueryParser::parseQueryString(queryStr7);
    std::cout << "----- QUERY 8 ------" << std::endl;
    QueryParser::parseQueryString(queryStr8);
    std::cout << "----- QUERY 9 ------" << std::endl;
    QueryParser::parseQueryString(queryStr9);
    std::cout << "----- QUERY 10 ------" << std::endl;
    QueryParser::parseQueryString(queryStr10);
    std::cout << "----- QUERY 11 ------" << std::endl;
    QueryParser::parseQueryString(queryStr11);

    return 0;


}
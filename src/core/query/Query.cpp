#include "Query.h"

namespace SPIDERWEBDB {
    
    Query::Query(){}
    Query::Query(const std::string& queryStr){
        m_queryStr = queryStr;
    }
    Query::~Query(){}

    const std::string& Query::getQueryString() const{
        return m_queryStr;
    }

    void Query::setQueryString(const std::string& queryStr){
        m_queryStr = queryStr;
    }


    std::string Query::toString() const{
        return m_queryStr;
    }

    std::ostream& operator << (std::ostream &os, const Query &query) {
        os << query.toString();
        return os;
    }

    bool Query::operator==(const Query &q) const
    {
        return this->m_queryStr == q.m_queryStr;
    }

    bool Query::operator!=(const Query &q) const
    {
        return !(*this == q);
    }
}


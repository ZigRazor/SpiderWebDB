#pragma once

#include <string>

namespace SPIDERWEBDB {
    
    class Query {
        public:

            Query();
            Query(const std::string& queryStr);
            virtual ~Query();

            const std::string& getQueryString() const;
            void setQueryString(const std::string& queryStr);

            virtual std::string toString() const;

            friend std::ostream& operator<<(std::ostream& os, const Query &query);

            bool operator==(const Query &q) const;

            bool operator!=(const Query &q) const;

        private:
            std::string m_queryStr;

    };
}
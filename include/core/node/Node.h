#pragma once

#include <string>
#include <sstream>

namespace SPIDERWEBDB {
    
    class Node {
        public:

            Node();
            Node(const std::string& id);
            virtual ~Node();

            const std::string_view getId() const; 

            virtual std::string toString() const;

            friend std::ostream& operator<<(std::ostream& os, const Node &node);

            bool operator==(const Node &n) const;

            bool operator!=(const Node &n) const;

        private:
            std::string m_id;

    };
}
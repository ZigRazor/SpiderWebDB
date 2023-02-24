#pragma once

#include <string>
#include <utility>
#include <memory>

#include "Node.h"

namespace SPIDERWEBDB {
    
    class Relation {
        public:

            Relation();
            Relation(const std::string& relationName, const std::pair<std::shared_ptr<Node>,std::shared_ptr<Node>>& nodes);
            Relation(const std::string& relationName, std::shared_ptr<Node> node_1, std::shared_ptr<Node> node_2);
            Relation(const std::string &relationName, std::string& strDBEntry);
            
            virtual ~Relation();

            const std::string_view getName() const; 

            const std::pair<std::shared_ptr<Node>,std::shared_ptr<Node>>& getNodes() const;

            virtual std::string toString() const;
            virtual std::string toStringDBEntry() const;
            

            friend std::ostream& operator<<(std::ostream& os, const Relation &r);

            bool operator==(const Relation &r) const;

            bool operator!=(const Relation &r) const;

        private:

            std::string m_name;
            std::pair<std::shared_ptr<Node>,std::shared_ptr<Node>> m_nodes;

    };
}
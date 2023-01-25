#include "Node.h"

namespace SPIDERWEBDB {
    
    Node::Node(){}
    Node::Node(const std::string& id){
        m_id = id;
    }
    Node::~Node(){}

    const std::string_view Node::getId() const{
        return m_id;
    }

    std::string Node::toString() const{
        return m_id;
    }

    std::ostream& operator << (std::ostream &os, const Node &node) {
        os << node.toString();
        return os;
    }
}


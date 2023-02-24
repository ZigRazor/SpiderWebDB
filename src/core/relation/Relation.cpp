#include "Relation.h"
#include <cstdio>
#include "UtilitySharedPtr.hpp"
#include "Constants.hpp"

namespace SPIDERWEBDB
{

    Relation::Relation() {}

    Relation::Relation(const std::string &relationName, const std::pair<std::shared_ptr<Node>, std::shared_ptr<Node>> &nodes)
    {
        m_name = relationName;
        m_nodes = nodes;
    }

    Relation::Relation(const std::string &relationName, std::shared_ptr<Node> node_1, std::shared_ptr<Node> node_2)
    {
        m_name = relationName;
        m_nodes.first = node_1;
        m_nodes.second = node_2;
    }

    Relation::Relation(const std::string &relationName, std::string& strDBEntry){
        m_name = relationName;
        m_nodes.first = std::make_shared<Node>(strDBEntry.substr(0, strDBEntry.find(CONSTANTS::COMMA_CHAR)));
        strDBEntry.erase(0, (strDBEntry.find(CONSTANTS::COMMA_CHAR) + 1));
        m_nodes.second = std::make_shared<Node>(strDBEntry);
    }

    Relation::~Relation() {}

    const std::string_view Relation::getName() const
    {
        return m_name;
    }

    const std::pair<std::shared_ptr<Node>, std::shared_ptr<Node>> &Relation::getNodes() const
    {
        return m_nodes;
    }

    std::string Relation::toString() const
    {
        return m_nodes.first->toString() + CONSTANTS::BLANK_CHAR + m_name + CONSTANTS::BLANK_CHAR + m_nodes.second->toString();
    }

    std::string Relation::toStringDBEntry() const
    {
        return m_nodes.first->toString() + CONSTANTS::COMMA_CHAR + m_nodes.second->toString();
    }

    bool Relation::operator==(const Relation &r) const
    {
        return this->m_name == r.m_name && compare_shared_ptr(this->m_nodes.first, r.m_nodes.first) && compare_shared_ptr(this->m_nodes.second, r.m_nodes.second);
    }

    bool Relation::operator!=(const Relation &r) const
    {
        return !(*this == r);
    }

    std::ostream &operator<<(std::ostream &os, const Relation &r)
    {
        os << r.toString();
        return os;
    }
}
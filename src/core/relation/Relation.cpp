#include "Relation.h"

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
        return m_nodes.first->toString() + " " + m_name + " " + m_nodes.second->toString();
    }

    bool Relation::operator==(const Relation &r) const
    {
        return this->m_name == r.m_name && this->m_nodes == r.m_nodes;
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
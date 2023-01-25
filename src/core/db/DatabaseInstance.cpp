#include "DatabaseInstance.h"

#include <sys/stat.h>
#include <fstream>
#include <filesystem>
#include <sstream>

namespace SPIDERWEBDB
{

    DatabaseInstance::DatabaseInstance() {}

    DatabaseInstance::DatabaseInstance(std::string dbName)
    {
        m_name = dbName;
    }

    DatabaseInstance::~DatabaseInstance() {}

    const std::string_view DatabaseInstance::getName() const
    {
        return m_name;
    }

    void DatabaseInstance::addRelations(std::shared_ptr<RelationsList> relations)
    {
        m_relationsMap.addRelations(relations);
    }

    void DatabaseInstance::addRelations(const RelationsList &relations)
    {
        m_relationsMap.addRelations(relations);
    }

    void DatabaseInstance::addRelation(std::shared_ptr<Relation> relation)
    {
        m_relationsMap.addRelation(relation);
    }

    void DatabaseInstance::addRelation(const Relation &relation)
    {
        m_relationsMap.addRelation(relation);
    }

    void DatabaseInstance::removeRelations(std::shared_ptr<RelationsList> relations)
    {
        m_relationsMap.removeRelations(relations);
    }

    void DatabaseInstance::removeRelations(const RelationsList &relations)
    {
        m_relationsMap.removeRelations(relations);
    }

    void DatabaseInstance::removeRelations(const std::string &relationsName)
    {
        m_relationsMap.removeRelations(relationsName);
    }

    void DatabaseInstance::removeRelation(std::shared_ptr<Relation> relation)
    {
        m_relationsMap.removeRelation(relation);
    }

    void DatabaseInstance::removeRelation(const Relation &relation)
    {
        m_relationsMap.removeRelation(relation);
    }

    int DatabaseInstance::writeToFile() const
    {

        auto dbTofile = [&]()
        {
            for (auto relations : m_relationsMap.getRelationsMap())
            {
                std::ofstream relationsFile(m_name + "/" + "relations_" + std::string(relations.second->getRelationsName()) + ".csv");
                for (auto relation : relations.second->getRelations())
                {
                    auto nodes = relation->getNodes();
                    relationsFile << *nodes.first << "," << *nodes.second << std::endl;
                }
                relationsFile.close();
            }
        };

        struct stat sb;
        if (stat(m_name.c_str(), &sb) != 0)
        {
            int check;

            check = mkdir(m_name.c_str(), 0777);

            // check if directory is created or not
            if (!check)
            {
                // printf("Directory created\n");
                dbTofile();
            }
            else
            {
                // printf("Unable to create directory\n");
                //  exit(1);
                return -1;
            }
        }
        else
        {
            dbTofile();
        }
        return 0;
    }

    int DatabaseInstance::readFromFile()
    {
        auto dbFromfile = [&]()
        {
            for (const auto &entry : std::filesystem::directory_iterator(m_name))
            {
                std::string relationsSubStr = "relations_";
                if (entry.path().filename().string().rfind(relationsSubStr, 0) == 0)
                {
                    std::string relationsName = entry.path().filename().string().erase(0,relationsSubStr.length());
                    std::string line;
                    std::ifstream relationsFile(entry.path().string());
                    while (std::getline(relationsFile, line))
                    {
                        std::stringstream str(line);
                        std::string node_1;
                        std::string node_2;
                        std::getline(str, node_1, ',');
                        std::getline(str, node_2, ',');
                        Relation r(relationsName,std::make_shared<Node>(node_1), std::make_shared<Node>(node_2));
                        this->addRelation(r);
                    }
                }
            }
        };

        struct stat sb;
        if (stat(m_name.c_str(), &sb) != 0)
        {
            dbFromfile();
        }else{ // Database does not exist
            return -1;
        }
        return 0;
    }

    std::string DatabaseInstance::toString() const
    {
        std::stringstream ss;
        ss << "Database Instance: " << m_name << std::endl
           << m_relationsMap;
        return ss.str();
    }

    std::ostream &operator<<(std::ostream &os, const DatabaseInstance &dbi)
    {
        os << dbi.toString();
        return os;
    }

}
#pragma once

#include "RelationsMap.h"

namespace SPIDERWEBDB
{

    class CheckUtils
    {
    public:
        static bool existRelationNameInRelationsMap(const RelationsMap &relationsMap, const std::string &relationName);
        static bool existRelationInRelationsList(const RelationsList &relationsList, const Relation &relation);
    };
}
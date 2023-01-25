#include <gtest/gtest.h>
#include "RelationsMap.h"

using namespace SPIDERWEBDB;

TEST(RelationMapTest, Constructor_01)
{
    RelationsMap rm;
    ASSERT_TRUE(rm.getRelationsMap().empty());
}


TEST(RelationsMapTest, Insert_01)
{
    RelationsMap rm;
    RelationsList rl1;
    auto n1_ptr = std::make_shared<Node>("n1");
    auto n2_ptr = std::make_shared<Node>("n2");
    Relation r1(std::string("relation"), std::make_pair<>(n1_ptr,n2_ptr));
    rl1.addRelation(r1);

    auto n3_ptr = std::make_shared<Node>("n3");
    auto n4_ptr = std::make_shared<Node>("n4");
    Relation r2(std::string("relation"), std::make_pair<>(n3_ptr,n4_ptr));
    rl1.addRelation(r2);

    rm.addRelations(rl1);
    ASSERT_FALSE(rm.getRelationsMap().empty());
    ASSERT_EQ(rm.getRelationsMap().size(),1);

    RelationsList rl2;
    Relation r3(std::string("relation_new"), std::make_pair<>(n1_ptr,n2_ptr));
    rl2.addRelation(r3);

    rm.addRelations(rl2);
    ASSERT_FALSE(rm.getRelationsMap().empty());
    ASSERT_EQ(rm.getRelationsMap().size(),2);

}

TEST(RelationsMapTest, Insert_02)
{
    RelationsMap rm;
    auto n1_ptr = std::make_shared<Node>("n1");
    auto n2_ptr = std::make_shared<Node>("n2");
    Relation r1(std::string("relation"), std::make_pair<>(n1_ptr,n2_ptr));
    rm.addRelation(r1);

    ASSERT_FALSE(rm.getRelationsMap().empty());
    ASSERT_EQ(rm.getRelationsMap().size(),1);

    auto n3_ptr = std::make_shared<Node>("n3");
    auto n4_ptr = std::make_shared<Node>("n4");
    Relation r2(std::string("relation"), std::make_pair<>(n3_ptr,n4_ptr));
    rm.addRelation(r2);

    ASSERT_FALSE(rm.getRelationsMap().empty());
    ASSERT_EQ(rm.getRelationsMap().size(),1);

    Relation r3(std::string("relation_new"), std::make_pair<>(n1_ptr,n2_ptr));

    rm.addRelation(r3);
    ASSERT_FALSE(rm.getRelationsMap().empty());
    ASSERT_EQ(rm.getRelationsMap().size(),2);

}

TEST(RelationsMapTest, Remove_01)
{
    RelationsMap rm;
    RelationsList rl1;
    auto n1_ptr = std::make_shared<Node>("n1");
    auto n2_ptr = std::make_shared<Node>("n2");
    Relation r1(std::string("relation"), std::make_pair<>(n1_ptr,n2_ptr));
    rl1.addRelation(r1);

    auto n3_ptr = std::make_shared<Node>("n3");
    auto n4_ptr = std::make_shared<Node>("n4");
    Relation r2(std::string("relation"), std::make_pair<>(n3_ptr,n4_ptr));
    rl1.addRelation(r2);

    rm.addRelations(rl1);

    RelationsList rl2;
    Relation r3(std::string("relation_new"), std::make_pair<>(n1_ptr,n2_ptr));
    rl2.addRelation(r3);

    rm.addRelations(rl2);

    rm.removeRelations(rl1);
    ASSERT_FALSE(rm.getRelationsMap().empty());
    ASSERT_EQ(rm.getRelationsMap().size(),1);

    rm.removeRelations(rl2);
    ASSERT_TRUE(rm.getRelationsMap().empty());
    ASSERT_EQ(rm.getRelationsMap().size(),0);

}

TEST(RelationsMapTest, Remove_02)
{
    RelationsMap rm;
    auto n1_ptr = std::make_shared<Node>("n1");
    auto n2_ptr = std::make_shared<Node>("n2");
    Relation r1(std::string("relation"), std::make_pair<>(n1_ptr,n2_ptr));
    rm.addRelation(r1);

    auto n3_ptr = std::make_shared<Node>("n3");
    auto n4_ptr = std::make_shared<Node>("n4");
    Relation r2(std::string("relation"), std::make_pair<>(n3_ptr,n4_ptr));
    rm.addRelation(r2);

    Relation r3(std::string("relation_new"), std::make_pair<>(n1_ptr,n2_ptr));

    rm.addRelation(r3);

    rm.removeRelation(r1);
    ASSERT_FALSE(rm.getRelationsMap().empty());
    ASSERT_EQ(rm.getRelationsMap().size(),2);

    rm.removeRelation(r3);
    ASSERT_FALSE(rm.getRelationsMap().empty());
    ASSERT_EQ(rm.getRelationsMap().size(),1);

    rm.removeRelation(r2);
    ASSERT_TRUE(rm.getRelationsMap().empty());
    ASSERT_EQ(rm.getRelationsMap().size(),0);

}
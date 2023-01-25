#include <gtest/gtest.h>
#include "RelationsList.h"

using namespace SPIDERWEBDB;

TEST(RelationsListTest, Constructor_01)
{
    RelationsList rl;
    ASSERT_EQ(rl.getRelationsName(), "");
    ASSERT_TRUE(rl.getRelations().empty());
    ASSERT_EQ(rl.relationsSize(), 0);
}


TEST(RelationsListTest, Insert_01)
{
    RelationsList rl;
    auto n1_ptr = std::make_shared<Node>("n1");
    auto n2_ptr = std::make_shared<Node>("n2");
    Relation r1(std::string("relation"), std::make_pair<>(n1_ptr,n2_ptr));
    rl.addRelation(r1);
    ASSERT_EQ(rl.getRelationsName(), "relation");
    ASSERT_FALSE(rl.getRelations().empty());
    ASSERT_EQ(rl.relationsSize(), 1);

    auto n3_ptr = std::make_shared<Node>("n3");
    auto n4_ptr = std::make_shared<Node>("n4");
    Relation r2(std::string("relation"), std::make_pair<>(n3_ptr,n4_ptr));
    rl.addRelation(r2);
    ASSERT_EQ(rl.getRelationsName(), "relation");
    ASSERT_FALSE(rl.getRelations().empty());
    ASSERT_EQ(rl.relationsSize(), 2);

    auto n5_ptr = std::make_shared<Node>("n5");
    auto n6_ptr = std::make_shared<Node>("n6");
    Relation r3(std::string("not_relation"), std::make_pair<>(n5_ptr,n6_ptr));
    rl.addRelation(r3);
    ASSERT_EQ(rl.getRelationsName(), "relation");
    ASSERT_FALSE(rl.getRelations().empty());
    ASSERT_EQ(rl.relationsSize(), 2);

}

TEST(RelationsListTest, Remove_01)
{
    RelationsList rl;
    auto n1_ptr = std::make_shared<Node>("n1");
    auto n2_ptr = std::make_shared<Node>("n2");
    Relation r1(std::string("relation"), std::make_pair<>(n1_ptr,n2_ptr));
    rl.addRelation(r1);
    ASSERT_EQ(rl.getRelationsName(), "relation");
    ASSERT_FALSE(rl.getRelations().empty());
    ASSERT_EQ(rl.relationsSize(), 1);

    auto n3_ptr = std::make_shared<Node>("n3");
    auto n4_ptr = std::make_shared<Node>("n4");
    Relation r2(std::string("relation"), std::make_pair<>(n3_ptr,n4_ptr));
    rl.addRelation(r2);
    ASSERT_EQ(rl.getRelationsName(), "relation");
    ASSERT_FALSE(rl.getRelations().empty());
    ASSERT_EQ(rl.relationsSize(), 2);

    auto n5_ptr = std::make_shared<Node>("n5");
    auto n6_ptr = std::make_shared<Node>("n6");
    Relation r3(std::string("not_relation"), std::make_pair<>(n5_ptr,n6_ptr));
    rl.addRelation(r3);
    ASSERT_EQ(rl.getRelationsName(), "relation");
    ASSERT_FALSE(rl.getRelations().empty());
    ASSERT_EQ(rl.relationsSize(), 2);

    rl.removeRelation(r3);
    ASSERT_EQ(rl.getRelationsName(), "relation");
    ASSERT_FALSE(rl.getRelations().empty());
    ASSERT_EQ(rl.relationsSize(), 2);

    rl.removeRelation(r2);
    ASSERT_EQ(rl.getRelationsName(), "relation");
    ASSERT_FALSE(rl.getRelations().empty());
    ASSERT_EQ(rl.relationsSize(), 1);

    rl.removeRelation(r1);
    ASSERT_EQ(rl.getRelationsName(), "");
    ASSERT_TRUE(rl.getRelations().empty());
    ASSERT_EQ(rl.relationsSize(), 0);

}
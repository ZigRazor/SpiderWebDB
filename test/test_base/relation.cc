#include <gtest/gtest.h>
#include "Relation.h"

using namespace SPIDERWEBDB;

TEST(RelationTest, Constructor_01)
{
    Relation r;
    ASSERT_EQ(r.getName(), "");
    ASSERT_EQ(r.getNodes().first, nullptr);
    ASSERT_EQ(r.getNodes().second, nullptr);
}

TEST(RelationTest, Constructor_02)
{
    auto n1_ptr = std::make_shared<Node>("n1");
    auto n2_ptr = std::make_shared<Node>("n2");
    Relation r(std::string("relation"), std::make_pair<>(n1_ptr,n2_ptr));
    ASSERT_EQ(r.getName(), "relation");
    ASSERT_EQ(r.getNodes().first, n1_ptr);
    ASSERT_EQ(r.getNodes().second, n2_ptr);
}

TEST(RelationTest, Constructor_03)
{
    auto n1_ptr = std::make_shared<Node>("n1");
    auto n2_ptr = std::make_shared<Node>("n2");
    Relation r(std::string("relation"), n1_ptr, n2_ptr);
    ASSERT_EQ(r.getName(), "relation");
    ASSERT_EQ(r.getNodes().first, n1_ptr);
    ASSERT_EQ(r.getNodes().second, n2_ptr);
}
#include "syncopate/core/json_value.hpp"

#include <gtest/gtest.h>

// arrange-act-assert pattern

TEST(JsonValueGetterTest, EachJsonReturnsProperUnderlyingData) {
    // create json values of all available types
    syncopate::core::JsonValue nullJson = syncopate::core::JsonValue();
    syncopate::core::JsonValue boolJson = syncopate::core::JsonValue(true);
    syncopate::core::JsonValue doubleJson = syncopate::core::JsonValue(2.718);
    //!TODO: question that this raises is throwing errors when type is assumed implicitly (like long)
    // should the api still use double, uint, and int, should long be added, or should numbers be handled generically?
    syncopate::core::JsonValue uintJson = syncopate::core::JsonValue(static_cast<std::uint64_t>(100000000000));
    syncopate::core::JsonValue intJson = syncopate::core::JsonValue(static_cast<std::int64_t>(-1));
    syncopate::core::JsonValue stringJson = syncopate::core::JsonValue("const char c");
    syncopate::core::JsonValue stringTwoJson = syncopate::core::JsonValue(std::string("string"));
    syncopate::core::JsonValue vectorJson =
        syncopate::core::JsonValue(std::vector<syncopate::core::JsonValue>{nullJson, boolJson});
    syncopate::core::JsonValue mapJson = syncopate::core::JsonValue(
        std::map<std::string, syncopate::core::JsonValue>{{"one", doubleJson}, {"two", uintJson}});

    // check that the types match their expected types
    EXPECT_TRUE(nullJson.isNull());
    EXPECT_TRUE(boolJson.isBool());
    EXPECT_TRUE(doubleJson.isDouble());
    EXPECT_TRUE(uintJson.isUint());
    EXPECT_TRUE(intJson.isInt());
    EXPECT_TRUE(stringJson.isString());
    EXPECT_TRUE(stringTwoJson.isString());
    EXPECT_TRUE(vectorJson.isArray());
    EXPECT_TRUE(mapJson.isObject());

    // extract the values from the json
    EXPECT_EQ(boolJson.getBool(), true);
    EXPECT_EQ(doubleJson.getDouble(), 2.718);
    EXPECT_EQ(uintJson.getUint(), 100000000000);
    EXPECT_EQ(intJson.getInt(), -1);
    EXPECT_EQ(stringJson.getString(), "const char c");
    EXPECT_EQ(stringTwoJson.getString(), "string");

    // test arrays and objects member wise
    const std::vector<syncopate::core::JsonValue>& actualVec = vectorJson.getArray();
    EXPECT_EQ(actualVec.size(), 2);
    EXPECT_TRUE(actualVec[0].isNull());
    EXPECT_TRUE(actualVec[1].isBool());
    EXPECT_EQ(actualVec[1].getBool(), true);

    const std::map<std::string, syncopate::core::JsonValue>& actualMap = mapJson.getObject();
    EXPECT_EQ(actualMap.size(), 2);
    auto iter = actualMap.find("one");
    // in our imaginary json {"one" : "2.718"}
    EXPECT_NE(iter, actualMap.end());
    EXPECT_TRUE(iter->second.isDouble());
    EXPECT_EQ(iter->second.getDouble(), 2.718);
}
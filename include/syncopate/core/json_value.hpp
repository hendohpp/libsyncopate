#ifndef SYNCOPATE_JSON_VALUE_HPP_
#define SYNCOPATE_JSON_VALUE_HPP_

#include <cstdint>
#include <map>
#include <string>
#include <variant>
#include <vector>

namespace syncopate::core {

// datatypes: null, bool, number, string, array, object/map
class JsonValue {
  public:
    JsonValue();
    JsonValue(std::nullptr_t);
    JsonValue(bool bit);
    JsonValue(double num);
    JsonValue(std::uint64_t num);
    JsonValue(std::int64_t num);
    JsonValue(const char* str);
    JsonValue(std::string str);
    JsonValue(std::vector<JsonValue> arr);
    JsonValue(std::map<std::string, JsonValue> obj);

    bool isNull() const;
    bool isBool() const;
    bool isDouble() const;
    bool isUint() const;
    bool isInt() const;
    bool isString() const;
    bool isArray() const;
    bool isObject() const;

    bool getBool() const;
    double getDouble() const;
    std::uint64_t getUint() const;
    std::int64_t getInt() const;
    const std::string& getString() const;
    const std::vector<JsonValue>& getArray() const;
    const std::map<std::string, JsonValue>& getObject() const;

  private:
    // clang-format off
    using jsonType = std::variant<
        std::nullptr_t, 
        bool, 
        double, std::uint64_t, std::int64_t,
        std::string, 
        std::vector<JsonValue>,
        std::map<std::string, JsonValue>
    >;
    // clang-format on
    jsonType data_;
};

} // namespace syncopate::core

#endif // SYNCOPATE_JSON_VALUE_HPP_
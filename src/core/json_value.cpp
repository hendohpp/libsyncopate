#include "syncopate/core/json_value.hpp"

syncopate::core::JsonValue::JsonValue() : data_(nullptr) {}
syncopate::core::JsonValue::JsonValue(std::nullptr_t) : data_(nullptr) {}
syncopate::core::JsonValue::JsonValue(bool bit) : data_(bit) {}
syncopate::core::JsonValue::JsonValue(double num) : data_(num) {}
syncopate::core::JsonValue::JsonValue(std::uint64_t num) : data_(num) {}
syncopate::core::JsonValue::JsonValue(std::int64_t num) : data_(num) {}
syncopate::core::JsonValue::JsonValue(const char* str) : data_(std::string(str)) {}
syncopate::core::JsonValue::JsonValue(std::string str) : data_(std::move(str)) {}
syncopate::core::JsonValue::JsonValue(std::vector<JsonValue> arr) : data_(std::move(arr)) {}
syncopate::core::JsonValue::JsonValue(std::map<std::string, JsonValue> obj)
    : data_(std::move(obj)) {}

/**
 * @brief checks if the current json value holds a nullptr type
 * @return true if the underlying json data is null, false otherwise
 */
bool syncopate::core::JsonValue::isNull() const {
    return std::holds_alternative<std::nullptr_t>(data_);
}

/**
 * @brief checks if the current json value holds a boolean type
 * @return true if the underlying json data is a boolean, false otherwise
 */
bool syncopate::core::JsonValue::isBool() const { return std::holds_alternative<bool>(data_); }

/**
 * @brief checks if the current json value holds a double type
 * @return true if the underlying json data is a floating point number, false otherwise
 */
bool syncopate::core::JsonValue::isDouble() const { return std::holds_alternative<double>(data_); }

/**
 * @brief checks if the current json value holds a uint64 type
 * @return true if the underlying json data is an unsigned integer, false otherwise
 */
bool syncopate::core::JsonValue::isUint() const {
    return std::holds_alternative<std::uint64_t>(data_);
}

/**
 * @brief checks if the current json value holds an int64 type
 * @return true if the underlying json data is an integer, false otherwise
 */
bool syncopate::core::JsonValue::isInt() const {
    return std::holds_alternative<std::int64_t>(data_);
}

/**
 * @brief checks if the current json value holds a string type
 * @return true if the underlying json data is a string, false otherwise
 */
bool syncopate::core::JsonValue::isString() const {
    return std::holds_alternative<std::string>(data_);
}

/**
 * @brief checks if the current json value holds a vector of json values
 * @return true if the underlying json data is a json array, false otherwise
 */
bool syncopate::core::JsonValue::isArray() const {
    return std::holds_alternative<std::vector<JsonValue>>(data_);
}

/**
 * @brief checks if the current json value holds a json object/map type
 * @return true if the underlying json data is a json object, false otherwise
 */
bool syncopate::core::JsonValue::isObject() const {
    return std::holds_alternative<std::map<std::string, JsonValue>>(data_);
}

/**
 *
 */
bool syncopate::core::JsonValue::getBool() const { return std::get<bool>(data_); }

/**
 *
 */
double syncopate::core::JsonValue::getDouble() const { return std::get<double>(data_); }

/**
 *
 */
std::uint64_t syncopate::core::JsonValue::getUint() const {
    return std::get<std::uint64_t>(data_);
}

/**
 *
 */
std::int64_t syncopate::core::JsonValue::getInt() const {
    return std::get<std::int64_t>(data_);
}

/**
 *
 */
const std::string& syncopate::core::JsonValue::getString() const {
    return std::get<std::string>(data_);
}

/**
 *
 */
const std::vector<syncopate::core::JsonValue>& syncopate::core::JsonValue::getArray() const {
    return std::get<std::vector<syncopate::core::JsonValue>>(data_);
}

/**
 *
 */
const std::map<std::string, syncopate::core::JsonValue>&
syncopate::core::JsonValue::getObject() const {
    return std::get<std::map<std::string, syncopate::core::JsonValue>>(data_);
}
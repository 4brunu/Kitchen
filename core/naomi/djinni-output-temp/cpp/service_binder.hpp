// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from chef.djinni

#pragma once

#include <memory>
#include <string>

namespace naomi_gen {

class SimpleCursor;
enum class load_type;

class ServiceBinder {
public:
    virtual ~ServiceBinder() {}

    virtual ::naomi_gen::load_type load_type() = 0;

    virtual void on_error(const std::string & message) = 0;

    virtual void on_load(const std::string & message, bool cache, const std::shared_ptr<SimpleCursor> & cursor) = 0;
};

}  // namespace naomi_gen

// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from chef.djinni

#pragma once

#include <memory>
#include <vector>

namespace naomi_gen {

class Config;

class Recipe {
public:
    virtual ~Recipe() {}

    virtual std::vector<std::shared_ptr<Config>> get_configurations() = 0;
};

}  // namespace naomi_gen

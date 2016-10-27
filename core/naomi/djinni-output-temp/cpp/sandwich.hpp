// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from chef.djinni

#pragma once

#include <memory>
#include <string>

namespace naomi_gen {

class Dish;
class Recipe;
enum class module;

class Sandwich {
public:
    virtual ~Sandwich() {}

    virtual std::string get_version() = 0;

    virtual std::shared_ptr<Dish> grab(module module) = 0;

    virtual void add_recipe(const std::shared_ptr<Recipe> & recipe) = 0;
};

}  // namespace naomi_gen
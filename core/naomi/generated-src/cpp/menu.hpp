// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from application.djinni

#pragma once

#include <functional>

namespace naomi_gen {

enum class menu : int {
    OPEN_BEETROOT_SANDWICH,
};

}  // namespace naomi_gen

namespace std {

template <>
struct hash<::naomi_gen::menu> {
    size_t operator()(::naomi_gen::menu type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std

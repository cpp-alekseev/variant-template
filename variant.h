#pragma once

#include <variant>

template <typename... Args>
using Variant = std::variant<Args...>;

template <std::size_t I, class... Types>
constexpr auto& Get(std::variant<Types...>& v) {
    return std::get<I, Types...>(v);
}

template <std::size_t I, class... Types>
constexpr auto&& Get(std::variant<Types...>&& v) {
    return std::get<I, Types...>(std::move(v));
}

template <std::size_t I, class... Types>
constexpr const auto& Get(const std::variant<Types...>& v) {
    return std::get<I, Types...>(v);
}

template <std::size_t I, class... Types>
constexpr const auto&& Get(const std::variant<Types...>&& v) {
    return std::get<I, Types...>(std::move(v));
}

template <class T, class... Types>
constexpr T& Get(Variant<Types...>& v) {
    return std::get<T, Types...>(v);
}

template <class T, class... Types>
constexpr T&& Get(Variant<Types...>&& v) {
    return std::get<T, Types...>(std::move(v));
}

template <class T, class... Types>
constexpr const T& Get(const Variant<Types...>& v) {
    return std::get<T, Types...>(v);
}

template <class T, class... Types>
constexpr const T&& Get(const Variant<Types...>&& v) {
    return std::get<T, Types...>(std::move(v));
}

// TODO: Solution above is smart enough, but please, remove it and add your declarations here

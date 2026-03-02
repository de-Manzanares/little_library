#pragma once

#include <iostream>
#include <random>
#include <type_traits>

namespace llib {

/**
 * @param low_b lower bound
 * @param up_b upper bound
 * @return random integer in range [low_b, up_b] following uniform distribution
 * @note rand_engine is thread_local to avoid constructing a new engine each
 * time this function is called
 */
template <typename T = int>
auto random_in_range(const int low_b = 0, const int up_b = 9) -> T
  requires(std::is_integral_v<T>)
{
  thread_local std::ranlux48_base rand_engine{std::random_device{}()};
  auto dist = std::uniform_int_distribution<T>{static_cast<T>(low_b), static_cast<T>(up_b)};
  return dist(rand_engine);
}

inline void print() {}

template <typename T, typename... Types> auto print(T firstArg, Types... args) -> void
{
  std::cout << firstArg << ' ';
  print(args...);
}

} // namespace llib

#ifndef _TRAITS_H_
#define _TRAITS_H_

#include <type_traits>

namespace traits {
	template <typename T, typename... Types>
	constexpr bool is_any_of_v = (std::is_same_v<T, Types> || ...);
}

#endif  // _TRAITS_HPP_
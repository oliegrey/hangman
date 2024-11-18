#include "Random.h"

#pragma once
namespace Words
{
	const inline std::vector<std::string_view> words
	{
		"mystery",
		"broccoli",
		"account",
		"almost",
		"spaghetti",
		"opinion",
		"beautiful",
		"distance",
		"luggage",
	};

	inline std::string_view random() {
		return words[
			Random::get(0, static_cast<int>(words.size()) - 1)
		];
	}
}
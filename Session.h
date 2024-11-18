#include "Constants.h"
#include "Words.h"

#pragma once
class Session
{
public:
	enum GameState { playing, won, dead };

private:
	std::string_view m_word{};
	std::string m_wrongGuesses{};
	std::string m_rightGuesses{};

	const std::string constructFiller(const char filler)
	{
		std::string result{};
		for (int i{0}; i < Constants::maxLives; ++i) { result += filler; }
		return result;
	}

	const std::string getGuessInput();

	const bool testChar(char guess);

	void addWrongGuess(char wrongChar);

public:
	Session() :
		m_word{Words::random()},
		m_wrongGuesses{constructFiller(Constants::wrongFiller)},
		m_rightGuesses{constructFiller(Constants::rightFiller)}
	{}

	GameState stepForward()
	{
		const std::string guess{getGuessInput()};
		GameState gamestate{playing};

		if (guess.size() == 1 && testChar(guess[0])) { gamestate = won; }

		else if (m_word == guess) { gamestate = won; }

		else if (guess.size() > 1) { addWrongGuess(Constants::wrongWordChar); }

		if (m_wrongGuesses.find(Constants::wrongFiller) == std::string::npos) 
		{ 
			gamestate = dead; 
		}

		std::cout << "The word: " << m_rightGuesses << '\t';
		std::cout << "Wrong guesses: " << m_wrongGuesses << "\n\n";

		return gamestate;
	}
};
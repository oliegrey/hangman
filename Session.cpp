#include <iostream>

#include "Session.h"
#include "Words.h"
#include "Constants.h"


const std::string Session::getGuessInput()
{
	std::string guess{};
	while (true)
	{
		std::cout << "Enter a letter or word: ";
		std::getline(std::cin >> std::ws, guess);

		if (!std::cin)
		{
			std::cout << "Invalid input.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		return guess;
	}
}


const bool Session::testChar(char guessChar)
{
	for (size_t i{0}; i < m_word.size(); ++i)
	{
		if (m_word[i] == guessChar)
		{
			m_rightGuesses[i] = guessChar;
			return (m_word == m_rightGuesses);
		}
	}

	addWrongGuess(guessChar);
	return false;
}


void Session::addWrongGuess(char wrongChar)
{
	std::string temp{constructFiller(Constants::wrongFiller)};
	bool addedChar{false};

	//inserts wrong guess char alphabetically and discards last char of m_wrongguesses
	for (size_t i{0}; i < Constants::maxLives; ++i)
	{
		if (addedChar) 
		{
			temp[i] = m_wrongGuesses[i - 1];
		}
		else if (m_wrongGuesses[i] > wrongChar || m_wrongGuesses[i] == Constants::wrongFiller)
		{
			temp[i] = wrongChar;
			addedChar = true;
		}
		else 
		{
			temp[i] = m_wrongGuesses[i];
		}
	}

	m_wrongGuesses = temp;
}


#include <iostream>
#include <vector>

#include "Session.h"

int main()
{
	Session session{};
	int score{0};
	
	while (true)
	{
		session = {};

		std::cout << "~~ Hangman ~~\n" << 
			"Guess the word before you run out of stars.\n\n";
		
		Session::GameState gameState{Session::playing};
		while (gameState == Session::playing){gameState = session.stepForward();} 

		switch (gameState)
		{
		case Session::dead:
			score = 0;
			std::cout << "you ded!\nScore reset.";
			break;
		case Session::won:
			std::cout << "grats you won!\nScore: " << ++score;
			break;
		default:
			std::cout << "error";
			break;
		}

		std::cout << "\n\n";
	}
}
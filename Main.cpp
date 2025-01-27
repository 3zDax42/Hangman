#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

const int Max_Incorrect = 6;
char Incorrect[Max_Incorrect];
int numIncorrect = 0;
int Misses = 0;
void Display_Hangman();
void Display(string GuessedWord);
string ProcessGuess(char guess, string word, string GuessedWord);

int main()
{
	string WordList[] = { "computer", "science", "programming", "engineering", "biology" };
	srand(time(0));
	string word = WordList[rand() % 5];
	string GuessedWord(word.length(), '_');

	cout << "Welcome to Hangman!\n";
	while (Misses, Max_Incorrect && GuessedWord != word) {
		Display(GuessedWord);
		cout << "ENTER YOUR GUESS: ";
		char guess;
		cin >> guess;

		string oldGuessedWord = GuessedWord;
		GuessedWord = ProcessGuess(guess, word, GuessedWord);

		if (GuessedWord == oldGuessedWord) {
			cout << "You guessed that letter already >.< \n";
		}
		else {
			cout << "QwQ good job!\n";
		}
	}
	if (GuessedWord == word) {
		cout << "Congrats! You win! The word was" << word << "\n";
	}
	else {
		cout << "Game Over! Your word was" << word << "\n";
	}
	return 0;
}

void Display_Hangman() 
{
	cout << "\n"; // other option for endl;
	switch (Misses)
	{
	case 0:
		cout << "  |----|\n";
		cout << "  |    |\n";
		cout << "       |\n";
		cout << "       |\n";
		cout << "       |\n";
		cout << "       |\n";
		cout << "==========\n";
		break;
	case 1:
		cout << "  |----|\n";
		cout << "  |    |\n";
		cout << "  O    |\n";
		cout << "       |\n";
		cout << "       |\n";
		cout << "       |\n";
		cout << "==========\n";
		break;
	case 2:
		cout << "  |----|\n";
		cout << "  |    |\n";
		cout << "  O    |\n";
		cout << "  |    |\n";
		cout << "       |\n";
		cout << "       |\n";
		cout << "==========\n";
		break;
	case 3:
		cout << "  |----|\n";
		cout << "  |    |\n";
		cout << "  O    |\n";
		cout << "  |\\   |\n";
		cout << "       |\n";
		cout << "       |\n";
		cout << "==========\n";
		break;
	case 4:
		cout << "  |----|\n";
		cout << "  |    |\n";
		cout << "  O    |\n";
		cout << " /|\\   |\n";
		cout << "       |\n";
		cout << "       |\n";
		cout << "==========\n";
		break;
	case 5:
		cout << "  |----|\n";
		cout << "  |    |\n";
		cout << "  O    |\n";
		cout << " /|\\   |\n";
		cout << "  \\    |\n";
		cout << "       |\n";
		cout << "==========\n";
		break;
	case 6:
		cout << "  |----|\n";
		cout << "  |    |\n";
		cout << "  O    |\n";
		cout << " /|\\   |\n";
		cout << " /\\    |\n";
		cout << "       |\n";
		cout << "==========\n";
		break;
	}
}

void Display(string GuessedWord) 
{
	cout << "\n Word:";
	for (int i = 0; i < GuessedWord.length(); i++) {
		cout << GuessedWord[i] << ' ';
	}
	cout << "\n Incorrect Guesses: ";
	for (int i = 0; i < 6; i++) {
		cout << Incorrect[i] << ' ';
	}
	cout << "\n Misses left: " << Max_Incorrect - Misses << "\n";
	Display_Hangman();
}

string ProcessGuess(char guess, string word, string GuessedWord) 
{
	bool isCorrect = false;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] == guess && GuessedWord[i] == '_') {
			GuessedWord[i] = guess;
			isCorrect = true;
		}
	}
	if (!isCorrect) {
		bool alreadyGuessed = false;
		for (int i = 0; i < numIncorrect; i++) {
			if (Incorrect[i] == guess) {
				alreadyGuessed = true;
				break;
			}
		}
		if (!alreadyGuessed) {
			Incorrect[numIncorrect++] = guess;
			Misses++;
		}

	}
	return GuessedWord;
}

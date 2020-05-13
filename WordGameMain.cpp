
#include <iostream>
#include <ctime>
#include "graph1.h"
#include "WordGame.h"

#pragma warning(disable:4996)
using namespace std;

int main()
{
	//Variable Declaration/Initialization
	int rand_no = 0;
	int score = 0;
	char fn[255];
	char repeat = 'y';
	WordGame WordGame;

	//Display graphics
	displayGraphics();

	//Initialize random # generator
	srand(time(0));

	//Run program as many times as desired
	do
	{

		//Generate random #
		rand_no = rand() % 1149;

		//Prompt for fn
		cout << "Enter filename that contains words: ";
		cin >> fn;

		//Set the filename
		WordGame.setFileName(fn);

		//Set the word
		WordGame.setWord(rand_no);

		//Draw the scene
		WordGame.draw();

		//The score
		score=score+WordGame.play();
		gout << setPos(100, 70) << "Total Score: " << score << endg;

		//Get the word
		char* temp = WordGame.getWord();

		//Display the actual word
		cout << "The word is: " << temp << endl;

		cout << "Repeat? (y/n): ";
		cin >> repeat;

		//Clear screen
		system("cls");
		clearGraphics();

		//Cleanup memory
		delete[] temp;

	} while ((repeat == 'y') || (repeat == 'Y'));





	return 0;
}

#include<iostream>
#include<cstring>
#include<fstream>
#include"graph1.h"
#include"WordGame.h"

#pragma warning(disable:4996)
using namespace std;

//Constructor
WordGame::WordGame(){
	fileName = NULL;
	word = NULL;
}

//Destructor
WordGame::~WordGame(){
	delete[] fileName;
	delete[] word;
}

//WordGame method
WordGame::WordGame(const WordGame& wg){
	this->setFileName(wg.fileName);
	this->word = new char[strlen(wg.word) + 1];
	strcpy(this->word, wg.word);
}

//Getter for file name
char* WordGame::getFileName(){
	char* copy = new char[strlen(fileName) + 1];
	strcpy(copy, fileName);
	return(copy);
}

//Setter for file name
void WordGame::setFileName(char* fn){
	this->fileName = new char[strlen(fn) + 1];
	strcpy(this->fileName, fn);
}

//Setter for word
void WordGame::setWord(int rand_no){
	//Variable Declaration/Initialization
	int count = 0;
	char word[100];
	int rand_num = 0;
	//Open file for reading
	fstream in_file(this->fileName, ios::in);
	//2.Test if opened correctly
	if (!in_file){
		cout << "Cannot open " << fileName << endl;
		exit(-1);
	}
	//3.Read each word from the file
	while (true){
		//Read a word
		in_file >> word;
		//Check for eof
		if (in_file.eof()){
			break;
		}
		//Otherwise, process a word
		if (count == rand_no)
			break;
		count++;
	}
	//Set word to the Game
	this->word = new char[strlen(word) + 1];
	strcpy(this->word, word);
	in_file.close();
}

//Getter for word
char* WordGame::getWord(){
	char* copy = new char[strlen(word) + 1];
	strcpy(copy, word);
	return(copy);
}

//Draw method
void WordGame::draw(){
	int i = 0;
	for (i = 0; i < (int)strlen(word); i++){
		drawRect(100 + i * 33, 200, 32, 32);
	}
	Sleep(2000);
}

//Play method
int WordGame::play(){
	int i = 0;
	int j = 0;
	int score = 0;
	int guess_number = 1;
	char display[30];
	char guess[30];
	char vowels[] = { 'a', 'e', 'i', 'o', 'u' };
	bool find_vowel = false;
	bool game_over=true;
	int* hint = new int[(int)strlen(word)];

	//Check for vowels
	for (i = 0; i < (int)strlen(word); i++){ 
		for (j = 0; j < 5; j++){
			if (word[i] == vowels[j]){
				find_vowel = true;
			}
		}
		//Prepare to display the vowels
		if (find_vowel == true){
			hint[i] = 1;
		}
		else{
			hint[i] = 0;
		}
		find_vowel = false;
		}

		//Prepare to display the first letter
		hint[0] = 1;

	while(true){
		//Display letters
		for (i = 0; i < (int)strlen(word); i++){
			if (hint[i] == 1){
				sprintf(display, "%c.bmp", word[i]);
				displayBMP(display, 100 + 33 * i, 200);
			}
		}

		
			//Numbers of guesses
			cout << "Guess # " << guess_number << endl;

			//Ask for the guess
			cout << "What is the word? ";
			cin >> guess;
		

		//Compare the guess and the word
		if (strcmp(word, guess) == 0){
			gout << setPos(100, 100) << "!!!Correct!!!" << endg;
			gout << setPos(100, 120) << "Guess number: " << guess_number << endg;
			for (i = 0; i < (int)strlen(word); i++){
				if (hint[i] == 0){
					score += 10;
				}
				else
					score +=0;
			}
			gout << setPos(100, 140) << "Score: " << score << endg;
			return score;
		}
		//If the guess is wrong
		else{
			gout << setPos(100, 100) << "!!!Incorrect!!!" << endg;
			gout << setPos(100, 120) << "Guess number: " << guess_number << endg;
			for (i = 0; i < (int)strlen(word)-1; i++){
				if (hint[i] == 0){
					hint[i] = 1;
					guess_number++;
					game_over = false;
					break;
				}
					game_over = true;
			}
			
			if (game_over){
				gout << setPos(100, 100) << "!!!Game Over!!!" << endg;
				gout << setPos(100, 120) << "Correct Answer: " << word << endg;
				gout << setPos(100, 140) << "Score: 0"<< endg;
				return score;
				break;
			}
		}
	}
}
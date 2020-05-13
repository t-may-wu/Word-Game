
#ifndef WORDGAME_H
#define WORDGAME_H

class WordGame
{
private:
	char* fileName;
	char* word;

public:
	WordGame();
	~WordGame();
	WordGame(const WordGame& wg);
	char* getFileName();
	void setFileName(char* fn);
	void setWord(int rand_no);
	char* getWord();
	void draw();
	int play();
};

#endif

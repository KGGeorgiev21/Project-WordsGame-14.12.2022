#pragma once
#include "precompile.h"

class field {
public:
	// s for string, i for int
	field(char type);
	~field();
	
	void getInputString(string message);
	void getInputInt(int message);
	void setAnswerInt(int answer);
	void setAnswerString(string answer);

	bool checkAnswer();

private:
	int num = 0;
	int answerNum = 0;
	char type = ' ';
	string message = "";
	string answerString = "";

};
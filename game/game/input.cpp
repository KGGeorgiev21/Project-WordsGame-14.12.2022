#include "precompile.h"
#include "input.h"

field::field(char type) {
	if (type == 's' || type == 'i') {
		this->type = type;

	}
	else {
		cerr << invalid_argument("Invalid field type").what();
	}
}

field::~field() {

}

void field::getInputString(string message) {
	this->message = message;
}

void field::getInputInt(int num) {
	this->num = num;
}

void field::setAnswerInt(int answer) {
	this->answerNum = answer;
}

void field::setAnswerString(string answer) {
	this->answerString = answer;
}

bool field::checkAnswer() {
	if (this->type == 's') {

	}
	return true;
}
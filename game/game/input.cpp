#include "precompile.hpp"
#include "input.hpp"
#include <time.h>

field::field(sf::Color bgColor, int sizeX, int sizeY, float posX, float posY, float scaleX, float scaleY, sf::Font& font, sf::Texture& backgroundTexture) 
{
	this->background.setTexture(backgroundTexture);
	this->background.setPosition(sf::Vector2f(posX, posY));
	this->background.setScale(scaleX, scaleY);
	this->question.setFont(font);
	this->question.setCharacterSize(26);
	this->question.setFillColor(sf::Color(255,255,255));
	this->question.setPosition(sf::Vector2f(480, 257));
	this->input.setFont(font);
	this->input.setCharacterSize(36);
	this->input.setFillColor(sf::Color(255, 255, 255));
	this->input.setPosition(480 + 20, 400);


	this->QNAV = {
		{L"Как се пише \nбо_ \nб или п ? ", L"б"},
		{L"Как се пише \nду_ликат \nб или п?", L"б"},
		{L"Как се пише \nвкъ_и \nшт или щ?",L"щ"},
		{L"Как се пише \nинж_нер\nи или е?",L"е"},
		{L"Как се пише \nпиц_рия \nъ или а?",L"а"},
		{L"Как се пише \n'безпорно'\n'безспорно'?",L"безспорно"},
		{L"Как се пише \n'отвертка'\n'отверка'?",L"отвертка"},
		{L"Как се пише \nмер_дия\nо или у?",L"у"},
		{L"Как се пише \nас_алт\nф или в?",L"ф"},
		{L"Как се пише \n'здравей те'\n'здравейте'?",L"здравейте"},
		{L"Как се пише \nарг_мент\nо или у?",L"у"},
		{L"Как се пише \n'анцуг'\n'анцунг'?",L"анцуг"},
		{L"Как се пише \nкор_гирам \nе или и?",L"и"},
		{L"Как се пише \nмани_ \nя или а?",L"я"},
		{L"Как се пише \n'чуствам'\n'чувствам'?",L"чувствам"},
		{L"Как се пише \n'невинаги'\n'не винаги'?",L"невинаги"},
		{L"", L""}
		
	};
}

field::~field() 
{

}

// draw input field to the screen
void field::draw(sf::RenderWindow& window) {
	window.draw(this->background);
	window.draw(this->question);
	window.draw(this->input);
}

// get a random question
// takes integer up to 15 as an argument
void field::setQuestion(int row) {
	if (row == 15) {
		srand((int)time(0));

		int op = rand() % 5;

		int num1 = 0, num2 = 0, remainder = 0;

		switch (op) {
		case 0:
			num1 = rand() % 1000;
			num2 = rand() % 1000;
			this->QNAV[row].question = L"Колко е \n" + to_wstring(num1) + L" + " + to_wstring(num2) + L"?";
			this->QNAV[row].answer = to_wstring(num1 + num2);
			break;

		case 1:
			num1 = rand() % 1000;
			num2 = rand() % 1000;
			this->QNAV[row].question = L"Колко е \n" + to_wstring(num1) + L" - " + to_wstring(num2) + L"?";
			this->QNAV[row].answer = to_wstring(num1 - num2);
			break;

		case 2:
			num1 = rand() % 10;
			num2 = rand() % 10;
			this->QNAV[row].question = L"Колко е \n" + to_wstring(num1) + L" x " + to_wstring(num2) + L"?";
			this->QNAV[row].answer = to_wstring(num1 * num2);
			break;

		case 3:
			num1 = rand() % 100 + 1;
			num2 = rand() % 10 + 1;
			remainder = num1 % num2;

			while (remainder != 0) {
				num1 = rand() % 100 + 1;
				num2 = rand() % 10 + 1;

				remainder = (int)num1 % (int)num2;
			}
			this->QNAV[row].question = L"Колко е \n" + to_wstring(num1) + L" / " + to_wstring(num2) + L"?";
			this->QNAV[row].answer = to_wstring(num1 / num2);
			break;

		case 4:
			num1 = rand() % 10;
			this->QNAV[row].question = L"Колко е \n" +to_wstring(num1) + L" ^ 2?";
			this->QNAV[row].answer = to_wstring(num1 * num1);
			break;
		}

	}
	this->question.setString(this->QNAV[row].question);
}

bool field::checkAnswer(int row) {
	return this->input.getString() == this->QNAV[row].answer;
}
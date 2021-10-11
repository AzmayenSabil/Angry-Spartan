#include "ScoreSystem.h"

ScoreSystem::ScoreSystem()
{
	scoreFont.loadFromFile("Fonts/TYPEWR__.TTF");
	scoreText.setFont(scoreFont);
	//age ekhane setString use korechilam
	scoreText.setString("0");
	scoreText.setCharacterSize(22);
	scoreText.setFillColor(Color::Magenta);
	scoreText.setStyle(Text::Bold);
	scoreText.setPosition(5.f, 5.f);

	this->score = 0;
}

ScoreSystem::~ScoreSystem(){}

void ScoreSystem::updateScore(string enemyType)
{
	
	if (enemyType == "Swordsman") {
		score += 5;
		scoreText.setString(to_string(score));
	}
	if (enemyType == "Archer") {
		score += 10;
		scoreText.setString(to_string(score));
	}
}



void ScoreSystem::updateScoreFile()
{
	ofstream scoreFile;
	scoreFile.open("textfiles/Highscore.txt");

	if (!scoreFile) {
		cout << "couldn't open the file" << endl;
	}
	else {
		
		//while (!scoreFile.eof()) {}
		
		scoreFile << score;

		scoreFile.close();
	}

}

int ScoreSystem::getScore()
{
	return this->score;
}





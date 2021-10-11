#include "SaveFile.h"

SaveFile::SaveFile()
{
}

SaveFile::~SaveFile()
{
}

int* SaveFile::getProgress()
{
	std::ifstream file;
	file.open("Test.txt");
	for(int i=0; i< NUM; i++)
		file >> this->list[i];
	
	/*for (int i = 0; i < NUM; i++)
		cout << this->list[i] << " ";
	cout << endl;*/
	
	return this->list;
}

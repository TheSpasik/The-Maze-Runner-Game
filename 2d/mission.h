#pragma once
using namespace std;
int getCurrentMission(int x)
{
	int mission = 0;
	if (x == 0) { mission = 0; }
	if (x == 1) { mission = 1; }
	if (x == 2) { mission = 2; }
	if (x == 3) { mission = 3; }
	return mission;
}
string getTextMission(int currentMission) {
	string missionText = "";// создание текста для миссий

	switch (currentMission)// определение какой текст выводить
	{
	case 0: missionText = "\n Hello, Player!\n Your First Task!\nFIND MY EMERALD"; break;
	case 1: missionText = "\n You got it!\n Nice!\n Find gold coin"; break;
	case 2: missionText = "\n Great!\n One coin more!"; break;
	case 3: missionText = "\n You did it!\n Now\n RUUUUUNNNN"; break;
	}
	return missionText;
}


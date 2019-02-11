#pragma warning(disable : 4996);
#include "cricketTeam.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

//Default Constructor
cricketTeam::cricketTeam() {
	membernames = nullptr;
	teamName = nullptr;
	no_of_members = 0;
	for (int i = 0; i < 10; i++) {
		scoreInlast10matches[i] = -1;
	}
	Rank = -1;
	captain = '\0';
}

//Custom Constructor
cricketTeam::cricketTeam(string teamname, int No_of_members) {
	//teamName = new char[teamname.length()];
	teamName = &teamname[0u];
	cout << teamname << endl;
	cout << teamName << endl;
	no_of_members = No_of_members;
	Rank = -1;
	captain = '\0';
	membernames = nullptr;
	for (int i = 0; i < 10; i++) {
		scoreInlast10matches[i] = -1;
	}
}

//File Constructor
cricketTeam::cricketTeam(string filename) {
	ifstream fin(filename.c_str());
	if (fin.fail())
		cout << "Unable to open!" << endl;
	char temp[100];
	char T;
	fin.getline(temp, 100, ':');
	fin.getline(temp, 100);
	teamName=new char[strlen(temp)];
	strcpy(teamName, temp);
	fin.getline(temp, 100, ':');
	fin >> no_of_members;
	fin.getline(temp, 100);
	membernames = new string[no_of_members];
	for (int i = 0; i < no_of_members; i++) {
		fin.getline(temp, 100);
		membernames[i] = temp;
	}
	fin.getline(temp, 100, ':');
	fin >> Rank;
	fin.getline(temp, 100);
	fin.getline(temp, 100, ':');
	fin.getline(temp, 100);
	captain = temp;
	fin.getline(temp, 100, ':');
	
	for (int i = 0; i < 10; i++) {
		fin >> scoreInlast10matches[i];
		fin >> T;
	}
}

//Captain Setter
void cricketTeam::setCaptain(string name) {
	captain = name;
	cout << captain << endl;
}

//Captain Getter
string cricketTeam::getCaptain() {
	return captain;
}

//Rank Setter
void cricketTeam::setRank(int rank) {
	Rank = rank;
}

//Rank Getter
int cricketTeam::getRank() {
	if (Rank != -1)
		return Rank;
}

//Teamname Setter
void cricketTeam::setTeamname(string teamname) {
	if (teamName != nullptr) {
		//delete[]teamName;
		strcpy(teamName, teamname.c_str());
	}
	else
		strcpy(teamName, teamname.c_str());
}

//Teamname Getter
char* cricketTeam::getTeamname() {
	return teamName;
}

//No of Members Setter
void cricketTeam::setNo_of_members(int n) {
	no_of_members = n;
}

//No of Members Getter
int cricketTeam::getNo_of_members() {
	if (no_of_members != -1)
		return no_of_members;
}

//Average Score Function
int cricketTeam::avgScore() {
	int avg = 0;
	for (int i = 0; i < 10; i++) {
		avg = avg + scoreInlast10matches[i];
	}
	avg = avg / 10;
	return avg;
}

//Team Stats Print Function
void cricketTeam::printTeamStats() {
	int latestscore = -1;
	for (int i = 0; scoreInlast10matches[i] != -1 && i < 10; i++) {
		latestscore = scoreInlast10matches[i];
	}
	cout << "Latest Score: " << latestscore << endl;
	cout << teamName << endl;
	cout << captain << endl;
}

//User input Teamname
void cricketTeam::inputTeamMember(string name) {
	if (no_of_members < 11) {
		membernames[no_of_members] = name;
		no_of_members++;
	}
	else if (no_of_members == 11)
		cout << "There is no place for new team member!" << endl;
}

//User input score
void cricketTeam::inputScore(int score) {
	int x = 0;
	bool empty = false;
	for (x = 0; x < 10 && !empty; x++) {
		if (scoreInlast10matches[x] == -1)
			empty = true;
	}
	if (empty)
		scoreInlast10matches[x - 1] = score;
	else {
		for (int i = 0; i < 9; i++) {
			scoreInlast10matches[i] = scoreInlast10matches[i + 1];
		}
		scoreInlast10matches[9] = score;
	}
}

//Print Team
void cricketTeam::printTeam() {
	cout << "Team Name: " << teamName << endl;
	cout << "Total Members: " << no_of_members << endl;
	for (int i = 0; i < no_of_members; i++)
		cout << membernames[i] << endl;
	cout << "Rank: " << Rank << endl;
	cout << "Captain: " << captain << endl;
	cout << "Score: ";
	for (int i = 0; scoreInlast10matches[i] != -1 && i < 10; i++)
		cout << scoreInlast10matches[i] << ",";
	cout << endl;
}

//Compare Function
bool cricketTeam::compare(cricketTeam otherTeam) {
	int otherteam = otherTeam.avgScore();
	int thisTeam = avgScore();
	if (otherteam > thisTeam)
		return true;
	else if (otherteam < thisTeam)
		return false;
}

//Score Setter
void cricketTeam::ScoreSetter() {
	cout << "Input score: " << endl;
	for (int i = 0; i < 10; i++)
		cin >> scoreInlast10matches[i];
}

cricketTeam::~cricketTeam() {
	delete teamName;
	delete membernames;
	teamName = nullptr;
	membernames = nullptr;
	Rank = -1;
	captain = '\0';
	for (int i = 0; i < no_of_members; i++)
		scoreInlast10matches[i] = -1;
	no_of_members = 0;
}
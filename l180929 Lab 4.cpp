#include <iostream>
#include "l180929 cricketTeam.h"
#include <string>
using namespace std;


int main()
{
	string file = "C:\\Users\\Ali Ahmad\\Desktop\\l180929 Lab 4\\Pakistan.txt";
	string teamname = "Pakistan";
	cricketTeam Pakistan(file);
	cricketTeam otherTeam;
	
	//Print Team Information
	Pakistan.printTeam();

	//Print Team Stats
	Pakistan.printTeamStats();
	
	//Captain Getter Setter
	string captain = "Afridi";
	Pakistan.setCaptain(captain);
	captain = Pakistan.getCaptain();

	//Rank Getters Setter
	int rank = 0;
	Pakistan.setRank(5);
	rank = Pakistan.getRank();

	//Team Name Getter Setter
	teamname = "India";
	Pakistan.setTeamname(teamname);
	teamname = Pakistan.getTeamname();

	//No of members Getter Setter
	int members = 10;
	Pakistan.setNo_of_members(members);
	members = Pakistan.getNo_of_members();

	//User input team member
	string name = "Afridi";
	Pakistan.inputTeamMember(name);
	
	//User input Score
	int score = 250;
	Pakistan.inputScore(score);
	
	//Average Score
	int averageScore = Pakistan.avgScore();

	//otherTeam Score Setter
	//the creation of this function was not required by the lab manual
	otherTeam.ScoreSetter();

	//Compare
	bool compare;
	compare=Pakistan.compare(otherTeam);		// returns true if otherTeam has greater average score than Pakistan

	compare=otherTeam.compare(Pakistan);		//return true if Pakistan has greater average score than otherTeam

	system("pause");
}

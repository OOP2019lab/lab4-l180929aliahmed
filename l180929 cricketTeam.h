#include<iostream>
using namespace std;

class cricketTeam {
private:
	string* membernames;
	char* teamName;
	int no_of_members;
	int scoreInlast10matches[10];
	int Rank;
	string captain;
public:
	cricketTeam();
	cricketTeam(string teamname, int No_of_members);
	cricketTeam(string filename);
	void setCaptain(string name);
	void setRank(int rank);
	void setTeamname(string teamname);
	void setNo_of_members(int n);
	string getCaptain();
	int getRank();
	char* getTeamname();
	int getNo_of_members();
	void inputTeamMember(string name);
	void inputScore(int score);
	int avgScore();
	void printTeamStats();
	void printTeam();
	bool compare(cricketTeam otherTeam);
	void ScoreSetter();
	~cricketTeam();
};
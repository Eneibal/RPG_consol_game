#pragma once
#include<string>
#include<vector>
#include<fstream>

using namespace std;
class Puzzle
{
private:
	string qustion;
	vector<string>answers;
	int correct_answer;
public:
	Puzzle(string file_name_);
	~Puzzle();

	string get_as_string();

	const int& get_correct_ans()const;
};


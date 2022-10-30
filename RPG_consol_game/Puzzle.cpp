#include "Puzzle.h"

Puzzle::Puzzle(string file_name_)
{
	correct_answer = 0;

	ifstream in_file(file_name_, ios::in);

	int nr_of_ans = 0;
	int corect_ans = 0;
	string answer = "";
	if (in_file.is_open())
	{
		getline(in_file, qustion);
		in_file >> nr_of_ans;
		in_file.ignore();

		for (size_t i = 0; i < nr_of_ans; i++)
		{
			getline(in_file, answer);
			answers.push_back(answer);
		}
		in_file >> corect_ans;
		correct_answer = corect_ans;
		in_file.ignore();		
	}
	else
	{
		throw("Could not open puzzle!");
	}

	in_file.close();
}

Puzzle::~Puzzle()
{
}

string Puzzle::get_as_string()
{
	string load_answers = "";

	for (size_t i = 0; i < answers.size(); i++)
	{
		load_answers += to_string(i) + ": " + answers[i] + "\n";
	}

	return qustion + "\n" + "\n"
		+ load_answers + "\n"
		+ to_string(correct_answer)+"\n";
}
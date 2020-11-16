#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

using namespace std;

struct Nomination
{
	bool winner;
	string category;
	string actorName;
};

class Movie
{
public:
	/*Movie(int yearM, int yearC, string cat, string fName, bool win, string nomActor)
	{
		yearMovie = yearM;
		yearCeremony = yearC;
		category = cat;
		filmName = fName;
		winner = win;
		nominatedActor = nomActor;
	}*/

	Movie(int yearM, int yearC, string fName)
	{
		yearMovie = yearM;
		yearCeremony = yearC;
		filmName = fName;
	}
	Movie()
	{
		yearMovie = -1;
		yearCeremony = -1;
		filmName = "";
	}

	void AddNomination(string cat, string aName, bool win)
	{
		Nomination tNom;
		tNom.category = cat;
		tNom.actorName = aName;
		tNom.winner = win;

		noms.push_back(tNom);

	}

	int GetYearM()
	{
		return yearMovie;
	}

	int GetYearC()
	{
		return yearCeremony;
	}

	int GetNumberOfNominations()
	{
		return noms.size();
	}

	string GetNomCategory(int checkNom)
	{
		return noms[checkNom].category;
	}

	string GetNomActor(int checkNom)
	{
		return noms[checkNom].actorName;
	}

	bool GetNomWinner(int checkNom)
	{
		return noms[checkNom].winner;
	}

	string GetFilmName()
	{
		return filmName;
	}

	bool IsWinner()
	{
		for (int i = 0; i < noms.size(); i++)
		{
			if (noms[i].winner)
			{
				return true;
			}
		}

		return false;
	}



private:
	int yearMovie, yearCeremony;
	string filmName;
	vector<Nomination> noms;
};



#endif
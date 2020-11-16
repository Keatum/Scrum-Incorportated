#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Movie.h"

#ifndef MOVIEDATABASE_H
#define MOVIEDATABASE_H


using namespace std;

class MovieDatabase
{
public:

	//Takes in a file name of a CSV, loads lines from that file and creates a list of movies based on it
	//It takes a noticeable amount of time to get through the loading, at least on my machine.
	void LoadCSV(string filename)
	{
		fstream fin;
		string temp, yFilm, yCerem, cat, actorName, fName, winner;
		stringstream ss;
		vector<string> split;
		Movie *tMovie;

		fin.open(filename, ios::in);

		//get rid of category titles.
		getline(fin, temp);

		//Load the file line by line until we reach the end
		while (getline(fin, temp))
		{ 
			//This is for Debug
			lines.push_back(temp);

			ss << temp;

			//Witht he line in a string stream, use getline with comma as delimiter to get each component of the line separately and push them into a string vector.
			while (ss.good())
			{
				string substr;
				getline(ss, substr, ',');
				split.push_back(substr);
			}

			//clear the string stream for the next line
			ss.str("");
			ss.clear();

			//Split out the line into the important parts
			yFilm = split[0];
			yCerem = split[1];
			cat = split[3];
			actorName = split[4];
			fName = split[5];
			winner = split[6];

			//clear the string vector for the next line
			split.clear();

			//If the list doesn't have this movie already, then create it
			if (!ContainsMovie(fName))
			{
				//Convert strings and make the movie
				tMovie = new Movie(atoi(yFilm.c_str()), atoi(yCerem.c_str()), fName);

				//Add the new movie, then clear tMovie
				movies.push_back(*tMovie);
				delete tMovie;
			}
			//Add the nomination to the existing movie
			AddNomToMovie(cat, actorName, ((winner == "True") ? true : false), fName);
		}
	}
	
	Movie GetMovieAt(int num)
	{
		return movies[num];
	}

	string ReturnLineNum(int num)
	{
		return lines[num];
	}

	int MovieCount()
	{
		return movies.size();
	}

	bool ContainsMovie(string fName)
	{
		for (int i = 0; i < movies.size(); i++)
		{
			if (movies[i].GetFilmName() == fName)
			{
				return true;
			}
		}
		return false;
	}

	int GetMovieIndex(string fName)
	{
		for (int i = 0; i < movies.size(); i++)
		{
			if (movies[i].GetFilmName() == fName)
			{
				return i;
			}
		}
		return -1;
	}

	void AddNomToMovie(string cat, string aName, bool win, string fName)
	{
		int x = GetMovieIndex(fName);
		if (x >= 0)
		{
			movies[x].AddNomination(cat, aName, win);
		}
	}

	string ConvertStringFormat(string targetStr, char changeThis, char toThis)
	{
		for (int i = 0; i < targetStr.length(); i++)
		{
			if (targetStr[i] == changeThis)
			{
				targetStr[i] = toThis;
			}
		}

		return targetStr;
	}

private:
	vector<string> lines;
	vector<Movie> movies;
};


#endif

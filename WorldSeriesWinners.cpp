/***********************************************************************
CSCI 240         Program 7     Fall 2016

Programmer: Ben Lane

Section: 0002

Date Due: 10/28/16

Purpose: To select a team and report how many times they have won
		 the World Series (and in what years too!).
***********************************************************************/

#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

// Function prototypes.
int buildArray( string[] );
int numWins( string[], int, string );
void displayYears( string[], int, string );

// Size of array.
const int numElements = 120;

int main()
{
	string teamArray[numElements];
	int numTeams = 0, wins;
	string teamName;
	
	// Get the number of teams listed in file.
	numTeams = buildArray( teamArray );
	
	// Ask and get team name from user.
	cout << "Enter the team name: ";
	getline( cin, teamName );		
		
	// Add up how mnay times specific team is listed.
	wins = numWins( teamArray, numTeams, teamName );
	
	if ( wins == 0 or wins > 1 )
		cout << endl << "The " << teamName << " have won the World Series a total of " << wins << " times. " << endl << endl;
	else
		cout << endl << "The " << teamName << " have won the World Series a total of " << wins << " time. " << endl << endl;
	
	displayYears( teamArray, numTeams, teamName );
	

	return 0;
}


int buildArray( string teamArray[] )
{
	ifstream infile;
	string teamName;
	int i = 0, numTeams = 0;
	
	infile.open( "WorldSeriesWinners.txt" );
	
	if ( !infile )
		cout << "File failed to open. ";		
	
	// While file is being read, add team from file to 
	// to a specific array element. 	
	while ( getline(infile, teamName) )
		{
		teamArray[i] = teamName;
		numTeams++;
		i++;
		
		}
	
	
	return numTeams;
}


int numWins( string teamArray[], int numTeams, string teamName )
{
	int numWins = 0;
	
	// Every time team is in array, add one to win counter.
	for ( int i = 0; i < numTeams; i++ )
		{
		if ( teamArray[i] == teamName )
			numWins++;	
			
		}
	
	return numWins;
	
}


void displayYears( string teamArray[], int numTeams, string teamName )
{
	int column = 1;
	
	// Display each year the team has won, with a maximum of 7 per line.
	for ( int i = 0; i < numTeams; i++ )
		{
		if ( teamArray[i] == teamName )
			{
			cout << 1903 + i << " ";
			column++;
			if ( column == 8 )
				{
				cout << endl;
				column = 1;
				
				}
				
			}		
			
		}
	
}


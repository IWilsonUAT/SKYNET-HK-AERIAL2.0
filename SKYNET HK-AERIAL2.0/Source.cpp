#include <iostream>
using namespace std;

//start of any c++ program
int main()
{
	//creating variables for the program to use 
	int SearchGridHighNumber = 64;
	int SearchGridLowNumber = 0;
	int TargetLocationPrediction = ((SearchGridHighNumber - SearchGridLowNumber) / 2) + SearchGridLowNumber;
	int EnemyLocation = rand() % 63+1;
	//ping is being used to keep track of the number of attempts it took to find the enemy
	int PingB = 1;
	int PingP = 1;
	int PingL = 1;
	int PingR = 1;
	int PlayerGuess;
	int RandomGuess = rand()%63+1;
	int LinearGuess = 0;
	cout << "Generating a Random Enemy location in an 8x8 grid.\n";
	cout << "The Enemy location is " << EnemyLocation << " on a 8x8 grid with sectors 1-64.\n";
	cout << "SKYNET HK-AERIAL Initializing Software.\n";
	cout << "-------------------------------------------------------------------------------------------\n\n";
	cout << "Please enter your guess.";
	cin >> PlayerGuess;
	//loop for player
	while(PlayerGuess != EnemyLocation)
	{
		cout << "SKYNET HK-AERIAL player is sending out ping #" << PingP << ".\n\n";
		//using an if statement to determine if the player guess is higher than the enemy location
		if (PlayerGuess > EnemyLocation)
		{
			cout << "The player guess location of " << PlayerGuess << " was higher than the enemy location.\n";
			cout << "-------------------------------------------------------------------------------------------\n\n";
		}
		else if (PlayerGuess < EnemyLocation)
		{
			//using an else if statement to determine if the player guess is lower than the enemy location
			cout << "The player guess location of " << PlayerGuess << " was lower than the enemy location.\n";
			cout << "-------------------------------------------------------------------------------------------\n\n";
		}
		else
		{
			//in case some weird random event happens that causes an error
			cout << "ERROR, ERROR, ERROR.\n You can thank Brandon for this.";
		}
		cout << "Please enter your guess.";
		cin >> PlayerGuess;
		PingP++;
	}
	//loop for linear guess
	//linear is start at bottom go up by one
	while(LinearGuess != EnemyLocation)
	{
		cout << "SKYNET HK-AERIAL linear is sending out ping #" << PingL << ".\n\n";
		LinearGuess++;
		cout << "The linear prediction location of " << LinearGuess << " was lower than the enemy location of " << EnemyLocation << ".\n";
		cout << "-------------------------------------------------------------------------------------------\n\n";
		PingL++;
	}
	//loop for the random guess
	while(RandomGuess != EnemyLocation)
	{
		cout << "SKYNET HK-AERIAL random is sending out ping #" << PingB << ".\n\n";
		if(RandomGuess > EnemyLocation)
		{
			cout << "The random prediction location of " << RandomGuess << " was higher than the enemy location of " << EnemyLocation << ".\n";
		}
		else if(RandomGuess < EnemyLocation)
		{
			cout << "The random prediction location of " << RandomGuess << " was lower than the enemy location of " << EnemyLocation << ".\n";
		}
		else
		{
			//in case some weird random event happens that causes an error
			cout << "ERROR, ERROR, ERROR.\n You can thank Brandon for this.";
		}
		RandomGuess = rand() % 63 + 1;
		PingR++;
	}
	//using a while loop to keep checking the location until it is correct 
	while (TargetLocationPrediction != EnemyLocation)
	{
		cout << "SKYNET HK-AERIAL is sending out ping #" << PingB << ".\n\n";
		//using an if statement to determine if the predicted location is higher than the enemy location
		if (TargetLocationPrediction > EnemyLocation)
		{
			cout << "The target prediction location of " << TargetLocationPrediction << " was higher than the enemy location of " << EnemyLocation << ".\n";
			//changing the searchGridHighNumber to the new max number
			SearchGridHighNumber = TargetLocationPrediction;
			cout << "The new searchGridHighNumber is " << SearchGridHighNumber << ".\n\n";
			cout << "-------------------------------------------------------------------------------------------\n\n";
		}
		else if (TargetLocationPrediction < EnemyLocation)
		{
			//using an else if statement to determine if the predicted location is lower than the enemy location
			cout << "The target prediction location of " << TargetLocationPrediction << " was lower than the enemy location of " << EnemyLocation << ".\n";
			//changing the searchGridLowNumber to the new minimum number
			SearchGridLowNumber = TargetLocationPrediction;
			cout << "The new searchGridLowNumber is " << SearchGridLowNumber << ".\n\n";
			cout << "-------------------------------------------------------------------------------------------\n\n";
		}
		else
		{
			//in case some weird random event happens that causes an error
			cout << "ERROR, ERROR, ERROR.\n You can thank Brandon for this.";
		}
		TargetLocationPrediction = ((SearchGridHighNumber - SearchGridLowNumber) / 2) + SearchGridLowNumber;
		PingB++;
	}
	//outputting the enemy location and the number of attempts it took to find it
	
	cout << "The Enemy has been found at location " << TargetLocationPrediction << ".\n\n";
	cout << "SKYNET HK-AERIAL Player found the enemy in " << PingP << " attempts.\n";
	cout << "SKYNET HK-AERIAL Linear found the enemy in " << PingL << " attempts.\n";
	cout << "SKYNET HK-AERIAL Random found the enemy in " << PingR << " attempts.\n";
	cout << "SKYNET HK-AERIAL Binary found the enemy in " << PingB << " attempts.\n";
	return 0; 
} 
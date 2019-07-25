/*
A simple dictionary program to print out and ommit certain words.

© D. Green 2019.
*/

#include"D:\Visual_Studio_Projects_Cpp_book\std_lib_facilities.h"

int main()
{
	cout << "Please type 'quit' to proceess input and exit program.\n";

	vector<string> wordsList;

	for (string tempWord; cin >> tempWord && tempWord != "quit";)
	{
		wordsList.push_back(tempWord);
	}

	cout << "The number of words in the dictionary are " << wordsList.size() << '\n';

	// Sort alphabetically
	sort(wordsList);

	////For each
	//for (string words : wordsList)
	//{
	//	cout << words << ", ";
	//}


	// Check for duplicates and then ommit them during printing of the dictionary vector.
	//for (int i = 0; i < wordsList.size(); ++i)
	//{
	//	/*
	//	This must be done this way [i - 1], comparing current with previous instead of current with next, because to compare current with next
	//	would req. the syntax [i + 1] which would take us off the end of the vector resulting in an error.
	//	*/
	//	if (i == 0 || wordsList[i - 1] != wordsList[i])
	//	{
	//		cout << wordsList[i] << ".\n";
	//	}
	//}

	vector<string> disliked = { "dog", "fox", "jumped" };

	// Iterate over wordsList.
	for (int i = 0; i < wordsList.size(); ++i)
	{
		// Check if the previous word was the same as the current, if not, run code block. (check for duplicates in other words)
		if (i == 0 || (wordsList[i - 1] != wordsList[i]))
		{
			// Iterate over disliked words list.
			for (int j = 0; j < disliked.size(); ++j)
			{
				// Compare disliked word at given element against wordsList at given element. If found print BLEEP! and break out of loop.
				if (wordsList[i] == disliked[j])
				{
					cout << "BLEEP!" << '\n';
					break;
				}
				else if (j == (disliked.size() - 1))									// If we have iterated over the entire disliked words list and haven't found disliked word then print the word we are chekcing.
				{					
					cout << wordsList[i] << ".\n";
					
					//cout <<  wordsList[i] << " is not on the dislike list!\n";
				}
			}
		}
	}

	return 0;
}
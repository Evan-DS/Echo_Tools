#pragma once	//Include once

// Declare Library(s) and function(s)
#include <iostream>		//Library for cout, cin, endl, etc...
#include <string>		//Library for string
#include <math.h>		//Library for math
#include <time.h>		//Library for time
#include <glut.h>		//Library for glut (OpenGL)
#include <fstream>		//Library for file-stream
#include <sstream>		//Library for string-stream
#include <typeinfo>		//Library for info of types

#include "ICS_Game.h"			// for the simple game framework *** MUST COME BEFORE "ICS_ConsoleHelper.h" ---> "#include <winsock2.h>	// for Windows internet communication... this must come before Windows.h!" ***
#include "ICS_ConsoleHelper.h"	// for changing colors in, clearing, and pausing the console
#include "ICS_Sound.h"			// for playing sounds
#include "ICS_Sprite.h"			// for sprite

/*--------------------------------------------------------------------------------------------------------------*/


/************************
*		VARIABLES		*
************************/
/*~~~~~Definitions~~~~~*/

#define NUMBER_LINE COUT "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" ENDL	// used to print a number line for debug purposes
#define TAB_LINE COUT "       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |" ENDL	// used to print a number line for debug purposes
#define ZERO 0 		// used to set a variable to decimal[0]	
#define ONE 1		// used to set a variable to decimal[1]	
#define MEMORY_ADDRESS - ONE	// used to account for an array starting at value [0] instead of [1]
#define PI 3.14159265359f	// the mathematical constant pi
#define T true		// used to declare state true
#define F false		// used to declare state false
#define NULL_PTR nullptr	// re-define NULL to be less problematic
#define ENDLINE cout << endl;	// used to efficently skip an output line
#define SPACE << " "			// used to efficently skip writing a spacing line
#define SPACES_IN_A_TAB 8		// used to define total spaces in a tab
#define TAB << "\t"				// used to efficently skip writing a tab line
#define MANUAL_TAB "        "	// used to efficently skip writing a tab line manually due to tab positioning in fixed locations and console paramaters(8 spaces)
#define BAR << "|"				// used to efficently skip writing a bar line
#define ENDL << endl;			// used to efficently skip writing an endline
#define COUT cout <<			// used to efficently skip writing a console output call
#define PASSXTHROUGH int x = ZERO	// used to efficently skip writing the beginning of most base for-loops
#define PASSYTHROUGH int y = ZERO	// used to efficently skip writing the beginning of most secondary for-loops
#define PASSZTHROUGH int z = ZERO	// used to efficently skip writing the beginning of most tertiary for-loops
#define FAUX_RAN srand((unsigned int)time(NULL));	// used to efficently seed 'srand'
#define ONE_HUNDRED_MILLION 100000000	// used to efficently write and count out each '0' in '100000000'
#define IN_HALF / 2		// used to efficently divide by '2'
#define DOUBLE_IT * 2	// used to efficently multiply by '2'
#define INT_NULL typeid(NULL).name()		// used to define type state(s)
#define FLOAT_NULL typeid(0.00).name()		// used to define type state(s)
#define BOOL_NULL typeid(F).name()			// used to define type state(s)
#define CHAR_NULL typeid(' ').name()			// used to define type state(s)
#define STRING_NULL typeid("").name()		// used to define type state(s)


/*~~~~~Integer~~~~~*/



/*~~~~~Float~~~~~*/



/*~~~~~String~~~~~*/



/*~~~~~Boolean~~~~~*/



/*~~~~~Character~~~~~*/



/*~~~~~Sound~~~~~*/
unsigned int soundId_music_ECHO;

static int totalAudioFiles = ZERO;
int maxAudioArraySize = ONE;

int* audioArray = new int[maxAudioArraySize];


/*--------------------------------------------------------------------------------------------------------------*/

/****************************************************************************************************************
*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*
*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*
*																												*
*													FUNCTIONS													*
*																												*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*
*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*
*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*
****************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------*/

/************************
*	  	 CONSOLE		*
************************/

// Black console
void systemBlack_ECHO()			// Create a function called "systemBlack"
{
	system("pause");				// Pause console
	clearConsole(COLOR_INTENSE_BLACK);		// Clear and colour the console black
}

// White console
void systemWhite_ECHO()			// Create a function called "systemWhite"
{
	system("pause");				// Pause console
	clearConsole(COLOR_INTENSE_WHITE);		// Clear and colour the console black
}

// Red console
void systemRed_ECHO()			// Create a function called "systemRed"
{
	system("pause");				// Pause console
	clearConsole(COLOR_RED);		// Clear and colour the console red
}

// Green console
void systemGreen_ECHO()			// Create a function called "systemGreen"
{
	system("pause");				// Pause console
	clearConsole(COLOR_GREEN);		// Clear and colour the console green
}

// Blue console
void systemBlue_ECHO()			// Create a function called "systemBlue"
{
	system("pause");				// Pause console
	clearConsole(COLOR_BLUE);		// Clear and colour the console blue
}

// Colour console
void systemColour_ECHO(short int colour = COLOR_BLACK)	// Create a function called "systemColour"
{
	system("pause");			// Pause console
	clearConsole(colour);		// Clear and colour the console black
}

int handleExit_ECHO(float sleepTimer = ZERO)
{
	ENDLINE
	Sleep(sleepTimer);
	system("pause");
	return ZERO;
}

void resizeConsole(int xOffset = ZERO, int yOffset = ZERO, int newWidth = 1920, int newHeight = 1080)
{
	HWND console = GetConsoleWindow();
	RECT rect;
	GetWindowRect(console, &rect); //stores the console's current dimensions
	MoveWindow(console, rect.left - xOffset, rect.top - yOffset, newWidth, newHeight, TRUE);
}

int leftToTab_ECHO(int lengthFromOrigin = ZERO)
{
	int leftToTabVar = (SPACES_IN_A_TAB - (lengthFromOrigin % SPACES_IN_A_TAB));	//characters left to the next tab
	return leftToTabVar;
}

int nextTabStop_ECHO(int lengthFromOrigin = ZERO)
{
	int nextTabStopVar = (lengthFromOrigin + SPACES_IN_A_TAB) / SPACES_IN_A_TAB * SPACES_IN_A_TAB;
	return nextTabStopVar;
}


/*--------------------------------------------------------------------------------------------------------------*/

/************************
*	  	  ARRAY			*
************************/

std::string defineCharArray_ECHO(char token, int length)
{
	std::string output = "";

	for (PASSXTHROUGH; x < length; x++)
	{
		output += token;
	}
	
	return output;
}

template <typename Type>
void printArray_ECHO(Type& desiredArray, int arrayLength, std::string token = " ", std::string endLine = "\n")
{
	for (PASSXTHROUGH; x < arrayLength; x++)
	{
		COUT desiredArray[x] << token;
	}

	COUT endLine;
}

template <typename Type>
void printArray_ECHO(Type& desiredArray, int arrayXLength, int arrayYLength, std::string token = " ", std::string endLine = "\n")
{
	for (PASSYTHROUGH; y < arrayYLength; y++)
	{
		for (PASSXTHROUGH; x < arrayXLength; x++)
		{
			COUT desiredArray[x][y] << token;
		}
	}

	COUT endLine;
}

template <typename Type>
void resizeArray_ECHO(Type*& desiredArray, int currentSize, int& maxSize, int rateOfChange = 2, bool multiply = T)
{
	if (multiply)
	{
		maxSize *= rateOfChange;
	}
	else
	{
		maxSize += rateOfChange;
	}
	Type* tempArray = new Type[maxSize];

	for (int passThrough = ZERO; passThrough < currentSize; passThrough++)
	{
		tempArray[passThrough] = desiredArray[passThrough];
	}

	desiredArray = NULL;
	delete[] desiredArray;

	desiredArray = tempArray;

}

template <typename Type>
void combineArray_ECHO(Type* data, int end = ONE, int start = ZERO)
{
	int index = ZERO;

	while (end <= sizeof(data) && start != end)
	{
		if (data[start] > data[end])
		{
			index = data[end];

			for (PASSXTHROUGH + end; x > start; x--)
			{
				data[x] = data[x - ONE];
			}

			data[start] = index;
			start++;
			end++;
		}
		else
		{
			start++;
		}
	}
}

template <typename Type>
void divideArray_ECHO(Type* data, int end = ONE, int start = ZERO)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
	}
}

/*--------------------------------------------------------------------------------------------------------------*/

/************************
*	  	  MATH			*
************************/

float milisecondsToSeconds_ECHO(float miliseconds)
{
	float seconds = miliseconds / 1000;
	return seconds;
}


/*--------------------------------------------------------------------------------------------------------------*/

/************************
*	   PARAMETERS		*
************************/

void clamp_ECHO(int& value, int min, int max)
{
	// if the value is less than the minimum, set it to the minimum
	if (value < min)
	{
		value = min;
	}

	// if the value is greater than the maximum, set it to the maximum
	if (value > max)
	{
		value = max;
	}
}


/*--------------------------------------------------------------------------------------------------------------*/

/************************
*		SEARCHING		*
************************/

template <typename Type>
Type linearSearch_ECHO(Type* array, int length = 2, Type searchVal = ONE)
{
	for (int i = ZERO; i < length; i++)
	{
		if (array[i] == searchVal)
		{
			return i;
		}
	}
	return MEMORY_ADDRESS;
}

template <typename Type>
Type linearSearch_ECHO(const Type* array, int length = 2, Type searchVal = ONE)
{
	for (int i = ZERO; i < length; i++)
	{
		if (array[i] == searchVal)
		{
			return i;
		}
	}
	return MEMORY_ADDRESS;
}

template <typename Type>
int binarySearch_ECHO(Type* array, int start = ZERO, int end = ONE, Type target = ZERO)
{
	if (start > end)
	{
		return MEMORY_ADDRESS;
	}

	int midPoint = (start + end) IN_HALF;

	if (array[midPoint] < target)
	{
		return binarySearch_ECHO(array, start, midPoint - MEMORY_ADDRESS, target);
	}
	else if (array[midPoint] > target)
	{
		return binarySearch_ECHO(array, start, midPoint MEMORY_ADDRESS, target);
	}
	else
	{
		return midPoint;
	}
}

template <typename Type>
int binarySearch_ECHO(const Type* array, int start = ZERO, int end = ONE, Type target = ZERO)
{
	if (start > end)
	{
		return MEMORY_ADDRESS;
	}

	int midPoint = (start + end) IN_HALF;

	if (array[midPoint] < target)
	{
		return binarySearch_ECHO(array, start, midPoint - MEMORY_ADDRESS, target);
	}
	else if (array[midPoint] > target)
	{
		return binarySearch_ECHO(array, start, midPoint MEMORY_ADDRESS, target);
	}
	else
	{
		return midPoint;
	}
}

template <typename Type>
void findSmallest_ECHO(Type* array, int length, Type& smallestValue, int& occurrences)
{
	if (length > ZERO)
	{
		smallestValue = array[ZERO];
		occurrences = ONE;
	}

	for (PASSXTHROUGH + ONE; x < length; x++)
	{
		if (array[x] < smallestValue)
		{
			smallestValue = array[x];
			occurrences = ONE;
		}
		else if (array[x] == smallestValue)
		{
			occurrences++;
		}
	}
}

template <typename Type>
int countMultiples_ECHO(Type* array, int length, Type value, int delimeter)
{
	int counter = ZERO;

	for (PASSXTHROUGH + delimeter; x < length; x++)
	{
		if (array[x] % value == ZERO)
		{
			counter++;
		}
	}
	return counter;
}

template <typename Type>
int countMultiples_ECHO(const Type* array, int length, Type value, int delimeter)
{
	int counter = ZERO;

	for (PASSXTHROUGH + delimeter; x < length; x++)
	{
		if (array[x] % value == ZERO)
		{
			counter++;
		}
	}
	return counter;
}

template <typename Type>
void threeInARow_ECHO(Type* array, int length, int& pivot, Type& element)
{
	pivot = MEMORY_ADDRESS;
	element = ZERO;

	for (int z = ZERO; z < length MEMORY_ADDRESS DOUBLE_IT; z++)
	{
		if (array[z] == array[z + ONE] && array[z] == array[z + 2])
		{
			pivot = z;
			element = array[z];
			return;
		}
	}
}

template <typename Type>
Type findMedian_ECHO(Type* array, int length = 2)
{
	if (length % 2 == ZERO)
	{
		Type val1 = array[length IN_HALF];
		Type val2 = array[length IN_HALF - ONE];
		Type medianVal = (val2 + val1) IN_HALF;
		return medianVal;
	}
	else
	{
		return array[length IN_HALF];
	}
}


/*--------------------------------------------------------------------------------------------------------------*/

/************************
*		 SORTING		*
************************/

template <typename Type>
using SortingPrototype = void(*)(Type*, bool, int, int);

template <typename Type>
float elapsedTime_ECHO(SortingPrototype<Type> function, int dataSet = ONE_HUNDRED_MILLION, bool miliseconds = T, bool seedRand = T)
{
	if (seedRand)
	{ 
		FAUX_RAN
	}

	int* elapsedTimeArray = new int[dataSet];
	int elapsedTimeVal = ZERO;

	for (PASSXTHROUGH; x < dataSet; x++)
	{
		elapsedTimeVal += rand() % 5;
		elapsedTimeArray[x] = elapsedTimeVal;
	}

	clock_t startTimer = clock();

	function(elapsedTimeArray, T, dataSet, ZERO);

	float timeElapsed = clock() - startTimer;

	elapsedTimeArray = NULL_PTR;
	delete[] elapsedTimeArray;

	if (!miliseconds)
	{
		return milisecondsToSeconds_ECHO(timeElapsed);
	}
	else
	{
		return timeElapsed;
	}
}

template <typename Type>
float elapsedTime_ECHO(SortingPrototype<Type> function, Type* array, bool ascending = T, int end = ONE, int start = ZERO, bool miliseconds = T, Type* exceptionHandler = NULL_PTR, int exceptions = ZERO, Type xHandle = NULL_PTR, Type yHandle = NULL_PTR, std::string functionName = "NULL ADDRESS", std::string fileName = "NULL ADDRESS", std::string functionException = "NULL", std::string fileException = "NULL")
{
	clock_t startTimer = clock();

	for (PASSXTHROUGH; x < exceptions; x++)
	{
		std::stringstream exceptionData; //<< xHandle SPACE << yHandle;
		exceptionData << xHandle;

		if (exceptionHandler[x] == xHandle && yHandle)
		{
			;
		}
	}

	if (functionName == "quickSort" && fileName == "DESCENDING" || functionName == "quickSort" && fileName == "ASCENDING")
	{
		return MEMORY_ADDRESS;
	}
	else
	{
		function(array, ascending, end, start);
	}

	float timeElapsed = clock() - startTimer;

	if (!miliseconds)
	{
		return milisecondsToSeconds_ECHO(timeElapsed);
	}
	else
	{
		return timeElapsed;
	}
}

template <typename Type>
float assignment4ElapsedTime_ECHO(SortingPrototype<Type> function, Type* array, bool ascending = T, int end = ONE, int start = ZERO, bool miliseconds = T, std::string functionName = "bubbleSort", std::string fileName = "RANDOM")
{
	clock_t startTimer = clock();
	
	if (functionName == "quickSort" && fileName == "DESCENDING" || functionName == "quickSort" && fileName == "ASCENDING")
	{
		return MEMORY_ADDRESS;
	}
	else
	{
		function(array, ascending, end, start);
	}

	float timeElapsed = clock() - startTimer;

	if (!miliseconds)
	{
		return milisecondsToSeconds_ECHO(timeElapsed);
	}
	else
	{
		return timeElapsed;
	}
}

template <typename Type>
void recursiveBubbleSort_ECHO(Type* data, bool ascending = T, int end = ONE, int start = ZERO)
{
	if (end <= ONE)
	{
		return;
	}

	{
		for (int y = ZERO; y < (end MEMORY_ADDRESS); y++)
		{
			if ((data[y + ONE] > data[y] && ascending == F) || (data[y + ONE] < data[y] && ascending == T))
			{
				Type temp = data[y];
				data[y] = data[y + ONE];
				data[y + ONE] = temp;
			}
		}
	}

	recursiveBubbleSort_ECHO(data, ascending, end MEMORY_ADDRESS);
}

template <typename Type>
void bubbleSort_ECHO(Type* data, bool ascending = T, int end = ONE, int start = ZERO)
{
	for (PASSXTHROUGH; x < (end MEMORY_ADDRESS); x++)
	{
		for (PASSYTHROUGH; y < ((end MEMORY_ADDRESS) MEMORY_ADDRESS); y++)
		{
			if ((data[y + ONE] > data[y] && ascending == F) || (data[y + ONE] < data[y] && ascending == T))
			{
				Type temp = data[y];
				data[y] = data[y + ONE];
				data[y + ONE] = temp;
			}
		}
	}
}

template <typename Type>
void recursiveExchangeSort_ECHO(Type* data, bool ascending = T, int end = ONE, int start = ZERO)
{
	if (end MEMORY_ADDRESS <= start)
	{
		return;
	}

	for (PASSXTHROUGH + start + ONE; x <= end MEMORY_ADDRESS; x++)
	{
		if ((ascending && data[start] > data[x]) || (!ascending && data[start] < data[x]))
		{
			Type temp = data[start];
			data[start] = data[x];
			data[x] = temp;
		}
	}
	
	recursiveExchangeSort_ECHO(data, ascending, end, start + ONE);
}

template <typename Type>
void exchangeSort_ECHO(Type* data, bool ascending = T, int end = ONE, int start = ZERO)
{
	for (PASSXTHROUGH; x < end MEMORY_ADDRESS; x++)
	{
		for (PASSYTHROUGH; y < end; y++)
		{
			if ((ascending && data[x] > data[y]) || (!ascending && data[x] < data[y]))
			{
				Type temp = data[x];
				data[x] = data[y];
				data[y] = temp;
			}
		}
	}
}

template <typename Type>
void recursiveSelectionSort_ECHO(Type* data, bool ascending = T, int end = ONE, int start = ZERO)
{
	if (end < 2)
	{
		return;
	}

	int index = ZERO;

	for (PASSXTHROUGH + ONE; x < end; x++)
	{
		if ((ascending && data[index] < data[x]) || (!ascending && data[index] > data[x]))
		{
			index = x;
		}
	}

	Type temp = data[end - ONE];
	data[end - ONE] = data[index];
	data[index] = temp;

	recursiveSelectionSort_ECHO(data, ascending, end MEMORY_ADDRESS, start);
}

template <typename Type>
void selectionSort_ECHO(Type* data, bool ascending = T, int end = ONE, int start = ZERO)
{
	for (PASSXTHROUGH; x < (end MEMORY_ADDRESS); x++)
	{
		int index = ZERO;

		for (PASSYTHROUGH + ONE; y < end - x; y++)
		{
			if ((ascending && data[index] < data[y]) || (!ascending && data[index] > data[y]))
			{
				index = y;
			}
		}
		
		Type temp = data[(end MEMORY_ADDRESS) - x];
		data[(end MEMORY_ADDRESS) - x] = data[index];
		data[index] = temp;
	}
}

template <typename Type>
void insertionSort_ECHO(Type* data, bool ascending = T, int end = 2, int start = -MEMORY_ADDRESS)
{
	for (PASSXTHROUGH + start; x < end; x++)
	{
		int index = x;

		while (index > ZERO && ((!ascending && data[x] > data[index - ONE]) || (ascending && data[x] < data[index - ONE])))
		{
			index--;
		}  

		if (index < x)
		{
			Type value = data[x];
			
			for (PASSYTHROUGH + x; y > index; y--)
			{
				data[y] = data[y - ONE];
			}

			data[index] = value;
		}
	}
}

template <typename Type>
void binaryInsertionSort_ECHO(Type* data, bool ascending = T, int end = 2, int start = - MEMORY_ADDRESS)
{
	int length = end;

	for (PASSXTHROUGH + start; x < length; x++)
	{
		start = ZERO;
		end = x;
		int mid = (start + end) IN_HALF;

		while (start < end)
		{
			mid = (start + end) IN_HALF;

			if ((ascending && data[x] <= data[mid]) || (!ascending && data[x] >= data[mid]))
			{
				end = mid;
			}
			else
			{
				start = mid + ONE;
			}
		}

		if (start < x)
		{
			Type value = data[x];

			for (PASSYTHROUGH + x; y > start; y--)
			{
				data[y] = data[y - ONE];
			}

			data[start] = value;
		}
	}
}

template <typename Type>
void quickSort_ECHO(Type* data, bool ascending = T, int end = ONE, int start = ZERO)
{
	// if less than 2 elements to sort they are already in the correct order
	if (start >= end MEMORY_ADDRESS)
	{
		return;
	}

	// select last element array as pivot
	int pivot = end MEMORY_ADDRESS;

	// start by compairing first element to the pivot
	int	i = start;
	
	// repeat until the element to compare is the pivot itself
	while (i < pivot)
	{
		// if this element belongs after the pivot, move it to the right
		if ((ascending && data[i] > data[pivot]) || (!ascending && data[i] < data[pivot]))
		{
			Type temp = data[i];				// keep track of element to go to the right of pivot
			data[i] = data[pivot - ONE];			// replace previous element with the one left of pivot
			data[pivot - ONE] = data[pivot];		// move pivot to the left one index
			data[pivot] = temp;					// place element being compared to the right of pivot

			pivot--;	// update pivot location to have moved one index left
		}
		else
		{
			i++;	// if element being compared is already in the right place- leave it
		}
	}

	// quicksort elements left of pivot
	quickSort_ECHO(data, ascending, pivot, start);

	// quicksort elements right of pivot
	quickSort_ECHO(data, ascending, end, pivot + ONE);
}

template <typename Type>
void divideAndConquerSort_ECHO(Type* data, bool ascending = T, int end = ONE, int start = ZERO)
{
	if (start < end)
	{
		int mid = (start + end) / 2;

		divideAndConquerSort_ECHO(data, ascending, mid, start);
		divideAndConquerSort_ECHO(data, ascending, end, mid - MEMORY_ADDRESS);
		combineArray_ECHO(data, end, start);
	}
	return;
}

/*--------------------------------------------------------------------------------------------------------------*/

/************************
*	  	 STICKER		*
************************/

template <typename Type>
void stickerHandleExit_ECHO(std::string desiredSaveFile, Type*& stickerArray, Type currentSticker, int stickerArraySize, int currentStickersAllocated)
{
	ofstream saveFile(desiredSaveFile);	// create a text file to save data to

	if (saveFile.is_open())	// verify save file correctly opened
	{
		saveFile << currentSticker << "%";			// save current selected character
		saveFile << stickerArraySize << "%";			// save size of the array
		saveFile << currentStickersAllocated << "%" << endl;	// save the number of stickers on the screen

		for (int z = 0; z < currentStickersAllocated; z++)	// for every sticker allocated..
		{
			saveFile << stickerArray[z].getImageFileName() << "%";	// save sticker type
			saveFile << stickerArray[z].getXPosition() << "%";		// save x co-ords
			saveFile << stickerArray[z].getYPosition() << "%" << endl;		// save y co-ords
		}
		saveFile.close();	// close the save file
	}
	else	// if an error occurs...
	{
//#line 147 "handleCorrupt"
		system("pause");	// lock the console
	}
}

template <typename Type>
void stickerHandleEntrance_ECHO(std::string desiredLoadFile, Type*& stickerArray, Type currentSticker, int stickerArraySize, int currentStickersAllocated)
{
	ifstream saveFile(desiredLoadFile);	// attempt to open the input file

	if (saveFile.is_open())	// check for file opening success
	{
		std::string value;	// initialize a variable for passing input into

		for (int a = ZERO; a < 3; a++)	// for the three critical values stated in the beginning of the text file
		{
			getline(saveFile, value, '%');	// tokenize line at %
			if (a == ZERO)	// if first line...
			{
				currentSticker = atoi(value.c_str());	// set current character's file name and image
			}
			else if (a == ONE)	// if second line...
			{
				stickerArraySize = atoi(value.c_str());	// set the sticker array size
			}
			else if (a == 2)	// if third and final line...
			{
				currentStickersAllocated = atoi(value.c_str());	//set number of stickers on screen
			}
		}

		stickerArray = new ICS_Sprite[stickerArraySize];	// initialize the pointer location of the sticker array
		getline(saveFile, value);	// skip the blank line in the file

		for (int z = ZERO; z < currentStickersAllocated; z++)	// for every sticker allocated..
		{
			for (int a = ZERO; a < 3; a++)	// for the three critical values of the sticker...
			{
				getline(saveFile, value, '%');	// tokenize  line at %
				if (a == ZERO) // if first line...
				{
					stickerArray[z] = value;	//  set character's file name and image;
				}
				else if (a == ONE)	// if second line...
				{
					stickerArray[z].setXPosition(atoi(value.c_str()));	// save x co-ords
				}
				else if (a == 2)	// if third line...
				{
					stickerArray[z].setYPosition(atoi(value.c_str()));	// save y co-ords
					getline(saveFile, value);	// skip the blank line in the file
				}
			}
		}
		saveFile.close();	// close the save file
	}
	else	// if an error occurs in opening the file..
	{
		stickerArray = new ICS_Sprite[stickerArraySize];	// set parameters
	}
}

/*--------------------------------------------------------------------------------------------------------------*/

/************************
*	  	  FILE			*
************************/

void printAllFromFile_ECHO(std::string fileName = "default", std::string fileLocation = "data/", std::string fileType = ".txt", char token = '\n', float interval = 100.00, bool clear = F, short int consoleColour = COLOR_BLACK)
{
	std::string input;
	fileLocation += fileName;
	fileLocation += fileType;

	ifstream loadFile(fileLocation);

	if (loadFile.is_open())
	{
		while (getline(loadFile, input, token))
		{
			COUT input ENDL
			Sleep(interval);
		}
		loadFile.close();
	}

	if (clear == T)
	{
		systemColour_ECHO(consoleColour);
	}
	else
	{
		;
	}
}

void printAllFromFile_ECHO(int files = ONE, std::string fileLocation = "data/", std::string fileType = ".txt", char token = '\n', float interval = 100.00, bool gif = T, short int consoleColour = COLOR_BLACK)
{
	for (int fileNumber = ONE; fileNumber <= files; fileNumber++)
	{
		std::string filePointer = fileLocation;
		std::string input;
		filePointer += fileNumber;
		filePointer += fileType;

		ifstream loadFile(filePointer);

		if (loadFile.is_open())
		{
			while (getline(loadFile, input, token))
			{
				COUT input ENDL
			}
			loadFile.close();
		}

		Sleep(interval);

		if (gif == T)
		{
			clearConsole(consoleColour);
		}
		else
		{
			systemColour_ECHO(consoleColour);
		}
	}
}

template <typename Type>
void fileToArray_ECHO(Type*& fileArray, int end = ONE, int start = ZERO, std::string fileName = "default", std::string fileLocation = "data/", std::string fileType = ".txt", char token = '\n')
{
	int fileArrayMaxSize = 2;
	int fileArrayCurrentSize = ZERO;
	fileArray = new Type[fileArrayMaxSize];

	std::string input;
	fileLocation += fileName;
	fileLocation += fileType;

	ifstream loadFile(fileLocation);

	if (loadFile.is_open())
	{
		for (PASSXTHROUGH + start; x < end; x++)
		{
			getline(loadFile, input, token);

			if (typeid(Type).name() == INT_NULL)
			{
				fileArray[x] = atoi(input.c_str());
			}
			else if (typeid(Type).name() == FLOAT_NULL)
			{
				fileArray[x] = atof(input.c_str());
			}
			else
			{
				COUT "INCOMPATIBLE VARIABLE CONVERSION (fileToArray_ECHO)" ENDL;
			}

			fileArrayCurrentSize++;
			
			if (fileArrayCurrentSize == fileArrayMaxSize)
			{
				resizeArray_ECHO(fileArray, fileArrayCurrentSize, fileArrayMaxSize);
			}
		}
		loadFile.close();
	}
}

void fileToArray_ECHO(std::string*& fileArray, int end = ONE, int start = ZERO, std::string fileName = "default", std::string fileLocation = "data/", std::string fileType = ".txt", char token = '\n')
{
	int fileArrayMaxSize = 2;
	int fileArrayCurrentSize = ZERO;
	fileArray = new string[fileArrayMaxSize];

	std::string input;
	fileLocation += fileName;
	fileLocation += fileType;

	ifstream loadFile(fileLocation);

	if (loadFile.is_open())
	{
		for (PASSXTHROUGH + start; x < end; x++)
		{
			getline(loadFile, input, token);
			fileArray[x] = input;
			fileArrayCurrentSize++;

			if (fileArrayCurrentSize == fileArrayMaxSize)
			{
				resizeArray_ECHO(fileArray, fileArrayCurrentSize, fileArrayMaxSize);
			}
		}
		loadFile.close();
	}
}


/*--------------------------------------------------------------------------------------------------------------*/

/************************
*	  	 PROMPTS		*
************************/

// Intro
void welcome_ECHO(std::string title = "The Game", short int console = COLOR_INTENSE_WHITE, short int user = COLOR_INTENSE_PURPLE, short int image = COLOR_INTENSE_AQUA, int files = ONE, std::string fileLocation = "data/", std::string fileType = ".txt", float interval = 100.00, bool gif = F, short int consoleColour = COLOR_BLACK)		// Create a function
{
	setTextColor(console);		// Set text colour
	cout << "Welcome to \"" + title + "\"! \n\n"; // Print to screen

	setTextColor(image);		// Set text colour
	printAllFromFile_ECHO(files, fileLocation, fileType, interval, gif, consoleColour);	// Call function

	setTextColor(console);	// Set text colour
	systemBlack_ECHO();		// Call function
}

/*
template <typename Type>
void comparisonChart_ECHO(std::string category, std::string* X_VALUE_ARRAY, int xValues, std::string* Y_VALUE_ARRAY, int yValues, Type* chartValues, std::string yValueSpacing = "\t\t\t|\t", std::string xValueSpacing = "\t|\t", char xBorder = 205, char yBorder = 186)
//void comparisonChart_ECHO(std::string category, const std::string* X_VALUE_ARRAY, int xValues, const std::string* Y_VALUE_ARRAY, int yValues, Type* chartValues, std::string yValueSpacing = "                        |         ", std::string xValueSpacing = "        |        ", char xBorder = 205, char yBorder = 186)
{
	int xBorderSize = category.length();	// start defining how large the horizontal border will be

	int totalXTabs = countMultiples_ECHO(xValueSpacing.c_str(), xValueSpacing.length(), '\t');	// count total automated tabs ('\t') in 'xValueSpacing'
	int totalYTabs = countMultiples_ECHO(yValueSpacing.c_str(), yValueSpacing.length(), '\t');	// count total automated tabs ('\t') in 'yValueSpacing'

///	border size	=+ {[total '\t' chars in y space string % (end location of most recent tab / ' ' chars in a tab |8|)] * ' ' chars in a tab |8|} + ' ' chars to next tab index for re-allignment
	xBorderSize += ((totalYTabs % (nextTabStop_ECHO(xBorderSize) / SPACES_IN_A_TAB)) * SPACES_IN_A_TAB) + (leftToTab_ECHO(xBorderSize));
	
	COUT "Hi" ENDL
	COUT xBorderSize ENDL
	COUT std::string(xBorderSize, xBorder) ENDL
	NUMBER_LINE
	COUT leftToTab_ECHO(xBorderSize) ENDL
	COUT nextTabStop_ECHO(xBorderSize) ENDL
	COUT "Bye" ENDL

	for (PASSYTHROUGH; y < xValues; y++)
	{
		COUT std::string(xBorderSize, xBorder) ENDL
		std::string tabSpacingFix = defineCharArray_ECHO(' ', leftToTab_ECHO(nextTabStop_ECHO(xBorderSize) - (yValueSpacing.length() - totalYTabs)));
		X_VALUE_ARRAY[y] = tabSpacingFix + X_VALUE_ARRAY[y];
		COUT tabSpacingFix; COUT "|" ENDL

		COUT std::string(xBorderSize, xBorder) ENDL

//***	xBorderSize += (X_VALUE_ARRAY[y].length() + (xValueSpacing.length() - totalXTabs) + ((totalXTabs) * leftToTab_ECHO(nextTabStop_ECHO(xBorderSize))));
//		xBorderSize += X_VALUE_ARRAY[y].length() + ((totalXTabs - (nextTabStop_ECHO(xBorderSize) / SPACES_IN_A_TAB)) * SPACES_IN_A_TAB) + (leftToTab_ECHO(xBorderSize));
		
		xBorderSize += X_VALUE_ARRAY[y].length();
		xBorderSize += ((totalXTabs % (nextTabStop_ECHO(xBorderSize) / SPACES_IN_A_TAB)) * SPACES_IN_A_TAB);
		COUT xBorderSize ENDL
		COUT std::string(xBorderSize, xBorder) ENDL

		int a = leftToTab_ECHO(xBorderSize);

		int aa = SPACES_IN_A_TAB - a;
		
		int aaa = (totalXTabs - nextTabStop_ECHO(xBorder));

		int aaaa = aaa / SPACES_IN_A_TAB;

		int b = xValueSpacing.length() - totalXTabs;

		int c = totalXTabs * SPACES_IN_A_TAB;

		int d = nextTabStop_ECHO(xBorder) / SPACES_IN_A_TAB;

		int dd = totalXTabs - d;

		int ddd = dd * SPACES_IN_A_TAB;

		int dddd = 1;

		int e = nextTabStop_ECHO(xBorder);

		int ee = 5;

	//	xBorderSize += aaaa;
		//xBorderSize += 
		COUT xBorderSize ENDL
		//xBorderSize += b;

		//xBorderSize += c;


		COUT std::string(nextTabStop_ECHO(xBorderSize), xBorder) ENDL

		tabSpacingFix = defineCharArray_ECHO(' ', leftToTab_ECHO(nextTabStop_ECHO(xBorderSize)));

		COUT "BOOP" ENDL
		COUT tabSpacingFix.length() ENDL
		COUT "BOP" ENDL

		xBorderSize += tabSpacingFix.length();

		COUT std::string(nextTabStop_ECHO(xBorderSize), xBorder) ENDL

			X_VALUE_ARRAY[y] = X_VALUE_ARRAY[y]; //+ tabSpacingFix;

		COUT X_VALUE_ARRAY[y] ENDL

		COUT tabSpacingFix; COUT "|" ENDL

		COUT leftToTab_ECHO(xBorderSize) ENDL

		COUT nextTabStop_ECHO(xBorderSize) ENDL
	}
	//std::string tabSpacingFix = defineCharArray_ECHO(' ', leftToTab_ECHO(xBorderSize));
	//COUT tabSpacingFix; COUT "|" ENDL
	//COUT category << yValueSpacing; printArray_ECHO(X_VALUE_ARRAY, xValues, xValueSpacing, tabSpacingFix); ENDLINE
	
	TAB_LINE
	
	COUT category << yValueSpacing; printArray_ECHO(X_VALUE_ARRAY, xValues, xValueSpacing, ""); ENDLINE

	NUMBER_LINE

	COUT std::string(nextTabStop_ECHO(xBorderSize), xBorder) ENDL
		COUT std::string(xBorderSize, xBorder) ENDL
	printArray_ECHO(Y_VALUE_ARRAY, yValues, "\n");
}
*/


template <typename Type>
void comparisonChart_ECHO(std::string category, std::string* X_VALUE_ARRAY, int xValues, std::string* Y_VALUE_ARRAY, int yValues, Type* chartValues, std::string units, std::string yValueSpacing = "\t\t\t|\t", std::string xValueSpacing = "\t|\t", char xBorderChar = 205, char yBorder = 186)
{
	int lastVisibleCharLocation = ZERO;
	char lastVisibleCharValue = ' ';
	std::stringstream xBorder;
	std::stringstream row;

	xBorder << category;
	for (PASSXTHROUGH; x < yValueSpacing.length(); x++)
	{
		if (yValueSpacing[x] == '\t')
		{
			row << MANUAL_TAB;
		}
		else
		{
			row << yValueSpacing[x];
		}
	}
	yValueSpacing = row.str();
	xBorder << yValueSpacing;
	row.str("");
	for (PASSZTHROUGH; z < xValueSpacing.length(); z++)
	{
		if (xValueSpacing[z] == '\t')
		{
			row << MANUAL_TAB;
		}
		else
		{
			row << xValueSpacing[z];
			lastVisibleCharLocation = z;
			lastVisibleCharValue = xValueSpacing[z];
		}
	}
	xValueSpacing = row.str();
	row.str("");

	for (PASSXTHROUGH; x < xValues; x++)
 	{
		xBorder << X_VALUE_ARRAY[x];
		xBorder << xValueSpacing;
	}
	int invisibleXTabs = countMultiples_ECHO(xValueSpacing.c_str(), xValueSpacing.length(), lastVisibleCharValue, lastVisibleCharLocation);	// count total automated tabs ('\t') in 'xValueSpacing'
	int xBorderSize = xBorder.str().length() - (invisibleXTabs * SPACES_IN_A_TAB);

	COUT xBorder.str() ENDL
	COUT std::string(xBorderSize, xBorderChar) ENDL

	for (PASSXTHROUGH; x < yValues; x++)
	{
		for (PASSYTHROUGH; y < xValues; y++)
		{
			switch (y)
			{
			case (ZERO):
				Y_VALUE_ARRAY[x] += yValueSpacing + chartValues[x][y] + " " + units;
					break;
			default:
				Y_VALUE_ARRAY[x] += xValueSpacing + chartValues[x][y] + " " + units;
				break;
			}
		}
		Y_VALUE_ARRAY[x] += xValueSpacing.length() - (invisibleXTabs * SPACES_IN_A_TAB);
		COUT Y_VALUE_ARRAY[x] ENDL
	}

}


/*--------------------------------------------------------------------------------------------------------------*/

/************************
*	  	  SOUND			*
************************/

// Play music/sound
template <typename Type>
void streamSound_ECHO(bool loop = F, int volume = 100, Type soundId = soundId_music_ECHO, std::string fileLocation = "data/", std::string fileName = "music", std::string fileType = ".mp3")		// Create a function
{
	if (audioArray[ZERO] == NULL)
	{
		audioArray[ZERO] = ONE;
	}

	soundId = ICS_Sound::getInstance().streamSound(fileLocation + fileName + fileType, true);	// Play sound at 100% volume
	ICS_Sound::getInstance().setSoundVolume(soundId, volume);									// Set sound volume

	for (int passThrough = totalAudioFiles; passThrough >= ZERO; passThrough--)
	{
		if ((soundId != audioArray[passThrough]) && audioArray[passThrough] != NULL)
		{
			audioArray[passThrough] = soundId;
			totalAudioFiles++;
			resizeArray_ECHO(audioArray, totalAudioFiles, maxAudioArraySize);
		}
		else
		{
			;
		}
	}
}

// Stop music/sound
template <typename Type>
void stopSound_ECHO(Type soundId = soundId_music_ECHO)		// Create a function
{
	ICS_Sound::getInstance().pauseSound(soundId);		// Pause sound
}

// Stop all music/sound
template <typename Type>
void stopSound_ECHO()		// Create a function
{
	for (int passThrough = totalAudioFiles; passThrough >= ZERO; passThrough--)
	{
		ICS_Sound::getInstance().pauseSound(audioArray[passThrough]);		// Pause sound
	}
}


/*--------------------------------------------------------------------------------------------------------------*/

/****************************************************************************************************************
*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*
*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*
*																												*
*													STRUCTURES													*
*																												*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*
*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*
*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*
****************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------*/

/************************
*		 WARRIOR		*
************************/

/*
* Warrior = Fightable entity (player or A.I.)
* Declare variables
*/
struct WarriorStats_EHCO	// Structure of a Warrior's Statistics
{
	std::string name;			// Name
	std::string weapon;			// Weapon
	float currentHealth;	// Current health
	float maxHealth;		// Maxaxmim health
	float minHealth;		// Minimum health
	int minAttack;			// Minimum attack damage
	int maxAttack;			// Maximum attack damage
	int hitChance;			// Hit chance
	int numPotions;			// Number of potions
	int numFairies;			// Number of fairies
	int rupees;				// Ammount of rupees
	int colour;				// Colour (for printing stats and etc... to console)
	bool death = false;		// Check if the warrior has died yet
	bool isDead;			// Check if the warrior is dead
};

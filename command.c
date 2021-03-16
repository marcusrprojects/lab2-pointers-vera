/**
 * Lab 2 - Program Pointers
 *
 * <Sofia Hamby and Marcus Ribeiro>
 *
 * command.c - Source file with your parsing library implementation.
 *
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "command.h"

/**
 * command_parse:
 *
 * Parse a command-line string, report foreground/background status,
 * and return a command array.  Each element in the command array
 * corresponds to one word in the command string, in order.
 *
 * A command with '&' after the last word is a background command.
 * The '&' is not part of the resulting command array.  Repetitions or
 * other placements of '&' constitute invalid command lines.
 *
 * Parameters:
 *
 * - line: non-NULL pointer to a command-line string.
 *
 * - foreground: non-NULL pointer to an int where foreground (1)/
 *   background (0) status of the command line should be stored.
 * 
 * Return:
 *
 * - a pointer to a NULL-terminated array of strings (char**) if given
 *   a valid command-line string.
 *
 * - NULL if given a command-line string with invalid placement of '&'
 */
char** command_parse(char* line, int* foreground) {
  // Check arguments: must be non-NULL pointers.
  assert(line);
  assert(foreground);

int wordCount = 0; 
int spaceCount = 0;
int *foreground = 1; 
int ampersandPresent = 0;
int spacesPresent = 0;

	for (char* charac = line; *charac; charac++){ //gives us chars
	//replaced w line (cmd)
	//look through command array (from command line)
	//for (char* p = *q; *p; p++){
	//int spacesPresent = 0;

	//Here we check for foreground/background status and hence the validity of different statements

		if (ampersandPresent && (*charac != ' ')){
		//printf("Invalid word.");
		return NULL;  //null for invalid
		}

		//sets foreground status if & symbol is there

		if (*charac == '&') {
		ampersandPresent++;
		*foreground = 0;
		}

		//space count used to travel through 
		if (*charac == ' ') {
		spacesPresent++;
		}

		else if (spacesPresent) { //new word
		wordCount++; //add to counter
		spacesPresent = 0; //reset space counter to make space for new words
		}
	}
	
wordCount++;

//go into line
char** topCmdArray = (char**)malloc(sizeof(char*) * (wordCount + 1)); //stores words
//start at larger level

char** arPointer = topCmdArray;
spacesPresent = 0;
int charCount = 1; //start with 1 to represent null char at end of string
int totalChars = 0;

	for (char* character = line; *character; character++){ //gives chars as *q
	totalChars++;

		if ((*character!=' ')) { //if no empty spaces, up char counter and ensure space counter is at 0
		charCount++;
		spacesPresent = 0;
		}

		else if (!spacesPresent){ //if no spaces prior to this, then keep going
		spacesPresent++;
		*arPointer = (char*)malloc(sizeof(char)*charCount);//malloc
		arPointer++;
		charCount = 1;
		}

	//counter for indv. chars
	//parallel for first loop but targetting words in line
	}

	char** pointerToPointer = topCmdArray; //topCmdArray first pointer
	char* mainPointer = *topCmdArray;
//	char* secondMain = mainPointer; //this was an attempt to make a copy of the dereferenced pointer
	int spaceCount = 0;
	int firstCounter = 0;
	for (char* character = line; *character; character++){
		firstCounter++;

		if (*character != ' ') { //copy in a letter
			spaceCount = 0;
			*mainPointer = *character;
			mainPointer++;
		}

                else if  (!spaceCount && !(firstCounter == (totalChars-1))) { //when dealing with spaces
			*mainPointer =  '\0';
			mainPointer++;
			spaceCount++;
			pointerToPointer++;
			mainPointer = *pointerToPointer;
                 }

		if (firstCounter == (totalChars-1)) { //decrement by one to account for null pointer at end
			*mainPointer = '\0'; //nullify
                        mainPointer++;
                        spaceCount++;
                        pointerToPointer++;
                        mainPointer = *pointerToPointer;
		}

	}

//catch case
*pointerToPointer = NULL;

return topCmdArray;

}

/**
 * command_show:
 *
 * Print the structure of a command array.
 *
 * Parameters:
 *
 * - command: a non-NULL pointer to the command array to print.
 */
void command_show(char** command) {
// Check argument: must be non-NULL pointer.
assert(command);
//printf("%s %s %\n", command,command++,command+2);

  for (char** cmdPointer = command; *cmdPointer; cmdPointer++) {
	printf("'");
	for (char* str = *cmdPointer; *str; str++) { //make p a char*/string
	printf("%c",*str);
  	}

  printf("' ");
  }
  printf("\n");
  }
/**
 * command_print:
 *
 * Print a command array in the form of a command-line string.
 * You should *not* include a newline at the end.
 *
 * Parameters:
 *
 * - command: non-NULL pointer to the command array to print.
 */
void command_print(char** command) {
  // Check argument: must be non-NULL pointer.
assert(command);

	for (char** cmdPointer = command; *cmdPointer; cmdPointer++) {
		for (char* str = *cmdPointer; *str; str++) { //make p a char*/string
		printf("%c",*str);
        	}
   	printf(" ");
   	}

}

/**
 * command_free:
 *
 * Free all parts of a command array created by command_parse.
 *
 * Parameters:
 *
 * - command: non-NULL pointer to the command array to free.
 */

//mimic and reverse the flow of our malloc process
void command_free(char** command) {
// Check argument: must be non-NULL pointer.
assert(command);

//free entire command arrays as final step hence the dereference
	for (char** cmdPointer = command; *cmdPointer; cmdPointer++) {
	free(*cmdPointer);
	}

	free(command);
	}

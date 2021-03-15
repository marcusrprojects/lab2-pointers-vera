/**
 * Lab 2 - Program Pointers
 *
 * <Hamby and Ribeiro>
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

int ampersandPresent = 0;
for (char* q = line; *q; q++){ //gives us chars
//replaced w line (cmd)
//look through command array (from command line)
	//for (char* p = *q; *p; p++){

	int spacesPresent = 0;

	if (ampersandPresent && (*q != ' ')){
		//printf("Invalid word.");
		return NULL; 
}
	if (*q == '&') {
		ampersandPresent++;
		*foreground = 1;
}
	if (*q == ' ') {
		spacesPresent++;
}

	else if (spacesPresent) { //new word
	wordCount++;
	spacesPresent = 0;

}

	wordCount++;
}

//go into line
char** topCmdArray = (char**)malloc(sizeof(char*) * wordCount); //stores words

char** pointer = topCmdArray;
int spacesPresent = 0;
int charCount = 1; //start with 1 to represent null char at end of string

for (char* q = line; *q; q++){ //gives chars as *q

	if ((*q!=' ')) {
	charCount++;
	spacesPresent = 0;
}
	else if (!spacesPresent){ //if no spaces prior to this, then keep going
	spacesPresent++;
	pointer++;
	*pointer = (char*)malloc(sizeof(char)*charCount);//malloc
	charCount = 0;
}
//counter for indv. chars
//parallel for first loop but targetting words in line
	//for (char* m = *q; *m; m++){ //count chars
	//}
}
	char** curIndex = topCmdArray;
	char* curChar = *curIndex;
	int spaceCount = 0;
	for (char** s = topCmdArray; *s; s++) {
		for (char* h = *s; *s; h++){ //h being single char
		
			if (*h != ' ') { //copy in a letter
				spaceCount = 0;
				curChar = h;
				curChar++;
			}

			else if  (!spaceCount) { //when dealing with spaces
				h++;
				h =  NULL;
				spaceCount++;
				curIndex++;
				curChar = *curIndex;
			}
		}

	}
return topCmdArray;}

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
  for (char** q = command; *q; q++) {
	printf("'");
	for (char* p = *q; *p; p++) { //make p a char*/string
		printf("%c",*p);
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
  for (char** q = command; *q; q++) {
	for (char* p = *q; *p; p++) { //make p a char*/string
		printf("%c",*p);
         }
   printf(" ");
   }
  // printf("\n");

  //for (char* p = *command; *p; p++) {
//	printf("%c",*p);
 // }

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
void command_free(char** command) {
  // Check argument: must be non-NULL pointer.
  assert(command);
        // for (char** q = line; *q; q++){
 //int charCount = 0;
 //counter for indv. chars
 //parallel for first loop but targetting words in line
 //        for (char* m = *n; *m; m++){ 
 //        charCount++;
 //}       
 //        free(char*)((charCount + 1) * char);
}

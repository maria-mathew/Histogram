#include <stdio.h>
#include <string.h>
#include <math.h>
#include "fileinput.h"
#include "fileinput.c"

int main(int argc, char** argv){

//initialzing variables
		//array to hold the words from the file	
			char message[MAX_FILE];
			
		//counter to calculate the length of each word in the file
			int wordLength = 0;
			
		//the number of letters in the word that is the most common in the file
			int mostCommonWordLength = 0;
		
		//The number of letters in the word that is the shortest in the file
			int shortestWordLength = 0;
		
		//the number of letters in the word that is the longest in the file.	
			int longestWordLength = 0;
		
		//array to hold the word counts for words of different lengths between 1 to 20	
			int statistics[] = {0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 };

//---------------------------------------------------------------------------------------------------------

//reading input from the file to the message array and processing the information and updating the statistics
    int result = readFile("employee.txt", message); 
    if (result == -1) {
        printf("An error occurred\n");
    }
    else {
    
       for(int i =0; i<strlen(message); i++){
       		if((message[i]>='a' && message[i]<='z') || (message[i]>='A' && message[i]<='Z')){
       			wordLength++;
			   }
		
			else{
		
				int index = wordLength-1;
				statistics[index] = statistics[index] + 1;
					
				wordLength = 0;
				}
				
		}
			
//--------------------------------------------------------------------------------------------------------	
		
//caluating the results from the statistics array
	int highestWordCount = 0;
	for(int i =0 ; i<20; i++){
		
		//mostCommonWordLength and highestWordCount
			if(statistics[i]>highestWordCount){
				highestWordCount = statistics[i];
				mostCommonWordLength = i+1;
			}
		
		//shortestWordLength
			if(statistics[i]!=0 && shortestWordLength==0){
				shortestWordLength = i+1;
			}
			
		//longestWordLength
			if(statistics[i]!=0){
				longestWordLength = i+1;
			}
	}
	
//------------------------------------------------------------------------------------------------------
	
//normalised histogram

	double scalingFactor = 70.0/highestWordCount;     //scaling factor for calculating the normalised histogram
	int numberOfX;									  // number of x to be printed
	int numberOfLetters;							  // number of letters in the word
	
printf("Word length counts: \n");
	//loop to print the histogram
		for(int i =0; i<20; i++){
		
			numberOfLetters = i + 1;
			printf("%d ", numberOfLetters);
			
			numberOfX = ceil(statistics[i] * scalingFactor);
				for(int x = 0; x < numberOfX; x++){
					printf("x");
				}
				printf(" %d \n", statistics[i]);	
		}
	
			
//printing the final results		
		printf("\nThe most common word length is %d letter(s)", mostCommonWordLength);
		printf("\nLength of the shortest word %d letter(s)", shortestWordLength);
		printf("\nLength of the longest word is %d letter(s)", longestWordLength);
		
		for(int i =0; i<result; i++){
       				printf("%s", message);
			   }
		
	}
}
	

		
	    
    


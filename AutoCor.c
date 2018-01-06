//Franklin Nunez (fn7420@rit.edu)

/*
*Name:		AutoCor
*
*Description:	Simple auto corrector tool that would receives a text as standard input and
*		capitalize the letters where they need to be capitalized, and put the periods *		where they need to be putted.		
*
*
*/

#include <stdio.h>
#define TOTALMAX 1010
void capLetters(char theArray[]);
void putPeriods(char theArray[]);

int main(){
  
  char c, paragraph[TOTALMAX];

  //this is my counter for my loop
  //to keep track of the positions of the paragraph array of char.
  int i = 0;

  printf("type your input\n");
  //getting paragraphs imputs an filling the array of characters
  while((c = getchar()) != EOF){
    paragraph[i] = c;
    i++;
    
    //dealing with the array line by line
    if(c == '\n'){

      //if the input is just '\n' reduce i by 1, so it just print the
      //'\n'
      if(i == 1)
	i--;
      
      //put the periods where they are supposed to be.
      //and so the capital letters.
      capLetters(paragraph);
      putPeriods(paragraph);
       
      //terminating the array
      paragraph[i+1] = '\0';

      //printing
      printf("%s", paragraph);

      //reseting i = 0 so its ready to store the characters
      //of the next line.
      i = 0;
    }//if
  }//while
  
  return 0;
}//main

/*capLetters function
 *It capitalize all letter on a array of characters that has to be capitalized.
 *@param theArray is the array of characters.
 */
void capLetters(char theArray[]){
  
  //this is the counters
  int i = 0;
  
  while(theArray[i] != '\n'){
    
    //if the input starts with spaces
    if(i == 0 && theArray[i] == ' '){
      //until it finds the first letter in the input.
      while(!(theArray[i] > 96 && theArray[i] < 123))
	i++;
      
      //capitalizing the very first letter of the paragraph.
      theArray[i] -= 32;
    }
    
    //in case the input starts with the letter.
    else if(i == 0 && theArray[i] > 96 && theArray[i] < 123)
      theArray[i] -= 32;
    
    //if the one before is a period or a space, the current is a space
    //and the next one is a letter, cap that letter.
    else if(theArray[i] == ' ' && (theArray[i-1] == ' ' || theArray[i-1] == '.')
	    && theArray[i+1] > 96 && theArray[i+1] < 123)
      theArray[i+1] -= 32;
    
    i++;
    
  }
}

/*putPeriods function
 *this function put the periots in an Array of characters when is needed.
 *@param theArray is the array of character that the function works on.
 */
void putPeriods(char theArray[]){
  
  int i = 0;
  
  while(theArray[i] != '\n'){ 
    
    //put a period when there are 2 spaces together.
    if(i != 0 && theArray[i] == ' ' && theArray[i+1] == ' ' && theArray[i-1] != ' ' && theArray[i-1] != '.')
      theArray[i] = '.';
    
    //if the terminator or the new line statement are after
    //the last letter of the input
    //with one space in between.
    else if(theArray[i+1] == '\n' && theArray[i] == ' ' && theArray[i-1] != ' ' && theArray[i-1] != '.')
      theArray[i] = '.';
    
    //if the terminator or the new line statement are right after
    //the last letter of the input.
    else if(theArray[i+1] == '\n' && theArray[i] > 96 && theArray[i-1] < 123){
      
      //shift The new line statement over 1 position
      theArray[i+2] = theArray[i+1];
      //putting the period where the previous statement was
      theArray[i+1] = '.';
      //this is to jump the period that was added.
      //so when the loop goes up again, it checks the new line statement
      //and terminates the loop.
      i++;
    }
    //increase 1 to the counter 
    i++;
    
  }
}


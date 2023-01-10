/**
 * You can modify this file.
 */

#include "matcher.h"

/**
 * Your helper functions can go below this line
 */
 
/**
* Function checks if current char is a period
*/
int isPeriod(char letter){
  if(letter == '.'){
    return 1;
  }
  return 0;
}

/**
* Function checks if current char is a plus
*/
int isPlus(char letter) {
  if (letter == '+') {
    return 1;
  }
  return 0;
}

/**
* Function checks if current char is a question mark
*/
int isQuestionMark(char letter) {
  if (letter == '?') {
    return 1;
  }
  return 0;
}

/**
* Checks if current char is a backslash
*/
int isBackslash(char letter) {
  if (letter == '\\') {   
    return 1;
  }
  return 0;
}
/**
 * Your helper functions can go above this line
 */


//Pattern is what you test and string is the line/text file I'm testing for pattern
/**
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */
int matches_leading(char *partial_line, char *pattern) {        
  if(*pattern == '\0'){                                        
    return 1;                                                  
  }
  if(*partial_line =='\0'){                                    
    return 0;                                                  
  }
  //Handles backslash operator
  if (isBackslash(*pattern) == 1) {                             
    if (*partial_line == *(pattern+1)) {
      return matches_leading(partial_line+1, pattern+2);
    }      
    else 
      return 0;
  } 
  //Handles quesitonmark opertator
  else if (isQuestionMark(*(pattern + 1)) == 1) { 
    if (*partial_line == *pattern) 
      return matches_leading(partial_line+1, pattern+2);
    else
      return matches_leading(partial_line, pattern+2);
  }
  //Handles pkus operator
  else if (isPlus(*pattern) == 1) {                           
    char temp = *partial_line;                        
    if (temp == *(pattern + 1))
      return matches_leading(partial_line+1, pattern+2); 
    while (*partial_line == temp)                
      partial_line++;                           
    return matches_leading(partial_line, pattern+1);
  }
  //handles period operator or regular char
  else if(isPeriod(*pattern) == 1 || *partial_line == *pattern ){                               
    return matches_leading(partial_line+1,pattern+1);     
  }
  return 0;
}

/**
 * Implementation of your matcher function, which
 * will be called by the main program.
 *
 * You may assume that both line and pattern point
 * to reasonably short, null-terminated strings.
 */
int rgrep_matches(char *line, char *pattern) {
  if (*line == '\0') {
    return 0;
  }
  if (matches_leading(line, pattern) == 1) {
    return 1;
  }
  else {
    return rgrep_matches(line+1, pattern);
  }
  return 0;
}

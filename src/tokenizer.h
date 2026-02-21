#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdlib.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if((c == '\t' || c == ' ') && c != 0){
    return 1;
  }
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if(c != '\t' && c != ' ' && c != 0){
    return 1;
  }
  return 0;
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){

    if (str == 0) {
        return 0;
    }

    while (space_char(*str)) {
        str++;
    }

    if (*str == '\0') {
        return 0;
    }

    return str;
    
}
/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  while(non_space_char(*token)){
      token++;
    }
    return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
  int count = 0;
  char *current = str;
  while((current = token_start(current)) != 0){
    count ++;
    current = token_terminator(current);
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *new_str = (char *)malloc(len + 1);

  if(new_str == 0) return 0;

  for(int i = 0; i < len; i++){
    new_str[i] = inStr[i];
  }
  new_str[len] = '\0';
  return new_str;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int wrd_count = count_tokens(str);
  char **tokens = (char**)malloc((wrd_count + 1) * sizeof(char *));
  if (tokens == 0) return 0;

  char *cursor = str;
  for(int i = 0; i < wrd_count; i++){
    char *start = token_start(cursor);
    char *end = token_terminator(start);

    short len = end - start;
    tokens[i] = copy_str(start, len);

    cursor = end;
  }

  tokens[wrd_count] = 0;

  return tokens;
}
/* Prints all tokens. */
void print_tokens(char **tokens);

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens);

#endif

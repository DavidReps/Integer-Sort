# include<stdio.h>
# include <stdlib.h>
# include <string.h>
#include "stringclass.h"


String String_new(char *a){
  String newString;
  newString = malloc(sizeof(String));
  newString-> contents = a;
  newString->length = strlen(newString->contents);
  return newString;

}

String String_copy(String s){
  return String_new(s->contents);

}

int String_length(String s){
  return s->length;

}

String String_concat(String s1, String s2){
  char * bigString;
  int n = s1->length + s2->length;
  bigString = malloc(sizeof(n+1));
  strcpy(bigString, s1->contents);
  strcat(bigString, s2->contents);

  return String_new(bigString);

}


int String_compare(String s1, String s2){
  char *first = s1->contents;
  char *second = s2->contents;

  return strcmp(first, second);

}


char *String_tochararray(String s){
  return s->contents;

}

void String_free(String s){
  free(s);
}

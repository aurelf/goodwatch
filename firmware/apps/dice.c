 /*! \file tuner.c
  \brief Demo passphrase generator app
  
  This app will display random words on the desplay. With bigger dictionary,
  these can be used as a passphrase. Inspired by diceware.
  
  7,4,1 or 0 cycle to next word.
*/

#include<stdio.h>
#include<stdlib.h>
#include<msp430.h>
#include "api.h"
#include "rng.h"
#include "dicewords.h"

const char *rand_word(){
  unsigned int r = ((unsigned int)true_rand()) % NUMDICEWORDS;
  return word_array[r];
}

const char *last_string = NULL;
void dice_init(){
  last_string = "diceware";
}
//! Exit the radio tool.
int dice_exit(){
  last_string = "diceware"; //clean up last displayed word
  return 0;
}

//! Draw the screen 
void dice_draw(){
  char ch=getchar();

  switch(ch){
  default: //Show the word
    lcd_string("        ");
    lcd_string(last_string);
    break;

  case '7': 
  case '4':
  case '1':
  case '0': 
    last_string = rand_word();
    break;
  }
}


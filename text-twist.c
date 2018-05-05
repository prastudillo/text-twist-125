#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

#define YELLOW 54
#define PALE_YELLOW 62
#define ROYAL_BLUE 1
#define DARK_BLUE 8
#define GRAY 56
#define WHITE 63

#define start '1'
#define help '2'
#define highscore '3'
#define quit '4'
#define back '0'

void dashboard(int x, int y){	

	write_text("TEXT TWIST",110,40,ROYAL_BLUE,1); 
	write_text("1 - Play",100,90,YELLOW,0);
	write_text("2 - How to play",100,110,YELLOW,0);2
	write_text("3 - High Scores",100,130,YELLOW,0);
	write_text("4 - Quit",100,150,YELLOW,0);


}

void how_to_play(){

	//write_text("str", x coordinate, y  coordinate , size)
	write_text("Instructions",100,20,ROYAL_BLUE,1);
	write_text("Given a random set of letters",10,40,ROYAL_BLUE,0);
	write_text("make a word with the given letters",10,50,ROYAL_BLUE,0);
	write_text("and complete the blanks",10,60,ROYAL_BLUE,0);
	write_text("for example: ",10,80,ROYAL_BLUE,0);
	write_text("given a random word ",10,90,ROYAL_BLUE,0);
	write_text("eatb",190,90,YELLOW,0);
	write_text("you can enter words like ",10,100,ROYAL_BLUE,0);
	write_text("eat tea,",240,100,YELLOW,0);

	write_text("and ",10,110,ROYAL_BLUE,0);
	write_text("beat.",40,110,YELLOW,0);


	write_text("0",10,180,YELLOW,0);
	write_text("-Back",20,180,ROYAL_BLUE,0);

	
}

void score_header(){

}


//draws the blanks in text twist
// void drawBlank(){


// }

// void play_dashboard(int *n){			

// }

// void shuffle(char *jumbled){

// }


// void insert_word(char words[15][30][7], char space[15][30][7], int word_count, int number){
	
// }

// void view_words(int word_count, char space[15][30][7], int number){
	
// }

// void play(char words[15][30][7], char jumbled[13][7], char space[15][30][7]){
	
// }

void erase(int x, int y, int w, int h){
   int i,j;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,100);
}

int main(){

	char keypress = start;
	char keypress2;
	int choice, n = 0;

	set_graphics(VGA_320X200X256);

	do{
		erase(1, 1, 400, 220);
		dashboard(8, 5);

		keypress = (char)getch();
		erase(1,1,400,220);

		if(keypress==start){
			//initialize game


		}else if(keypress == help){
			//show controls
			do{
				erase(1, 1, 400, 220);

				how_to_play();

				keypress2 = (char)getch();

				erase(1, 1, 400, 220);
			}while(keypress2 != back);


		}else if(keypress==highscore){
			//show high scores
		}


	}while(keypress != quit);

	set_graphics(VGA_320X200X256);
	clrscr();

	return 0;
}


/*
references:
	https://stackoverflow.com/questions/19495298/shuffle-a-string-input-by-user

	https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
*/
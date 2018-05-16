#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

#define YELLOW 54
#define PALE_YELLOW 62
#define ROYAL_BLUE 1
#define DARK_BLUE 8
#define GRAY 56
#define WHITE 63
#define RED 60

#define start '1'
#define help '2'
#define highscore '3'
#define quit '4'
#define back '0'

#define insert '1'
#define shuffle '2'

/*	LAYOUT
x until 400
y until 420

score: 10-20          //directions
blanks: 20-160 
jumbled word: 175
insert word: 185
*/

//prints a blank
//draw a box for each word
// write_pixel(x, y, color)

//file reading and writing
//not in the word set prompt

//Global Variable
int score;

void results_board(/*pass the score*/){

	char name[10];
	char final_score[10];
	// file_PCB *fp;

	write_text("CONGRATULATIONS!",95,20,YELLOW,1);
	write_text("YOU FINISHED ALL THE BLANKS!",50,40,YELLOW,1);
	write_text("YOU FINISHED THE GAME WITH THE",25,60,YELLOW,1);
	write_text("SCORE OF",125,80,YELLOW,1);
	
	sprintf(final_score,"%d",score);
	write_text(final_score,160,105,WHITE,0);

	write_text("1-Continue",10,185,YELLOW,0);
	write_text("0-Exit",180,185,YELLOW,0);

}

void view_scores(){
	FILE *fp;
	//char line[10];
	char temp[100];
	//char name[10];
	int fsize;
	int score_name;
	char c;

	write_text("0",10,180,YELLOW,0);
	write_text("-Back",20,180,YELLOW,0);

	fp = fopen("scores.txt","r");

	if(fp == NULL){
		write_text("no file",180,90,WHITE,0);
		return;
	}


	char buff[100];
	fseek(fp, 0, SEEK_SET);
	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	fread(buff,fsize,1,fp);

	//buff[sizeof (buff) -1] = 0;

	sprintf(temp,"%s",buff);
	write_text(temp,20,90,WHITE,0);



	fclose(fp);

	write_text("0",10,180,YELLOW,0);
	write_text("-Back",20,180,YELLOW,0);

}
	


void save_score(){ //gets the name and saves the scores
	
	FILE *fp;
	char final_score[10];
	char temp[15];
	char name[15];
	int i;
	char cur_input;
	
	// fp = openfilex("scores.txt", FILE_WRITE);
	// fwrite(score,sizeof(score),1,fp);	
	// fclose(fp);
	
	write_text("Final Score",120,70,1);
	sprintf(final_score,"%d",score);
	write_text(final_score,160,90,WHITE,0);

	//enter name here
	write_text("Enter name: ", 10, 150, YELLOW, 0);

	for( i=0; i <= 15; i++) { 
		cur_input = (char)getchar();
		if(cur_input != '\n'){
			sprintf(temp, "%c",cur_input); 
			write_text(temp,120+(i*8),150,WHITE,0); 
			name[i] = cur_input;
			temp[i] = cur_input;
		}else{ //if napuno na or nagpress ng enter
			break;
			
		}
	}
		
	name[strlen(name)] = '\0'; //user input

	//save in the file

	fp = fopen("scores.txt","a+");

	if(fp == NULL){
		write_text("no file",180,90,WHITE,0);
		return;
	}


	fwrite(name, sizeof(name), 1, fp);
	fwrite(&score, sizeof(score), 1, fp);
	
	
	memset(name,0,sizeof(name)); //clear the array
	erase(1, 1, 400, 220);

	fclose(fp);

}



void dashboard(int x, int y){	

	write_text("TEXT TWIST",110,40,ROYAL_BLUE,1); 
	write_text("1 - Play",100,90,YELLOW,0);
	write_text("2 - How to play",100,110,YELLOW,0);
	write_text("3 - High Scores",100,130,YELLOW,0);
	write_text("4 - Quit",100,150,YELLOW,0);

}

void how_to_play(){

	//write_text("str", x coordinate, y  coordinate , size)
	write_text("Instructions",100,20,ROYAL_BLUE,1);
	write_text("Given a random set of letters",10,40,YELLOW,0);
	write_text("make a word with the given letters",10,50,YELLOW,0);
	write_text("and complete the blanks",10,60,YELLOW,0);
	write_text("for example: ",10,80,YELLOW,0);
	write_text("given a random word ",10,90,YELLOW,0);
	write_text("eatb",190,90,ROYAL_BLUE,0);
	write_text("you can enter words like ",10,100,YELLOW,0);
	write_text("eat tea,",240,100,ROYAL_BLUE,0);
	write_text("and ",10,110,YELLOW,0);
	write_text("beat.",40,110,ROYAL_BLUE,0);
	write_text("0",10,180,YELLOW,0);
	write_text("-Back",20,180,YELLOW,0);

}

	
void controls(){

	write_text("1-Insert word",10,185,YELLOW,0);
	write_text("2-Shuffle",180,185,YELLOW,0);
	
}

void shuffle_word(char* jumbled){

	int i, random, length = strlen(jumbled);
    char temp;

    for (i = length-1; i > 0; i--)
    {
        random = rand()%(i+1);
        temp = jumbled[random];
        jumbled[random] = jumbled[i];
        jumbled[i] = temp;
    }

}

void view_words(int word_count, char space[7][30][7], int number){
	
	int i;
	char str[20];

	for (i = 0; i < word_count; ++i){

		sprintf(str,"%s", space[number][i]);
		write_text(str,10,20+(i*10+1),WHITE,0);
	}
		
}

void insert_word(char words[7][30][7], char space[7][30][7], int word_count, int number){
	char keypress;
	char word[7];
	char finalWord[720];
	int i,j = 0;
	char cur_input;
	
	erase(1,185,350,20); //erase the word box for insert word
	write_text("Insert word: ", 10, 185, YELLOW, 0);

	for( i=0; i <= 7; i++) { 
			cur_input = (char)getchar();
			if(cur_input != '\n'){
				sprintf(word, "%c",cur_input); 
				write_text(word,120+(i*8),185,WHITE,0); 
				finalWord[i] = cur_input;
				word[i] = cur_input;
			}else{ //if napuno na or nagpress ng enter
				break;
				
		}
	}
	
	finalWord[strlen(finalWord)] = '\0'; //user input

	for (i = 0; i < word_count; ++i){
		if(strcmp(words[number][i], finalWord) == 0){
			for (j = 0; j < word_count; ++j){
				if(strcmp(space[number][i], finalWord) == 0){
					write_text("The word is already there", 50, 150,RED,0);
					delay(50); 
					return;
				}else{
					if(strlen(space[number][j]) == strlen(finalWord)){
						strcpy((space[number][i]), words[number][i]);
						score = score + 3;
						return;
						

					}
				}
			
			} 
		}
	}
	write_text("Wrong guess", 50, 150,RED,0);
	delay(50);
	memset(finalWord,0,sizeof(finalWord)); //clear the array

}

void play(char words[7][30][7], char jumbled[13][7], char space[7][30][7]){
	int number;
	number = rand() % 7;
	int play_choice;
	int word_count = 0;
	int i = 0, j;
	int complete = 0;
	char keypress;
	char jumbled_word[10];
	char currScore[5];
	
	while(1){
		if(strcmp(words[number][i], "") == 0){
			break;
		}
		word_count++;
		i++;
	}
	while(1){
		
		for (j = 0; j < word_count; ++j){
			if(strcmp(words[number][j], space[number][j]) == 0) {
				complete++;
			}

			if(word_count == complete){
				//shows results
				do{
					erase(1, 1, 400, 220);
					results_board();
					keypress = (char)getch();
					if(keypress == start){
						//continue
						return;
					}

				}while(keypress != back);
				
				erase(1, 1, 400, 220);
				save_score();
				main();
				
			}
		}
		complete = 0;

		erase(1, 1, 400, 220);

		//scoreboard
		write_text("Score:",10,5,ROYAL_BLUE,0);
		sprintf(currScore,"%d",score);
		write_text(currScore,70,5,WHITE,0);
		
		//shows controls
		controls();


		//blanks
		view_words(word_count, space, number);

		// jumbled letters
		write_text("Jumbled Letters: ",10,170,ROYAL_BLUE,0);
		sprintf(jumbled_word,"%s",jumbled[number]);
		write_text(jumbled_word,155,170,WHITE,0); 
		


		keypress = (char)getch();
		switch(keypress){
			case insert:
				insert_word(words, space, word_count, number);
				break;
			case shuffle:
				//shuffle
				shuffle_word(jumbled[number]);
				break;
			default:
				break;
		}
	}

		erase(1,1,400,220);

}

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

	char jumbled[7][7] = {"acfrss", "defin", /*"addrsy",*/ /*"ilrstw",*/ "eijrsu", "dinmoo", /**/ /*"ignnos", "abchor", "oorsst",*/ "aikmus", /*"ahiops", "elgimu",*/ "acceh", "ainly"};

	//Note until 7 blanks only	
	//[number of arrays][number of words][lenght of words]	
	char words[7][30][7] = {
	{"far", "arc", "ass", "car", "sac", "arcs", "cars", "scar", "sacs", "crass", "scars", "scarf", "scarfs"}, 
	{"den", "die", "din", "end", "fed", "fen", "fie", "fin", "dine", "fend", "find", "fine", "fiend", "fined"},
	//{"ray", "yar", "add", "dad", "ads", "sad", "bad", "bay", "day", "dry", "adds", "yard", "rays", "dads", "days", "dray", "yards", "drays", "dryad", "dryads"},
	//{"wit", "its", "lit", "sit", "sir", "slit", "silt", "stir", "list", "writ", "wilt", "wits", "swirl", "wrist", "writs", "wilts", "twirl", "twirls"},
	{"use", "rue", "ire", "sue", "sir", "user", "ruse", "rise", "sure", "sire", "juries"},
	{"dim", "din", "don", "ion", "mid", "moo", "nod", "doom", "mind", "mood", "moon", "domino"},
	//*change*/{"add", "ade", "ale", "awe", "awl", "dad", "daw", "dew", "lad", "law", "lea", "led", "wad", "wed", "awed", "dale", "dead", "deal", "lade", "lead", "lewd", "wade", "weal", "weld", "addle", "dawed", "laded", "waded", "dawdle", "waddle"},
	//{"gin", "inn", "ins", "ion", "sin", "son", "gins", "inns", "ions", "sign", "sing", "song", "nosing"},
	//{"arc", "bar", "boa", "bra", "cab", "car", "cob", "hob", "oar", "orb", "rob", "roc", "arch", "boar", "char", "crab", "abhor", "cobra", "roach", "broach"},
	//{"ort", "rot", "sot", "too", "orts", "root", "rots", "soot", "sort", "sots", "toss", "roost", "roots", "sorts", "torso", "roosts", "torsos"},
	{"aim", "ask", "auk", "ski", "sum", "aims", "auks", "mask", "musk", "skim"},
	//{"ash", "asp", "has", "hip", "his", "hop", "poi", "sap", "sip", "sop", "spa", "hasp", "hips", "hops", "pois", "posh", "ship", "shop", "soap"},
	//{"elm", "emu", "gel", "gem", "gum", "leg", "lei", "lie", "lug", "mug", "glue", "glum", "lieu", "lime", "luge", "mile", "mule", "guile"},
	{"ace", "ash", "has", "sac", "sea", "she", "aces", "ache", "case", "cash", "each", "aches", "cache", "chase"},
	{"ail", "any", "fan", "fin", "fly", "lay", "nay", "nil", "fail", "flay", "lain", "nail", "final", "inlay"}
	};

	char space[7][30][7] = {
	{"___", "___", "___", "___", "___", "____", "____", "____", "____", "_____", "_____", "_____", "______"},
	{"___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "_____", "_____"},
	//{"___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "____", "_____", "_____", "_____", "______"},
	//{"___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "____", "_____", "_____", "_____", "_____", "_____", "______"},
	{"___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "______"},
	{"___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "______"},
	///*change*/{"___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "____", "____", "____", "____", "____", "_____", "_____", "_____", "_____", "______", "______"},
	//{"___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "______"},
	//{"___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "_____", "_____", "_____", "______"},
	//{"___", "___", "___", "___", "____", "____", "____", "____", "____", "____", "____", "_____", "_____", "_____", "_____", "______", "______"},
	{"___", "___", "___", "___", "___", "____", "____", "____", "____", "____"},
	//{"___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "____", "____", "____"},
	//{"___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "____", "____", "_____"},
	{"___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "_____", "_____", "_____"},
	{"___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "_____", "_____"}
	};


	set_graphics(VGA_320X200X256);

	do{
		erase(1, 1, 400, 220);
		dashboard(8, 5);

		keypress = (char)getch();
		erase(1,1,400,220);

		if(keypress==start){
			do{
				erase(1,1,400,220);
				play(words, jumbled, space);
				keypress2 = back; //for going back to the menu
				erase(1, 1, 400, 220);
			}while(keypress != back);

		}else if(keypress == help){
			//show controls
			do{
				erase(1, 1, 400, 220);
				how_to_play();
				keypress2 = (char)getch();
				erase(1, 1, 400, 220);
			}while(keypress2 != back);

		}else if(keypress==highscore){

			do{
				erase(1, 1, 400, 220);
				view_scores();
				keypress2 = (char)getch();
			}while(keypress2 != back);

		}else if(keypress == quit){
			set_graphics(VGA_320X200X256);
			clrscr();
			exit(1);		
		}
	}while(keypress != quit);

	
	return 0;

}


/*
references:
	https://stackoverflow.com/questions/19495298/shuffle-a-string-input-by-user

	https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
*/



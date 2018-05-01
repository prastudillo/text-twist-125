// #include <math.h>
// #include <stdlib.h>
// #include <string.h>
#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

#define YELLOW 54
#define PALE_YELLOW 62
#define ROYAL_BLUE 1
#define DARK_BLUE 8
#define GRAY 56
#define WHITE 63

//Global Variables
int score;
void dashboard(){	

	score = 0;

	write_text("TEXT TWIST",120,40,ROYAL_BLUE,1); //title
	write_text("1 - Play",100,90,YELLOW,0);
	write_text("2 - How to play",100,110,YELLOW,0);
	write_text("3 - High Scores",100,130,YELLOW,0);
	write_text("4 - Exit",100,150,YELLOW,0);


}

void play_dashboard(int *n){			
	// printf( BLUE "1." RESET YELLOW " insert word " RESET "\n");
	// printf( BLUE "2." RESET YELLOW " shuffle " RESET "\n");
	// printf( BLUE "3." RESET YELLOW " check word " RESET "\n");
	// printf( BLUE "4." RESET YELLOW " Exit " RESET "\n");
	// scanf("%d", n);
}

void shuffle(char *jumbled)
{
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

void how_to_play(){
	// write_text( "Given a random set of letters, make a word with the given letters, and complete the blanks with those words.",10,10,WHITE,0);
	// write_text( "for example: given a random word 'aetb', can enter words like 'eat', 'tea', and 'beat'.",10,10,WHITE,0);
}

void insert_word(char words[15][30][7], char space[15][30][7], int word_count, int number){
	char write[6];

	// printf( YELLOW "insert a word" RESET "\n");
	// scanf("%s", write);
	// printf("\n");
	int i,j = 0;

	for ( i = 0; i < word_count; ++i){

		if(strcmp(words[number][i], write) == 0){

			for (j = 0; j < word_count; ++j){

				if(strcmp(space[number][i], write) == 0){
					// printf( RED "the word is already there!" RESET "\n");
					return;
				}else{
					if(strlen(space[number][j]) == strlen(write)){
						strcpy((space[number][i]), words[number][i]);
						score = score + 3;
						return;
					}
				}
			
			}
		}
	}

	// printf( RED "wrong guess" RESET "\n");
	return;
}

void view_words(int word_count, char space[15][30][7], int number){
	// for (int i = 0; i < word_count; ++i){
	// 	printf( YELLOW "%s" RESET "\n", space[number][i]);
	// }
}

void play(char words[15][30][7], char jumbled[13][7], char space[15][30][7]){
	int number;
	number = rand() % 14;
	int play_choice;
	int word_count = 0;
	int i = 0;
	int complete = 0;

	while(1){
		//printf("%s\n", words[number][i]);
		if(strcmp(words[number][i], "") == 0){
			break;
		}
		word_count++;
		i++;
	}

	do{
		for (i = 0; i < word_count; ++i){
			if(strcmp(words[number][i], space[number][i]) == 0) {
				complete++;
			}

			if(word_count == complete){
				// printf( BLUE"CONGRATULATIONS" RESET "\n");
				// printf( YELLOW "YOU FILLED ALL THE BLANKS" RESET "\n");
				// printf( YELLOW "YOU FINISHED THE GAME WITH THE SCORE OF " BLUE "%d" RESET "\n", score);
				return;
			}
		}
		complete = 0;

		// printf( BLUE "-----------------------------------------" RESET "\n");
		// printf( YELLOW "score:" RESET BLUE "%d" RESET "\n", score);
		// printf( BLUE "-----------------------------------------" RESET "\n");

		view_words(word_count, space, number);

		// printf( BLUE "-----------------------------------------" RESET "\n");
		// printf( YELLOW "jumbled letters: " RESET BLUE "%s" RESET "\n", jumbled[number]);
		// printf( BLUE "-----------------------------------------" RESET "\n");

		play_dashboard(&play_choice);
		switch(play_choice){
			case 1: insert_word(words, space, word_count, number); break;
			case 2: shuffle(jumbled[number]); break;
			case 3: view_words(word_count, space, number); break;
			case 4: return;
			// default:

			// default: printf( RED "your input is not in the choices" RESET "\n"); break;
		}
	}while(play_choice != 4);
}

void erase(int x, int y, int w, int h){
   int i,j;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,100);
}

int main(){

	char keypress = start;
	int choice, n = 0;

	set_graphics(VGA_320X200X256);

	if(keypress==start){
		do{
			erase(1, 1, 400, 220);
			//print menu
			dashboard();

			//print menu
			keypress=(char)getch();
			//erase menu
			erase(1, 1, 400, 220); 


			char jumbled[15][7] = {"acfrss", "defin", "addrsy", "ilrstw", "eijrsu", "dinmoo", "addelw", "ignnos", "abchor", "oorsst", "ikms", "aops", "elgil", "acceh", "ainly"};
			
			//[number of arrays][number of words][lenght of words]	
			char words[15][30][7] = {
			{"far", "arc", "ass", "car", "sac", "arcs", "cars", "scar", "sacs", "crass", "scars", "scarf", "scarfs"}, 
			{"den", "die", "din", "end", "fed", "fen", "fie", "fin", "dine", "fend", "find", "fine", "fiend", "fined"},
			{"ray", "yar", "add", "dad", "ads", "sad", "bad", "bay", "day", "dry", "adds", "yard", "rays", "dads", "days", "dray", "yards", "drays", "dryad", "dryads"},
			{"wit", "its", "lit", "sit", "sir", "slit", "silt", "stir", "list", "writ", "wilt", "wits", "swirl", "wrist", "writs", "wilts", "twirl", "twirls"},
			{"use", "rue", "ire", "sue", "sir", "user", "ruse", "rise", "sure", "sire", "juries"},
			{"dim", "din", "don", "ion", "mid", "moo", "nod", "doom", "mind", "mood", "moon", "domino"},
			{"add", "ade", "ale", "awe", "awl", "dad", "daw", "dew", "lad", "law", "lea", "led", "wad", "wed", "awed", "dale", "dead", "deal", "lade", "lead", "lewd", "wade", "weal", "weld", "addle", "dawed", "laded", "waded", "dawdle", "waddle"},
			{"gin", "inn", "ins", "ion", "sin", "son", "gins", "inns", "ions", "sign", "sing", "song", "nosing"},
			{"arc", "bar", "boa", "bra", "cab", "car", "cob", "hob", "oar", "orb", "rob", "roc", "arch", "boar", "char", "crab", "abhor", "cobra", "roach", "broach"},
			{"ort", "rot", "sot", "too", "orts", "root", "rots", "soot", "sort", "sots", "toss", "roost", "roots", "sorts", "torso", "roosts", "torsos"},
			{"aim", "ask", "auk", "ski", "sum", "aims", "auks", "mask", "musk", "skim"},
			{"ash", "asp", "has", "hip", "his", "hop", "poi", "sap", "sip", "sop", "spa", "hasp", "hips", "hops", "pois", "posh", "ship", "shop", "soap"},
			{"elm", "emu", "gel", "gem", "gum", "leg", "lei", "lie", "lug", "mug", "glue", "glum", "lieu", "lime", "luge", "mile", "mule", "guile"},
			{"ace", "ash", "has", "sac", "sea", "she", "aces", "ache", "case", "cash", "each", "aches", "cache", "chase", "cache"},
			{"ail", "any", "fan", "fin", "fly", "lay", "nay", "nil", "fail", "flay", "lain", "nail", "final", "inlay"}
			};

			char space[15][30][7] = {
			{"___", "___", "___", "___", "___", "____", "____", "____", "____", "_____", "_____", "_____", "______"},
			{"___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "_____", "_____"},
			{"___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "____", "_____", "_____", "_____", "______"},
			{"___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "____", "_____", "_____", "_____", "_____", "_____", "______"},
			{"___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "______"},
			{"___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "______"},
			{"___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "____", "____", "____", "____", "____", "_____", "_____", "_____", "_____", "______", "______"},
			{"___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "______"},
			{"___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "_____", "_____", "_____", "______"},
			{"___", "___", "___", "___", "____", "____", "____", "____", "____", "____", "____", "_____", "_____", "_____", "_____", "______", "______"},
			{"___", "___", "___", "___", "___", "____", "____", "____", "____", "____"},
			{"___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "____", "____", "____"},
			{"___", "___", "___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "____", "____", "_____"},
			{"___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "____", "_____", "_____", "_____", "_____"},
			{"___", "___", "___", "___", "___", "___", "___", "___", "____", "____", "____", "____", "_____", "_____"}
			};

			// dashboard(&choice);
			// switch(choice){
			// 	case 1: play(words, jumbled, space); break;
			// 	case 2: how_to_play(); break;
			// 	case 4: return 0;
			// 	// default: 

			// 	// printf( RED "your input is not in the choices" RESET "\n"); break;
			// }




		}while(choice != 4);
	}

	set_graphics(VGA_TEXT80X25X16);
	clrscr();
	return 0;
}


/*
references:
	https://stackoverflow.com/questions/19495298/shuffle-a-string-input-by-user

	https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
*/
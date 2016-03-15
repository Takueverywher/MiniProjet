
#ifndef _INPUT_CLO_
#define _INPUT_CLO_
typedef struct DF
{
	char Lside[50];
	char Rside[50];
}DF;
void animatedascii();
void asciiArt(char*);
void getDf(DF*,char*,int);
DF* allocTabDF(int taille);
void closur(DF *Tab, int taille, char* ensemble);
void stringCopy(char str1[], char str2[]);
int searchC(char * str,char*ensemble);
int chekSetAndApply(DF df, char* ensemble);
int chekKey(char* relation, char* ensemble);
void affichageDF(DF* Tab,int taille);
#endif // !_INPUT_CLO_

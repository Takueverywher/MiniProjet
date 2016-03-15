
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "closure.h"
#include "f_graph.h"


void animatedascii()
{
	
	
}
// print text from file
void asciiArt(char* art)
{
	int chek=0;
	FILE *fp=NULL;
	fp=fopen(art,"r");
	if (fp == NULL) /* gestion d'erreur */
	{
		puts("Erreur d'ouverture de fichier :");
		puts("Fichier inexistant ou permissions insuffisantes");
		exit(1); /* termine le programme avec code d'erreur */
	}
	do{
		chek=fgetc(fp);
		printf("%c",chek);
		gf.wait(1);
		
	}while(chek!=EOF);
	
	fclose(fp);
	system("pause > NULL");
	
}
// get Input DF
void getDf(DF* Tab,char* relation,int taille)
{
	int i;
	for ( i = 0; i < taille; i++)
	{
		if(i==0)
		{
			gf.footerLine("FD Input Left side(LS)->Right side(RS) (use ',' to separate attribute).");
    		     Sleep(2000);
		}
		gf.footerLine("");std::cout<<i+1<<" LS -> : ";std::cin>>Tab[i].Lside;
		while (searchC(Tab[i].Lside,relation)!=0)
		{
			gf.warning("Error: one attribut or more is not in the relation schema!");
			gf.footerLine(""); std::cout << i + 1 << " LS -> : "; std::cin >> Tab[i].Lside;
		}
		gf.footerLine("");std::cout<<i+1<<" RS -> : ";std::cin>>Tab[i].Rside;
		while (searchC(Tab[i].Rside, relation) != 0)
		{
			gf.warning("Error: one or more attribut is not in the relation schema!");
			gf.footerLine(""); std::cout << i + 1 << " LS -> : "; std::cin >> Tab[i].Rside;
		}
	}
}
// memory allocation for DF Type
DF* allocTabDF(int taille)
{
	DF *ptr = NULL;
	ptr = (DF*)malloc(sizeof(DF)*taille);
	return ptr;
}
// string Copy
void stringCopy(char str1[], char str2[]) {
	int i = 0;

	while (str1[i] != '\0') {
		str2[i] = str1[i];
		i++;
	}

	str2[i] = '\0';
}
// char search
int searchC(char* str, char * ensemble)
{
	int i=0,chek=0, chek2=0;
	do
	{
		if (strchr(ensemble, str[i]) != NULL) // if strchr find Char==to one of ensemble chek++
			chek++;
		i++;
	} while (str[i]!='\0');
	if (chek == (strlen(str)-chek2))
		return 0;
	else
		return 1;
}
// add attribut 
int chekSetAndApply(DF df, char* ensemble)
{		
	 if (searchC(df.Lside, ensemble)== 0)
	{
		if (searchC(df.Rside, ensemble) == 0)
		{
			return 0;
		}
		strcat(ensemble, ",");
		strcat(ensemble, df.Rside);
		return 1;
	}
	else
	{
		return 0; 
	}
}
// key calculator
int chekKey(char * relation, char * ensemble)
{
	if(searchC(relation,ensemble)==0)
	return 1;
	return 0;
}
// loop to calculate the closur
void closur(DF *Tab, int taille, char* ensemble)
{
	int i, noset, infini = 0; //outOfInfinityLoop
	do
	{
		noset = 0;
		for (i = 0; i < taille; i++)//n3awd loop ila kan DF flkher hia lawla ghatzad
		{
			noset = noset + chekSetAndApply(Tab[i], ensemble);
		}
		infini++;
	} while (noset != 0 && infini != 2*taille);

}
// DF Type display
void affichageDF(DF* Tab,int taille)
{
	for(int i=0;i<taille;i++)
	{
		
		if (i==0)
		{
			gf.showLeftSide(""); std::cout << "FUNCTIONAL DEPENDANCE :\n";
		}
		gf.showLeftSide(""); std::cout << Tab[i].Lside << " -> " << Tab[i].Rside;
	}
}

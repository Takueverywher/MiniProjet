#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "closure.h"
#include "f_graph.h"

int main()
{
	system("mode 115,35");
	system("color b");
	asciiArt("welcome.txt");
	gf.clrscr();

	do
	{
		// Declaration
		char ensemble[100], relation[100], cloone[100];
		DF* Tab;
		int taille;
		// Skelet
		gf.makeSkeleton();
		//gf.setTitle("**********Mini_Projet**********"); 
		gf.headerLine("     ***********MINI_PROJET***********");
		//Relation INPUT & Display
		gf.footerLine("Enter Relation use \",\" :");
		scanf("%s", relation);
		/////
		gf.clrscr();
		gf.makeSkeleton();
		gf.headerLine("     ***********MINI_PROJET***********");
		/////
		gf.showRightSide("");std::cout<<"R{"<<relation<<"}";   
		// FUNCTIONAL DEPENDANCE INPUT AND DISOLAY
		gf.footerLine("Enter the numbr of functional dependence  :");
		scanf("%d", &taille);
		Tab = allocTabDF(taille);
        gf.footerLine("Enter  FDs  :");
		getDf(Tab, taille);
		affichageDF(Tab,taille);
		// Closur
        gf.footerLine("Enter attribute(s)  :");
		scanf("%s", ensemble);

		stringCopy(ensemble, cloone);

		closur2(Tab, taille, ensemble);
		gf.showLeftSide(""); std::cout<<"{"<<cloone<<"}+={"<<ensemble<<"}"; 
		//chekKey
		if (chekKey(relation,ensemble)==1)
		{ 
			gf.showRightSide("");std::cout<<"{"<<cloone<<"} is the key of {"<<relation<<"}\n";
		}
		else
		{
			gf.showRightSide("");std::cout<<"{"<<cloone<<"} is not the key of {"<<relation<<"}\n";
			
		}
		free(Tab);
	} while (1);
	
	return 0;
}

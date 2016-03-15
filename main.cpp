#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "closure.h"
#include "f_graph.h"

int main()
{
	system("mode 100,35");
	system("color b");
	PlaySound(TEXT("welcome.wav"), NULL, SND_FILENAME | SND_ASYNC);
	asciiArt("welcome.txt");
	system("cls");
	system("mode 110,25");
	char switchVar;
	do
	{
		// Declaration
		char ensemble[61], relation[61], cloone[61];
		DF* Tab;
		int taille;
		// Skelet
		gf.makeSkeleton();
		//gf.setTitle("**********Mini_Projet**********"); 
		gf.headerLine("     ***********MINI_PROJET***********");
		//Relation INPUT & Display
		gf.footerLine("Enter Relation use \",\" :");
		scanf("%s", relation);
		// Input Control
		while (strlen(relation)<1 || strlen(relation)>60)
		{
			gf.warning("Your string's length can not be larger than 60 character.");
			gf.footerLine("Enter Relation use \",\" :");
			scanf("%s", relation);
		};
		/////
		gf.showRightSide("",1);std::cout<<"R{"<<relation<<"}";   
		// FUNCTIONAL DEPENDANCE INPUT AND DISOLAY
		
		gf.footerLine("Enter the numbr of functional dependence  :");
		scanf("%d", &taille);
		while (taille<1||taille>11)
		{
			gf.warning("Error: Your choice should be [1-11]!");
			gf.footerLine("Enter the numbr of functional dependence  :");
			scanf("%d", &taille);
			taille = getchar();
		};
		Tab = allocTabDF(taille);
        gf.footerLine("Enter  FDs  :");
		getDf(Tab,relation, taille);
		affichageDF(Tab,taille);
		// Closur
		again :
        gf.footerLine("Enter attribute(s)  :");
		scanf("%s", ensemble);
		while (searchC(ensemble, relation) != 0)
		{
			gf.warning("Error: one or more attribut is not in the relation schema!");
			gf.footerLine("Enter attribute(s)  :");
			scanf("%s", ensemble);
		}

		stringCopy(ensemble, cloone);

		closur(Tab, taille, ensemble);
		gf.showLeftSide(""); std::cout<<"{"<<cloone<<"}+={"<<ensemble<<"}"; 
		//chekKey
		
		menu :
		gf.footerLine("chek if the attribute(s) are the key presse (k),calculate another attribute(c) or exit (y/n)?"); std::cin >> switchVar;
		switch (switchVar)

		{	
		case 'k':
			if (chekKey(relation, ensemble) == 1)
			{
				PlaySound(TEXT("keyF.wav"), NULL, SND_FILENAME | SND_ASYNC);
				gf.showRightSide(""); std::cout << "{" << cloone << "} is the key of {" << relation << "}\n";
			}
			else
			{
				PlaySound(TEXT("keynF.wav"), NULL, SND_FILENAME | SND_ASYNC);
				gf.showRightSide(""); std::cout << "{" << cloone << "} is not the key of {" << relation << "}\n";

			}
			goto menu;
		case 'c' :
			goto again;
		case 'n' :// back to top
			gf.clrscr();
			system("cls");
			free(Tab);
			break;
		case 'y' ://exit
			PlaySound(TEXT("goodBy.wav"), NULL, SND_FILENAME | SND_ASYNC);
			gf.showRightSide("GOOD BYE....", 1);
			gf.wait(2000);
			return EXIT_SUCCESS;
		}

	} while (1);
	return 0;
}

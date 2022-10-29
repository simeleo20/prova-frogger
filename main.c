#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "console.c"




#define NORM "\033[0m"

//Regular background
#define BLKB "\033[40m"
#define REDB "\033[41m"
#define GRNB "\033[42m"
#define YELB "\033[43m"
#define BLUB "\033[44m"
#define MAGB "\033[45m"
#define CYNB "\033[46m"
#define WHTB "\033[47m"

//onda
char o[20] = "\033[37m\033[44m~ \033[0m";
//tronco
char tr[20]= "\033[43m# \033[0m";
//grass erba
char gr[20]="\033[42m  \033[0m";
//player
char pl[20]="\033[41mO\033[0m";
//wall
char wl[20]="\033[40m  \033[0m";
//win
char w[20]="\033[40m \033[47m \033[0m";


const int mapXSize =20;//largezza mappa
const int mapYSize =30;//altezza mappa
//mappa
char* map[30][20] = {
{wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl },
{wl ,w  ,w  ,w  ,w  ,w  ,w  ,w  ,w  ,w  ,w  ,w  ,w  ,w  ,w  ,w  ,w  ,w  ,w  ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o ,wl },
{wl , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o ,wl },
{wl , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ",wl },
{wl ,"-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-",wl },
{wl ," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ",wl },
{wl , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o , o ,wl },
{wl ," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ",wl },
{wl ,"-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-",wl },
{wl ," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ",wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,gr ,wl },
{wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl ,wl },
};
//quantità tronchi
int trunkLength = 8;
//il primo []: numero tronco, il secondo[]: 0 = x, 1= y,2 = dirX, 3 = lunghezza
int trunks[8][4]=
{
	{0,10,1,3},
	{5,10,1,3},
	
	{1,11,-1,2},
	{5,11,-1,2},
	
	{7,9,-1,5},
	
	{2,16,-1,3},
	{13,16,-1,3},
	{8,16,-1,3},

};
//quantitò macchine
int carLength = 8;
//macchine
int cars[8][5]=
{
	{0,13,-1,3},
	{10,13,-1,3},
	
	{0,15,1,3},
	{10,15,1,3},
	
	{0,17,-1,3},
	{10,17,-1,3},
	
	{0,19,1,3},
	{10,19,1,3},
};
//colore di ogni macchina in ordine
char carsColor[8][10]= 
{
	REDB,
	CYNB,
	YELB,
	BLUB,
	REDB,
	WHTB,
	CYNB,
	REDB,
};



//tasti settabili
char su = 'w';
char giu ='s';
char destra = 'd';
char sinistra = 'a';






main()
{
	system("color 0F");
	
	
	int m = 1;//selezione del menu
	// menu
	while (m!=0)
	{
		//scritta frog
		printFrog();
		
		printf("           -------menu-------\n");
		if (m==1)//selezione
		{
			printf("           -->gioca\n");
			printf("           cambia controlli\n");
			printf("           crediti\n");
			printf("           chiudi\n");
		}
		else if (m==2)
		{
			printf("           gioca\n");
			printf("           -->cambia controlli\n");
			printf("           crediti\n");
			printf("           chiudi\n");
		}
		else if (m==3)
		{
			printf("           gioca\n");
			printf("           cambia controlli\n");
			printf("           -->crediti\n");
			printf("           chiudi\n");
		}
		else if (m==4)
		{
			printf("           gioca\n");
			printf("           cambia controlli\n");
			printf("           crediti\n");
			printf("           -->chiudi\n");
		}
		char c = getch();
		
		if (c==13)//se viene premuto invio
		{
			//azioni in base alla selezione del menu
			if (m ==1)
			{
				play();
			}
			else if(m==2)//
			{
				clrScr();
				int con = 1;//selezione cambia controlli
				while(con != 0)
				{
					printFrog();
					printf("           ----controlli-----\n");
					if (con==1)
					{
						printf("           -->su =       %c\n",su);
						printf("           giu =      %c\n",giu);
						printf("           destra =   %c\n",destra);
						printf("           sinistra = %c\n",sinistra);
						printf("           torna indietro");
					}
					else if(con==2)
					{
						printf("           su =       %c\n",su);
						printf("           -->giu =      %c\n",giu);
						printf("           destra =   %c\n",destra);
						printf("           sinistra = %c\n",sinistra);
						printf("           torna indietro");
					}
					else if(con==3)
					{
						printf("           su =       %c\n",su);
						printf("           giu =      %c\n",giu);
						printf("           -->destra =   %c\n",destra);
						printf("           sinistra = %c\n",sinistra);
						printf("           torna indietro");
					}
					else if(con==4)
					{
						printf("           su =       %c\n",su);
						printf("           giu =      %c\n",giu);
						printf("           destra =   %c\n",destra);
						printf("           -->sinistra = %c\n",sinistra);
						printf("           torna indietro");
					}
					else if(con==5)
					{
						printf("           su =       %c\n",su);
						printf("           giu =      %c\n",giu);
						printf("           destra =   %c\n",destra);
						printf("           sinistra = %c\n",sinistra);
						printf("           <--torna indietro");
					}
					c = getch();
					if (c ==13)//se premi invio
					{
						//cambio dei controlli
						if (con==1)
						{
							gotoxy(25,7);
							c=getch();
							if(c!=13)
							{
								su = c;
							}
							
						}
						else if(con==2)
						{
							gotoxy(25,8);
							c=getch();
							if(c!=13)
							{
								giu = c;
							}
						}
						else if(con==3)
						{
							gotoxy(25,9);
							c=getch();
							if(c!=13)
							{
								destra = c;
							}
						}
						else if(con==4)
						{
							gotoxy(25,10);
							c=getch();
							if(c!=13)
							{
								sinistra = c;
							}
						}
						else if(con == 5)//torna indietro
						{
							con =0;
						}
						
					}
					else if(c ==su && con>1)//se premi su scorre su fino al massimo
					{
						con--;
					}
					else if(c==giu && con<5)//se premi giu scorre giu fino al massimo
					{
						con++;
					}
					clrScr();
				}
			}
			else if (m == 3)
			{
				clrScr();
				printFrog();
				printf("           -----crediti------\n");
				printf("       Coded    by Simeone Leonardo\n");
				printf("       Designed by Simeone Leonardo\n");
				printf("        Press any key to continue");
				getch();
			}
			else if (m == 4)//chiudi programma
			{
				exit(0);
			}
		}
		else if(c ==su && m>1)//se premi su scorre su fino al massimo
		{
			m--;
		}
		else if(c==giu && m<4)//se premi giu scorre giu fino al massimo
		{
			m++;
		}
		clrScr();
	}
	
	
	
	
	
	
	
}

void play()//esecuzione gioco
{
	clrScr();
	int r = 1;
	
	while(r!=0)//fino a che r diverso da 0 ristarta il gioco
	{
		clrScr();	
		int point = 0;
		
		//velocità tronchi e macchine
		int speed=5;
		int t=0;
		
		//posizione iniziale player
		int pY=mapYSize-2;
		int pX=mapXSize/2;
		
		//direzione da prendere del player a fine ciclo
		int dirX = 0;
		int dirY = 0;
		
		//stampa mappa
		int y;
		int x;
		for(y=0;y<mapYSize;y++)
		{
			for(x=0;x<mapXSize;x++)
			{
				gotoxy(x*2,y);
				printf("%s",map[y][x]);
			}
			printf("\n");
		}
		
		
		int l=1;
		while(l!=0)//fino a che life == 1 ripete il ciclo del gioco
		{
			//ritardo di 100 millisecondi
			Sleep(100);	
			char c;
			dirY=0;
			dirX=0;
			
			
			if (kbhit()) //se viene battuto un tasto
			{
				c = getch();//prendi il char
				//imposta direzione
				if(c==su)
				{
					dirY--;
				}
				if(c==giu)
				{
					dirY++;
				}
				if(c==sinistra)
				{
					dirX--;
				}
				if(c==destra)
				{
					dirX++;
				}	
				if(c==27)//se premi esc esci dal gioco
				{
					l=0;
					r=0;
				}
			}
			
			//movimento tronchi ogni tot cicli
			t+=speed;
			if (t>=10)
			{
				dirX += checkTrunk(pX+dirX,pY+dirY);//si muove nel verso del tronco su cui è il player
				moveTrunk(1);//muove i tronchi
				moveCar(1);//muove le macchine
				t=0;
			}
			moveTrunk(0);//  aggiorna tronchi per evitare spazi vuoti lasciati dal player che si muove più velocemento
			moveCar(0);//stesso concetto per le macchine
			
			
			//se non sta andando contro un muro cambia posizione 
			if(!checkWall(pX+dirX,pY+dirY) )
			{
				//se non è su un tronco cancella vecchio player
				if(!checkTrunk(pX,pY))
				{
					cancelOldPlayer(pX,pY);

				}

				pX+=dirX;
				pY+=dirY;
			}

			
			//stampa il player
			gotoxy(pX*2,pY);
			printf("%s",pl);
			
			/*if (checkCar(pX,pY))
			{
				l=0;
			}*/
			
			//verifica morte in acqua e sbattendo contro un'auto
			if ((checkGround(pX,pY,o) && !checkTrunk(pX,pY)) || checkCar(pX,pY))
			{
				l=0;
			}
			
			//verifica vittoria
			if(pY == 1)
			{
				cancelOldPlayer(pX,pY);
				pY = mapYSize-2;
				pX = mapXSize/2;
				point++;
			}
			

			//stampa controlli
			gotoxy((mapXSize)*2,0);
			printf("su:       %c",su);
			gotoxy((mapXSize)*2,1);
			printf("giu:      %c",giu);
			gotoxy((mapXSize)*2,2);
			printf("destra:   %c",destra);
			gotoxy((mapXSize)*2,3);
			printf("sinistra: %c",sinistra);
			gotoxy((mapXSize)*2,4);
			printf("esci:     esc");
			
			//stampa punteggio
			gotoxy((mapXSize)*2,mapYSize/2);
			printf("punteggio: %d",point);
		}
		if(r!=0)
		{
			//pagina morte
			clrScr();
			gotoxy(mapXSize-5,mapYSize/2-3);
			printf("%s sei morto!%s",REDB,NORM);
			gotoxy(mapXSize-4,mapYSize/2-1);
			printf("punteggio");
			gotoxy(mapXSize,mapYSize/2);
			printf("%d",point);
			gotoxy(mapXSize-14,mapYSize/2+2);
			printf("premi invio per ricominciare");
			int invio =0;
			while (getch() != 13);//fino a che premi invio
		}
				
	}
}

void cancelOldPlayer(pX,pY)//sostituisce il player con il pezzo giusto di mappa
{
	gotoxy(pX*2,pY);
	printf(map[pY][pX]);
}

int checkGround(X,Y,GR)//data una stringa verifica se si trova in una certa posizione della mappa
{
	if (map[Y][X] == GR)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int checkWall(X,Y)//verifica se la posizione è fuori dalla mappa o su un muro
{
	if(X < 0 || X > mapXSize)//se la X è sotto la mappa
	{
		return 1;
	}
	if (map[Y][X] == wl)//se la posizione è un muro
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int checkTrunk(X,Y)//verifica se la posizione è su un tronco e ritorna la direzione di esso
{
	
	int j;
	for (j=0;j<trunkLength;j++)
	{
		int size = trunks[j][3];
		int x = trunks[j][0];
		int y = trunks[j][1];
		int dir = trunks[j][2];
		
		if (Y==y && (X>x && X<x+size+1) )
		{
			return dir;
		}
	}
	return 0;
}
int checkCar(X,Y)//verifica se la posizione è su una auto e ritorna la direzione di esso
{
	
	int j;
	for (j=0;j<carLength;j++)
	{
		int size = cars[j][3];
		int x = cars[j][0];
		int y = cars[j][1];
		int dir = cars[j][2];
		
		if (Y==y && (X>x && X<x+size+1) )
		{
			return 1;
		}
	}
	return 0;
}

void moveTrunk(int on)//muove i tronchi
{
	int j;
	for (j=0;j<trunkLength;j++)//per ogni tronco
	{
		int i;
		int size = trunks[j][3];
		int dir = trunks[j][2];
		trunks[j][0]+=dir*on;//x+=dir
		
		//posizione dell'inizio del tronco
		int x = trunks[j][0];
		int y = trunks[j][1];
		
		for (i=0;i<size;i++)//per ogni pezzo di tronco
		{
			if(!checkWall((x+i+1),y))//se non è su un muro
			{
				//stampa il tronco
				gotoxy((x+i+1)*2,y);
				printf("%s",tr);
			}
		}
		//se il tronco va a destra
		if(dir>0)
		{
			//se non è su un muro rimette l'onda al posto del tronco
			if(!checkWall(x,y))
			{
				gotoxy(x*2,y);
				printf("%s",o);	
			}
			if(x==mapXSize-2)//uscito dalla mappa 
			{
				trunks[j][0]=-size;//porta il tronco a sinistra
			}
		}
		else //se il tronco va a sinistra
		{
			//se non è su un muro rimette l'onda al posto del tronco
			if(!checkWall(x+size+1,y))
			{
				gotoxy((x+size+1)*2,y);
				printf("%s",o);
			}
			if(x==-size)//uscito dalla mappa 
			{
				trunks[j][0]=mapXSize-1;//porta il tronco a destra
			}	
		}		
	}
}
void moveCar(int on)
{
	int j;
	for (j=0;j<carLength;j++)//per ogni auto
	{
		int i;
		int size = cars[j][3];
		int dir = cars[j][2];
		int col = carsColor[j];
		cars[j][0]+=dir*on;//x+=dir
		
		//posizione di inizio dell'auto
		int x = cars[j][0];
		int y = cars[j][1];

		for (i=0;i<size;i++)// per ogni pezzo d'auto 
		{
			if(!checkWall((x+i+1),y))//se è dentro alla mappa
			{
				gotoxy((x+i+1)*2,y);
				printf("%s  %s",col,NORM);
			}
		}
	
		//se l'auto va a destra
		if(dir>0)
		{
			//se non è un muro cancella l'auto
			if(!checkWall(x,y))
			{
				gotoxy(x*2,y);
				printf("  ");
			}
			//se l'auto supera i bordi va dall'altro lato
			if(x==mapXSize-2)
			{
				cars[j][0]=-size;
			}
		}
		else //se l'auto va a sinistra
		{
			if(!checkWall(x+size+1,y))
			{
				gotoxy((x+size+1)*2,y);
				printf("  ");
			}
			//se l'auto supera i bordi va dall'altro lato
			if(x==-size)
			{
				cars[j][0]=mapXSize-1;//x = mapXSize-1
			}	
		}		
	}
}
	
void printFrog()
{
	printf("           %s    %s %s   %s %s    %s %s    %s\n",GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM);//                                           XXXX XXX XXXX XXXX
	printf("           %s %s    %s %s %s %s %s %s  %s %s %s %s  %s %s\n",GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM);// X    X X X  X X  X
	printf("           %s   %s  %s   %s %s %s  %s %s %s %s   \n",GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM);//                             XX   XXX X  X X  
	printf("           %s %s    %s  %s  %s %s  %s %s %s %s %s  %s\n",GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM);//               X    XX  X  X X XX
	printf("           %s %s    %s %s %s %s %s %s  %s %s %s %s  %s %s\n",GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM);// X    X X X  X X  X
	printf("           %s %s    %s %s %s %s %s    %s %s    %s\n",GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM,GRNB,NORM);//                             X    X X XXXX XXXX 
}


	
	
	

	
		
	
	



/****  IMPLEMENTAZIONE FUNZIONI  *************/
//---------------------------------------------

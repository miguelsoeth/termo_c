#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

int end_flag=0;
int count_chutes=0;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void func_chuta(char (*chute)[5]) {
	printf("\n");
	gets(chute[count_chutes]);
	while (strlen(chute[count_chutes])!=5) {
		printf("A palavra deve ter 5 letras\n");
		func_chuta(chute);
	}
	for (int i=0; i<5; i++) {
		chute[count_chutes][i]=toupper(chute[count_chutes][i]);
	}
	system("cls");
}

void func_display(const char palavra_secreta[], char (*chute)[5]) {
	if (strcmp(palavra_secreta, chute[count_chutes])) {
	} else {
		end_flag=1;
	}
	for (int i=0; i<=count_chutes; i++) {
		for (int j=0; j<5; j++) {
			if(palavra_secreta[j]==chute[i][j]) {
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("%c ", chute[i][j]);
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			} else {
				int flag_has=0;
				for (int k=0; k<5; k++) {
					if (chute[i][j]==palavra_secreta[k]) {
						SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
						printf("%c ", chute[i][j]);
						flag_has=1;
						SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
						break;
					}
				}
				if (flag_has==0) {
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
					printf("%c ", chute[i][j]);
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				}
			}
		}
		printf("\n");
	}
}
void func_inicio() {
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf( "######## ######## ########  ##     ##  #######  \n"
			"   ##    ##       ##     ## ###   ### ##     ## \n"
			"   ##    ##       ##     ## #### #### ##     ## \n"
			"   ##    ######   ########  ## ### ## ##     ## \n"
			"   ##    ##       ##   ##   ##     ## ##     ## \n"
			"   ##    ##       ##    ##  ##     ## ##     ## \n"
			"   ##    ######## ##     ## ##     ##  #######  \n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("Azul: a palavra secreta possui a letra mas nao nessa posicao\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("Verde: letra na posicao correta\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("Vermelho: a palavra secreta nao possui essa letra\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("\n\nDigite uma palavra de 5 letras para comecar\n");
}

void func_final () {
	if (end_flag==0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		int piscando=1;
	    while (1) {
	        system("cls");
	        if (piscando) {
			    printf("ddb    db  .d88b.   .o88b. d88888b \n"
						" 88    88 .8P  Y8. d8P  Y8 88'     \n"
						" Y8    8P 88    88 8P      88ooooo \n"
						" `8b  d8' 88    88 8b      88~~~~~ \n"
						"  `8bd8'  `8b  d8' Y8b  d8 88.     \n"
						"    YP     `Y88P'   `Y88P' Y88888P \n");
	            piscando = 0;
	        } else {
	            printf("d88888b d8888b. d8888b.  .d88b.  db    db \n"
						"88'     88  `8D 88  `8D .8P  Y8. 88    88 \n"
						"88ooooo 88oobY' 88oobY' 88    88 88    88 \n"
						"88~~~~~ 88`8b   88`8b   88    88 88    88 \n"
						"88.     88 `88. 88 `88. `8b  d8' 88b  d88 \n"
						"Y88888P 88   YD 88   YD  `Y88P'  ~Y8888P' \n");
	            piscando = 1;
	        }
	        Sleep(1000);
	    }
	} else {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		int piscando=1;
	    while (1) {
	        system("cls");
	        if (piscando) {
			    printf("ddb    db  .d88b.   .o88b. d88888b \n"
						" 88    88 .8P  Y8. d8P  Y8 88'     \n"
						" Y8    8P 88    88 8P      88ooooo \n"
						" `8b  d8' 88    88 8b      88~~~~~ \n"
						"  `8bd8'  `8b  d8' Y8b  d8 88.     \n"
						"    YP     `Y88P'   `Y88P' Y88888P \n");
	            piscando = 0;
	        } else {
	            printf(" .d8b.   .o88b. d88888b d8888b. d888888b  .d88b.  db    db \n"
						"d8' `8b d8P  Y8 88'     88  `8D `~~88~~' .8P  Y8. 88    88 \n"
						"88ooo88 8P      88ooooo 88oobY'    88    88    88 88    88 \n"
						"88~~~88 8b      88~~~~~ 88`8b      88    88    88 88    88 \n"
						"88   88 Y8b  d8 88.     88 `88.    88    `8b  d8' 88b  d88 \n"
						"YP   YP  `Y88P' Y88888P 88   YD    YP     `Y88P'  ~Y8888P' \n");
	            piscando = 1;
	        }
	        Sleep(1000);
	    }
	}
}

const char* func_palavra() {
    const char* palavra = "NAVIO";
    return palavra;
}

main () {
	const char* palavra_secreta = func_palavra();
	char chute[6][5], p_display[6][5];

	func_inicio();
	while (count_chutes < 6 && end_flag==0) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		func_chuta(chute);
		func_display(palavra_secreta, chute);
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		count_chutes++;
	}
	func_final();
}

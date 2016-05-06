#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define maxCap 10

struct utas {
	char* nev;
	char ido[30];
	char* uti_cell;
	char* telefon;
};

struct jarat {
	char* nev;
	char* ido;
};

void menu() {
	printf("\n");
	printf("\t MENU\n");
	printf("0. kilepes\n");
	printf("1. jarat kiiras\n");
	printf("2. uj jarat felvetel\n");
	printf("3. jarat torles\n");
	printf("4. uj utas\n");
	printf("5. utas torles\n");
	printf("6. utas modositas\n");
	printf("7. fajbla iras\n");
	printf("\n");
}

void jarat_kiiras(struct jarat j[], int meret) {
	int i;
	for(i = 0; i < meret; i++) {
			printf("\t %d. Nev: %s  ", i, j[i].nev);
			printf("Ido: %s\n", j[i].ido);
	}
}

void utas_kiiras(struct utas u[], int utas_meret) {
	int i;
	for(i = 0; i < utas_meret; i++) {
			printf("\t %d. Nev: %s", i, u[i].nev);
			printf(", Uticell: %s", u[i].uti_cell);
			printf(", Tel: %s", u[i].telefon);
			printf(", Ido: %s\n", u[i].ido);
	}
}

void jarat_infok(struct jarat j[], struct utas u[], int jarat_meret, int utas_meret) {
	int i;
	for(i = 0; i < jarat_meret; i++) {
			printf("\t %d. Nev: %s  ", i, j[i].nev);
			printf("Ido: %s\n", j[i].ido);
			int k;
			for(k = 0; k < utas_meret; k++) {
				if(!strcmp(j[i].nev, u[k].uti_cell)) {
				
					printf("\t\t %s", u[k].nev);
					printf(", %s", u[k].ido);
					printf(", %s", u[k].uti_cell);
					printf(", %s\n", u[k].telefon);
				}
			}
			
	}
}

void jarat_inicializalas(struct jarat jaratok[]) {
	jaratok[0].nev = "Krakko";
	jaratok[0].ido = "14:55";
	
	jaratok[1].nev="Praga";
	jaratok[1].ido="17:23";
	              
	jaratok[2].nev="Becs";
	jaratok[2].ido="03:15";

}

void uj_jarat(struct jarat jaratok[], int meret) {
				
}

int main() {
	
	struct utas utasok[maxCap];
	struct jarat jaratok[maxCap];
	int meret = 3;
	int utas_meret = 0;
	char* tmp1;
	char* tmp2;
	char* tmp_nev;     
	char* tmp_uti_cell;
	int sor;
	char* tmp_tel;
	int i,z,f;
	
	jarat_inicializalas(jaratok);
	
	char valasz = ' ';
	fflush(stdin);
	menu();
	
	
	while(valasz != '0') {
		
		scanf("%c", &valasz);
		
		switch(valasz) {
			case '1':
				jarat_infok(jaratok, utasok, meret, utas_meret);
				menu();
			break;
			case '2':
				tmp2 = malloc(sizeof(char) * 64);
				tmp1 = malloc(sizeof(char) * 64);
				printf("Uj nev: ");
				fflush(stdin);
				scanf("%s", tmp1);
				
				jaratok[meret].nev = tmp1;
				printf("Uj ido: ");
				fflush(stdin);
				scanf("%s", tmp2);
				jaratok[meret].ido = tmp2;
				meret++;
				menu();
			break;
			case '3':
				jarat_kiiras(jaratok, meret);
				fflush(stdin);
				scanf("%d" , &sor);
				printf("%d : ", sor);
				if(sor != meret - 1) {
					for(i = 0; i < meret - 1; i++) {
						if(i >= sor)  {
							printf("%s : ", jaratok[i].nev);
							jaratok[i].nev = jaratok[i+1].nev;
							jaratok[i].ido = jaratok[i+1].ido;
						}
					}
				}
				meret--;
				menu();
			break;
			case '4':
				tmp_nev      = malloc(sizeof(char) * 64);
				tmp_uti_cell = malloc(sizeof(char) * 64);
				tmp_tel      = malloc(sizeof(char) * 64);
				
				printf("Uj nev: ");
				fflush(stdin);
				scanf("%s", tmp_nev);
				utasok[utas_meret].nev = tmp_nev;
				
				printf("Uj uticell: ");
				fflush(stdin);
				scanf("%s", tmp_uti_cell);
				utasok[utas_meret].uti_cell = tmp_uti_cell;
				
				printf("Uj telefon: ");
				fflush(stdin);
				scanf("%s", tmp_tel);
				utasok[utas_meret].telefon = tmp_tel;
				
				utasok[utas_meret].ido[0] = '\0';
				time_t most = time(NULL);
				strcat(utasok[utas_meret].ido, ctime(&most));
				utasok[utas_meret].ido[strlen(utasok[utas_meret].ido)-1] = '\0';
				utas_meret++;
				menu();
			break;
			case '5':
				utas_kiiras(utasok, utas_meret);
				fflush(stdin);
				scanf("%d" , &sor);
				if(sor <= utas_meret - 1) {
					for(i = 0; i < utas_meret - 1; i++) {
						if(i >= sor)  {
							printf("%s : ", utasok[i].nev);
							utasok[i].nev = utasok[i+1].nev;
							for(z = 0; z < strlen(utasok[i+1].ido); z++) {
								utasok[i].ido[z] = utasok[i+1].ido[z]; 
							}
							utasok[i].uti_cell = utasok[i+1].uti_cell;
							utasok[i].telefon = utasok[i+1].telefon;
						}
					}
					utas_meret--;
				}
				menu();
			break;
			case '6':
				utas_kiiras(utasok, utas_meret);
				tmp_nev      = malloc(sizeof(char) * 64);
				tmp_uti_cell = malloc(sizeof(char) * 64);
				tmp_tel      = malloc(sizeof(char) * 64);
				
				fflush(stdin);
				scanf("%d" , &sor);
				
				printf("Uj nev: ");
				fflush(stdin);
				scanf("%s", tmp_nev);
				utasok[sor].nev = tmp_nev;
				
				printf("Uj uticell: ");
				fflush(stdin);
				scanf("%s", tmp_uti_cell);
				utasok[sor].uti_cell = tmp_uti_cell;
				
				printf("Uj telefon: ");
				fflush(stdin);
				scanf("%s", tmp_tel);
				utasok[sor].telefon = tmp_tel;
				
				utasok[sor].ido[0] = '\0';
				time_t most1 = time(NULL);
				strcat(utasok[sor].ido, ctime(&most1));
				utasok[sor].ido[strlen(utasok[sor].ido)-1] = '\0';
				menu();
			break;
			case '7':
				f = open("uber.txt", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
				int i;
				for(i = 0; i < meret; i++) {
					write(f, jaratok[i].nev, strlen(jaratok[i].nev));
					write(f, " ", 1);
					write(f, jaratok[i].ido, strlen(jaratok[i].ido));
					write(f, "\n", 1);
					int k;
					for(k = 0; k < utas_meret; k++) {
						if(!strcmp(jaratok[i].nev, utasok[k].uti_cell)) {
						
							write(f, utasok[k].nev, strlen(utasok[k].nev));
							write(f, " ", 1);
							write(f, utasok[k].ido, strlen(utasok[k].ido));
							write(f, " ", 1);
							write(f, utasok[k].uti_cell, strlen(utasok[k].uti_cell));
							write(f, " ", 1);
							write(f, utasok[k].telefon, strlen(utasok[k].telefon));
							write(f, "\n", 1);
						}
					}
				}	
				close(f);
				menu();
			break;
		}
	}
	return 0;
}
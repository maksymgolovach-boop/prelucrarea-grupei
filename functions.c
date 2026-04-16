#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "functionshead.h"

void input(int *nrst, char ***numeprenume, int **note1, int **note2){
    int i;
    printf("Introduceti numarul de studenti: ");
    scanf("%d", nrst);

    *numeprenume = (char**)malloc((*nrst) * sizeof(char*));
    *note1 = (int*)calloc(*nrst, sizeof(int));
    *note2 = (int*)calloc(*nrst, sizeof(int));
    if(*note1 == NULL || *note2 == NULL || *numeprenume == NULL){
        printf("Alocare de memorie a esuat");
        exit(EXIT_FAILURE);
    }
    printf("Introduceti numele si prenumele a fiecarui student:\n");
    getchar();
    for(i=0; i<*nrst; i++){
        (*numeprenume)[i] = (char*)malloc(sizeof(char)*30);
        printf("Numele si prenumele a studentului %d: ",i+1);
        gets((*numeprenume)[i]);
    }
    for(i=0; i<*nrst; i++){
        printf("Intoduceti notele de la testul 1 si 2 a studentului %s: \n", (*numeprenume)[i]);
        printf("Nota 1: ");
        scanf("%d", &(*note1)[i]);
        printf("Nota 2: ");
        scanf("%d", &(*note2)[i]);
    }
}

void add_spaces(char *string, int NumSpace){
    int lenght = strlen(string);
    for(int i = 0; i<NumSpace; ++i){
        string[i + lenght] = ' ';
    }
    string[lenght + NumSpace] = '\0';
}

void afisare(int nrst, char **numeprenume, int *note1, int *note2){
    int i;
    int spaces;
    char max[25], spaces_pren[] = "    ";
    char spac[]="         ";
    char numep[] = "PRENUME SI NUME";
    strcpy(max, numeprenume[0]);
    for(i=1; i<nrst; i++){
        if(strlen(max)<strlen(numeprenume[i])){
            strcpy(max, numeprenume[i]);
        }
    }
    if(strlen(max)<strlen(numep)){
        for(i = 0; i<nrst; ++i){
            spaces = strlen(numep) - strlen(numeprenume[i]);
            add_spaces(numeprenume[i], spaces);
        }
    } else {
        for(i = 0; i<nrst; ++i){
            spaces = strlen(max) - strlen(numeprenume[i]);
            add_spaces(numeprenume[i], spaces);
        }
        spaces = strlen(max) - strlen(numep);
        add_spaces(spaces_pren, spaces);
    }

    printf("PRENUME SI NUME%sNOTA 1    NOTA 2\n", spaces_pren);
    for(i=0;i<nrst; i++){
        printf("%s    %d%s%d\n", numeprenume[i], note1[i], (note1[i] >= 10) ? (spac+1) : spac, note2[i]);
    }
}
void salvareText(int nrst, char **numeprenume, int *note1, int *note2){
    int i;
    int spaces;
    char max[25], spaces_pren[] = "    ";
    char spac[]="         ";
    char numep[] = "PRENUME SI NUME";
    FILE *f = fopen("DateStudenti.txt", "wt");
    if(f == NULL){
        printf(BRED"Eroare la crearea fisierului!"CRESET);
        exit(-1);
    }
    strcpy(max, numeprenume[0]);
    for(i=1; i<nrst; i++){
        if(strlen(max)<strlen(numeprenume[i])){
            strcpy(max, numeprenume[i]);
        }
    }
    if(i != nrst){
        if(strlen(max)<strlen(numep)){
            for(i = 0; i<nrst; ++i){
                    spaces = strlen(numep) - strlen(numeprenume[i]);
                    add_spaces(numeprenume[i], spaces);
                }
            } else {
                for(i = 0; i<nrst; ++i){
                    spaces = strlen(max) - strlen(numeprenume[i]);
                    add_spaces(numeprenume[i], spaces);
                }
                spaces = strlen(max) - strlen(numep);
                add_spaces(spaces_pren, spaces);
            }
    } else {
        if(strlen(max)>strlen(numep)){
            spaces = strlen(max) - strlen(numep);
            add_spaces(spaces_pren, spaces);
        }
    }
    fprintf(f,"PRENUME SI NUME%sNOTA 1    NOTA 2\n", spaces_pren);
    for(i=0;i<nrst; i++){
        fprintf(f,"%s    %d%s%d\n", numeprenume[i], note1[i], (note1[i] >= 10) ? (spac+1) : spac, note2[i]);
    }
    fclose(f);
    printf("Studentii introdusi au fost salvati cu succes!\n");
}
void citiredinfisier(){
    FILE *f;
    char c;
    f = fopen("DateStudenti.txt", "rt");
    if(f == NULL){
        printf(BRED"Eroare la deschiderea fisierului!"CRESET);
        exit(-1);
    } else {
        c = fgetc(f);
        while(!feof(f)){
            putch(c);
            c = fgetc(f);
        }
    }
    fclose(f);
}
float calcmedia(int a, int b){
    float medie;
    medie = ((float)a + b)/2;
    return medie;
}
void promovati(int nrst, char **numeprenume, int *note1, int *note2){
    int i;
    int spaces;
    char max[25], spaces_pren[] = "    ";
    char spac[]="         ";
    char numep[] = "PRENUME SI NUME";
    strcpy(max, numeprenume[0]);
    for(i=1; i<nrst; i++){
        if(strlen(max)<strlen(numeprenume[i])){
            strcpy(max, numeprenume[i]);
        }
    }
    if(i != nrst){
        if(strlen(max)<strlen(numep)){
            for(i = 0; i<nrst; ++i){
                spaces = strlen(numep) - strlen(numeprenume[i]);
                add_spaces(numeprenume[i], spaces);
            }
        } else {
            for(i = 0; i<nrst; ++i){
                spaces = strlen(max) - strlen(numeprenume[i]);
                add_spaces(numeprenume[i], spaces);
            }
            spaces = strlen(max) - strlen(numep);
            add_spaces(spaces_pren, spaces);
        }
    } else {
        if(strlen(max)>strlen(numep)){
            spaces = strlen(max) - strlen(numep);
            add_spaces(spaces_pren, spaces);
        }
    }
    printf("PRENUME SI NUME%sNOTA 1    NOTA 2    MEDIA\n", spaces_pren);
    for(i=0;i<nrst; i++){
        if(calcmedia(note1[i], note2[i])>=5){
            printf("%s    %d%s%d%s%.1f\n", numeprenume[i], note1[i], (note1[i] >= 10) ? (spac+1) : spac, note2[i], (note2[i] >= 10) ? (spac+1): spac , calcmedia(note1[i], note2[i]));
        }
    }
}
void nrpromovati(int nrst, int *note1){
    int i,nrprom=0;
    for(i=0; i<nrst; i++){
        if(note1[i] >= 5){
            nrprom++;
        }
    }
    printf("Numarul de studenti promovati la primul test este: %d din %d\n", nrprom, nrst);
}
void MedieGrupaTest2(int nrst, int *note2){
    int i, sum=0;
    for(i=0; i<nrst; i++){
        sum += note2[i];
    }
    printf("Media generala a grupei la testul doi: %d\n", (sum/nrst));
}
void StPicati(int nrst, char **numeprenume, int *note1, int *note2){
    int i, nr_picati=0;
    int spaces;
    char max[25], spaces_pren[] = "    ";
    char spac[]="         ";
    char numep[] = "PRENUME SI NUME";
    FILE *f = fopen("StudentiPicati.txt", "wt");
    if(f == NULL){
        printf(BRED"Eroare la crearea fisierului!\n"CRESET);
        exit(-1);
    }
    strcpy(max, numeprenume[0]);
    for(i=1; i<nrst; i++){
        if(strlen(max)<strlen(numeprenume[i])){
            strcpy(max, numeprenume[i]);
        }
    }
    if(i != nrst){
        if(strlen(max)<strlen(numep)){
            for(i = 0; i<nrst; ++i){
                    spaces = strlen(numep) - strlen(numeprenume[i]);
                    add_spaces(numeprenume[i], spaces);
                }
            } else {
                for(i = 0; i<nrst; ++i){
                    spaces = strlen(max) - strlen(numeprenume[i]);
                    add_spaces(numeprenume[i], spaces);
                }
                spaces = strlen(max) - strlen(numep);
                add_spaces(spaces_pren, spaces);
            }
    } else {
        if(strlen(max)>strlen(numep)){
            spaces = strlen(max) - strlen(numep);
            add_spaces(spaces_pren, spaces);
        }
    }
    for(i=0; i<nrst; i++){
        if(calcmedia(note1[i], note2[i])>=5){
            nr_picati++;
        }
    }
    if(nr_picati==0){
        fprintf(f,"Nu sunt studenti picati!\n");
    } else {
        fprintf(f, "\t\tStudenti picati \n");
        fprintf(f, "PRENUME SI NUME%sNOTA 1    NOTA 2    MEDIA\n", spaces_pren);
        for(i=0;i<nrst; i++){
            if(calcmedia(note1[i], note2[i])<5){
                fprintf(f,"%s    %d%s%d%s%.1f\n", numeprenume[i], note1[i], (note1[i] >= 10) ? (spac+1) : spac, note2[i], (note2[i] >= 10) ? (spac+1): spac , calcmedia(note1[i], note2[i]));
            }
        }
    }
    fclose(f);
    printf("Informatia despre studentii picati este disponibila in fisierul StudentiPicati.txt\n");
}
void malfunction(){
    printf(BRED"Eroare, introduceti datele mai intai!\n"reset);
}
void info(){
    printf(HGRN" __  __    _    _  ________   ____  __     _   _ \n"
            "|  \\/  |  / \\  | |/ / ___\\ \\ / /  \\/  |   | | | |\n"
            "| |\\/| | / _ \\ | ' /\\___ \\\\ V /| |\\/| |   | |_| |\n"
            "| |  | |/ ___ \\| . \\ ___) || | | |  | |   |  _  |\n"
            "|_|  |_/_/   \\_\\_|\\_\\____/ |_| |_|  |_|___|_| |_|\n"
            "                                     |_____|     \n"reset);
}
void menu(){
    printf(BHCYN"<<<<<<================== \\\\ PRELUCRAREA INFORMATIEI DESPRE STUDENTI //==================>>>>>>\n");
    printf("[I] - Introducere date\n"
           "[A] - Afisare\n"
           "[S] - Salvare in fisier text\n"
           "[C] - Citire din fisier\n"
           "[P] - Afisare promovati - nume, note si medie\n"
           "[N] - Numar studenti promovati la primul test\n"
           "[M] - Media generala a grupei la testul al doilea\n"
           "[F] - Creare fisier nou ce contine studentii picati\n"
           "[L] - Informatie autor\n"
           "[X] - Exit\n");
    printf("\nOperatiunea dmns: "CRESET);
}

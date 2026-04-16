#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functionshead.h"
int main()
{
    char choice;
    char **numesiprenume;
    int nrst, *not1, *not2, val = 0;

    do {
        menu();
        scanf(" %c", &choice);
        system("cls");
        switch(tolower(choice)){
        case 'i':
            input(&nrst, &numesiprenume, &not1, &not2);
            val = 1;
            break;
        case 'a':
            if(val == 0){
                malfunction();
            } else {
                afisare(nrst, numesiprenume, not1, not2);
            }
            break;
        case 's':
            if(val == 0){
                malfunction();
            } else {
                salvareText(nrst, numesiprenume, not1,not2);
            }
            break;
        case 'c':
            citiredinfisier();
            break;
        case 'p':
            if(val == 0){
                malfunction();
            } else {
                promovati(nrst, numesiprenume, not1, not2);
            }
            break;
        case 'n':
            if(val == 0){
                malfunction();
            } else {
                nrpromovati(nrst, not1);
            }
            break;
        case 'm':
            if(val == 0){
                malfunction();
            } else {
                MedieGrupaTest2(nrst, not2);
            }
            break;
        case 'f':
            if(val == 0){
                malfunction();
            } else {
                StPicati(nrst, numesiprenume, not1, not2);
            }
            break;
        case 'l':
            info();
            break;
        case 'x':
            if(val == 1){
                free(not1);
                free(not2);
                for(int i = 0; i<nrst; i++){
                    free(numesiprenume[i]);
                }
                free(numesiprenume);
            }
            printf("Va multumim pentru utilizare!");
            exit(0);
        default:
            printf("\nOptiune inexistenta\n");
            break;
        }

    }   while(1>0);

    return 0;
}

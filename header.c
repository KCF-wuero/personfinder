//
// Created by KCF on 12/07/2022.
//
#include <stdio.h>
#include <string.h>


#include "header.h"


void readfile(FILE * personen, int * zeile,struct Person * persons)
{

    char satz[MAXSATZ];

    while(!feof(personen))
    {
        fgets(satz, MAXSATZ, personen);

        tokensaver(satz, *zeile, persons);

        (*zeile)++;
    }


}

void tokensaver(char satz[], int zeile, struct Person * persons)
{

    char *wort;
    for (int i = 1; i < 12; ++i)
    {
        wort = strtok_r(satz, " \n", &satz);

        switch (i) {

            case 1:
                strcpy(persons[zeile].vorname, wort);
                break;

            case 2:
                strcpy(persons[zeile].zuname, wort);

                break;

            case 3:
                strcpy(persons[zeile].gesch, wort);
                break;

            case 4:
                strcpy(persons[zeile].gebjahr, wort);
                break;

            case 5:
                strcpy(persons[zeile].todjahr, wort);
                break;

            case 6:
                strcpy(persons[zeile].fatvornam, wort);
                break;

            case 7:
                strcpy(persons[zeile].fatzunam, wort);
                break;

            case 8:
                strcpy(persons[zeile].fatgebjahr, wort);
                break;

            case 9:
                strcpy(persons[zeile].mutvornam, wort);
                break;

            case 10:
                strcpy(persons[zeile].mutzunam, wort);
                break;

            case 11:
                strcpy(persons[zeile].mutgebjahr, wort);
                break;

            default:

                break;
        }

    }
    strcpy(persons[zeile].personid, "") ;
    strcat(persons[zeile].personid, persons[zeile].vorname);
    strcat(persons[zeile].personid, persons[zeile].zuname);
    strcat(persons[zeile].personid, persons[zeile].gebjahr);

    strcpy(persons[zeile].fatid, "") ;
    strcat(persons[zeile].fatid, persons[zeile].fatvornam);
    strcat(persons[zeile].fatid, persons[zeile].fatzunam);
    strcat(persons[zeile].fatid, persons[zeile].fatgebjahr);

    strcpy(persons[zeile].mutid, "") ;
    strcat(persons[zeile].mutid, persons[zeile].mutvornam);
    strcat(persons[zeile].mutid, persons[zeile].mutzunam);
    strcat(persons[zeile].mutid, persons[zeile].mutgebjahr);

}

int personfinder(char searchval[60],struct Person * persons)
{
    int perspossave;
    int i = 0;
    if(0 == strcmp("--0",searchval))
    {
        return 9999;
    }
    while( 0 != strcmp(searchval,persons[i].personid)){
        i++;
    }
    perspossave = i;
    return perspossave;
}

void parentsfinder(int personpos,int * fatpos,int * mutpos,struct Person * persons)
{

    if(personpos >= (9999) )
    {
    return;
    }

    *fatpos = personfinder(persons[personpos].fatid,persons);

    *mutpos = personfinder(persons[personpos].mutid,persons);


}

int kinderfinder(int fatpos,int mutpos,int maxzeilen,int * kinderpos,struct Person * persons)
{
    int i = 0;

    for (int j = 0; j < maxzeilen; j++) {
        if (9999 == fatpos || 9999 == mutpos) {


        } else {
            if (0 == strcmp(persons[fatpos].personid, persons[j].fatid)
                && 0 == strcmp(persons[mutpos].personid, persons[j].mutid)
                    ) {

                kinderpos[i] = j;
                i++;
            }
        }
    }

        return i;
    }
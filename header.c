//
// Created by KCF on 12/07/2022.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "header.h"
struct Person * persons;

struct Person * readfile(FILE * personen, int * zeile)
{
    persons = malloc(sizeof (struct Person)*MAX);
    char satz[MAXSATZ];

    while(!feof(personen))
    {
        fgets(satz, MAXSATZ, personen);

        tokensaver(satz, *zeile);

        (*zeile)++;
    }

    return persons;
}

void tokensaver(char satz[], int zeile)
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

}

void person finder(char searchval[])
{
    int perspossave;
    int i = 0;
    while( 0 != strcmp(searchval,persons[i].personid)){
        i++;
    }
    perspossave = i;



}
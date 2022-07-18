#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

FILE * personen;
FILE * output;
//
int main(int argc,char * argv[]) {

char searchid[60];
int zeile = 0;
int snprintfreturn;
int searchperspos;
int mutpos;
int fatpos;
int *kinderpos;

    if((personen = fopen(argv[2],"r")) == NULL)
    {
        printf("fehler beim öfenen der ersten datai");
        return -1;
    }

    if((output = fopen(argv[3],"w")) == NULL)
    {
        printf("fehler beim öfenen der zweiten datai");
        return -2;
    }

    strcpy(searchid,"");
    strcat(searchid,argv[4]);
    strcat(searchid,argv[5]);
    strcat(searchid,argv[6]);
    //TODO: optinal funktion die herausfindet in welcher reinfolge die eingabe steht (vornahme nachname gebdat)
    //TODO: auswahl welche art von verwanten man sucht
    struct Person * personlist = readfile(personen, &zeile);


fclose(personen);
    for (int i = 0; i < zeile; i++) {

        fprintf(output,"%s ", personlist[i].vorname);
        fprintf(output,"%s ", personlist[i].zuname);
        fprintf(output,"%s ", personlist[i].gesch);
        fprintf(output,"%s ", personlist[i].gebjahr);
        fprintf(output,"%s ", personlist[i].todjahr);
        fprintf(output,"%s ", personlist[i].fatvornam);
        fprintf(output,"%s ", personlist[i].fatzunam);
        fprintf(output,"%s ", personlist[i].fatgebjahr);
        fprintf(output,"%s ", personlist[i].mutvornam);
        fprintf(output,"%s ", personlist[i].mutzunam);
        fprintf(output,"%s", personlist[i].mutgebjahr);
        if(i != zeile - 1 ) {
            fprintf(output, "\n");
        }

    }

    searchperspos = personfinder(searchid);
    parentsfinder(searchperspos,&fatpos,&mutpos);

    kinderpos = malloc(sizeof (int)*zeile);
    kinderfinder(fatpos,mutpos,zeile,searchperspos,kinderpos);
    printf("Die gesuchte person ist %s\n",personlist[searchperspos].personid);

    printf("Die eltern der person sind %s = pos: %d und %s = pos: %d\n",
           personlist[searchperspos].fatid, fatpos, personlist[searchperspos].mutid, mutpos);

    printf("Die geschwister sind:\n");
    for (int i = 0; i < sizeof(kinderpos)/sizeof(kinderpos[0]); ++i)
    {

        printf("%s\n",personlist[kinderpos[i]].personid);
    }
    fclose(output);
    free(kinderpos);
    free(personlist);
    return 0;
}



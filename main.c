#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

FILE * personen;
FILE * output;

int main(int argc,char * argv[]) {
int zeile = 0;
int snprintfreturn;

    if((personen = fopen(argv[1],"r")) == NULL)
    {
        printf("fehler beim öfenen der ersten datai");
        return -1;
    }

    if((output = fopen(argv[2],"w")) == NULL)
    {
        printf("fehler beim öfenen der zweiten datai");
        return -2;
    }

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
    fclose(output);
    return 0;
}
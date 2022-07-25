#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include <stdbool.h>

FILE *personen;
FILE *output;

//
void onkelundtantenfinder(int kindersaver, int kinderpos[], int geltern[], int *tant[], int *onkel[],
                          struct Person *personlist, int *onkcount, int *tantcount);

int main(int argc, char *argv[]) {
    int kindersaver = 0;
    int eltern[] = {9999, 9999};
    int geltern[] = {9999, 9999, 9999, 9999};
    int ugeltern[] = {9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999};
    char searchid[60];
    int zeile = 0;
    int counter = 0;
    int searchperspos;
    int mutpos;
    int fatpos;
    int *kinderpos;
    int amountofkind;
    int *tant;
    int *onkel;
    int onkcount = 0;
    int tantcount = 0;


    if ((personen = fopen(argv[2], "r")) == NULL) {
        printf("fehler beim öfenen der ersten datai");
        return -1;
    }

    if ((output = fopen(argv[3], "w")) == NULL) {
        printf("fehler beim öfenen der zweiten datai");
        return -2;
    }

    strcpy(searchid, "");
    strcat(searchid, argv[4]);
    strcat(searchid, argv[5]);
    strcat(searchid, argv[6]);


    struct Person *personlist = malloc(sizeof(struct Person) * MAX);
    readfile(personen, &zeile, personlist);


    fclose(personen);
    for (int i = 0; i < zeile; i++) {

        fprintf(output, "%s ", personlist[i].vorname);
        fprintf(output, "%s ", personlist[i].zuname);
        fprintf(output, "%s ", personlist[i].gesch);
        fprintf(output, "%s ", personlist[i].gebjahr);
        fprintf(output, "%s ", personlist[i].todjahr);
        fprintf(output, "%s ", personlist[i].fatvornam);
        fprintf(output, "%s ", personlist[i].fatzunam);
        fprintf(output, "%s ", personlist[i].fatgebjahr);
        fprintf(output, "%s ", personlist[i].mutvornam);
        fprintf(output, "%s ", personlist[i].mutzunam);
        fprintf(output, "%s", personlist[i].mutgebjahr);
        if (i != zeile - 1) {
            fprintf(output, "\n");
        }

    }
    searchperspos = personfinder(searchid, personlist);
    parentsfinder(searchperspos, &fatpos, &mutpos, personlist);

    eltern[0] = fatpos;
    eltern[1] = mutpos;

    for (int i = 0; i < 2; i++) {
        parentsfinder(eltern[i], &fatpos, &mutpos, personlist);

        geltern[counter] = fatpos;
        geltern[counter + 1] = mutpos;
        counter += 2;
    }
    counter = 0;
    for (int i = 0; i < 4; i++) {

        if (9999 != geltern[i]) {
            parentsfinder(geltern[i], &fatpos, &mutpos, personlist);
            ugeltern[counter] = fatpos;
            ugeltern[counter + 1] = mutpos;
            counter += 2;

        }
    }


    kinderpos = malloc(sizeof(int) * zeile);
    counter = 0;
    for (int i = 0; i < 4; i++) {

        amountofkind = kinderfinder(ugeltern[counter], ugeltern[counter + 1], zeile, kinderpos, personlist);
        kindersaver += amountofkind;
        counter += 2;
    }
    tant = malloc(sizeof(int) * 30);
    onkel = malloc(sizeof(int) * 30);
    onkelundtantenfinder(kindersaver, kinderpos, geltern, tant, onkel, personlist,
                         &onkcount, &tantcount);

    printf("Die gesuchte person ist %s\n", personlist[searchperspos].personid);

    printf("Die eltern der person sind %s = pos: %d und %s = pos: %d\n",
           personlist[eltern[0]].personid, eltern[0], personlist[eltern[1]].personid, eltern[1]);


    if (0 == strcmp(argv[7], "tanten")) {
        printf("Die Grossonkel der person sind:\n");
        for (int i = 0; i < tantcount; i++) {
            printf("%s\n", personlist[tant[i]].personid);
        }
    } else {

        printf("Die Grossonkel der person sind:\n");
        for (int i = 0; i < onkcount; i++) {

            printf("%s\n", personlist[onkel[i]].personid);
        }
    }
    fclose(output);
    free(kinderpos);
    free(personlist);
    return 0;
}


void onkelundtantenfinder(int kindersaver, int kinderpos[], int geltern[], int *tant[], int *onkel[],
                          struct Person *personlist, int *onkcount, int *tantcount) {
    bool istgelternteil = false;
    for (int i = 0; i < kindersaver; i++) {

        for (int j = 0; j < 4; j++) {
            if (kinderpos[i] == geltern[j]) {
                istgelternteil = true;
                break;
            }
        }
        if (!istgelternteil) {

            if (0 == strcmp(personlist[kinderpos[i]].gesch, "m")) {

                onkel[*onkcount] = kinderpos[i];
                *onkcount++;
            } else {

                tant[*tantcount] = kinderpos[i];
                *tantcount++;
            }
        }


    }



}

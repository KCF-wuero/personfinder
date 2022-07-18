//
// Created by KCF on 12/07/2022.
//

#ifndef UNTITLED1_HEADER_H
#define UNTITLED1_HEADER_H

#endif //UNTITLED1_HEADER_H
#define MAX 500
#define MAXSATZ 500
struct Person{

    char personid[60];
    char zuname[21];
    char vorname[21];
    char gesch[2];
    char gebjahr[5];
    char todjahr[5];
    char fatid[60];
    char fatvornam[21];
    char fatzunam[21];
    char fatgebjahr[5];
    char mutid[60];
    char mutvornam[21];
    char mutzunam[21];
    char mutgebjahr[5];
};

void tokensaver(char satz[], int zeile, struct Person * persons);
int personfinder(char searchval[60],struct Person * persons);
void parentsfinder(int personpos,int * fatpos,int * mutpos,struct Person * persons);
int kinderfinder(int fatpos,int mutpos,int maxzeilen,int personpos,int * kinderpos,struct Person * persons);
void readfile(FILE * personen, int * zeile,struct Person * persons);

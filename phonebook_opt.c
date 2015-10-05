#include <stdlib.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    unsigned int index=hash(lastname,HASH_TABLE_SIZE);

    if(strcasecmp(pHead[index].lastName,lastname)==0) {
        return &pHead[index];
    }

    return NULL;
}

entry *append(char lastName[], entry *e)
{
    unsigned int index=hash(lastName,HASH_TABLE_SIZE);

    strcpy(e[index].lastName,lastName);

    return e;
}

unsigned int hash(char lastName[],int ht_size)
{
    int htmp=0,i=0;
    while(lastName[i]!='\0') {
        htmp<<=2;
        htmp+=lastName[i];
        i++;
    }

    return htmp % ht_size;
}
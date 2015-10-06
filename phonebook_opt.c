#include <stdlib.h>

#include "phonebook_opt.h"

unsigned int getKey(char lastname[])
{
    int x=0,i=0;

    while(lastname[i]!='\0') {
        x<<=2;
        x+=lastname[i];
        i++;
    }

    return x;
}

entry *findName(char lastname[], entry *root)
{
    int key=getKey(lastname);
    entry *cnode=root;

    while(cnode!=NULL) {
        if(key==cnode->key) {
            if(strcasecmp(cnode->lastName,lastname)==0)
                return cnode;
            else
                cnode=cnode->pLeft;
        } else if(key<cnode->key) {
            cnode=cnode->pLeft;
        } else {
            cnode=cnode->pRight;
        }
    }

    return NULL;
}

entry *append(char lastname[], entry *root)
{
    int key=getKey(lastname);
    int finish=0;
    entry *cnode=root,*nnode;
    if(root==NULL) {
        root=(entry *) malloc(sizeof(entry));
        root->key=key;
        root->pLeft=NULL;
        root->pRight=NULL;
        strcpy(root->lastName,lastname);
        return root;
    }

    while(finish==0) {
        if(key<=cnode->key) {
            if(cnode->pLeft!=NULL)
                cnode=cnode->pLeft;
            else {
                cnode->pLeft=(entry *) malloc(sizeof(entry));
                nnode=cnode->pLeft;
                nnode->key=key;
                nnode->pLeft=NULL;
                nnode->pRight=NULL;
                strcpy(nnode->lastName,lastname);
                finish++;
            }
        } else {
            if(cnode->pRight!=NULL)
                cnode=cnode->pRight;
            else {
                cnode->pRight=(entry *) malloc(sizeof(entry));
                nnode=cnode->pRight;
                nnode->key=key;
                nnode->pLeft=NULL;
                nnode->pRight=NULL;
                strcpy(nnode->lastName,lastname);
                finish++;
            }
        }
    }

    return root;
}
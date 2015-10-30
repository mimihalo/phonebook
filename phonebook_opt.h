#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* optimized version */
struct ENTRY_INFO {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
};

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pLeft,*pRight;
    struct ENTRY_INFO *info;
    unsigned int key;
} entry;

entry *findName(char lastname[], entry *root);
entry *append(char lastname[], entry *root);
entry *init_struct();

#endif

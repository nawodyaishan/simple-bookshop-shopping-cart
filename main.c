#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct book {
    int isbn;
    char title[20];
    char author[20];
    int price;
};

struct cart {
    int isbn;
    char title[20];
    int price;
    int quantity;
    int total;
    struct cart *link;

};

struct cart *insert(int i, char t[20], int p, int q, int T, struct cart *h);

struct cart *remv(int i, struct cart *h);

void displayLL(struct cart *h);

struct cart *process(struct cart *h);

struct cart mycart[];

struct book items[5] = {{1001, "Book1", "Author1", 250},
                        {1002, "Book2", "Author2", 500},
                        {1003, "Book3", "Author3", 750},
                        {1004, "Book4", "Author4", 480},
                        {1005, "Book5", "Author5", 140}};

int main() {

    int x, y = 1, isbn, OpCart, adCt, rmCt, a, Tot = 0;
    struct cart *head = NULL;
    //head=insert(1001,"Book1",250,2,500,head); head=insert(1002,"Book2",500,1,500,head);

    while (y = !0) {

        printf("\n____________________ WELCOME TO THE ABC BOOKSHOP ____________________\n");
        printf("\n_____________________________________________________________________\n");
        printf("\n____________________________ Main Menu ______________________________\n\n");
        printf("\n 1) Book Details\n");
        printf("\n 2) Search Books\n");
        printf("\n 3) My Cart\n");
        printf("\n 4) Quit\n\n");
        printf("Enter Your Option > ");
        scanf("%d", &x);

        if (x == 1) {

            printf("\n\n isbn no.      Name        Author      Unit Price (LKR)\n\n");
            printf("\n  %d\t      %s\t  %s\t   %d", items[0].isbn, items[0].title, items[0].author, items[0].price);
            printf("\n  %d\t      %s\t  %s\t   %d", items[1].isbn, items[1].title, items[1].author, items[1].price);
            printf("\n  %d\t      %s\t  %s\t   %d", items[2].isbn, items[2].title, items[2].author, items[2].price);
            printf("\n  %d\t      %s\t  %s\t   %d", items[3].isbn, items[3].title, items[3].author, items[3].price);
            printf("\n  %d\t      %s\t  %s\t   %d", items[4].isbn, items[4].title, items[4].author, items[4].price);
            printf("\n\n\nEnter Any number to go main menu ");
            scanf("%d", &y);

        }

        if (x == 2) {
            int b = 1;
            printf("\nEnter isbn no. :");
            scanf("%d", &isbn);
            for (a = 0; a < 5; a++) {
                if (isbn == items[a].isbn) {
                    printf("\n\n isbn no.      Name        Author      unit price (LKR)\n\n");
                    printf("\n  %d\t      %s\t  %s\t   %d", items[a].isbn, items[a].title, items[a].author,
                           items[a].price);
                    b = 0;
                }

            }
            if (b == 1) {
                printf("\n\nisbn no. not exists");
            }

            printf("\n\n\nEnter Any number to go main menu ");
            scanf("%d", &y);

        }

        if (x == 3) {
            while (y = !0) {

                int b = 0;
                printf("\n\n          My Cart         ");
                printf("\n\n1)View My Cart");
                printf("\n2)Add to cart");
                printf("\n3)Remove from cart");
                printf("\n4)Process cart");
                printf("\n5)Back to main menu");
                printf("\n\nEnter your option > ");
                scanf("%d", &OpCart);


                if (OpCart == 1) {

                    displayLL(head);

                }

                if (OpCart == 2) {
                    int price, total, Q = 0, b = 1;
                    char title[20];
                    printf("\n\nEnter item code :- ");
                    scanf("%d", &isbn);


                    for (a = 0; a < 5; a++) {

                        if (isbn == items[a].isbn) {

                            printf("\n\n isbn no.      Name        Author      unit price (LKR)\n\n");
                            printf("\n  %d\t      %s\t  %s\t   %d", items[a].isbn, items[a].title, items[a].author,
                                   items[a].price);
                            b = 0;

                            printf("\n\n\nEnter quantity :- ");
                            scanf("%d", &Q);
                            price = items[a].price;
                            total = price * Q;

                            printf("\n\nEnter 1 to add item : ");
                            scanf("%d", &adCt);
                            if (adCt == 1) {
                                head = insert(isbn, title, price, Q, total, head);
                                displayLL(head);
                            }

                        }
                    }
                    if (b == 1) {
                        printf("\n\nisbn no. not exists\n\n\n\n");
                    }


                }


                if (OpCart == 3) {
                    int price, total, Q = 0, b = 1;
                    char title[20];
                    printf("\n\nEnter item code :- ");
                    scanf("%d", &isbn);


                    for (a = 0; a < 5; a++) {

                        if (isbn == items[a].isbn) {

                            printf("\n\n isbn no.      Name        Author      unit price (LKR)\n\n");
                            printf("\n  %d\t      %s\t  %s\t   %d", items[a].isbn, items[a].title, items[a].author,
                                   items[a].price);
                            b = 0;

                            head = remv(isbn, head);
                            displayLL(head);

                        }
                    }
                    if (b == 1) {
                        printf("\n\nisbn no. not exists\n\n\n\n");
                    }


                }

                if (OpCart == 4) {

                    displayLL(head);
                    head = process(head);
                    //struct cart* head=NULL;


                }


                if (OpCart == 5) {
                    break;
                }
            }

        }

        if (x == 4) {
            printf("\n\n___________________Thank you___________________\n\n");
            break;
        }
    }


    return (0);
}


struct cart *insert(int i, char t[20], int p, int q, int T, struct cart *h) {

    struct cart *loop = NULL;


    struct cart *prev = NULL;


    struct cart *new = malloc(sizeof(struct cart));

    (*new).isbn = i;
    (*new).title[20] = t[20];
    (*new).price = p;
    (*new).quantity = q;
    (*new).total = T;
    (*new).link = NULL;


    if (h == NULL) {
        h = new;
    } else {
        loop = h;
        while (loop != NULL) {
            prev = loop;
            loop = (*loop).link;
        }

        (*prev).link = new;
    }
    return h;
}


struct cart *remv(int i, struct cart *h) {

    int rmCt;
    printf("\n\nEnter 1 to remove item : ");
    scanf("%d", &rmCt);
    if (rmCt == 1) {
        if (h == NULL) {
            printf("\n\ncart is empty\n");
        } else {
            struct cart *loop = NULL;
            struct cart *temp = NULL;
            struct cart *prev = NULL;

            if ((*h).isbn == i) {
                temp = h;
                h = ((*h).link);
                free(temp);
                return h;

            } else {
                loop = h;
                while (loop != NULL) {
                    if ((*loop).isbn == i) {
                        (*prev).link = (*loop).link;
                        return h;
                    }
                    prev = loop;
                    loop = (*loop).link;
                }
                printf("\n Invalid ISBN.\n");
                return h;
            }

        }
        //displayLL(h);


    }

}


struct cart *process(struct cart *h) {
    int Tot = 0, x, am, bl;
    struct cart *loop = NULL;
    loop = h;
    while (loop != NULL) {
        Tot = Tot + (*loop).total;
        loop = (*loop).link;
    }
    printf("\n                                  Total                   : %d", Tot);
    printf("\n_____________________________________________________________________\n");
    printf("\n\nEnter 1 to checkout cart: ");
    scanf("%d", &x);
    if (x == 1) {
        printf("\nEnter the given amount: ");
        scanf("%d", &am);
        bl = am - Tot;
        printf("\nBalance: %d", bl);
        printf("\n\n\n_____________________________Paid___________________________________\n\n     ");
        h = NULL;
        return h;
    }


}


void displayLL(struct cart *h) {
    struct cart *loop = NULL;
    loop = h;
    printf("\n_____________________________________________________________________\n");
    printf("\n\n isbn no.      Name        Unit Price (LKR)      Quantity      Total\n\n");
    while (loop != NULL) {
        printf("\n  %d\t", (*loop).isbn);
        printf("      %s\t\t", (*loop).title);
        printf("  %d\t\t", (*loop).price);
        printf("  %d\t\t", (*loop).quantity);
        printf(" %d", (*loop).total);
        //printf("\n| %d |", (*loop).isbn); printf(" %p ", (*loop).link);
        loop = (*loop).link;


    }
    printf("\n_____________________________________________________________________\n");


}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Info{
    char *fname;
    char *lname;
    int num;
    int status;
    int pN;
};

void func(char *s, char *t, int n){
    while (n){
        *s++ = *t++;
        n--;
    }
}

int equal(char* a, char *b){
    while (*a != 0 && *b != 0){
        if (*a != *b) return 0;
        ++a;
        ++b;
    }
    return *a == *b;
}

const int N = 50;
const int n = 15;

int main (){
    
    struct Info mC[N];
    
    for (int i = 0; i < N; i++){
        mC[i].status = 0;
        mC[i].pN = i + 1;
    }

    mC[0].pN = 1;               //для примера работы программы
    mC[0].num = 77722;
    mC[0].fname = "Oleg\n";
    mC[0].lname = "Fedorov\n";
    mC[0].status = 1;
    
    mC[1].pN = 2;               //для примера работы программы
    mC[1].num = 77111;
    mC[1].fname = "Oleg\n";
    mC[1].lname = "Markov\n";
    mC[1].status = 1;
    
    int menu = 0;
    int menu2 = 0;
    char str1[n];
    char str2[n];
    int str3 = 0;
    int ex = 1;
    char *strU1;
    strU1 = str1;
    char *strU2;
    strU2 = str2;
    
    while(ex == 1){
        
        printf ("Select an action: \n");
        printf ("1. Add contact \n");
        printf ("2. Delete contact \n");
        printf ("3. Search for a contact \n");
        printf ("4. Display the entire list of contacts \n");
        printf ("5. Exit \n");
        
        scanf("%d", &menu);
    
        if (menu == 1){
            printf("Enter the number \n");
            scanf("%d", &str3);
            getchar();
            printf("Enter first name \n");
            fgets(str1, sizeof(str1), stdin);
            fflush(stdin);
            printf("Enter last name \n");
            fgets(str2, sizeof(str2), stdin);
            fflush(stdin);
            
            for (int i = 0; i < N; i++){
                if (mC[i].status == 0){
                    mC[i].pN = i + 1;
                    mC[i].fname = (char*)malloc(sizeof(char)*n);
                    func(mC[i].fname, strU1, n);
                    mC[i].lname = (char*)malloc(sizeof(char)*n);
                    func(mC[i].lname, strU2, n);
                    mC[i].num = str3;
                    mC[i].status = 1;
                    printf("Contact added \n");
                    break;
                }
            }
            printf("--------------\n");
        }
              
        if (menu == 2){
            printf("Enter the number \n");
            scanf("%d", &str3);
            getchar();
            int s = 0;
            
            for(int i = 0; i < N; i++){
                if ((str3 == mC[i].num) && (mC[i].status != 0)){
                    mC[i].status = 0;
                    s = i;
                    break;
                }
            }
            for(int j = s; j < N; j++){
                mC[j].pN = j;
            }
            printf("Contact deleted \n");
            printf("--------------\n");
        }
        
        if (menu == 3){
            printf("Search by: \n");
            printf("1. First name \n");
            printf("2. Last name \n");
            printf("3. Number \n");
            scanf("%d", &menu2);
            getchar();
            
            if (menu2 == 1){
                printf("Enter first name \n");
                fgets(str1, sizeof(str1), stdin);
                fflush(stdin);
                    
                for (int i = 0; i < N + 1; i++){
                    if(mC[i].status != 0){
                        if(equal (mC[i].fname, str1) == 1){
                            printf("Fast Name: %s", mC[i].fname);
                            printf("Last Name: %s", mC[i].lname);
                            printf("Number: %d\n", mC[i].num);
                        }
                    }
                    else if(i == N){
                        printf("Contact not found \n");
                    }
                }
            }
            if (menu2 == 2){
                printf("Enter last name \n");
                fgets(str2, sizeof(str2), stdin);
                fflush(stdin);
                
                for (int i = 0; i < N + 1; i++){
                    if(mC[i].status != 0){
                        if(equal (mC[i].lname, str2) == 1){
                            printf("Fast Name: %s", mC[i].fname);
                            printf("Last Name: %s", mC[i].lname);
                            printf("Number: %d\n", mC[i].num);
                        }
                    }
                    else if(i == N){
                        printf("Contact not found \n");
                    }
                }
            }
            if (menu2 == 3){
                printf("Enter the number \n");
                scanf("%d", &str3);
                getchar();
                
                for(int i = 0; i < N + 1; i++){
                    if ((str3 == mC[i].num)&&(mC[i].status != 0)){
                        printf("Fast Name: %s", mC[i].fname);
                        printf("Last Name: %s", mC[i].lname);
                        printf("Number: %d\n", mC[i].num);
                        break;
                    }else if(i == N){
                        printf("Contact not found \n");
                    }
                }
            }
            printf("--------------\n");
        }
        
        if (menu == 4){
            for(int i = 0; i < 50; i++){
                if(mC[i].status != 0){
                    printf("%d.------------\n", mC[i].pN);
                    printf("Fast Name: %s", mC[i].fname);
                    printf("Last Name: %s", mC[i].lname);
                    printf("Number: %d\n", mC[i].num);
                    printf("--------------\n");
                }
            }
        }
        
        if (menu == 5){
            ex = 0;
        }
    }    
    
return 0;
}
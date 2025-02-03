#include<stdio.h>
int main(){
    int n,ch,x,sum=0,first,start,receiver,find,divisn;
    char resp;
    do{


    printf("\nEnter the number of player:");
    scanf("%d",&n);
    if(n==1)
       {printf("\nInvalid number of players");
        return 0;}
    printf("\n1.Finding player number getting last card\n2.Finding which player received Nth card");
    printf("\n\nEnter the choice:");
    scanf("%d",&ch);
    printf("\nDistribution of cards started from:\n1. Distributor\n2. Player next to distributor\n");
    printf("Enter 1 or 2: ");
    scanf("%d",&start);
    switch(ch){
        case 1:
            printf("Enter the player number who distributed cards: ");
            scanf("%d",&x);
             if (start == 1) {
                    receiver=(x+51)%n;
                } else {
                    receiver=(x+51+1)%n;
                }
                if(receiver==0)
                    receiver=n;

            printf("The last card will be received by player %d\n", receiver);
            break;

        case 2:
             printf("Enter the player number who distributed card: ");
            scanf("%d",&x);
            printf("\n Enter the card number to find the receiver: ");
            scanf("%d",&find);
            if(find>52)
                {printf("\nInvalid card number");
                break;}
            if(start==1){
                 if(find%n==0&&x==1)
                {
                    printf("%dth card will be received by %dth player: ",find,n);
                }
                else if(find%n==0&&x!=1){
                    printf("%dth card will be received by %dth player",find,x-1);
                }
                else if(find%n!=0){// matlab jab find%n==0 nhi hua
                if(x==1){
                receiver=find%n;
                printf("%dth player will receive %dth card",receiver,find);}
                else
                {
                    receiver=(find%n)+(x-1);
                    if(receiver>n){
                        receiver=receiver-n;
                    }
                    printf("%dth card will be received by %dth player",find,receiver);

                }

            }

            }
            else if(start==2){
                if(n%2==0){
                    if(find%n==0)
                        printf("%dth card will be received by %dth player: ",find,x);
                    else{
                        divisn=find/n;
                        if(divisn>n)
                            printf("card will be received by %dth player",divisn-n+(find%n));
                        else if(divisn<n)
                            printf("card will be received by %dth player",n-divisn+(find%n));

               }
            }

            else{
                if(find>n)
                    printf("card will be received by %dth player",find%n);
                else
                    printf("card will be received by %dth player",find);
            }


            }
            break;



    }
    printf("\n Want to continue?(y/n):");
    scanf(" %c",&resp);
    }while(resp=='y');
    return 0;
}



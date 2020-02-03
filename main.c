#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
//stock
struct stock
{
    char book_name[50];
    int quantity;
    struct stock *next;
    int shelf;
    int cost;
    int sell;
}*start=NULL;
//purchase
struct node
{
	char book_name[50];
	int qty;
	int sell;
	int total;
	int profit;
	struct node *next,*prev;
}*top=NULL;

//stack program
//push a purchase
void push(struct stock *temp,int n)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    strcpy(newnode->book_name,temp->book_name);
    newnode->qty=n;
    newnode->sell=temp->sell;
    newnode->total=n*temp->sell;
    newnode->profit=(n*(temp->sell - temp->cost));
    if(top==NULL)
    {
        top=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    else
    {
        newnode->prev=top;
        newnode->next=NULL;
        top->next=newnode;
        top=newnode;

    }
}
//display purchase list
void display_record()
{
    struct node *temp,*temp1;
    temp=top;
    if(top==NULL)
    {
        printf("\n\n\n\n\t\t\t\t\t\tNo Records Found");
    }
    else
    {
        char b[20]="BOOKS",q[10]="QUANTITY",p[10]="PRICE",t[10]="TOTAL",e[10]="PROFIT";
        printf("\n\n\n\t\t\t%-20s%-15s%-15s%-15s%-15s\n",b,q,p,t,e);
        while(temp->prev!=NULL)
        {
            printf("%-20s%-15d%-15d%-15d%-15d\n",temp->book_name,temp->qty,temp->sell,temp->total,temp->profit);
            temp1=temp;
            temp=temp->prev;
            free(temp1);
        }
        printf("\n\n\t\t\t%-20s%-15d%-15d%-15d%-15d\n",temp->book_name,temp->qty,temp->sell,temp->total,temp->profit);
        free(temp1);
    }
}

//stock program
//add new book
void insert_new_book()
{
    struct stock *temp,*newnode;
    char s[50];
    int n,sh,cost,sell;
    printf("\n\n\t\t\t\t\t\tEnter Book Name:");
    scanf("%s",s);
    printf("\n\t\t\t\t\t\tEnter Quantity:");
    scanf("%d",&n);
    printf("\n\t\t\t\t\t\tEnter Shelf No:");
    scanf("%d",&sh);
    printf("\n\t\t\t\t\t\tEnter Cost Price: Rs ");
    scanf("%d",&cost);
    printf("\n\t\t\t\t\t\tEnter Sell Price: Rs ");
    scanf("%d",&sell);
    newnode=(struct stock*)malloc(sizeof(struct stock));
    strcpy(newnode->book_name,s);
    newnode->quantity=n;
    newnode->shelf=sh;
    newnode->cost=cost;
    newnode->sell=sell;
    if(start==NULL)
    {
        start=newnode;
        newnode->next=NULL;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;

    }
}

//search a book
struct stock *srch()
{
    struct stock *temp;
    printf("\n\n\n\t\t\t\t\t\tEnter Book Name :");
    char s[50];
    scanf("%s",s);
    temp=start;
    while(temp!=NULL)
    {
        if(strcmp(s,temp->book_name)==0)
        {

            break;
        }
        else
        {
        temp=temp->next;
        }
    }
    return temp;
}

//display details of a book
void display_book(struct stock *temp)
{
    printf("\n\n\t\t\t\t\t\tBook Name: %s\n",temp->book_name);
    printf("\n\t\t\t\t\t\tQuantity Available: %d\n",temp->quantity);
    printf("\n\t\t\t\t\t\tShelf No.: %d\n",temp->shelf);
    printf("\n\t\t\t\t\t\tPrice : Rs %d",temp->sell);
}
//refill a book
void refill()
{
    int q;
    struct stock *temp;
    temp=srch();
    display_book(temp);
    printf("\n\n\t\t\t\t\t\tEnter Quantity To Add : ");
    scanf("%d",&q);
    temp->quantity=temp->quantity+q;
    printf("\n\t\t\t\t\t\tCurrent quantity : %d",temp->quantity);
}

// sell a book
int sell(struct stock *temp)
{
    int n;
    printf("\n\n\n\t\t\t\t\t\tEnter No. of Books : ");
    scanf("%d",&n);
    if(temp->quantity==0)
    {
        printf("\n\n\t\t\t\t\t\tStock Not Available");
        return 0;
    }
    else if(n>(temp->quantity))
    {
        printf("\n\n\t\t\t\t\t\tStock Not Sufficient\n\t\t\t\t\t\tAvailable Stock : %d",temp->quantity);
        return 0;
    }
    else
    {
        temp->quantity=temp->quantity-n;
        push(temp,n);
        printf("\n\n\n\t\t\t\t\t\tBooks sold successfully!\n");
        return 0;
    }

}
//Demand list
// A linked list (LL) node to store a queue entry
struct QNode {
    char person_name[50];
	char book_name[50];
	int contact;
	int units;
    struct QNode* next;
};

// The queue, front stores the front node of LL and rear stores the
// last node of LL
struct Queue {
    struct QNode *front, *rear;
};

// A function to create an empty queue
struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// The function to add a value to q
void enQueue(struct Queue* q)
{
    // Create a new LL node
	struct QNode  *newnode;
	newnode= (struct QNode*)malloc(sizeof(struct QNode));
	char p_name[50],b_name[50];
	int unit_book;
	int long num;
	printf("\n\n\n\t\t\t\t\tEnter the name of Person : ");
	scanf("%s",p_name);
	printf("\n\t\t\t\t\tEnter the required book : ");
	scanf("%s",b_name);
	printf("\n\t\t\t\t\tEnter no of units : ");
	scanf("%d",&unit_book);
	printf("\n\t\t\t\t\tEnter contact no : ");
	scanf("%ld",&num);
	strcpy(newnode->person_name,p_name);
	strcpy(newnode->book_name,b_name);
	newnode->contact = num;
	newnode->units = unit_book;

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = newnode;
    }
    else
    {
        q->rear->next = newnode;
        q->rear = newnode;
    }

}

// Function to remove a value from given queue q
void deQueue(struct Queue* q)
{
    struct QNode *temp=q->front;
    if(q->rear == q->front)
    {
        q->front=NULL;
        q->rear=NULL;
    }
    else
    {
        q->front=q->front->next;
    }
    free(temp);


}
void displayList(struct Queue* q)
{
	struct QNode *temp;
	temp=q->front;
	char n[10]="NAME",b[10]="BOOK",c[10]="CONTACT";
	printf("\n\n\n\t\t\t\t\t%-20s%-20s%-20s\n",n,b,c);
	while(temp!=NULL)
	{
		printf("\n\n\t\t\t\t\t%-20s%-20s%-20d\n",temp->person_name,temp->book_name,temp->contact);
		temp=temp->next;
	}
}

void store()
{

            printf("\n\n\n\t\t\t\t\t\tSYMPHONY BOOK STORE");
            printf("\n\n\t\t\t\tHigh Cliff Building, Sector 5,Vile Parle(West),Mumbai");
            printf("\n\n\t\t\t\t\tContact no: 34980237823/82379202932");
            printf("\n========================================================================================================================");
}
int main()
{
    int option=0;
    struct Queue* qp=createQueue();
    while(option!=5)
    {
        system("cls");
        system("COLOR F1");
        printf("\n\n\n\t\t\t\t\t %c WELCOME TO SYMPHONY BOOK STORE %c \n ",(char)174,(char)175);
        printf("\n\n\t\t\t\tHigh Cliff Building, Sector 5,Vile Parle(West),Mumbai");
        printf("\n\n\t\t\t\t\tContact no: 34980237823/82379202932");
        printf("\n\n\n************************************************************************************************************************");
        printf("\n\n\t\t\t\t\t\t\tMAIN MENU\n\n");
        printf("************************************************************************************************************************");
        printf("\n\n\t\t\t\t\t\t\t1.SELL A BOOK\n");
        printf("\t\t\t\t\t\t\t2.STOCK ANALYSIS\n");
        printf("\t\t\t\t\t\t\t3.PURCHASE RECORD\n");
        printf("\t\t\t\t\t\t\t4.DEMAND LIST\n");
        printf("\t\t\t\t\t\t\t5.EXIT\n");
        printf("\n\n\t\t\t\t\t\t\tENTER YOUR CHOICE : ");
        scanf("%d",&option);
        switch(option)
        {
            //case 1 sell
            case 1:
                {
                    system("cls");
                    system("COLOR 0D");
                    printf("\n\n\n\t\t\t\t\t\tSYMPHONY BOOK STORE");
                    printf("\n\n\t\t\t\tHigh Cliff Building, Sector 5,Vile Parle(West),Mumbai");
                    printf("\n\n\t\t\t\t\tContact no: 34980237823/82379202932");
                    printf("\n========================================================================================================================");
                    struct stock* var=srch();
                    if(var !=NULL)
                    {
                        sell(var);
                    }
                    else
                    {
                        printf("\n\n\n\t\t\t\t\t\tNot available");
                    }
                }
                //end of sell
                printf("\n\n\n\t\t\t\t\t\tPress any key to continue");
                getch();
            break;
            //case 2 stock
            case 2:
                {
                    system("cls");
                    system("COLOR F4");
                    printf("\n\n\n\t\t\t\t\t\tSYMPHONY BOOK STORE");
                    printf("\n\n\t\t\t\tHigh Cliff Building, Sector 5,Vile Parle(West),Mumbai");
                    printf("\n\n\t\t\t\t\tContact no: 34980237823/82379202932");
                    printf("\n========================================================================================================================");
                    printf("\n\n\n\t\t\t\t\t\t1.Insert a new book\n\n\t\t\t\t\t\t2.Search a book\n\n\t\t\t\t\t\t3.Refill books\n");
                    int opt1;
                    printf("\n\n\t\t\t\t\t\tENTER YOUR CHOICE : ");
                    scanf("%d",&opt1);
                    switch(opt1)
                    {
                        case 1:
                            {
                                system("cls");
                                printf("\n\n\n\t\t\t\t\t\tSYMPHONY BOOK STORE");
                                printf("\n\n\t\t\t\tHigh Cliff Building, Sector 5,Vile Parle(West),Mumbai");
                                printf("\n\n\t\t\t\t\tContact no: 34980237823/82379202932");
                                printf("\n========================================================================================================================");
                                insert_new_book();
                                printf("\n\n\t\t\t\t\t\tPress any key to continue");
                                getch();
                            }
                        break;
                        case 2:
                            {
                                system("cls");
                                 printf("\n\n\n\t\t\t\t\t\tSYMPHONY BOOK STORE");
                                 printf("\n\n\t\t\t\tHigh Cliff Building, Sector 5,Vile Parle(West),Mumbai");
                                 printf("\n\n\t\t\t\t\tContact no: 34980237823/82379202932");
                                printf("\n========================================================================================================================");
                                struct stock *temp1=srch();
                                if (temp1!=NULL)
                                {
                                    display_book(temp1);
                                }
                                else
                                {
                                    printf("\n\t\t\t\t\t\tNot in stock");
                                }
                                printf("\n\n\t\t\t\t\t\tPress any key to continue");
                getch();
                            }
                        break;
                        case 3:
                            {
                                system("cls");
                                printf("\n\n\n\t\t\t\t\t\tSYMPHONY BOOK STORE");
                                printf("\n\n\t\t\t\tHigh Cliff Building, Sector 5,Vile Parle(West),Mumbai");
                                printf("\n\n\t\t\t\t\tContact no: 34980237823/82379202932");
                                printf("\n========================================================================================================================");
                                refill();
                                printf("\n\n\t\t\t\t\t\tPress any key to continue");
                getch();
                            }

                    }
                }
                //end of stock
                break;
                //case 3 purchase record
                case 3:
                    {
                        system("cls");
                        system("COLOR 0E");
                        printf("\n\n\n\t\t\t\t\t\tSYMPHONY BOOK STORE");
                        printf("\n\n\t\t\t\tHigh Cliff Building, Sector 5,Vile Parle(West),Mumbai");
                        printf("\n\n\t\t\t\t\tContact no: 34980237823/82379202932");
                        printf("\n========================================================================================================================");
                        printf("\n\n\n\n\t\t\t\t\t\t\tSALES RECORD");
                        printf("\n\n\t\t\t\t\t\t1.Display records\n\n\t\t\t\t\t\t2.Insert in purchase\n");
                        int opt2;
                        printf("\n\t\t\t\t\t\tENTER YOUR CHOICE : ");
                        scanf("%d",&opt2);
                        switch(opt2)
                        {
                            case 1:
                                {
                                    system("cls");
                                     printf("\n\n\n\t\t\t\t\t\tSYMPHONY BOOK STORE");
                                     printf("\n\n\t\t\t\tHigh Cliff Building, Sector 5,Vile Parle(West),Mumbai");
                                     printf("\n\n\t\t\t\t\tContact no: 34980237823/82379202932");
                                     printf("\n========================================================================================================================");
                                     printf("\n\n\n\n\t\t\t\t\t\t\tSALES RECORD");
                                    display_record();
                                    printf("\n\n\t\t\t\t\t\tPress any key to continue");
                getch();
                                }
                            break;
                            case 2:
                                {
                                    system("cls");
                                    int n_book;
                                    printf("\n\n\n\t\t\t\t\t\tSYMPHONY BOOK STORE");
                                    printf("\n\n\t\t\t\tHigh Cliff Building, Sector 5,Vile Parle(West),Mumbai");
                                    printf("\n\n\t\t\t\t\tContact no: 34980237823/82379202932");
                                    printf("\n========================================================================================================================");
                                    struct stock *var2=srch();
                                    printf("\n\n\t\t\t\t\t\tEnter the number of units : ");
                                    scanf("%d",&n_book);
                                    if(var2!=NULL)
                                        push(var2,n_book);
                                    else
                              {
                                  printf("\n\n\t\t\t\t\t\tNot in stock\n");
                              }
                                        printf("\n\n\t\t\t\t\t\tPress any key to continue");
                getch();
                                }

                        }

                    }
                    //end of purchase
                break;
                //case 4 demand list
                case 4:
                    {
                        system("cls");
                        system("COLOR F0");
                        printf("\n\n\n\t\t\t\t\t\tSYMPHONY BOOK STORE");
                        printf("\n\n\t\t\t\tHigh Cliff Building, Sector 5,Vile Parle(West),Mumbai");
                        printf("\n\n\t\t\t\t\tContact no: 34980237823/82379202932");
                        printf("\n========================================================================================================================");
                        printf("\n\n\n\t\t\t\t\t\t1.Display demand list\n\n\t\t\t\t\t\t2.Insert demand\n\n\t\t\t\t\t\t3.Clear demand\n");
                        int opt3;
                        printf("\n\n\t\t\t\t\t\tEnter your choice : ");
                        scanf("%d",&opt3);
                        switch(opt3)
                        {
                            case 1:
                                {
                                    system("cls");
                                    store();
                                    displayList(qp);
                                    printf("\n\n\t\t\t\t\t\tPress any key to continue");
                        getch();
                                }
                            break;
                            case 2:
                                {
                                    system("cls");
                                    store();
                                    enQueue(qp);
                                    printf("\n\n\t\t\t\t\t\tPress any key to continue");
                        getch();
                                }
                            break;
                            case 3:
                                {
                                    system("cls");
                                    store();
                                    struct stock *temp3=start;
                                    while(temp3!=NULL)
                                    {
                                        if(strcmp(qp->front->book_name,temp3->book_name)==0 )
                                        {
                                            if(temp3->quantity>= qp->front->units)
                                            {
                                                push(temp3,qp->front->units);
                                                temp3->quantity=temp3->quantity-(qp->front->units);
                                                deQueue(qp);
                                                break;
                                            }
                                            else{
                                                printf("\n\n\t\t\t\t\t\tPlease refill stock!\n");
                                                break;
                                            }
                                        }
                                        else
                                        {
                                           temp3=temp3->next;
                                        }

                                    }
                                    printf("\n\n\t\t\t\t\t\tPress any key to continue");
                                    getch();
                                    break;


                                }

                        }
                    }
                    //end of demand list


        }
        //end of  switch

    }

}
























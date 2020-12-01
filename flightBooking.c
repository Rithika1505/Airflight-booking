#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define AVAILABLE 1
#define NOT_AVAILABLE 0

//***Creating a Structure array for storing the details of passengers(Economy class)***
struct details
{
    char book_id[100];
    int ticket_price;
    int row_no;
    char seat_name;
    char meal;
};
char arrangement_f101_eco[100][100];
int availabilty_f101_eco[100][100];
struct details booking_details_f101_eco[100][100];
char arrangement_f101_bus[100][100];
int availabilty_f101_bus[100][100];
struct details booking_details_f101_bus[100][100];
int right_seats_f101_eco=4;
int left_seats_f101_eco=3;
int mid_seats_f101_eco=4;
int tot_rows_f101_eco=20;
int right_seats_f101_bus=2;
int left_seats_f101_bus=2;
int mid_seats_f101_bus=3;
int tot_rows_f101_bus=12;
int business_ticket_cost=2000;
int economy_ticket_cost=1000;

int col;

int count=0;int k=0;
//***Booking of tickets***
void init();
void SeatAvl(int flight_no,char clas);
void ticket_booking(int fno,char clas,int row,char seat,int meal);
    int main()
    {
        int row,i;char seat;int no,meal;
        int choice;
        char bookingid[100];int fno;
        char clas;
        init();
        printf("1.Booking\n2.Cancellation\n3.SeatAvailibity\n4.Meal ordered\n5.Display");
        do
        {
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
               printf("Enter the flight no\nAvailable Flights :\n1.F101\n2.F102\nEnter 101 or 102:\n");
               scanf("%d",&fno);
               printf("Select your Class :\n1.Economy(E)\n2.Business(B)\nEnter B or E:\n");
               scanf(" %c",&clas);
               if(clas=='E')
               {
                    printf("Welcome to Economy class booking!\n");
                    SeatAvl(fno,clas);
                    printf("Enter the no of seats\n");
                    scanf("%d",&no);
                    for(i=0;i<no;i++)
                    {
                      printf("Enter the seat row in number and seat name as char: ");
                      scanf("%d %c",&row,&seat);
                      printf("\nDo you req Meal ?\n Cost of meal is INR 200\n");
                      printf("1.Yes\n2.No\n");
                      scanf("%d",&meal);
                      ticket_booking(fno,clas,row,seat,meal);
                      economy_ticket_cost+=100;
                      //printf("\nSuccessfully booked\n");
                     //SeatAvl(fno,clas);
                    }
               }
                   else   if(clas=='B')
                   {
                    printf("Welcome to BUSINESS class booking!\n");
                    SeatAvl(fno,clas);
                    printf("Enter the no of seats\n");
                    scanf("%d",&no);
                    for(i=0;i<no;i++)
                    {
                      printf("Enter the seat row in number and seat name as char: ");
                      scanf("%d %c",&row,&seat);
                      printf("\nDo you req Meal ?\n Cost of meal is INR 200\n");
                      printf("1.Yes\n2.No\n");
                      scanf("%d",&meal);
                      ticket_booking(fno,clas,row,seat,meal);
                      business_ticket_cost+=100;
                      //printf("\nSuccessfully booked\n");
                      SeatAvl(fno,clas);
                     }
                   }


               break;
            case 2:
               printf("Ticket Cancellation:\n");
               printf("Enter the booking id: ");
               scanf("%s\n",bookingid);
               //TicketCancel(bookingid);
               break;
            case 3:
               break;
            case 4:
               printf("Seat nos for which meal ordered:\n");
               //seatMeal();
               break;
            case 5:
               printf("Enter the booking id: ");
               scanf("%s\n",bookingid);
              // print(bookingid);
               break;
            default:
               exit(0);
        }
        }while(choice!=0);
return 0;
    }
void ticket_booking(int fno,char clas,int row,char seat,int meal)
{
    char id1[]="f101";
    char no_str[100];
    static int unique_no=1;
    if(fno==101)
    {
        if(clas=='E')
        {
            booking_details_f101_eco[row][seat-65].row_no=row;
            booking_details_f101_eco[row][seat-65].seat_name=seat;
            booking_details_f101_eco[row][seat-65].ticket_price=economy_ticket_cost;
            if(arrangement_f101_eco[row][seat-65]=='A'||arrangement_f101_eco[row][seat-65]=='W')
                 booking_details_f101_eco[row][seat-65].ticket_price += 100;
            if(meal==1)//YES
            {
                booking_details_f101_eco[row][seat-65].meal='Y';
                 booking_details_f101_eco[row][seat-65].ticket_price += 200;
            }
            else
            {
                booking_details_f101_eco[row][seat-65].meal='N';
            }
            strcpy(booking_details_f101_eco[row][seat-65].book_id,id1);
            strcat(booking_details_f101_eco[row][seat-65].book_id,"E");
            sprintf(no_str,"%d",unique_no);
            strcat(booking_details_f101_eco[row][seat-65].book_id,no_str);
            unique_no++;
            availabilty_f101_eco[row][seat-65]=NOT_AVAILABLE;
            printf("\nBooked Sucessfuly\n");
            printf("FLIGHT NO F%d :\n",fno);
            printf("Economy Class: \n");
            printf("%d %c\n",row,seat);
            printf("Booking ID : %s\n",booking_details_f101_eco[row][seat-65].book_id);
        }
        else if(clas=='B')
        {
            booking_details_f101_bus[row][seat-65].row_no=row;
            booking_details_f101_bus[row][seat-65].seat_name=seat;
            booking_details_f101_bus[row][seat-65].ticket_price=business_ticket_cost;
            if(arrangement_f101_bus[row][seat-65]=='A'||arrangement_f101_bus[row][seat-65]=='W')
                 booking_details_f101_bus[row][seat-65].ticket_price += 100;
            if(meal==1)//YES
            {
                booking_details_f101_bus[row][seat-65].meal='Y';
                 booking_details_f101_bus[row][seat-65].ticket_price += 200;
            }
            else
            {
                booking_details_f101_bus[row][seat-65].meal='N';
            }
            strcpy(booking_details_f101_bus[row][seat-65].book_id,id1);
            strcat(booking_details_f101_bus[row][seat-65].book_id,"E");
            sprintf(no_str,"%d",unique_no);
            strcat(booking_details_f101_bus[row][seat-65].book_id,no_str);
            unique_no++;
            availabilty_f101_bus[row][seat-65]=NOT_AVAILABLE;
            printf("\nBooked Sucessfuly\n");
            printf("FLIGHT NO F%d :\n",fno);
            printf("Business Class: \n");
            printf("%d %c\n",row,seat);
            printf("Booking ID : %s\n",booking_details_f101_bus[row][seat-65].book_id);

        }

    }
}
void init()
{
   int i,j,col_seats;
col_seats=right_seats_f101_eco+left_seats_f101_eco+mid_seats_f101_eco;
for(i=0;i<tot_rows_f101_eco;i++)
{
   for(j=0;j<col_seats;j++)
   {
       if(j==0||j==col_seats-1)
        arrangement_f101_eco[i][j]='W';
       else
       {
           arrangement_f101_eco[i][j]='M';
       }
       availabilty_f101_eco[i][j]=AVAILABLE;
   }
}
for(i=0;i<tot_rows_f101_eco;i++)
{
   for(j=0;j<col_seats;j++)
   {
       if(j==right_seats_f101_eco||j==right_seats_f101_eco-1
            ||j==(right_seats_f101_eco+left_seats_f101_eco)||
              (j==right_seats_f101_eco+left_seats_f101_eco+1))
       arrangement_f101_eco[i][j]='A';
   }
}

col_seats=right_seats_f101_bus+left_seats_f101_bus+mid_seats_f101_bus;
for(i=0;i<tot_rows_f101_bus;i++)
{
   for(j=0;j<col_seats;j++)
   {
       if(j==0||j==col_seats-1)
        arrangement_f101_bus[i][j]='W';
       else
       {
           arrangement_f101_bus[i][j]='M';
       }
       availabilty_f101_bus[i][j]='N';
   }
}
for(i=0;i<tot_rows_f101_bus;i++)
{
   for(j=0;j<col_seats;j++)
   {
       if(j==right_seats_f101_bus||j==right_seats_f101_bus-1
            ||j==(right_seats_f101_bus+left_seats_f101_bus)||
              (j==right_seats_f101_bus+left_seats_f101_bus+1))
       arrangement_f101_bus[i][j]='A';
   }
}

}
void SeatAvl(int flight_no,char clas)
{
   int i,j;
        int tot_cols;
   if(flight_no==101)
        {
            if(clas=='E')
            {
                tot_cols=(left_seats_f101_eco+right_seats_f101_eco+mid_seats_f101_eco);
                printf("\nEconomy Class \n   ");
                for(j=0 ;j<tot_cols;j++)
                {
                   if(j==left_seats_f101_eco+1||j==left_seats_f101_eco+mid_seats_f101_eco+1)
                        printf(" ");
                    printf("%c ",j+65);
                }
                printf("\n");
                for(i=0;i<tot_rows_f101_eco;i++)
                {
                    printf("%2d ",i+1);
                    for(j=0;j<tot_cols;j++)
                    {
                       if(j==left_seats_f101_eco+1||j==left_seats_f101_eco+mid_seats_f101_eco+1)
                        printf(" ");
                       if(availabilty_f101_eco[i][j]==AVAILABLE)
                        printf("%c ",arrangement_f101_eco[i][j]);
                       else
                         printf("X ");
                    }
                    printf("\n");
                }
            }
            else if(clas=='B')
            {
                tot_cols=(left_seats_f101_bus+right_seats_f101_bus+mid_seats_f101_bus);
                printf("\nBusiness Class \n   ");
                for(j=0 ;j<tot_cols;j++)
                {
                   if(j==left_seats_f101_bus+1||j==left_seats_f101_bus+mid_seats_f101_bus+1)
                        printf(" ");
                    printf("%c ",j+65);
                }
                printf("\n");
                for(i=0;i<tot_rows_f101_bus;i++)
                {
                    printf("%2d ",i+1);
                    for(j=0;j<tot_cols;j++)
                    {
                       if(j==left_seats_f101_bus+1||j==left_seats_f101_bus+mid_seats_f101_bus+1)
                        printf(" ");
                       if(availabilty_f101_bus[i][j]==AVAILABLE)
                        printf("%c ",arrangement_f101_bus[i][j]);
                       else
                         printf("X ");
                    }
                    printf("\n");
                }
            }

        }
        printf("A-AISLE W-WINDOW M-MID X-BOOKED\n");

}

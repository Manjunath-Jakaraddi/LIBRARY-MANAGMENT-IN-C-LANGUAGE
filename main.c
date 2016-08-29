#include<stdio.h>
#include "studentheader.h"
#include<stdlib.h>
#include<windows.h>
COORD coord={0,0};
wel=0;
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void clrscr(void)
{
    system("cls");
}
struct date
{
  int dd,mm,yy;
};
struct issuebook
{
  int serialno,regno,bookid;
  struct date issuedate,duedate,returndate;
};
int main()
{
  int start;
  if(wel==0)
  {
      start=welcome();
      wel++;
  }
  int i;struct issuebook ib;
  char filename[]="c:\\turboc3\\finalp\\studinfo.txt";
  char filename1[]="c:\\turboc3\\finalp\\bookinfo.txt";
  char filename2[]="c:\\turboc3\\finalp\\issinfo.txt";
	gotoxy(20,3);
	printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\n\n\n\t\t\t\t\xDB\xDB\xDB\xDB\xB2 1. STUDENT");
	gotoxy(20,7);
	printf("\n\n\n\t\t\t\t\xDB\xDB\xDB\xDB\xB2 2. BOOKS");
	gotoxy(20,9);
	printf("\n\n\n\t\t\t\t\xDB\xDB\xDB\xDB\xB2 3. ISSUE BOOKs");
	gotoxy(20,11);
	printf("\n\n\n\t\t\t\t\xDB\xDB\xDB\xDB\xB2 4. RETURN BOOKS");
        gotoxy(20,13);
        printf("\n\n\n\t\t\t\t\xDB\xDB\xDB\xDB\xB2 5. REPORTS");
        gotoxy(20,15);
	printf("\n\n\n\t\t\t\t\xDB\xDB\xDB\xDB\xB2 6. Close Application");
	gotoxy(20,17);
	printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,22);
	printf("\t\tEnter your choice:");
    scanf("%d",&i);fflush(stdin);
        switch(i)
        {
		case 1:clrscr();
		       student();fflush(stdin);
		       break;
        case 2:clrscr();fflush(stdin);
		       book();
		       break;
        case 3:clrscr();
               issuebooks(&ib);
                if(ib.serialno==-1)
                {
                    printf("\nStudent registration number invalid");
                }
                else if(ib.serialno==-2)
                {
                    printf("\nBook not found");
                }
                else if(ib.serialno==-3)
                {
                    printf("\nBook not availaible");
                }
                else
                {
                    fflush(stdin);
                    updateissuebook(filename2,ib);
                    ustud(filename,ib.regno,0);
                    ubook(filename1,ib.bookid);
                }
                fflush(stdin);
                break;
        case 4:clrscr();fflush(stdin);
                retbook(filename2,filename,filename1);break;
        case 5:clrscr();
                FILE *fp;
                fp=fopen(filename2,"r");
                printf("\t  SERIAL NO | REG NO | BOOK ID | ISSUE DATE | RETURN DATE | DUE DATE\n");
                while(1)
                {
                   fread(&ib,sizeof(ib),1,fp);
                   if(feof(fp))
                     break;
                   displayissuebook(ib);
                 }
                 fclose(fp);
                printf("\n\t\tPRESS ENTER TO GO TO MAIN MENU :");
                getch();clrscr();fflush(stdin);
                 break;
        case 6:
                clrscr();
                close();
            exit(0);
                default:fflush(stdin);main();
        }fflush(stdin);main();clrscr();close();return(0);
}




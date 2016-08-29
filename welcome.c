#include<windows.h>
int welcome(void)
{
    int i;
    char password[]="manju1232";
    char pass[25];
    char ch;
    clrscr();
    char wel1[]="         APPLICATION FOR THE LIBRARY MANAGMENT";
    char wel4[]="USER NAME : MANJUNATH";
    char wel5[]="PASSWORD  : ";
    gotoxy(55,4);
    for(i=0;(ch=wel1[i])!='\0';i++)
    {
        Sleep(20);
        printf("%c",ch);
    }
    gotoxy(70,17);
    for(i=0;(ch=wel4[i])!='\0';i++)
    {
        Sleep(20);
        printf("%c",ch);
    }
    gotoxy(70,20);
    for(i=0;(ch=wel5[i])!='\0';i++)
    {
        Sleep(20);
        printf("%c",ch);
    }
    i=0;
    while(ch!=13)
   {
	ch=getch();
	putch('*');
    if(ch!=13)
    {
       pass[i] = ch;
       i++;
    }
   }
   pass[i] = '\0';
    if(strcmp(pass,password)!=0)
    {
        gotoxy(65,24);
        printf("SORRY , INCORRECT PASSWORD ");
        gotoxy(60,25);
        printf("PRESS ANY KEY TO CLOSE APPLICATION");
        getch();
        return(-1);
    }
    gotoxy(75,26);
    printf("WELCOME TO : ");
    gotoxy(63,28);
    printf("   LIBRARY MANAGMENT APPLICATION");
    gotoxy(75,29);
    printf("  V-1.2.3");
    gotoxy(75,34);
    printf("LOADING.....");
    gotoxy(30,35);
    ch=-80;
    for(i=0;i<110;i++)
    {
        printf("%c",ch);
    }
    gotoxy(30,35);
    for(i=0;i<110;i++)
    {
        Sleep(20);
        if(i>35&&i<45)
            Sleep(100);
        if(i>75&&i<79)
            Sleep(750);
        printf("\xDB");
    }
    gotoxy(30,39);
    printf("PRESS ANY KEY TO CONTINUE ");
    getch();
    clrscr();
    return(0);
}
void close(void)
{
    char ch;
    int i;
    char wel2[]="DEVELOPER : MANJUNATH JAKARADDI";
    char wel3[]="E-MAIL : manjunath180397@gmail.com";
    char wel4[]="PHONE NUMBER : 96*******40";
    gotoxy(70,4);
    printf("EXIT APPLICATION ");
    gotoxy(60,10);
    for(i=0;(ch=wel2[i])!='\0';i++)
    {
        Sleep(20);
        printf("%c",ch);
    }
    gotoxy(60,14);
    for(i=0;(ch=wel3[i])!='\0';i++)
    {
        Sleep(20);
        printf("%c",ch);
    }
    gotoxy(60,18);
    for(i=0;(ch=wel4[i])!='\0';i++)
    {
        Sleep(20);
        printf("%c",ch);
    }
    gotoxy(50,24);
    printf("CLOSING APPLICATION IN 3 SECONDS ");
    for(i=0;i<20;i++)
    {
        Sleep(80);
        printf(".");
    }
}

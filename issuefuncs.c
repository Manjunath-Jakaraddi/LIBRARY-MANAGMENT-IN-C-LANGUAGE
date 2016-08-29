#include<stdio.h>
struct date
{
  int dd,mm,yy;
};
struct issuebook
{
  int serialno,regno,bookid;
  struct date issuedate,duedate,returndate;
};

struct student
{
  int regno,nobissued;
  char name[20],address[200],contact[15];
};
struct book
{
  int bookid,price,availaible;
  char name[50],author[200],publisher[100];
};
void readdate(struct date *pd)
{
  char ch='-';fflush(stdin);
  scanf("%d",&pd->dd);putchar(ch);scanf("%d",&pd->mm);putchar(ch);scanf("%d",&pd->yy);
  fflush(stdin);
}
void incdate(struct date *p)
{
  p->dd++;
  if((p->mm==2)&&((p->yy%4)!=0)&&(p->dd==29))
  {
    p->dd=01;
    p->mm=03;
  }
  else if((p->mm==02)&&((p->yy%4)==0)&&(p->dd==30))
  {
    p->dd=01;
    p->mm=03;
  }
  else if(((p->mm==4)||p->mm==9)||((p->mm==6)||(p->mm==11))&&(p->dd==31))
  {
    p->dd=01;
    p->mm++;
  }
  else if(p->dd==32)
  {
    p->dd=01;
    p->mm++;
    if(p->mm==13)
    {
      p->mm=01;
      p->yy++;
    }
  }
}
struct date adddate(struct date dt,int nod)
{
  while(nod!=0)
  {
    incdate(&dt);
    nod--;
  }
return(dt);
}
void searchregno(char filename[],int *rno)
{
  FILE *fp;
  fp=fopen(filename,"r");
  while(1)
  {
    struct student s;
    fread(&s,sizeof(s),1,fp);
    if(feof(fp))
    {
       *rno=-1;
       break;
    }
    if(s.regno==*rno)
      break;
  }
fclose(fp);
}
void searchbookid(char filename1[],int *bid)
{
  struct book b;
  FILE *fp;
  fp=fopen(filename1,"r");
  while(1)
  {
    fread(&b,sizeof(b),1,fp);
    if(feof(fp))
    {
       *bid=-1;
       break;
    }
    if(b.bookid==*bid)
    {
       if(b.availaible==0)
       break;
       else
        {
          *bid=-2;
           break;
         }
    }
}
fclose(fp);
}
void issuebooks(struct issuebook *ib)
{
  fflush(stdin);
  char filename[]="c:\\turboc3\\finalp\\studinfo.txt";
  char filename1[]="c:\\turboc3\\finalp\\bookinfo.txt";
  printf("\nEnter the serial number :");
  scanf("%d",&ib->serialno);fflush(stdin);
  printf("\nEnter the registration number of student :");fflush(stdin);
  scanf("%d",&ib->regno);fflush(stdin);
  searchregno(filename,&ib->regno);
  if(ib->regno==-1)
  {
    ib->serialno=-1;
    return;
  }
  printf("Enter the book id :");
  scanf("%d",&ib->bookid);
  searchbookid(filename1,&ib->bookid);
  if(ib->bookid==-1)
  {
    ib->serialno=-2;
    return;
  }
  if(ib->bookid==-2)
  {
    ib->serialno=-3;
    return;
  }
  printf("\nEnter issue date dd/mm/yy :");
  readdate(&ib->issuedate);fflush(stdin);
  ib->duedate=adddate(ib->issuedate,15);fflush(stdin);
  ib->returndate.dd=00;
  ib->returndate.mm=00;
  ib->returndate.yy=00;
}
void displayissuebook(struct issuebook ib)
{
   fflush(stdin);
   printf("\t      %d     |  %d     |  %d      |  %d-%d-%d  |  %d-%d-%d | %d-%d-%d\n",ib.serialno,ib.regno,ib.bookid,ib.issuedate.dd,ib.issuedate.mm,ib.issuedate.yy,ib.returndate.dd,ib.returndate.mm,ib.returndate.yy,ib.duedate.dd,ib.duedate.mm,ib.duedate.yy);
}

void updateissuebook(char filename2[],struct issuebook ib)
{
  FILE *fp;fflush(stdin);
  fp=fopen(filename2,"a");
    fwrite(&ib,sizeof(struct issuebook),1,fp);
    printf("\nissued book record added");
    fclose(fp);getch();
}
void ustud(char filename[],int rno,int i)
{
  struct student s;
  FILE *fp,*fp1;
  fp1=fopen("c:\\turboc3\\files\\temp5.txt","w");
  fp=fopen(filename,"r");
  while(1)
  {
    fread(&s,sizeof(s),1,fp);
    if(feof(fp))
     break;
    if(s.regno==rno)
    {
      if(i==0)s.nobissued++;
      if(i==1)s.nobissued--;
      fwrite(&s,sizeof(s),1,fp1);
    }else
       fwrite(&s,sizeof(s),1,fp1);
  }
fclose(fp);
fclose(fp1);
remove(filename);
rename("c:\\turboc3\\files\\temp5.txt",filename);
}
void ubook(char filename1[],int bid)
{
  struct book b;
  FILE *fp,*fp1;
  fp=fopen(filename1,"r");
  fp1=fopen("c:\\turboc3\\files\\temp6.txt","w");
  while(1)
  {
    fread(&b,sizeof(b),1,fp);
    if(feof(fp))
      break;
    if(b.bookid==bid)
    {
      if(b.availaible==0)
          {b.availaible=1;printf("\nISSUE BOOK");}
       else
         {b.availaible=0;printf("\nBOOK RETURNED");}
       fwrite(&b,sizeof(b),1,fp1);
     }else
        fwrite(&b,sizeof(b),1,fp1);
clrscr();
  }
fclose(fp);
fclose(fp1);
remove(filename1);
rename("c:\\turboc3\\files\\temp6.txt",filename1);
printf("\n\nPRESS ENTER FOR MAIN MENU");
fflush(stdin);clrscr();main();
}
void retbook(char filename2[],char filename[],char filename1[])
{
   struct issuebook ib;
   FILE *fp;
   int regno;
   printf("\nEnter the serial number of student returning book");
  scanf("%d",&regno);fflush(stdin);
   fp=fopen(filename2,"r+");
   while(1)
   {
     fread(&ib,sizeof(ib),1,fp);
     if(feof(fp))
       break;
     if(ib.serialno==regno)
     {
       printf("\nEnter the return date");
       readdate(&ib.returndate);fseek(fp,sizeof(ib)*(-1),1);fwrite(&ib,sizeof(ib),1,fp);
        ustud(filename,ib.regno,1);
        ubook(filename1,ib.bookid);
       break;
     }
    }fflush(stdin);
    fclose(fp);
}

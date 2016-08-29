#include<stdio.h>
struct book
{
  int bookid,price,availaible;
  char name[50],author[200],publisher[100];
};

void readnewbook(struct book *b)
{
    fflush(stdin);
    printf("\t\t\t\tENTER BOOK DETAILS\n\n");
    printf("\t1 : BOOK ID   :=>");
    scanf("%d",&b->bookid);
    fgets(b->name,50,stdin);
    printf("\t2 : price   :=>");
    scanf("%d",&b->price);
    printf("\t3 : NAME   :=>");
    fgets(b->name,50,stdin);
    fgets(b->name,50,stdin);
    printf("\t4 : AUTHOR   :=>");
    fgets(b->author,200,stdin);
    printf("\t5 : PUBLISHER   :=>");
    fgets(b->publisher,100,stdin);
    b->availaible=0;
}
void displaybook(struct book b)
{
    printf("\t1 : BOOK ID : %d\n",b.bookid);
    printf("\t2 : PRICE : %d\n",b.price);
    printf("\t3 : NAME : %s",b.name);
    printf("\t4 : Author : %s",b.author);
    printf("\t5 : PUBLISHER : %s",b.publisher);
    printf("\t6 : AVAILAIBILITY : ");
    if(b.availaible==0)
      printf("book availaible");
    else
       printf("book not availaible");
}
void addbook(char filename1[],struct book b)
{
   FILE *fp;
   fp=fopen(filename1,"a");
   fwrite(&b,sizeof(struct book),1,fp);
   printf("\nbook record added\n");
   fclose(fp);
}
int searchbook(char filename1[],struct book *pb,int bid)
{
  FILE *fp;
  int flag=0;
  fp=fopen(filename1,"r");
  while(1)
  {
    fread(pb,sizeof(struct book),1,fp);
    if(feof(fp))
      break;
    if(bid==pb->bookid)
     {
       flag++;
       break;
     }
  }
fclose(fp);
return(flag);
}
void modifybook(struct book *b)
{
   char ch=getchar();
   printf("\nbook id  : %d ",b->bookid);
   printf("\nprice : %d",b->price);
   printf("\nmodify price : [Y/N]");
   ch=getchar();
   if(ch=='y')
   {
      printf("\nenter new price");
      scanf("%d",&b->price);
      ch=getchar();
    }
    else
       ch=getchar();
   printf("\nname : %s",b->name);
   printf("\nmodify name : [Y/N]");
   ch=getchar();
   if(ch=='y')
   {
      printf("\nenter new name :");
      fgets(b->name,50,stdin);
      fgets(b->name,50,stdin);
   }
   else
    ch=getchar();
   printf("\nauthor : %s",b->author);
   printf("\nmodify author : [Y/N]");
   ch=getchar();
   if(ch=='y')
   {
      printf("\nenter new author :");
      fgets(b->author,200,stdin);
      fgets(b->author,200,stdin);
   }
    else
     ch=getchar();
   printf("\npublisher : %s",b->publisher);
   printf("\nmodify publisher : [Y/N]");
   ch=getchar();
   if(ch=='y')
   {
      printf("\nenter new publisher :");

      fgets(b->publisher,100,stdin);
      fgets(b->publisher,100,stdin);
   }
else
ch=getchar();
}
void updatebook(char filename1[],int bid)
{
  struct book x,b;
  int flag=0;
  FILE *fp,*fp1;
  fp=fopen(filename1,"r+");
  fp1=fopen("c:\\turboc3\\files\\temp3.txt","w");
  while(1)
  {
    fread(&b,sizeof(struct book),1,fp);
    if(feof(fp))
      break;
       if(bid==b.bookid)
       {  flag++;
          printf("file found\n");
          modifybook(&b);
          fseek(fp,0,0);
         while(1)
         {
           fread(&x,sizeof(x),1,fp);
           if(feof(fp))
           break;
           if(b.bookid==x.bookid)
           fwrite(&b,sizeof(x),1,fp1);
           else
	   fwrite(&x,sizeof(x),1,fp1);
          }
       }
  }
    if(flag==0)
      printf("file not found\n");
      fclose(fp);
      fclose(fp1);
      remove(filename1);
      rename("c:\\turboc3\\files\\temp3.txt",filename1);
}
void deletebook(char filename1[],int bid)
{
  int flag=0;
  struct book b;
  FILE *fp,*fp1;
  fp=fopen(filename1,"r");
  fp1=fopen("c:\\turboc3\\files\\temp4.txt","w");
  while(1)
   {
     fread(&b,sizeof(b),1,fp);
     if(feof(fp))
       break;
     if(b.bookid==bid)
      flag++;
     else
       fwrite(&b,sizeof(b),1,fp1);
   }
fclose(fp);
fclose(fp1);
if(flag)
{
  printf("\nnumber of records deleted :%d",flag);
  remove(filename1);
  rename("c:\\turboc3\\files\\temp4.txt",filename1);
}
else
{
   printf("\nno such records exist to be deleted");
   remove("c:\\turboc3\\files\\temp4.txt");
}
}
void book()
{
  struct book b;
  struct book *p;
  int i,a,bid;
  char ch;
  char filename1[]="c:\\turboc3\\finalp\\bookinfo.txt";
  printf("\n\t\t\t\tBOOK MENU");
  printf("\n\n\t\t1:NEW BOOK\n\n\t\t2:SEARCH BOOK\n\n\t\t3:MODIFY BOOK\n\n\t\t4:DELETE BOOK\n\n\t\t5:EXIT TO MAIN MENU\n");
  printf("\n\n\n\t\tENTER YOUR CHOICE : ");
  scanf("%d",&i);
  switch(i)
  {
    case 1:clrscr();
           readnewbook(&b);getch();
           addbook(filename1,b);

           break;
    case 2:clrscr();
           printf("Enter the book id to be searched : ");
           scanf("%d",&bid);
           if(searchbook(filename1,&b,bid))
           {
              printf("FILE FOUND\n");
              displaybook(b);
            }
             else
                  printf("FILE NOT FOUND\n");

             break;
    case 3:clrscr();
           printf("Enter the book id to be modified : ");
           scanf("%d",&bid);
           updatebook(filename1,bid);

           break;
    case 4:clrscr();
           printf("enter the book id to be deleted\n");
           scanf("%d",&bid);
           deletebook(filename1,bid);

           break;
    default:clrscr();main();
  }fflush(stdin);book();
}

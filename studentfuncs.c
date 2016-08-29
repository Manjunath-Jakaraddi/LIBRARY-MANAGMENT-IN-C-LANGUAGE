#include<stdio.h>
struct student
{
  int regno,nobissued;
  char name[20],address[200],contact[15];
};

void readnewstudent(struct student *s)
{
    fflush(stdin);
    printf("\t\t\t\tENTER STUDENT DETAILS\n\n");
    printf("\t1 : REGISTRATION NUMBER   :=>");

    scanf("%d",&s->regno);
    printf("\t2 : NAME   :=>");
    fgets(s->name,20,stdin);
    fgets(s->name,20,stdin);
    printf("\t3 : ADDRESS   :=>");
    fgets(s->address,200,stdin);
    printf("\t4 : CONTACT   :=>");
    fgets(s->contact,15,stdin);
    s->nobissued=0;
}

void displaystudent(struct student s)
{
    printf("\t1 : REGISTRATION NUMBER : %d\n",s.regno);
    printf("\t2 : NAME : %s",s.name);
    printf("\t3 : ADDRESS : %s",s.address);
    printf("\t4 : CONTACT NUMBER : %s",s.contact);
    printf("\t5 : number of books issued : %d",s.nobissued);
}

void addstudent(char filename[],struct student s)
{
   FILE *fp;
   fp=fopen(filename,"a");fflush(stdin);
   fwrite(&s,sizeof(struct student),1,fp);
   printf("\nstudent record added\n");
   fclose(fp);
}

int searchstudent(char filename[],struct student *ps,int rno)
{
  FILE *fp;
  int flag=2;
  fp=fopen(filename,"r");
  while(1)
  {
    fread(ps,sizeof(struct student),1,fp);
    if(feof(fp))
      break;
    if(rno==ps->regno)
     {
       flag=1;
       break;
     }
  }
fclose(fp);
return(flag);
}

void modifystudent(struct student *s)
{
   char ch=getchar();
   printf("\nregistration number %d ",s->regno);
   printf("\nname : %s",s->name);
   printf("\nmodify name : [Y/N]");
   ch=getchar();
   if(ch=='y')
   {
      printf("\nenter new name :");
      fgets(s->name,20,stdin);
      fgets(s->name,20,stdin);
   }
   else
    ch=getchar();
   printf("\naddress : %s",s->address);
   printf("\nmodify address : [Y/N]");
   ch=getchar();
   if(ch=='y')
   {
      printf("\nenter new address :");

      fgets(s->address,200,stdin);
      fgets(s->address,200,stdin);
   }
    else
     ch=getchar();
   printf("\ncontact number : %s",s->contact);
   printf("\nmodify contact number : [Y/N]");
   ch=getchar();
   if(ch=='y')
   {
      printf("\nenter new contact number :");

      fgets(s->contact,15,stdin);
      fgets(s->contact,15,stdin);
   }
}

void updatestudent(char filename[],struct student s)
{
  struct student x;
  FILE *fp,*fp1;
  fp=fopen(filename,"r");
  fp1=fopen("c:\\turboc3\\files\\temp1.txt","w");
  while(1)
    {
      fread(&x,sizeof(x),1,fp);
      if(feof(fp))
       break;
      if(s.regno==x.regno)
        fwrite(&s,sizeof(x),1,fp1);
      else
	 fwrite(&x,sizeof(x),1,fp1);
    }
fclose(fp);
fclose(fp1);
remove(filename);
rename("c:\\turboc3\\files\\temp1.txt",filename);
}

void deletestudent(char filename[],int rno)
{
  int flag=0;
  struct student s;
  FILE *fp,*fp1;
  fp=fopen(filename,"r");
  fp1=fopen("c:\\turboc3\\files\\temp2.txt","w");
  while(1)
   {
     fread(&s,sizeof(s),1,fp);
     if(feof(fp))
       break;
     if(s.regno==rno)
      flag++;
     else
       fwrite(&s,sizeof(s),1,fp1);
   }
fclose(fp);
fclose(fp1);
if(flag)
{
  printf("\nnumber of records deleted :%d",flag);
  remove(filename);
  rename("c:\\turboc3\\files\\temp2.txt",filename);
}
else
{
   printf("\nno such records exist to be deleted");
   remove("c:\\turboc3\\files\\temp2.txt");
}
}
void student()
{
    struct student s;
  char filename[]="c:\\turboc3\\finalp\\studinfo.txt";
  char ch;
  int rno,i,a;
  printf("\n\t\t\t\tSTUDENT MENU");
  printf("\n\n\t\t1:NEW STUDENT REGISTRATION\n\n\t\t2:SEARCH REGISTRATION\n\n\t\t3:MODIFY REGISTRATION\n\n\t\t4:DELETE REGISTRATION\n\n\t\t5:EXIT TO MAIN MENU\n");
  printf("\n\n\n\t\tENTER YOUR CHOICE :");
  scanf("%d",&i);
  switch(i)
  {
    case 1:clrscr();
           readnewstudent(&s);
           addstudent(filename,s);fflush(stdin);
           break;
    case 2:clrscr();fflush(stdin);
           printf("Enter the roll number to be searched : ");
           scanf("%d",&rno);fflush(stdin);
           if(searchstudent(filename,&s,rno)==1)
           {
              printf("FILE FOUND\n");
              displaystudent(s);
            }
             else
                  printf("FILE NOT FOUND\n");
            break;
     case 3:clrscr();
           printf("Enter the roll number to be modified : ");
           scanf("%d",&rno);
           if(searchstudent(filename,&s,rno))
           {
             modifystudent(&s);
             updatestudent(filename,s);
           }
           else
              printf("FILE NOT FOUND\n");

           break;
     case 4:clrscr();
          printf("Enter the roll number to be deleted : ");
          scanf("%d",&rno);
          deletestudent(filename,rno);
           break;
    default:clrscr();main();
  }student();
}



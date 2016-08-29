struct student
{
  int regno,nobissued;
  char name[20],address[200],contact[15];
};

void readnewstudent(struct student*);

void displaystudent(struct student);

void addstudent(char[],struct student);

int searchstudent(char[],struct student*,int);

void modifystudent(struct student*);

void updatestudent(char[],struct student);

void deletestudent(char[],int);

void student(void);

struct book
{
  int bookid,price,availaible;
  char name[50],author[200],publisher[100];
};

void readnewbook(struct book*);

void displaybook(struct book);

void addbook(char[],struct book);

int searchbook(char[],struct book*,int);

void modifybook(struct book*);

void updatebook(char[],int);

void deletebook(char[],int);

void book(void);

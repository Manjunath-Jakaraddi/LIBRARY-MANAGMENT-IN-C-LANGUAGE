struct date
{
  int dd,mm,yy;
};
struct issuebook
{
  int serialno,regno,bookid;
  struct date issuedate,duedate,returndate;
};

void readdate(struct date*);

void incdate(struct date*);

struct date adddate(struct date,int);

void searchregno(char[],int*);

void searchbookid(char[],int*);

void issuebooks(struct issuebook*);

void displayissuebook(struct issuebook);

void updateissuebook(char[],struct issuebook);

void ustud(char[],int,int);

void ubook(char[],int);

void rep(char[]);

void retbook(char[],char[],char[]);



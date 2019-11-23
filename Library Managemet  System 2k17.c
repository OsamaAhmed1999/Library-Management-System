#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct book_record{
	int book_id;
	char book_name[50];
}book;

struct student_record{
	int student_id;
	int semester;
	char name[30];
	char course[10];
	char book[20];
}student;

int main()
{
	printf("\n\n\t\t\t\t***UMAER BASHA INSTITUTE OF INFORMATION TECHNOLOGY(UBIT)****\n");
	printf("\n\n\t\t\t\t\t\t**SEMINAR LIBRARY**\n\n\n\n");
    int choice;
    printf("\t\t\t1-FOR STUDENT SECTION ");
    printf("\t\t\t2-FOR BOOK SECTION \n\n");
    printf("\t\t\t3-FOR ISSUE SECTION");
    printf("\t\t\t4-FOR RETURN SECTION \n\n");
    printf("\t\t\t\t\t\t5-DEVELOPED BY");
    printf("\n\nEnter Your Choice: ");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
    case 1:
        Student_Section();
        break;
    case 2:
        Book_Section();
        break;
    case 3:
        Issue_Section();
        break;
    case 4:
        Return_Section();
        break;
    case 5:
    	printf("\n\n\t\tIt's developed by:\n\n\n\n\t\t\tCOURSE SUPERVISOR: MISS YUSRA MANSOOR\n\n\t\t\t1-OSAMA AHMED\t\t{BSCS-1st YEAR}\n\n\t\t\t2-SHAHBAZ ALI\t\t{BSCS 1st YEAR}\n\n\t\t\t3-MUHAMMAD FAHAD\t{BSCS-1st YEAR}");
    }
}

int Student_Section()
{
    FILE *fp;
    char update;
    char del;
    int choice;
    printf("\n\n\t\t\t\t**{STUDENT SECTION}**");
    printf("\n\n\t\t1-To MAKE NEW STUDENT RECORD OR ADD NEW STUDENT \n\n");
    printf("\t\t2-To SEARCH,UPDATE OR DELETE STUDENT RECORD \n\n");

    printf("Enter Your Choice:");
    scanf("%d",&choice);
    if(choice>2)
    {
        printf("Please Enter Correct Choice");
        scanf("%d",&choice);
    }
    system("cls");
    switch(choice)
    {
//STUDENT RECORD
       case 1:
           Student_record();
        break;
//SEARCH
        case 2:
            Search_in_File_Student("project.txt");
//UPDATE
            printf("\nDo You Want To Update It..?(Y/N)");
            update=getch();
            printf("\n\n");
            if(update=='y'||update=='Y')
            {
                Update();
            }
//DELETE
            printf("\nDo You Want To Delete It?(Y/N)");
            del=getch();
            printf("\n\n");
            if(del=='y'||del=='Y')
            {
                Delete_Student();
            }
            break;
            fclose(fp);
    }
}

int Student_record()
{
    int n,i;
    char another='y';
    FILE *fp;
    int choice;
    FILE *fileptr1, *fileptr2;
    char c;

    printf("\n\t\tRECORD OF STUDENT\n\n");

    fileptr1 = fopen("project.txt", "r");
    fileptr2 = fopen("replica.c", "w");

    c = getc(fileptr1);
    while (c != EOF)
    {
        putc(c, fileptr2);
        printf("%c",c);
        c = getc(fileptr1);
    }

    printf("\nPLEASE ENTER NEW STUDENT INFORMATION\n");
    while(another=='y'||another=='Y')
    {
     if(i>0)
        {
            printf("\n");
        }
        printf("\nBook Issued (In Capital Word):NONE\n");
        printf("NAME (In Capital Words):");
        scanf("%s",&student.name);
        printf("STUDENT ID:");
        scanf("%d",&student.student_id);
        printf("SEMESTER:");
        scanf("%d",&student.semester);
        printf("COURSE:");
        scanf("%s",&student.course);

        fprintf(fileptr2,"Book Issued:NONE\n");
        fprintf(fileptr2,"Name:%s\n",student.name);
        fprintf(fileptr2,"Student ID:%d\n",student.student_id);
        fprintf(fileptr2,"Semester:%d\n",student.semester);
        fprintf(fileptr2,"Course:%s\n\n",student.course);

        printf("\nADD ANOTHER RECORD (Y/N)");
        fflush(stdin);
        another=getch();
        if(another=='n'||another=='N')
        {
            system("cls");
        }
    }

    fclose(fileptr1);
    fclose(fileptr2);
    remove("project.txt");
    rename("replica.c", "project.txt");

    fileptr1 = fopen("project.txt", "r");

    c = getc(fileptr1);
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fileptr1);
    }
    fclose(fileptr1);
}

int Search_in_File_Student(char *fname )
{

	int line_num = 1;
	int find_result = 0;
	char temp[512];
	int i=0;
	char another;

	char *search[20];
	printf("\n\t\t\tSEARCH STUDENT\n\n");
	printf("Enter Name Of Student (In Capital Words):");
    scanf("%s",&search);


    FILE *fp;
    fp=fopen(fname, "r");
	if(fp==NULL)
	{
		return(-1);
	}
	while(fgets(temp, 512, fp) != NULL)
        {
            if(strstr(temp,search))
            {
			    printf("A Match Found On Line: %d\n", line_num);
                find_result++;
                printf("\n");
            }
            if(find_result>0)
            {
                if(i<4)
                {
                    printf("%s", temp);
                    i++;
                }
            }
            line_num++;
        }
	if(find_result == 0)
        {
            printf("\nSorry, couldn't find a match.\n");
        }
	if(fp)
        {
            fclose(fp);
        }

   	return(0);
}

int Update()
{
    FILE *fileptr1, *fileptr2;
    char filechar[40];
    char c;
    int delete_line, temp = 1;
    int choice;
    int choice2;

    fileptr1 = fopen("project.txt", "r");

    printf("\nWhat Do You Want To Update In This Line?\n\n");
    printf("1-For Semester \n\n");
    printf("2-For Course press \n\n");
    printf("Enter Choice:");
    scanf("%d",&choice);


    printf(" \nEnter Line Number:");
    scanf("%d", &delete_line);
    switch(choice)
    {
    case 1:
        delete_line=delete_line+2;
        choice2=3;
        break;
    case 2:
        delete_line=delete_line+3;
        choice2=4;
        break;
    }

    rewind(fileptr1);

    fileptr2 = fopen("replica.c", "w");
    c = getc(fileptr1);
    while (c != EOF)
    {
        if (c == '\n')
        {
            temp++;
        }

        if (temp != delete_line)
        {
            putc(c, fileptr2);
        }
        else
        {
            while ((c = getc(fileptr1)) != '\n')
            {
            }

         switch(choice2)
         {
        case 3:
            printf("\nSemester:");
            fflush(stdin);
            fprintf(fileptr2,"\nSemester:");
            while ((c = getchar()) != '\n')
                {
                    putc(c, fileptr2);
                }
            fputs("\n", fileptr2);
            break;

        case 4:
            printf("\nCourse:");
            fflush(stdin);
            fprintf(fileptr2,"\nCourse:");
            while ((c = getchar()) != '\n')
                {
                    putc(c, fileptr2);
                }

            fputs("\n", fileptr2);
            break;
         }
            temp++;
        }

        c = getc(fileptr1);
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove("project.txt");
    rename("replica.c", "project.txt");
    fileptr1 = fopen("project.txt", "r");

    c = getc(fileptr1);
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fileptr1);
    }

    fclose(fileptr1);
}

void Delete_Student()
{
FILE *fileptr1, *fileptr2;
    char filechar[40];
    char c;
    int delete_line, temp = 1;
    int i=0,j=0;


    fileptr1 = fopen("project.txt", "r");

    c = getc(fileptr1);
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fileptr1);
    }

    printf(" \nEnter Above Line Number:");
    scanf("%d", &delete_line);
    delete_line=delete_line-1;

    rewind(fileptr1);

    fileptr2 = fopen("replica.c", "w");
    c = getc(fileptr1);
    while (c != EOF)
    {
        if (c == '\n')
        {
            temp++;
        }

        if (temp != delete_line)
        {
            putc(c, fileptr2);
        }
        else
        {
			if(i<5)
            {
                delete_line++;
            }
            while ((c = getc(fileptr1)) != '\n')
            {
            }
            temp++;
        }
        c = getc(fileptr1);
    }

    fclose(fileptr1);
    fclose(fileptr2);
    remove("project.txt");
    rename("replica.c", "project.txt");
    fileptr1 = fopen("project.txt", "r");

    c = getc(fileptr1);
    while (c != EOF)
    {
        printf("%c", c);

        c = getc(fileptr1);
    }

    fclose(fileptr1);
}

int  Book_Section()
{
    int choice;
    char del;
    printf("\n\n\t\t\t\t**{BOOKS SECTION}**\n\n\n");
    printf("\t\t1-TO MAKE A BOOK RECORD OR ADD NEW BOOK\n\n");
    printf("\t\t2-TO SEARCH OR DELETE BOOK\n");

    printf("\nEnter Your Choice:");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
    case 1:
        Book_record();
        break;
    case 2:
//SEARCH
        Search_in_File_Book("book.txt");
//DELETE
        printf("\nDo You Want To Delete It?(Y/N)");
        del=getch();
        printf("\n\n");
        if(del=='y'||del=='Y')
        {
            Delete_Book();
        }
        break;

    }
}

int Book_record()
{
    FILE *fp;
    char another='y';
    int choice;
    FILE *fileptr1, *fileptr2;
    char c;
    printf("\n\t\tRECORD OF BOOKS\n\n");

    fileptr1 = fopen("book.txt", "r");
    fileptr2 = fopen("replica.c", "w");

    c = getc(fileptr1);
    while (c != EOF)
    {
        putc(c, fileptr2);
        printf("%c",c);
        c = getc(fileptr1);
    }
    printf("PLEASE ENTER NEW BOOK INFORMATION\n\n");
    while(another=='y'||another=='Y')
    {
        printf("Book Name (In Capital Words):");
        scanf("%s",&book.book_name);
        printf("Book ID:");
        scanf("%d",&book.book_id);

        fprintf(fileptr2,"Book Name:%s\n",book.book_name);
        fprintf(fileptr2,"Book ID:%d\n\n",book.book_id);

        printf("\nAdd Another New Book (Y/N)");
        fflush(stdin);
        another=getch();
        if(another=='n'||another=='N')
        {
            system("cls");
        }
        printf("\n\n");
    }

    fclose(fileptr1);
    fclose(fileptr2);
    remove("book.txt");
    rename("replica.c", "book.txt");

    fileptr1 = fopen("book.txt", "r");

    c = getc(fileptr1);
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fileptr1);
    }

    fclose(fileptr1);
}

int Search_in_File_Book(char *fname )
{
	int line_num = 1;
	int find_result = 0;
	char temp[512];
	int i=0;
	char another;

	char *search[20];
	printf("\n\t\t\tSEARCH BOOK\n\n");
	printf("Enter Book Name (In Capital Words):");
    scanf("%s",&search);

    FILE *fp;
    fp=fopen(fname, "r");
	if(fp==NULL)
	{
		return(-1);
	}
	while(fgets(temp, 512, fp) != NULL)
        {
            if(strstr(temp,search))
            {
			    printf("'A Match Found'\nLine Number: %d\n", line_num);
                find_result++;
                printf("\n");
            }
            if(find_result>0)
            {
                if(i<2)
                {
                    printf("%s", temp);
                    i++;
                }
            }
            line_num++;
        }
	if(find_result == 0)
        {
            printf("\nSORRY COULDN'T FIND A MATCH.\n");
        }
	if(fp)
        {
            fclose(fp);
        }

   	return(0);
 }

void Delete_Book()
{
    FILE *fileptr1, *fileptr2;
    char filechar[40];
    char c;
    int delete_line, temp = 1;
    int i=0,j=0;


    fileptr1 = fopen("book.txt", "r");

    printf(" \nPlease Enter Above Line Number:");
    scanf("%d", &delete_line);
    printf("\n");

    rewind(fileptr1);

    fileptr2 = fopen("replica.c", "w");

    c = getc(fileptr1);
    while (c != EOF)
    {
        if (c == '\n')
        {
            temp++;
        }

        if (temp != delete_line)
        {
            putc(c, fileptr2);
        }
        else
        {
			if(i<2)
            {
                delete_line++;
            }
            while ((c = getc(fileptr1)) != '\n')
            {
            }
            temp++;
        }
        c = getc(fileptr1);
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove("book.txt");
    rename("replica.c", "book.txt");
    fileptr1 = fopen("book.txt", "r");

    c = getc(fileptr1);
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fileptr1);
    }

    fclose(fileptr1);
}

int Issue_Section()
{
	char *search[20];
	char another;
    printf("\n\n\t\t\t\t\t**{ISSUE BOOK SEECTION}**\n\n");
	printf("\n\t\t\tCHECK AVAILABILITY OF BOOK\n\n");
	printf("Enter Book Name (In Capital Words):");
    scanf("%s",&search);

    Check_In_Book_Record(search);
    Check_In_Student_Record(search);

    printf("\nDo You Want To Issue Book(Y/N)");
    fflush(stdin);
    another=getch();
    printf("\n");
    if(another=='y'||another=='Y')
    {
        Delete_Book();
        system("cls");
        Search_Student_Issue_Book();
        Update_Book();
    }
    printf("\n\n");
}

int Check_In_Book_Record(char *search[20])
{
    int line_num = 1;
	int find_result = 0;
	char temp[512];
	int i=0;

    FILE *fp;
    fp=fopen("book.txt", "r");
	if(fp==NULL)
	{
		return(-1);
	}
	while(fgets(temp, 512, fp) != NULL)
        {
            if(strstr(temp,search))
            {
			    printf("'A Match Found'\nLine Number: %d\n\n", line_num);
                find_result++;
                printf("\nAvailable To Issue\n\n");
            }
            if(find_result>0)
            {
                if(i<2)
                {

                    printf("%s", temp);
                    i++;
                }
            }
            line_num++;
        }
	if(find_result == 0)
        {
            printf("\nNot Present In Book Record\n");
        }
	if(fp)
        {
            fclose(fp);
        }
    return(0);
}

int Check_In_Student_Record(char *search[20])
{
	int line_num = 1;
	int find_result = 0;
	char temp[512];
	int i=0;
	char another;

    FILE *fp;
    fp=fopen("project.txt", "r");
	if(fp==NULL)
	{
		return(-1);
	}
	while(fgets(temp, 512, fp) != NULL)
        {
            if(strstr(temp,search))
            {
			    printf("'A Match Found'\nLine Number: %d\n\n", line_num);
                find_result++;
                printf("This Book Is Issued\n");
            }
            if(find_result>0)
            {
                if(i<5)
                {
                    printf("%s", temp);
                    i++;
                }
            }
            line_num++;
        }
	if(find_result == 0)
        {
            printf("\nNot Issue To Any Student\n");
        }
	if(fp)
        {
            fclose(fp);
        }
   	return(0);
}

int Search_Student_Issue_Book()
{
    int line_num = 1, line_num2;
	int find_result = 0;
	char temp[512];
	char temp2[512];
	int i=0,count=1;
	char another;

	char *search[20];
	printf("\n\t\t\tSEARCH STUDENT FOR ISSUING BOOK\n\n");
	printf("Enter Name Of Student (In Capital Words):");
    scanf("%s",&search);

    FILE *fp,*fk;
    fp=fopen("project.txt", "r");
	if(fp==NULL)
	{
		return(-1);
	}
	while(fgets(temp, 512, fp) != NULL)
        {
            if(strstr(temp,search))
            {
			    printf("A Match Found On Line: %d\n", line_num);
                line_num2=line_num;
                find_result++;
                printf("\n");
            }
            line_num++;
        }
        if(find_result == 0)
        {
            printf("\nSorry, couldn't find a match.\n");
        }

    fk=fopen("project.txt","r");
    line_num2=line_num2-1;
    while(fgets(temp, 512, fk) != NULL)
    {
        if(count==line_num2)
        {
            if(find_result>0)
            {
                if(i<5)
                {
                    printf("%s", temp);
                    i++;
                }
            }
        }
        if(i==0)
        {
            count++;
        }
    }
    fclose(fp);
    fclose(fk);
   	return(0);
}

int Update_Book()
{
    FILE *fileptr1, *fileptr2;
    char filechar[40];
    char c;
    int delete_line, temp = 1;

    fileptr1 = fopen("project.txt", "r");
    printf("\n\t\tUpdate Book Information\n\n");
    printf(" \nEnter Line Number:");
    scanf("%d", &delete_line);
    delete_line=delete_line-1;

    rewind(fileptr1);

    fileptr2 = fopen("replica.c", "w");
    c = getc(fileptr1);
    while (c != EOF)
    {
        if (c == '\n')
        {
            temp++;
        }
        if (temp != delete_line)
        {
            putc(c, fileptr2);
        }
        else
        {
            while ((c = getc(fileptr1)) != '\n')
            {
            }
            printf("\nBook:");
            fflush(stdin);
            fprintf(fileptr2,"\nBook:");

            while ((c = getchar()) != '\n')
            {
                putc(c, fileptr2);
            }
            fputs("\n", fileptr2);
            temp++;
        }
        c = getc(fileptr1);
    }

    fclose(fileptr1);
    fclose(fileptr2);
    remove("project.txt");
    rename("replica.c", "project.txt");
    fileptr1 = fopen("project.txt", "r");

    c = getc(fileptr1);
    while (c != EOF)
    {
        printf("%c", c);
        c = getc(fileptr1);
    }
    fclose(fileptr1);
}

int Return_Section()
{
	printf("\t\t\t\t**{RETURN BOOK SECTION}**");
    Search_Student_Issue_Book();
    Update_Book();
    Book_record();
}

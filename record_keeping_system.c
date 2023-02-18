#include <stdio.h>
#include<stdlib.h>

struct student
{
    int stuid;
    char name[80];
    char last[80];
    float eng;
    float sci;
    float comp;
    float arts;
    float maths;
    char address[40];
    float avrg;
    char phone[15];
    char dob[15];
};

void accept(struct student[], int);
void display(struct student[], int);
void search(struct student[], int, int);


int main()
{
    struct student data[20];
    int n, choice, stuid;

    printf("  ************************************\n");
    printf("  * WELCOME TO STUDENT RECORD SYSTEM *\n");
    printf("  ***********************************\n");

    do
    {

        printf("\nResult Menu :\n");
        printf("\nPress 1 to create a record\n");
        printf("Press 2 to display all records.\n");
        printf("Press 3 to search a record.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
            case 1: printf("Number of records you want to enter? : ");
                    scanf("%d", &n);
                    accept(data, n);
                    break;

            case 2: display(data, n);
                    break;

            case 3: printf("Enter Student ID to search : ");
                    scanf("%d", &stuid);
                    search(data, n, stuid);
                    break;
        }
        getch();
    system("cls");
    }
    while (choice != 0);

    return 0;
}

void accept(struct student list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\nEnter data for Record #%d", i + 1);

        printf("\nEnter Student ID : ");
        scanf("%d", &list[i].stuid);
        fflush(stdin);
        printf("Enter first name : ");
        gets(list[i].name);

        printf("Enter last name : ");
        gets(list[i].last);

        printf("Enter DOB as (DD/MM/YYYY) : ");
        scanf("%s", list[i].dob);

        printf("Enter phone number : ");
        scanf("%s", list[i].phone);

        printf("Enter address : ");
        scanf("%s", list[i].address);

        printf("Enter marks of English : ");
        scanf("%f", &list[i].eng);

        printf("Enter marks of Maths : ");
        scanf("%f", &list[i].maths);

        printf("Enter marks of Science : ");
        scanf("%f", &list[i].sci);

        printf("Enter marks of Computing : ");
        scanf("%f", &list[i].comp);

        printf("Enter marks of Arts : ");
        scanf("%f", &list[i].arts);

        list[i].avrg = (list[i].eng+list[i].maths+list[i].sci+list[i].comp+list[i].arts)/5;

        printf("\n\n*****************************\n");
        printf("   RECORD AS BEEN SAVED\n");
        printf("   PRESS ENTER TO EXIT\n");
        printf("*****************************\n");
        getch();
    }
    system("cls");
}

    void display(struct student list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\n\n\nStudent ID : %d\n", list[i].stuid);
        printf("Name       : %s %s\n", list[i].name, list[i].last);
        printf("DOB        : %s\n", list[i].dob);
        printf("Address    : %s\n", list[i].address);
        printf("Phone number: %s\n", list[i].phone);
        printf("English    : %.2f\n", list[i].eng);
        printf("Maths      : %.2f\n", list[i].maths);
        printf("Science    : %.2f\n", list[i].sci);
        printf("Computing  : %.2f\n", list[i].comp);
        printf("Arts       : %.2f\n", list[i].arts);
        printf("Average    : %.2f\n", list[i].avrg);

    }

    getch();
    system("cls");
}

void search(struct student list[80], int s, int number)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].stuid == number)
        {
            printf("=====================\n");
            printf("*STUDENT INFORMATION*\n");
            printf("=====================\n");
            printf("Student ID  : %d\n", list[i].stuid);
            printf("Name        : %s %s\n", list[i].name, list[i].last);
            printf("DOB         : %s\n", list[i].dob);
            printf("Address     : %s\n", list[i].address);
            printf("Phone number: %s\n", list[i].phone);
            printf("English     : %.2f\n", list[i].eng);
            printf("Maths       : %.2f\n", list[i].maths);
            printf("Science     : %.2f\n", list[i].sci);
            printf("Computing   : %.2f\n", list[i].comp);
            printf("Arts        : %.2f\n", list[i].arts);
            printf("Average     : %.2f\n", list[i].avrg);
            printf("\n\nCourse that can be taken\n");

            if(list[i].avrg>3.8){
                printf("Medicine.\nElectrical, chemical, or mechanical engineering.\nArchitecture.\nNursing.\nAccounting.\nArts.");
            }
            if(list[i].avrg>3.3 && list[i].avrg<3.8){
                printf("Electrical, chemical, or mechanical engineering.\nArchitecture.\nNursing.\nAccounting.\nArts.");
            }
            if(list[i].avrg==3.2){
                printf("Architecture.\nNursing.\nAccounting.\nArts.");
            }
            if(list[i].avrg==3.1){
                printf("Accounting.\nArts.");
            }
            if(list[i].avrg<3.2){
                printf("Arts.\n");
            }

            return ;
        }
        getch();
        system("cls");
    }
    printf("Record not Found\n");
}

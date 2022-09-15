#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Employee 
{
    char Name[40];
    int E_ID;
    float Salary;
};
struct Employee p;
long int size=sizeof(p);
FILE *fp,*ft;
void add_Details()
{
    printf("Enter the Name of the Employee:");
    scanf("%s",p.Name);
    printf("Enter unique E_ID of the Employee:");
    scanf("%d",&p.E_ID);
    printf("Enter Salary of the Employee:");
    scanf("%f",&p.Salary);
    fwrite(&p,size,1,fp);
}
void delete_Details_having_EmployeeName()
{
    char pName[40];
    printf("Enter employee name that has to be deleted in the details:");
    scanf("%s",pName);
    ft=fopen("temp.txt","wb");
    rewind(fp);
    while(fread(&p,size,1,fp)==1)
    {
        if(strcmp(p.Name,pName)!=0)
        {
            fwrite(&p,size,1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("data.txt");
    rename("temp.txt","data.txt");
    fp=fopen("data.txt","rb+");
}
void display()
{
    printf("\t\t\t\tDetails\t\t\t\t\t\t\n");
    rewind(fp);
    while(fread(&p,size,1,fp)==1)
    {
        printf("%s\t\t\t%d\t\t\t%f\n",p.Name,p.E_ID,p.Salary);
    }
}
void display_Details_having_EmployeeName()
{
    char pName[40];
    rewind(fp);
    printf("Enter Employee Name that has to be displayed in the details:");
    scanf("%s",pName);
    while(fread(&p,size,1,fp)==1)
    {
        if(strcmp(pName,p.Name)==0)
        {
            printf("%s\t\t\t%d\t\t\t%f\n",p.Name,p.E_ID,p.Salary);
        }
    }
}
void display_Details_having_Eid()
{
    int id;
    rewind(fp);
    printf("Enter Employee_ID to display in the details:");
    scanf("%d",&id);
    while(fread(&p,size,1,fp)==1)
    {
        if(id==p.E_ID)
        {
            printf("%s\t\t\t%d\t\t\t%f\n",p.Name,p.E_ID,p.Salary);
        }
    }
}
void modify_Details_having_EmployeeName()
{
    char pName[40];
    printf("Enter Employee Name that has to be modified in the details:");
    scanf("%s",pName);
    rewind(fp);
    while(fread(&p,size,1,fp)==1)
    {
        if(strcmp(pName,p.Name)==0)
        {
            printf("Enter modified Name of the employee:");
            scanf("%s",p.Name);
            printf("Enter modified id number of the employee:");
            scanf("%d",&p.E_ID);
            printf("Enter modified Salary of the employee");
            scanf("%f",&p.Salary);
            fseek(fp, -size, SEEK_CUR);
            fwrite(&p,size,1,fp);
            break;
        }
    }
}
int main()
{
    int e;
    fp=fopen("data.txt","wb+");
    if(fp==NULL)
    {
        printf("Cannot open the file");
        exit(1);
    }
    while(1)
    {
        printf("Enter your choice:\n1.Add a record\n2.delete a record\n3.display all data\n4.display data of employee using employee name\n5.display data of employee using id no\n6.modify record using name\n7.exit\n");
        scanf("%d",&e);
        switch(e)
        {
            case 1: add_Details();
                        break;
            case 2: delete_Details_having_EmployeeName();
                        break;
            case 3: display();
                        break;
            case 4: display_Details_having_EmployeeName();
                        break;
            case 5: display_Details_having_Eid();
                        break;
            case 6: modify_Details_having_EmployeeName();
                        break;
            case 7: exit(0);
                        break;
            default: printf("Invalid option");
        }
    }
}

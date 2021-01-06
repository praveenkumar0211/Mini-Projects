#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct date
{
    int dd;
    int mm;
    int yy;
};
struct patient
{
    int sno;
    char name[30];
    char pwd[30];
    char mail[50];
    char num[50];
    char problem[40];
    struct date dob;
    int age;
    int height;
    int weight;
    int bp;
    int bloodsugar;
    char docname[30];
    struct date lastcheckup;
};
struct doctor
{
	int sno;
	char dname[30];
	char pwd[30];
	char mail[50];
	char num[50];
	char specialisation[40];
	char degree[10];
	int a[15];
	char app[30][30];
	int numapp;
	int salary;
	int age;
};
void getdate(struct date *d)
{
printf("\nEnter today's date");
scanf(" %d %d %d",&d->dd,&d->mm,&d->yy);
}
void docavail1(char c[])
{
	FILE *f1;
	struct doctor a;
	f1=fopen("doc.txt","rb");
	struct date d;
	getdate(&d);
	fread(&a,sizeof(struct doctor),1,f1);
	int flag=0;
	printf("\nOther Doctors available today are:");
	while(!feof(f1))
	{		
		for(int i=0;i<15;i++)
		{
        	if(d.dd==a.a[i])
        	{
			if(strcmp(a.dname,c)!=0)
            			printf("\n\t %s",a.dname);
        	}
		}
        fread(&a,sizeof(struct doctor),1,f1);
	}
}
void docupdate(struct doctor *p)
{
int a=0;
	while(a==0)
	{
    printf("\nchoose the detail to be updated");
    printf("\n(1)User name\n(2)Password\n(3)Mail\n(4)Contact number\n(5)Specialisation\n(6)Degree\n(7Salary\n(8)Age\n(9)Available dates\n(10)Exit");
    int choose;
	scanf(" %d",&choose);
    switch(choose)
    {
        case 1: scanf(" %s",p->dname);break;
        case 2: scanf(" %s",p->pwd);break;
        case 3: scanf(" %s",p->mail);break;
        case 4: scanf(" %s",p->num);break;
        case 5: scanf(" %s",p->specialisation);break;
        case 6: scanf(" %s",p->degree);break;
        case 7: scanf(" %d",&p->salary);break;
        case 8: scanf(" %d",&p->age);break;
        case 9: for(int i=0;i<15;i++)
				{
					printf("\nEnter your %d th available date",i+1);
					scanf(" %d",&p->a[i]);
				}	
				break;
		case 10:	a=1;break;
        default:    printf("\nInvalid choice"); break;
    }
	}
}
void docsignup()
{
    char ch[100],b;
    int a;
    struct doctor p,q;
    FILE *f;
    int x=0;
    f=fopen("doc.txt","rb+");
    printf("\nWelcome to our hospital");
    jump:
    rewind(f);
    printf("\nplease enter a unique username:\t");
    scanf(" %s",p.dname);
    fread(&q,sizeof(struct doctor),1,f);
    while(!feof(f))
    {
        x+=1;
        if(strcmp(q.dname,p.dname)==0)
        {
            printf("\nThis user name already exists");
            goto jump;        
        }
        fread(&q,sizeof(struct doctor),1,f);
    }
    java:
    printf("\nplease enter a strong password:\t");
    scanf(" %s",p.pwd);
    if(strlen(p.pwd)<5)
    {
        printf("\nthis is a weak password give more than 5 letters");
        goto java;
    }
    printf("\nplease enter your mail id:\t");
    scanf(" %s",p.mail);
    printf("\nplease enter your contact number:\t");
    scanf(" %s",p.num);
    printf("\nplease enter your age:\t");
    scanf(" %d",&p.age);
    printf("\nplease enter your specialisation:\t");
    scanf(" %s",p.specialisation);
	for(int i=0;i<15;i++)
	{
		printf("\nEnter your %d th available date",i+1);
		scanf(" %d",&p.a[i]);
	}
    printf("\nplease enter your doctoral degree:\t");
    scanf(" %s",p.degree);
    p.sno=x;
    printf("\nplease enter your salary in INR:\t");
    scanf("%d",&p.salary);
    p.numapp=0;
    fwrite(&p,sizeof(struct doctor),1,f);
    fclose(f);
}
void docdetails(struct doctor a)
{
	printf("\nName: %s \nMail: %s \nContact Number: %s \nSpecialisation: %s \nDegree: %s \nAvailable dates: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d \nAge: %d \nNo. of appoinments remaining: %d \nSalary: Rs.%d" ,a.dname,a.mail,a.num,a.specialisation,a.degree,a.a[0],a.a[1],a.a[2],a.a[3],a.a[4],a.a[5],a.a[6],a.a[7],a.a[8],a.a[9],a.a[10],a.a[11],a.a[12],a.a[13],a.a[14],a.age,a.numapp,a.salary);
}
void patdet(char ch[])
{
	FILE *f1;
	f1=fopen("pat.txt","rb+");
	struct patient a;
	fread(&a,sizeof(struct patient),1,f1);
	int flag=0;
	printf("\nYour Patients details are:");
	while(!feof(f1))
	{		
        	if(strcmp(ch,a.docname)==0)
        	{
            		printf("\nName: %s\t Num: %s\tProblem: %s\tAge: %d",a.name,a.num,a.problem,a.age);
        	}
        fread(&a,sizeof(struct patient),1,f1);
	}
}
void appointments(struct doctor q)
{
	printf("\nYour appoinments are");
	for(int i=0;i<q.numapp;i++)
	{
		printf(" %s\n",q.app[i]);
		i+=1;
	}
}
int doclogin()
{
    FILE *f;
    f=fopen("doc.txt","rb+");
    rewind(f);
    printf("\nWelcome to our hospital");
    char uname[30],pwd[30];
    struct doctor q;
    int flag=0;
    fun:
    rewind(f);
    printf("\nplease enter your username:\t");
    scanf(" %s",uname);
    fread(&q,sizeof(struct doctor),1,f);
    while(!feof(f))
    {
        if(strcmp(q.dname,uname)==0)
        {
            flag=1;
            break;    
        }
        fread(&q,sizeof(struct doctor),1,f);
    }
    if(flag==0)
    {
        printf("\nThe given user name is invalid");
        goto fun;
    }
    int temp1=0;
    python:
    printf("\nplease enter your password:\t");
    scanf(" %s",pwd);
    if(strcmp(pwd,q.pwd)!=0)
    {
        temp1+=1;
        if(temp1<=5)
        {
            printf("\nWrong password. Try again");
            goto python;
        }
        else
        {
            printf("\nToo many unsuccessful attempts. Try later.");
            return 0;
        }
    }
    printf("\nHello %s",q.dname);
    int choice;
	fpos_t position;
    do
    {
        printf("\n\nEnter your choice:\n(1)Check your details\n(2)Check your patient details\n(3)Check your appoinments for today\n(4)Check availability of today's doctor\n(5)Update your details\n(6)Logout\n");
        scanf(" %d",&choice);
        switch(choice)
        {
            case 1: docdetails(q);
		    break;
            case 2: patdet(q.dname);break;
            case 3: appointments(q);
		    fseek(f,-(sizeof(struct patient)),SEEK_CUR);
                    fwrite(&q,sizeof(struct patient),1,f);
		    break;
            case 4:	fgetpos(f, &position);
					fclose(f);
					docavail1(q.dname);
					f=fopen("doc.txt","rb+");
					fsetpos(f,&position);
					break;
            case 5: docupdate(&q);
                    fseek(f,-(sizeof(struct patient)),SEEK_CUR);
                    fwrite(&q,sizeof(struct patient),1,f);
                    break;
            case 6: printf("\nLogging out");
                    break;
            default:    printf("\nInvalid file");break;
        }
    }while(choice!=6);
	fclose(f);
	return 1;
}
void patsignup()
{
    char ch[100],b;
    int a;
    struct patient p,q;
    FILE *f;
    f=fopen("pat.txt","rb+");
    printf("\nWelcome to our hospital");
    names:
    fseek(f,0,0);
    printf("\nplease enter a unique username:\t");
    scanf(" %s",p.name);
    fread(&q,sizeof(struct patient),1,f);
	int x=0;
    while(!feof(f))
    {
        x+=1;
        if(strcmp(q.name,p.name)==0)
        {
            printf("\nThis user name already exists");
            goto names;        
        }
        fread(&q,sizeof(struct patient),1,f);
    }
    password:
    printf("\nplease enter a strong password:\t");
    scanf(" %s",p.pwd);
    if(strlen(p.pwd)<5)
    {
        printf("\nthis is a weak password give more than 5 letters");
        goto password;
    }
    printf("\nplease enter your mail id:\t");
    scanf("%s",p.mail);
    printf("\nplease enter your contact number:\t");
    scanf("%s",p.num);
    printf("\nplease enter your date of birth\t");
    scanf("%d %d %d",&p.dob.dd,&p.dob.mm,&p.dob.yy);
    printf("\nplease enter your age:\t");
    scanf("%d",&p.age);
    printf("\nplease enter your height:\t");
    scanf("%d",&p.height);
    printf("\nplease enter your blood pressure:\t");
    scanf("%d",&p.bp);
    printf("\nplease enter your blood sugar level in mg/L:\t");
    scanf("%d",&p.bloodsugar);
    printf("\nplease enter your weight:\t");
    scanf("%d",&p.weight);
    printf("\nplease enter your problem:\t");
    scanf(" %s",p.problem);
    printf("\nplease enter your doctor name:\t");
    scanf(" %s",p.docname);
    p.sno=x;
    printf("\nplease enter your date of last checkup\t");
    scanf(" %d %d %d",&p.lastcheckup.dd,&p.lastcheckup.mm,&p.lastcheckup.yy);
    fwrite(&p,sizeof(p),1,f);
    fclose(f);
}
void details(struct patient q)
{
    printf("\nName: %s\nMail:\t %s\nContact number:\t %s\nProblem:\t %s\nDoctor:\t %s \nDOB:\t %d / %d / %d \nAge: %d\nHeight:\t %d \nWeight:\t %d\nBlood pressure:\t %d\nBlood Sugar Level: %d\nLast Date of Checkup:\t %d / %d / %d \nWARNING: PLEASE UPDATE YOUR DETAILS REGULARLY\n",q.name,q.mail,q.num,q.problem,q.docname,q.dob.dd,q.dob.mm,q.dob.yy,q.age,q.height,q.weight,q.bp,q.bloodsugar,q.lastcheckup.dd,q.lastcheckup.mm,q.lastcheckup.yy);
}
void checkupdate(struct date a)
{
    struct date d;
	getdate(&d);
	printf("\nYour last checkup date is %d / %d / %d",a.dd,a.mm,a.yy);
	printf("\nToday's date is %d / %d / %d",d.dd,d.mm,d.yy);
	if(a.mm<12)
		a.mm+=1;
	else
	{
		a.mm=1;
		a.yy+=1;
	}
    printf("\nYour next checkup date is %d / %d / %d",a.dd,a.mm,a.yy);
	int b=0;
	if(a.dd>d.dd){
		b=a.dd-d.dd;
	}
	else{
		if(a.mm>d.mm){
			if(a.mm==2){
				a.dd+=28;
				b=a.dd-d.dd;
			}
			else if(a.mm==4||a.mm==6||a.mm==9||a.mm==11){
				a.dd+=30;
				b=a.dd-d.dd;
			}
			else{
				a.dd+=31;
				b=a.dd-d.dd;
		}}
		else{
			a.dd+=31;
			b=a.dd-d.dd;
		}
	}
	printf("\nYour next checkup is in %d days",b);
}
void health(int bp,int bs)
{
    if(bp<80)
    {
        printf("\n you have low blood pressure");
    }
    else if(bp>120)
    {
        printf("\n you have high blood pressure");
    }
    else
    {
        printf("\n your blood pressure level is fine");
    }
    if(bs<80)
    {
        printf("\n you have low blood sugar level");
    }
    else if(bs>120)
    {
        printf("\n you have high blood sugar level");
    }
    else
    {
        printf("\n your blood sugar level is fine");
    }
}
void docavail(char c[])
{
	FILE *f1;
	struct doctor a;
	f1=fopen("doc.txt","r");
	struct date d;
	getdate(&d);
	fread(&a,sizeof(struct doctor),1,f1);
	int flag=0;
	printf("\nDoctors available today are:");
	while(!feof(f1))
	{		
		for(int i=0;i<15;i++)
		{
        	if(d.dd==a.a[i])
        	{
            		printf("\n\t %s",a.dname);
			if(strcmp(a.dname,c)==0)
				flag=1;
        	}
		}
        fread(&a,sizeof(struct patient),1,f1);
	}
	if(flag==1)
		printf("\n\n\nYOUR DOCTOR IS AVAILABLE TODAY");
	else
		printf("\n\n\nYOUR DOCTOR IS NOT AVAILABLE TODAY");
	fclose(f1);
}
void bmi(int h,int w)
{
    float a;
    a=10000;
    a*=w;
    a/=h;
    a/=h;
    if(a>25)
    {
        printf("\nYour BMI is %.2f. You are Obese.",a);
    }
    else if(a<18)
    {
        printf("\nYour BMI is %.2f. You are Lean.",a);
    }
    else
    {
        printf("\nYour BMI is %.2f. You are Normal.",a);
    }
}
void appoint(struct patient q)
{
	FILE *f1;
	struct doctor a;
	f1=fopen("doc.txt","rb+");
	struct date d;
	getdate(&d);
	fread(&a,sizeof(struct doctor),1,f1);
	printf("\nDoctors available today are:");
    while(!feof(f1))
    {
		for(int i=0;i<15;i++)
		{
			if(d.dd==a.a[i])
			{
				printf("\n\t %s",a.dname);
			}
		}
        fread(&a,sizeof(struct patient),1,f1);
    }
	char ch[30];
	int i=0;
	printf("\nPlease enter the doctor name you want appointment from:\t");
	scanf(" %s",ch);
	rewind(f1);
	fread(&a,sizeof(struct doctor),1,f1);
	while(!feof(f1))
    	{
		if(strcmp(ch,a.dname)==0)
		{
			i=a.numapp;
			strcpy(a.app[i],q.name);
			a.numapp+=1;
			fseek(f1,-(sizeof(struct doctor)),SEEK_CUR);
			fwrite(&a,sizeof(struct doctor),1,f1);
			break;
		}
		fread(&a,sizeof(struct doctor),1,f1);
	}
	fclose(f1);
	printf("\nYour appoinment is fixed with the doctor");
}	
void patupdate(struct patient *p)
{
	int a=0;
	while(a==0)
	{
    printf("\n\nchoose the detail to be updated");
    printf("\n(1)User name\n(2)Password\n(3)Mail\n(4)Contact number\n(5)Problem\n(6)Doctor name\n(7)DOB\n(8)Age\n(9)Height\n(10)Weight\n(11)Blood pressure\n(12)Blood sugar level\n(13)Last checkup date\n(14)Exit");
    int choose;
	scanf(" %d",&choose);
    switch(choose)
    {
        case 1: scanf(" %s",p->name);break;
        case 2: scanf(" %s",p->pwd);break;
        case 3: scanf(" %s",p->mail);break;
        case 4: scanf(" %s",p->num);break;
        case 5: scanf(" %s",p->problem);break;
        case 6: scanf(" %s",p->docname);break;
        case 7: scanf(" %d %d %d",&p->dob.dd,&p->dob.mm,&p->dob.yy);break;
        case 8: scanf(" %d",&p->age);break;
        case 9: scanf(" %d",&p->height);break;
        case 10:    scanf(" %d",&p->weight);break;
        case 11:    scanf(" %d",&p->bp);break;
        case 12:    scanf(" %d",&p->bloodsugar);break;
        case 13:    scanf(" %d %d %d",&p->lastcheckup.dd,&p->lastcheckup.mm,&p->lastcheckup.yy);
		case 14:	a=1;break;
        default:    printf("\nInvalid choice"); break;
    }
	}
}
int patlogin()
{
    FILE *f;
    f=fopen("pat.txt","rb+");
    rewind(f);
    printf("\nWelcome to our hospital");
    char uname[30],pwd[30];
    struct patient q;
    int flag=0;
    fun:
    rewind(f);
    printf("\nplease enter your username:\t");
    scanf(" %s",uname);
    fread(&q,sizeof(struct patient),1,f);
    while(!feof(f))
    {
        if(strcmp(q.name,uname)==0)
        {
            flag=1;
            break;    
        }
        fread(&q,sizeof(struct patient),1,f);
    }
    if(flag==0)
    {
        printf("\nThe given user name is invalid");
        goto fun;
    }
    int temp1=0;
    python:
    printf("\nplease enter your password:\t");
    scanf(" %s",pwd);
    if(strcmp(pwd,q.pwd)!=0)
    {
        temp1+=1;
        if(temp1<=5)
        {
            printf("\nWrong password. Try again");
            goto python;
        }
        else
        {
            printf("\nToo many unsuccessful attempts. Try later.");
            return 0;
        }
    }
    printf("\nHello %s",q.name);
    int choice;
    do
    {
        printf("\n\nEnter your choice:\n(1)Check your details\n(2)Check your blood pressure and blood sugar level\n(3)Check your BMI\n(4)Check availability of your doctor\n(5)Next checkup date\n(6)Update your details\n(7)Take an appoinment today\n(8)Logout\n");
        scanf(" %d",&choice);
        switch(choice)
        {
            case 1: details(q);break;
            case 2: health(q.bp,q.bloodsugar);break;
            case 3: bmi(q.height,q.weight);break;
            case 4: docavail(q.docname);break;
            case 5: checkupdate(q.lastcheckup);break;
            case 6: patupdate(&q);
                    fseek(f,-(sizeof(struct patient)),SEEK_CUR);
                    fwrite(&q,sizeof(struct patient),1,f);
                    break;
			case 7:	appoint(q);break;
            case 8: printf("\nLogging out");
                    return 1;break;
            default:    printf("\nInvalid file");break;
        }
    }while(choice!=8);
	fclose(f);
}
int main()
{
	FILE *f1,*f2;
	f1=fopen("pat.txt","a");
	f2=fopen("doc.txt","a");
	fclose(f1);
	fclose(f2);
	int a,b,c;
	tempor:
	printf("\nWelcome to PPK hospital management system");
	printf("\nEnter 1 if you are Doctor\nEnter 2 if you are Patient\t");
	scanf(" %d",&a);
	if(a==2)
	{
	do{
		printf("\n\nEnter your choice:\n\n(1)New user?? Sign up\n(2) Login with user name and password \n(3) Go back one step \n(4) Exit the program");
		scanf(" %d",&b);
		switch(b)
		{
			case 1:	patsignup();break;
			case 2:	patlogin();break;
			case 3:	goto tempor;break;
			case 4: printf("\nThank you. Bye. Take Care because we Care\n");break;
			default:	printf("\nInvalid choice");break;
		}
	}while(b!=4);
	}
	else if(a==1)
	{
	do{
		printf("\n\nEnter your choice:\n\n(1)New user?? Sign up\n(2) Login with user name and password \n(3) Go back one step \n(4) Exit the program");
		scanf(" %d",&b);
		switch(b)
		{
			case 1:	docsignup();break;
			case 2:	doclogin();break;
			case 3:	goto tempor;break;
			case 4: printf("\nThank you. Bye. Take Care because we Care\n");break;
			default:	printf("\nInvalid choice");break;
		}
	}while(b!=4);
}
else
{
printf("\nThank you. Bye. Take Care because we Care\n");
}
struct patient pat;
struct doctor doc;
FILE *f3,*f4;
f1=fopen("pat.txt","rb");
f2=fopen("doc.txt","rb");
f3=fopen("patient.txt","w");
f4=fopen("doctor.txt","w");
fread(&pat,sizeof(struct patient),1,f1);
while(!feof(f1))
{
fprintf(f3,"\n\nName: %s\nMail:\t %s\nContact number:\t %s\nProblem:\t %s\nDoctor:\t %s \nDOB:\t %d / %d / %d \nAge: %d\nHeight:\t %d \nWeight:\t %d\nBlood pressure:\t %d\nBlood Sugar Level: %d\nLast Date of Checkup:\t %d / %d / %d \n\n",pat.name,pat.mail,pat.num,pat.problem,pat.docname,pat.dob.dd,pat.dob.mm,pat.dob.yy,pat.age,pat.height,pat.weight,pat.bp,pat.bloodsugar,pat.lastcheckup.dd,pat.lastcheckup.mm,pat.lastcheckup.yy);
fread(&pat,sizeof(struct patient),1,f1);
}
fread(&doc,sizeof(struct doctor),1,f2);
while(!feof(f2))
{
fprintf(f4,"\n\nName: %s \nMail: %s \nContact Number: %s \nSpecialisation: %s \nDegree: %s \nAvailable dates: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d \nAge: %d \nNo. of appoinments remaining: %d \nSalary: Rs.%d\n\n" ,doc.dname,doc.mail,doc.num,doc.specialisation,doc.degree,doc.a[0],doc.a[1],doc.a[2],doc.a[3],doc.a[4],doc.a[5],doc.a[6],doc.a[7],doc.a[8],doc.a[9],doc.a[10],doc.a[11],doc.a[12],doc.a[13],doc.a[14],doc.age,doc.numapp,doc.salary);
fread(&doc,sizeof(struct doctor),1,f2);
}
fclose(f1);
fclose(f2);
fclose(f3);
fclose(f4);
}

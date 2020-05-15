#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

struct Student{
	int roll;
	char name[20];
	int mat,ds,oop,dsa,ld,cosm;
	float per;
	int total;
	char grade;
	//char sem[5];
}st;

int ch;
FILE *fp;

void entry_menu(void);
void search_rec(int);
void result_menu(void);

void gotoxy(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void get_time(void)
{
	time_t t;
	time(&t);
	printf("%s",ctime(&t));
}

void error(void)
{
	printf("\n\nERROR!!\nFILE COULD NOT BE OPEN\nGo to entry menu to create a file..\n");
	printf(".\n.\n.\nProgram is closing...");
	getch();
	exit(0);
}

void intro(void)
{
	system("COLOR 1F");
	Color(26);
	gotoxy(80,15);
	printf("STUDENT RECORD");
	Color(26);
	gotoxy(83,17);
	printf("PROJECT");
	Color(15);
	gotoxy(135,50);
	printf("Pranoy Bhansali\n");
	gotoxy(135,51);
	Color(29);
	get_time();
	Color(15);
	getch();
	system("cls");
}

void class_result(void)
{
	int i=0;
	fp=fopen("student.txt","rb");
	if(fp=='\0')error();
	system("cls");
	gotoxy(70,5);
	printf("-----------CLASS RESULT-----------\n\n\n");
	gotoxy(11,9);
	printf("Roll No.  Name     Mathematics   Discrete Structures   Object Oriented   Data Structures   Logic Design   Computer Oriented    Total   Percentage   Grade");
	gotoxy(66,10); printf("Programming"); gotoxy(84,10); printf("Algorithms"); gotoxy(117,10); printf("Statistical Methods\n");
	while(fread(&st,sizeof(st),1,fp)>0)
	{
		gotoxy(11,13+i); printf("%d.",st.roll); gotoxy(21,13+i); printf("%s",st.name); gotoxy(34,13+i); printf("%d",st.mat); gotoxy(53,13+i); printf("%d",st.ds);
		gotoxy(72,13+i); printf("%d",st.oop); gotoxy(91,13+i); printf("%d",st.dsa); gotoxy(107,13+i); printf("%d",st.ld); gotoxy(126,13+i); printf("%d",st.cosm);
		gotoxy(139,13+i); printf("%d",st.total); gotoxy(149,13+i); printf("%.2f",st.per); gotoxy(161,13+i); printf("%c",st.grade);
		i=i+2;
	}
	fclose(fp);
	getch();
}

void student_report_card(void)
{
	printf("\n\nEnter Roll No. of Student:");
	scanf("%d",&ch);
	system("cls");
	search_rec(ch);
	//result_menu();
	//getch();
}


void create_rec()
{
	int t;
	fp=fopen("student.txt","ab");
	if(fp=='\0')error();
	printf("\nEnter the details of the New Student:\n\n");
	printf("\nEnter the Roll Number of the Student: ");
	scanf("%d",&st.roll);
	fflush(stdin);
	printf("\nEnter the Name of the Student:");
	gets(st.name);
	printf("\nEnter the marks obtained in Mathematics:");
	scanf("%d",&st.mat);
	printf("\nEnter the marks obtained in Discrete Structures:");
	scanf("%d",&st.ds);
	printf("\nEnter the marks obtained in OOP:");
	scanf("%d",&st.oop);
	printf("\nEnter the marks obtained in DSA:");
	scanf("%d",&st.dsa);
	printf("\nEnter the marks obtained in Logic Design:");
	scanf("%d",&st.ld);
	printf("\nEnter the marks obtained in COSM:");
	scanf("%d",&st.cosm);
	t=(st.cosm+st.ds+st.dsa+st.ld+st.mat+st.oop);
	st.total=t;
	st.per=(t/6);
	t=t/6;
	if(t>=65)st.grade='A';
	if(t>=55 && t<65)
	st.grade='B';
	if(t>=45 && t<55)
	st.grade='C';
	if(t>=35 && t<45)
	st.grade='D';
	if(t<35)
	st.grade='F';
	fwrite(&st,sizeof(st),1,fp);
	fclose(fp);
	printf("\nStudent Record has been Created.");
	getch();
	//entry_menu();
}

void display_all_rec()
{
	int i=0;
	system("cls");
	gotoxy(77,5);
	printf("DISPLAY ALL RECORDS");
	fp=fopen("student.txt","rb");
	if(fp=='\0')error();
	while(fread(&st,sizeof(st),1,fp)>0)
	{
		gotoxy(60,8+i);
		printf("==================================================\n");
		gotoxy(60,10+i);
		printf("NAME:%s",st.name);
		gotoxy(100,10+i);
		printf("ROLL NO.:%d\n\n",st.roll);
		gotoxy(60,12+i);
		printf("SUBJECTS");
		gotoxy(100,12+i);
		printf("MARKS");
		gotoxy(60,14+i); printf("Mathematics"); gotoxy(101,14+i); printf("%d",st.mat);
		gotoxy(60,15+i); printf("Discrete Structures"); gotoxy(101,15+i); printf("%d",st.ds);
		gotoxy(60,16+i); printf("Object Oriented Programming"); gotoxy(101,16+i); printf("%d",st.oop);
		gotoxy(60,17+i); printf("Data Structures and Algorithms"); gotoxy(101,17+i); printf("%d",st.dsa);
		gotoxy(60,18+i); printf("Logic Design"); gotoxy(101,18+i); printf("%d",st.ld);
		gotoxy(60,19+i); printf("Computer Oriented Statistical Methods"); gotoxy(101,19+i); printf("%d",st.cosm);
		gotoxy(100,21+i); printf("Total:%d",st.total);
		gotoxy(60,23+i); printf("--------------------------------------------------");
		gotoxy(62,24+i); printf("Percentage:%.2f",st.per); gotoxy(100,24+i); printf("Grade:%c",st.grade);
		gotoxy(60,25+i); printf("--------------------------------------------------\n\n\n");
		gotoxy(60,27+i); printf("==================================================\n");
		i=i+23;
		getch();
		//system("cls");
	}
	//printf("display all");
	fclose(fp);
	getch();
}

void search_rec(int ch)
{
	//system("cls");
	fp=fopen("student.txt","rb");
	if(fp=='\0')error();
	while(fread(&st,sizeof(st),1,fp)>0)
	{
		if(st.roll==ch)
		{
			gotoxy(75,4);
			printf("Report Card of %s -",st.name);
			gotoxy(60,8);
			printf("==================================================\n");
			gotoxy(60,10);
			printf("NAME:%s",st.name);
			gotoxy(100,10);
			printf("ROLL NO.:%d\n\n",st.roll);
			gotoxy(60,12);
			printf("SUBJECTS");
			gotoxy(100,12);
			printf("MARKS");
			gotoxy(60,14); printf("Mathematics"); gotoxy(101,14); printf("%d",st.mat);
			gotoxy(60,15); printf("Discrete Structures"); gotoxy(101,15); printf("%d",st.ds);
			gotoxy(60,16); printf("Object Oriented Programming"); gotoxy(101,16); printf("%d",st.oop);
			gotoxy(60,17); printf("Data Structures and Algorithms"); gotoxy(101,17); printf("%d",st.dsa);
			gotoxy(60,18); printf("Logic Design"); gotoxy(101,18); printf("%d",st.ld);
			gotoxy(60,19); printf("Computer Oriented Statistical Methods"); gotoxy(101,19); printf("%d",st.cosm);
			gotoxy(100,21); printf("Total:%d",st.total);
			gotoxy(60,23); printf("--------------------------------------------------");
			gotoxy(62,24); printf("Percentage:%.2f",st.per); gotoxy(100,24); printf("Grade:%c",st.grade);
			gotoxy(60,25); printf("--------------------------------------------------\n\n\n");
			gotoxy(60,27); printf("==================================================\n");
			//i=i+23;
			getch();
			fclose(fp);
			return;
		}
	}
	printf("\n\n\n\n\nRecord not Found..!!");
	fclose(fp);
	getch();
}

void modify_rec()
{
	FILE *fp2;
	int t,found=0;
	system("cls");
	printf("\n\nEnter the Roll No. of the Student you want to modify:");
	scanf("%d",&ch);
	fp=fopen("student.txt","rb");
	if(fp=='\0')error();
	fp2=fopen("tempmod.txt","wb");
	rewind(fp);
	while((fread(&st,sizeof(st),1,fp))>0)
	{
		if(st.roll!=ch)
		{
			fwrite(&st,sizeof(st),1,fp2);
		}
		else if(st.roll==ch)
		{
			gotoxy(60,10);
			printf("NAME:%s",st.name);
			gotoxy(100,10);
			printf("ROLL NO.:%d\n\n",st.roll);
			gotoxy(60,12);
			printf("SUBJECTS");
			gotoxy(100,12);
			printf("MARKS");
			gotoxy(60,14); printf("Mathematics"); gotoxy(101,14); printf("%d",st.mat);
			gotoxy(60,15); printf("Discrete Structures"); gotoxy(101,15); printf("%d",st.ds);
			gotoxy(60,16); printf("Object Oriented Programming"); gotoxy(101,16); printf("%d",st.oop);
			gotoxy(60,17); printf("Data Structures and Algorithms"); gotoxy(101,17); printf("%d",st.dsa);
			gotoxy(60,18); printf("Logic Design"); gotoxy(101,18); printf("%d",st.ld);
			gotoxy(60,19); printf("Computer Oriented Statistical Methods"); gotoxy(101,19); printf("%d",st.cosm);
			gotoxy(100,21); printf("Total:%d",st.total);
			gotoxy(60,23); printf("--------------------------------------------------");
			gotoxy(62,24); printf("Percentage:%.2f",st.per); gotoxy(100,24); printf("Grade:%c",st.grade);
			gotoxy(60,25); printf("--------------------------------------------------\n\n\n");
			
			printf("-- Enter the new details of the student --\n\n");
			printf("\nEnter the Roll Number of the Student: ");
			scanf("%d",&st.roll);
			fflush(stdin);
			printf("\nEnter the Name of the Student:");
			gets(st.name);
			printf("\nEnter the marks obtained in Mathematics:");
			scanf("%d",&st.mat);
			printf("\nEnter the marks obtained in Discrete Structures:");
			scanf("%d",&st.ds);
			printf("\nEnter the marks obtained in OOP:");
			scanf("%d",&st.oop);
			printf("\nEnter the marks obtained in DSA:");
			scanf("%d",&st.dsa);
			printf("\nEnter the marks obtained in Logic Design:");
			scanf("%d",&st.ld);
			printf("\nEnter the marks obtained in COSM:");
			scanf("%d",&st.cosm);
			t=(st.cosm+st.ds+st.dsa+st.ld+st.mat+st.oop);
			st.total=t;
			st.per=(t/6);
			t=t/6;
			if(t>=65)st.grade='A';
			if(t>=55 && t<65)
			st.grade='B';
			if(t>=45 && t<55)
			st.grade='C';
			if(t>=35 && t<45)
			st.grade='D';
			if(t<35)
			st.grade='F';
			
			fwrite(&st,sizeof(st),1,fp2);
			found=1;
			printf("\n\nRecord updated successfully..!!");
		}
	}
		fclose(fp);
		fclose(fp2);
		remove("student.txt");
		rename("tempmod.txt","student.txt");
		if(found==0)printf("\n\nRecord not found..!!");
		getch();
}

void delete_rec()
{
	int flag=0;
	FILE *fp2;
	printf("\n\nEnter the Roll No. of the student whose record is to be deleted:");
	scanf("%d",&ch);
	fp=fopen("student.txt","rb");
	fp2=fopen("temp.txt","wb");
	if(fp=='\0')error();
	rewind(fp);
	while((fread(&st,sizeof(st),1,fp))>0)
	{
		if(st.roll!=ch)
		{
			fwrite(&st,sizeof(st),1,fp2);
		}
		else if(st.roll==ch)flag=1;		
	}
	fclose(fp2);
	fclose(fp);
	remove("student.txt");
	rename("temp.txt","student.txt");
	if(flag==0)printf("\n\nRecord does not exist..!!");
	else printf("\n\nRecord deleted successfully..!!");
	//printf("\n\nRecord deleted successfully..!!");
	getch();
}

void result_menu()
{
	int ch;
	system("cls");
	gotoxy(60,6);
	printf("---------------------------------------------------");
	gotoxy(80,7);
	printf("RESULT MENU\n");
	gotoxy(60,8);
	printf("---------------------------------------------------");
	printf("\n\n1. Class Result\n\n2. Student Report Card\n\n3. Back to Main Menu\n");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			class_result();
			result_menu();
			break;
		case 2:
			student_report_card();
			result_menu();
			break;
		case 3:
			break;
	}
	//getch();
}

void entry_menu()
{
	int ch;
	system("cls");
	gotoxy(60,6);
	printf("---------------------------------------------------");
	gotoxy(80,7);
	printf("ENTRY MENU\n");
	gotoxy(60,8);
	printf("---------------------------------------------------");
	printf("\n\n1. Create Student Record\n\n2. Display All Students Record\n\n3. Search Student Record\n\n4. Back to Main Menu\n");
	printf("\n\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			create_rec();
			entry_menu();
			break;
		case 2:
			display_all_rec();
			entry_menu();
			break;
		case 3:
			printf("\n\nEnter the Roll No. of the student:");
			scanf("%d",&ch);
			system("cls");
			search_rec(ch);
			entry_menu();
			break;
		case 4:
			break;
	}
	//getch();
}

void edit_menu()
{
	system("cls");
	gotoxy(60,6);
	printf("---------------------------------------------------");
	gotoxy(80,7);
	printf("EDIT MENU\n");
	gotoxy(60,8);
	printf("---------------------------------------------------");
	printf("\n\n1. Modify Student Record\n\n2. Delete Student Record\n\n3. Back to Main Menu\n");
	printf("\n\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			modify_rec();
			edit_menu();
			break;
		case 2:
			delete_rec();
			edit_menu();
			break;
		case 3:
			break;
	}
	//getch();
}

void main()
{
	char ch;
	
	intro();
		
	do{
		system("cls");
		gotoxy(60,6);
		printf("---------------------------------------------------");
		gotoxy(80,7);
		printf("MAIN MENU\n");
		gotoxy(60,8);
		printf("---------------------------------------------------");
		printf("\n\n1. RESULT MENU");
		printf("\n\n2. ENTRY MENU");
		printf("\n\n3. EDIT MENU");
		printf("\n\n4. EXIT");
		printf("\n\nEnter your choice:");
		ch=getchar();
		//scanf("%d",&ch);
		switch(ch)
		{
			case '1':
				result_menu();
				break;
			case '2':
				entry_menu();
				break;
			case '3':
				edit_menu();
				break;
			case '4':
				exit(1);
			default:
				printf("\a");
		}
	}while(ch!='4');
}

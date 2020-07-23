//                                                     UNIVERSITY FUND MANGEMENT SYSTEM
/**

	users:
		1. Admin
		
	Main Menu:
		
		1. Student Management
		2. Course Management
		3. Fund Management
		4. Exit
		
	Functions:
		a) Students Management
		
			1. Add Student(Admission) 	{student-name, registration-number, student-father's-name, course, course-code }
			2. Remove Student			{student-name, Registration-number }
			3. Update Student			{registration-number }
			4. Show Students List		{all information }
			5. Main Menu
			6. Exit
			x. More
		
		b) Course Management
		
			1. Add course 			{course-name, course-code, tuition-fee, course-duration, student-intake }
			2. Remove course 		{course-name, course-code }
			3. Update Course		{course-code }
			4. Show Courses List	{all information }
			5. Main Menu
			6. Exit
			x. More
			
		c) Funds Management
			
			1. Salary Charges						
				a. Salary Payment					{employee-type, employee-name, amount }
				b. Salary History					{date, emloyee-type, employee-name, amount }
				c. Main menu
				d. Exit
			2. Tution Fees
				a. Tution Fees History				{date, course-name, registration-number, amount }
				b. Main menu
				c. Exit
			3. Tools charges		
				a. Tools payment					{amount, payment-by, description }
				b. Tools payment history			{date, amount, payment-by, description }
				c. Main menu
				d. Exit
			4. Maintenance Charge
				a. Maintenance Payment				{amount, payment-by, description }
				b. Maintenance Payment History		{date, amount, payment-by, description }
				c. Main menu
				d. Exit
			4. Available Fund						{amount of fund in-hand }
			5. Main Menu
			6. Exit
			x. More
			
			
	FILES :
		studentRecord				=	Record of Student information
		courseRecord				=	Record of courses information
		fundRecord					=	Record of avialable fund
		toolsPaymentRecord			=	Record of tools payment
		maintenancePaymentRecord	=	Record of maintenance payment 

*/

//UNIVERSITY FUND MANAGEMENT SYSTEM
//header files
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>

//function declarations
void menuHome();
void welcomeScreen();
void fordelay(int j);
int passLogin();
void menuAdmin();
void coursesList();
void close();
void menuFunds();
void addStudent();
void mcaStudents();
void mainMenu();
void studentMenu();
void removeStudent();
void updateStudent();
void studentList();
void courseMenu();
void addCourse();
void removeCourse();
void updateCourse();
void courseList();
void salaryCharges();
void tutionFees();
void toolsCharges();
void maintenanceCharges();
void avialableFunds();
void salaryPayment();
void salaryHistory();
void tutionFeesHistory();
void tPayment();
void tPaymentHistory();
void mPayment();
void mPaymentHistory();
void gotoxy(int, int);


struct{
	
	char name[30];
	char fname[30];
	long int regNo;
	char course[30];
	int courseCode;
}student;

struct{
	char name[30];
	int code;
	float fees;
	int duration;
	int capacity;
}course;

int main(){
	
	system("color F1");
	welcomeScreen();
	printf("UNIVERSITY FUND MANAGEMENT SYSTEM"); 
	mainMenu();
}

void gotoxy(int x, int y)
{
	COORD C;
	C.X=x;
	C.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),C);
}

// first apppear screen
void welcomeScreen(){
	
	system("color 0E");
	int i;
	printf("UNIVERSITY MANAGEMENT SYSTEM\n\n");
	printf("LOADING");
	for(i=0;i<=10;i++)
    {
    	printf(".");
       	fordelay(10000);
    }
    
    while(passLogin() != 1){
    	system("cls");
    	printf("Sorry, Invalid Password !\n\n");
		fordelay(100000000);
	}
    	
}

// for holding screen for sometime
void fordelay(int j){   
	int i,k;
    for(i=0;i<j;i++)
         k=i;
}

// password login function
int passLogin(){
	system("cls");
	char pasword[10],usrname[10],ch;
	int i;
	gotoxy(25,1);
	printf("Enter password to continue\n\n");
	
	for(i=0;i<4;i++)
	{
		ch = getch();
		pasword[i] = ch;
		if(ch == 0x0A){
			break;
	} 
	ch = '*' ;
	printf("%c",ch);
	}

	pasword[i] = '\0';
	
	if(strcmp(pasword,"2018") == 0){
		system("cls");
		{ 
		gotoxy(25,1);
		printf("\nPassword Matched !!!\n\n\nPLEASE WAIT WHILE LOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
		system("cls");
        }
        return 1;
	}
	else
		return 0;
}

void close(){
	system("cls");
	printf("\n\nThanks for using software !\n\n");
}

// home screen menu
void mainMenu(){
	
	system("cls");
	printf("\t\t\t********** WELCOME **********");
	gotoxy(23,3);
	printf("UNIVERSITY FUND MANAGEMENT SYSTEM\n\n"); 
	printf("\t\t\t\t  MAIN MENU\n\n\n");
	printf("Select any one option to continue...\n\n");
	printf("1. Student Management\n\n");
	printf("2. Course Management\n\n");
	printf("3. Funds Management\n\n");
	printf("4. Exit\n\n");
	
	
	int option;
	printf("\nYour Selection  ");
	scanf("%d",&option);
	switch(option){
		
		case 1:
			studentMenu();
			break;
		case 2:
			courseMenu();
			break;
		case 3:
			fundsMenu();
			break;
		case 4:
			close();
			break;
		default:
			printf("\nInvalid Selection\n");
			fordelay(100000000);
			system("cls");
			mainMenu();
	}
	
	
	
}

/*
	Course Management
*/

// student management menu
void studentMenu(){
	
	system("cls");
	gotoxy(23,1);
	printf("UNIVERSITY FUND MANAGEMENT SYSTEM\n\n"); 
	printf("\t\t\t\tSTUDENT MENU\n\n");
	printf("Select any one option to continue...\n\n");
	printf("1. Add Student\n\n");
	printf("2. Remove Student\n\n");
	printf("3. Update Student\n\n");
	printf("4. Show Students List\n\n");
	printf("5. Go to main menu\n\n");
	printf("6. Exit\n\n");
	
	int option;
	printf("\nYour Selection  ");
	scanf("%d",&option);
	switch(option){
		
		case 1:
			addStudent();
			break;
		case 2:
			removeStudent();
			break;
		case 3:
			updateStudent();
			break;
		case 4:
			studentList();
			break;
		case 5:
			mainMenu();
			break;
		case 6:
			close();
			break;
		default:
			printf("\nInvalid Selection\n");
			fordelay(100000000);
			system("cls");
			studentMenu();
		
	}
	
	
}

// add new student
void addStudent(){
	
	system("cls");
	FILE *ptr;
	ptr=fopen("studentRecord.dat","a+");
	
	printf("Name  \t");
	scanf("%s",student.name);
	printf("Student Father's Name  \t");
	scanf("%s",student.fname);
	printf("Registration Number  \t");
	scanf("%ld",&student.regNo);
	printf("Course Name  \t");
	scanf("%s",student.course);
	printf("Course Code  \t");
	scanf("%d",&student.courseCode);
	
	fprintf(ptr,"%ld\t  %s\t  %s\t  %s\t  %d\n",student.regNo,student.name,student.fname,student.course,student.courseCode);
	system("cls");
	fordelay(1000000);
	printf("Student added Successfully !");
	fclose(ptr);
	
	mainMenu();	
}

// remove the existing student
void removeStudent(){
	
}

// update the existing student
void updateStudent(){
	
}

// show all student list
void studentList(){
	
	system("cls");
	FILE *fp;
	char ch;
	
	fp = fopen("studentRecord.dat","r");
	
	if(fp == NULL){
		printf("Error while showing data");
		exit(EXIT_FAILURE);
	}
		printf("\n\n ### STUDENTS LIST ###\n\n");
	printf("Reg. No.  Name  Father's Name  Course  Course Code\t\n\n");
	while((ch = fgetc(fp)) != EOF){
		printf("%c",ch);
	}
	
	fclose(fp);
}

/*
	Course Management
*/

// course management menu
void courseMenu(){
	
	system("cls");
	gotoxy(23,1);
	printf("UNIVERSITY FUND MANAGEMENT SYSTEM\n\n");
	printf("\t\t\t\tCOURSE MENU\n\n");
	printf("Select any one option to continue.\n\n");
	printf("1. Add Course\n\n");
	printf("2. Remove Course\n\n");
	printf("3. Update Course\n\n");
	printf("4. Show Course List\n\n");
	printf("5. Go to main menu\n\n");
	printf("6. Exit\n\n");
	
	int option;
	printf("\nYour Selection  ");
	scanf("%d",&option);
	switch(option){
		
		case 1:
			addCourse();
			break;
		case 2:
			removeCourse();
			break;
		case 3:
			updateCourse();
			break;
		case 4:
			courseList();
			break;
		case 5:
			mainMenu();
			break;
		case 6:
			close();
			break;
		default:
			printf("\nInvalid Selection\n");
			fordelay(100000000);
			system("cls");
			mainMenu();
		
	}
	
}

// add new course
void addCourse(){
	
	system("cls");
	FILE *ptr;
	char c;
	ptr = fopen("courseRecord.dat","a+");
	
	printf("Enter Course name \t");
	scanf("%s",&course.name);
	printf("Enter Course Code \t");
	scanf("%d",&course.code);
	printf("Enter course duration(in years) \t");
	scanf("%d",&course.duration);
	printf("Enter course fees(per year) \t");
	scanf("%f",&course.fees);
	printf("Enter intake capacity \t");
	scanf("%d",&course.capacity);
	
	fprintf(ptr,"%s \t %d \t %d \t %.2f \t %d\n",course.name,course.code,course.duration,course.fees,course.capacity);
	system("cls");
	fordelay(1000000);
	printf("Student added Successfully !");
	fclose(ptr);
	
	mainMenu();
	
}

// remove the existing course
void removeCourse(){
	
}

// update the existing course
void updateCourse(){
	
}

// show all course list
void courseList(){
	
	system("cls");
	FILE *fp;
	char ch;
	
	fp = fopen("courseRecord.dat","r");
	
	if(fp == NULL){
		printf("Error while showing data");
		exit(EXIT_FAILURE);
	}
	
	printf("\n\n ### COURSES LIST ###\n\n");
	printf("Name \t Code \t Duration  Fees \t Intake\n\n");
	while((ch = fgetc(fp)) != EOF){
		printf("%c",ch);
	}
	
	fclose(fp);
}

/*
	Funds Management
*/

void fundsMenu(){
	
	system("cls");
	gotoxy(23,1);
	printf("UNIVERSITY FUND MANAGEMENT SYSTEM\n\n"); 
	printf("\t\t\t\tFUNDS MENU\n\n");
	printf("Select any one option to continue...\n\n");
	printf("1. Salary Charges\n\n");
	printf("2. Tution Fees\n\n");
	printf("3. Wifi, Telecome and other charges\n\n");
	printf("4. Maintenance Charge\n\n");
	printf("5. Avialable Funds\n\n");
	printf("6. Go to main menu\n\n");
	printf("7. Exit\n\n");
	
	int option;
	printf("\n\nYour Selection  ");
	scanf("%d",&option);
	switch(option){
		
		case 1:
			salaryCharges();
			break;
		case 2:
			tutionFees();
			break;
		case 3:
			toolsCharges();
			break;
		case 4:
			maintenanceCharges();
			break;
		case 5:
			avialableFunds();
			break;
		case 6:
			mainMenu();
			break;
		case 7:
			close();
			break;
		default:
			printf("\nInvalid Selection\n");
			fordelay(100000000);
			system("cls");
			fundsMenu();
		
	}	
}

// Salaries giving to employies and professores
void salaryCharges(){
	
	system("cls");
	printf("Select any one option to continue...\n\n");
	printf("1. Salary Payment\n\n");
	printf("2. Recent Salary History\n\n");
	printf("3. Go to main menu\n\n");
	printf("4. Exit\n\n");
	
	int option;
	printf("\nYour Selection  ");
	scanf("%d",&option);
	switch(option){
		
		case 1:
			salaryPayment();
			break;
		case 2:
			salaryHistory();
			break;
		case 3:
			mainMenu();
			break;
		case 4:
			close();
			break;
		default:
			printf("\nInvalid Selection\n");
			fordelay(100000000);
			system("cls");
			fundsMenu();
		
	}	
	
}

// Tution fees coming from student
void tutionFees(){
	
	system("cls");
	printf("Select any one option to continue.\n\n");
	printf("1. Tution Fees History\n\n");
	printf("2. Go to main menu\n\n");
	printf("3. Exit\n\n");
	
	int option;
	printf("\nYour Selection  ");
	scanf("%d",&option);
	switch(option){
		
		case 1:
			tutionFeesHistory();
			break;
		case 2:
			mainMenu();
			break;
		case 3:
			close();
			break;
		default:
			printf("\nInvalid Selection\n");
			fordelay(100000000);
			system("cls");
			fundsMenu();
		
	}	
	
}

// charges for wifi, electricity, telecommunication and others
void toolsCharges(){
	
	system("cls");
	printf("Select any one option to continue...\n\n");
	printf("1. Payment for tools\n\n");
	printf("2. View Payment History\n\n");
	printf("3. Go to main menu\n\n");
	printf("4. Exit\n\n");
	
	int option;
	printf("\nYour Selection  ");
	scanf("%d",&option);
	switch(option){
		
		case 1:
			tPayment();
			break;
		case 2:
			tPaymentHistory();
			break;
		case 3:
			mainMenu();
			break;
		case 4:
			close();
			break;
		default:
			printf("\nInvalid Selection\n");
			fordelay(100000000);
			system("cls");
			fundsMenu();
		
	}	
}

// charges for maintenance of the college and hostels
void maintenanceCharges(){
	
	system("cls");
	printf("Select any one option to continue...\n\n");
	printf("1. Maintenance Payment\n\n");
	printf("2. Payment History\n\n");
	printf("3. Go to main menu\n\n");
	printf("4. Exit\n\n");
	
	int option;
	printf("\nYour Selection  ");
	scanf("%d",&option);
	switch(option){
		
		case 1:
			mPayment();
			break;
		case 2:
			mPaymentHistory();
			break;
		case 3:
			mainMenu();
			break;
		case 4:
			close();
			break;
		default:
			printf("\nInvalid Selection\n");
			fordelay(100000000);
			system("cls");
			fundsMenu();
		
	}	
	
}

// add fund amount to avialable fund amount
void addFunds(float amount){
	
		
}

// remove fund amount from the avialable fund amount
void removeFunds(float amount){
	
}

// Amount of avialable funds
void avialableFunds(){
	
	
	
}

// Salary Payment for employee and professores
void salaryPayment(){
	
}

// Salary History of recent payments
void salaryHistory(){
	
}

// History of recent tution fees added
void tutionFeesHistory(){
	
}

// payment for tools like wifi, electricity, and others
void tPayment(){
	
}

// History of recent tools payment history
void tPaymentHistory(){
	
}

// payment for maintenance for the college and the hostel
void mPayment(){
	
	
}

// History of the recent maitenance payment history
void mPaymentHistory(){
	
}



/*                                                       BY
                                              ANURAG PANDEY & HARSH KUMAR
                                                   M.C.A.(I YEAR)
                                                  R.G.S.C.(B.H.U.) 
											         2018-19
*/

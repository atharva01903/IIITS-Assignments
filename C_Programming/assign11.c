#include<stdio.h>
#include<string.h>
#include<math.h>
#define Max 1000
int c=0;
int course[100];
struct Student 
{
	char a[25];
	char b[25];
	int roll;
	float c;
	int arr[30];
};
struct Student st[50];
void addStudent()
{
	int j,i,k,x;
	printf("Enter Record of Student no.%d",c+1);  
	printf("\nEnter First Name:");    
	scanf("%s",&st[c].a);    
	printf("Enter last Name:");    
	scanf("%s",&st[c].b);
	printf("Enter Rollno:");    
	scanf("%d",&st[c].roll);
	for(k=c;k>0;k--)
	{
		if(st[c].roll==st[k-1].roll)
		{
			printf("You've already entered this roll no.\n");
			return;
		}
	}
	printf("Enter CGPA:");    
	scanf("%f",&st[c].c);
	printf("Enter the course IDs(The 3 IDs should've value < 100 & inserted with spaces):"); 
	if(c==0)
	{
		for(x=0;x<100;x++)
		{
			course[x]=0;
		}
	}
	for(j=0;j<3;j++)   
	{
		scanf("%d",&(st[c].arr[j]));
		course[st[c].arr[j]]+=1;
	}
	c++;
}
void findStudent()
{
	int r,p,j,flag=0;
	printf("Enter the Roll no. of student you're searching for:");
	scanf("%d",&r);
	for(p=c;p>=0;p--)
	{
		if(st[p].roll==r)
		{
			flag++;			
			printf("\nFirst Name:%s \nLast Name:%s \nRoll no:%d \nCGPA:%f \nCourses enrolled:",st[p].a,st[p].b,st[p].roll,st[p].c); 
			for(j=0;j<3;j++)
			{ 
				printf("%d ",st[p].arr[j]);
			}  
			printf("\n");
		}
	}
	if(flag==0)
	{
		printf("The System did not find Roll no.%d in its record:(\n",r);
	}
}
void findByName()
{
	int jj,d,fl=0;	
	char name[25];
	printf("Enter the first name of the Student you're searching:");
	scanf("%s",name);
	for(d=c;d>=0;d--)
	{
		if(strcmp(st[d].a, name)==0)
		{
			fl++;			
			printf("\nFirst Name:%s \nLast Name:%s \nRoll no:%d \nCGPA:%f \nCourses enrolled:",st[d].a,st[d].b,st[d].roll,st[d].c); 
			for(jj=0;jj<3;jj++)
			{ 
				printf("%d ",st[d].arr[jj]);
			}  
			printf("\n");
		}
	}
	if(fl==0)
	{
		printf("The System did not find %s in its record:(\n",name);
	}
}
void findByCourse()
{
	int r,j,flg=0,t,e;
	printf("Enter the course ID:");
	scanf("%d",&r);
	printf("\nHere are the pupils with the course ID-%d",r);
	for(e=c;e>=0;e--)
	{
		for(t=0;t<3;t++)
		{
			if(st[e].arr[t]==r)
			{
				flg++;			
				printf("\nFirst Name:%s \nLast Name:%s \nRoll no:%d \nCGPA:%f \nCourses enrolled:",st[e].a,st[e].b,st[e].roll,st[e].c); 
				for(j=0;j<3;j++)
				{ 
					printf("%d ",st[e].arr[j]);
				}  
				printf("\n");
			}
		}
	}
	if(flg==0)
	{
		printf("The System did not find any student having enrolled the course with ID %d:(\n",r);
	}
}
void totalStudents()
{
	printf("Total number of students in the system=%d\n",c);
	//Below is the program to display all the students
	/*printf("\nStudent Information List:");    
	for(i=0;i<c;i++)
	{    
		printf("\nFirst Name:%s \nLast Name:%s \nRoll no:%d \nCGPA:%f \nCourses enorlled:",st[i].a,st[i].b,st[i].roll,st[i].c); 
		for(j=0;j<3;j++)
		{ 
			printf("%d ",st[i].arr[j]);
		}  
		printf("\n");
	}*/ 
}
void iistStudents()
{
	int i,j;
	printf("Total number of students in the system=%d\n",c);
	//Below is the program to display all the students
	if(c==0)
	{
		printf("There are no students in the list.First, create a list;)\n");
		return;
	}
	printf("\nStudent Information List:");    
	for(i=0;i<c;i++)
	{    
		printf("\nFirst Name:%s \nLast Name:%s \nRoll no:%d \nCGPA:%f \nCourses enorlled:",st[i].a,st[i].b,st[i].roll,st[i].c); 
		for(j=0;j<3;j++)
		{ 
			printf("%d ",st[i].arr[j]);
		}  
		printf("\n");
	} 
}
void deleteStudent()
{
	int r,pos,p,i,flag=0;
	printf("Enter the Roll no. of the student to be deleted:");
	scanf("%d",&r);
	for(p=c;p>=0;p--)
	{
		if(st[p].roll==r)
		{
			flag++;	
			pos=p;
			for(i=pos; i<=c-1; i++)
       		 	{
            			st[i] = st[i + 1];
        		}
        		c--;
			printf("Roll no.%d has been deleted successfully;)\n",r);
		}
	}
	if(flag==0)
	{
		printf("The System did not find Roll no.%d in its record:(\n",r);
	}
}
void updateStudent()
{
	int r,p,j,flag=0,num,jj,k;
	printf("Enter the roll no. of Student to be updated:");
	scanf("%d",&r);
	for(p=c;p>=0;p--)
	{
		if(st[p].roll==r)
		{
			flag++;	
			printf("\nHere's the numeric menu for updating the student info");	
			printf("\n1:Update First name\n2:Update Last name\n3:Update Roll no.\n4:Update CGPA\n5:Update couse ID\n");
			printf("Enter the option number for updating the info of Roll no.%d\n",r);	
			scanf("%d",&num);
			switch(num){
			case 1:	printf("\nEnter the updated First Name:");    
				scanf("%s",&st[p].a); 
				break; 
			case 2:	printf("\nEnter the updated Last Name:");    
				scanf("%s",&st[p].b); 
				break;
			case 3:	printf("\nEnter the updated Roll no.:");    
				scanf("%d",&st[p].roll);
				for(k=p;k>0;k--)
				{
					if(st[p].roll==st[k-1].roll)
					{
						printf("You've already entered this roll no.\n");
						st[p].roll=r;
						break;
					}
				} 
				for(k=p;k<c-1;k++)
				{
					if(st[p].roll==st[k+1].roll)
					{
						printf("You've already entered this roll no.\n");
						st[p].roll=r;
						break;
					}
				}
				break;
			case 4:	printf("\nEnter the updated CGPA:");    
				scanf("%f",&st[p].c); 
				break;
			case 5:	printf("\nEnter the updated entry of course IDs:");    
				for(jj=0;jj<3;jj++)   
				{
					scanf("%d",&(st[p].arr[jj]));
				} 	
				break;
			}
			printf("\nHere is the updated info of Roll no.%d",r);
			printf("\nFirst Name:%s \nLast Name:%s \nRoll no:%d \nCGPA:%f \nCourses enrolled:",st[p].a,st[p].b,st[p].roll,st[p].c); 
			for(j=0;j<3;j++)
			{ 
				printf("%d ",st[p].arr[j]);
			}  
			printf("\n");
		}
	}
	if(flag==0)
	{
		printf("The System did not find Roll no.%d in its record:(\n",r);
	}
}
void swap(float *p,float *q) {
   float t;
   
   t=*p; 
   *p=*q; 
   *q=t;
}

void sort(float a[],int n) { 
   int i,j,temp;

   for(i = 0;i < n-1;i++) {
      for(j = 0;j < n-i-1;j++) {
         if(a[j] > a[j+1])
            swap(&a[j],&a[j+1]);
      }
   }
}

void studentStats()
{
	int i,mid;
	float sum=0.0,mean,cgpa[c],stddev=0.0;
	for(i=0;i<c;i++)
	{
		cgpa[i]=st[i].c;
		sum+=cgpa[i];
	}
	mean=sum/c;
	sort(cgpa,c);
	mid=c/2;
	printf("Student Statistics:\n");
	printf("Mean CGPA=%f\n",mean);
	if(c%2==1)
	{
		printf("Median CGPA=%f\n",cgpa[mid]);
	}
	else
	{
		printf("Median CGPA=%f\n",(cgpa[mid]+cgpa[mid-1])/2.0);
	}
	for(i=0;i<c;i++)
	{
		stddev+=pow(cgpa[i]-mean,2);
	}
	printf("Standard deviation in CGPA=%f\n",sqrt(stddev/c));
}
void courseSummary()
{
	int kk;
	printf("Courses and number of students who've registered for it");
	for(kk=0;kk<100;kk++)
	{
		if(course[kk]!=0)
		{
			printf("\nCourse-ID=%3d | No. of registrations=%d",kk,course[kk]);
		}
	}
	printf("\n");
}
int main()
{
	int i,j,n;
	printf("Student Informatics Beureau");
	printf("\nHere's the numeric menu");
	printf("\n0:Quit\n1:Add a Student\n2:Find a Student(by roll)\n3:Find Students(by name)\n4:Find Students(by course ID)\n5:Total number of Students\n6:Delete a Student(by roll)\n7:Update the info of a Student(by roll)\n8:Print the Student Statistics\n9:Print the Course Summaries\n10:List all the students\n");
	while(1)
	{
		printf("Enter the number as per the numeric menu\n");
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		if(n>10)
		{
			printf("Invalid input!!:(\n");
			//break;/*Use break to terminate the loop here itself.But,then there would be no use of 0 command;P*/		
		}
		switch(n){
		case 1: addStudent();
			break;
		case 2: findStudent();
			break;
		case 3: findByName();
			break;
		case 4: findByCourse();
			break;
		case 5: totalStudents();
			break;
		case 6: deleteStudent();
			break;
		case 7: updateStudent();
			break;
		case 8: studentStats();
			break;
		case 9: courseSummary();
			break;
		case 10: iistStudents();
			break;
		}
	}
   	return 0;    
}












































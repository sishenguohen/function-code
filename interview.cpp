#include<cstdio>
#include<cstdlib>
#include<map>
#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<iterator>
#include<time.h>
#include<sys/time.h>

void point();

void back()
{
	char str[] = "hello world";
	int m = sizeof(str)/sizeof(char);
	printf("m = %d",m);
	for(int i=m-1;i>=0;i--)
		printf("%c",str[i]);
	printf("\n");
}



void map()
{
	std::map<const char *,int> months;
	months["january"] = 31;
	months["february"] = 28;
	months.insert(std::map< const char *,int>::value_type("march",31));
	std::map<int,const char *>days;
	days[1] = "ok";
	std::cout<<"January days is "<<months["january"]<<std::endl;
	std::cout<<"February days is "<<months["february"]<<std::endl;
	std::cout<<"March days is "<<months["march"]<<std::endl;
	std::cout<<days[1]<<std::endl;
}
	
char *strcpy(char *strDest,const char *strSrc)
{
	if(strDest == NULL || strSrc ==NULL)
		return NULL;
	if(strDest == strSrc)
		return strDest;
	char *tempptr = strDest;
	while( (*strDest++ = *strSrc++) != '\0');
	return tempptr;
}
	
	

void strcp()
{
	char a[11];
	char b[] = "hello world";
	strcpy(a,b);
	printf("%s\n",a);

		
}

void openfile()
{
	int str[] = {12,32,54,12,22,1,6,76,9};
	int str_len;
	str_len = sizeof(str)/sizeof(int);
	printf("str_len = %d\n", str_len);
	for(int i=0;i<str_len;i++)
		for(int j;j<str_len-1;j++)
		{
			if(str[j]<str[j+1])
			{
				int temp = str[j+1];
				str[j+1] = str[j];
				str[j] = temp;
			}
		}
	for(int i=0;i<str_len;i++)
		printf("%4d",str[i]);
	printf("\n");

	int fd;
	fd = open("./wwww.text",O_RDWR|O_CREAT);
	for(int i=0;i<str_len;i++)
		write(fd,&str[i],1);
	close(fd);
}


void checkstring()
{

	char string[] = "hello world , do you like swear dress?";
	int stringlen = sizeof(string);
	printf("%d\n",stringlen);
	int len,point,count=0,maxlen=0,maxpoint=0;
	for(int i=0; i<stringlen;i++)
	{
		if(i==0)
                        point = i;
	
		if(string[i] == ' '||string[i] == '\0')
		{
			count++;
			len = i-point;
			if(len >= maxlen)
			{
				maxlen = len;
				maxpoint = point;
			}
			point  = i+1;
			printf("i:%d\n",i);
		}

		if(string[i] == '\0')
		{
			printf("maxlen = %d,maxpoint = %d\n",maxlen,maxpoint);
			for(int i=0;i<maxlen;i++)
			{
				printf("%c",string[maxpoint+i]);
			}
			
		}
	}
	printf("\n");
	printf("count:%d\n",count);
}


void strsum()
{
	float sum[20];
	float count;
	for(int i=1;i<=20;i++)
	{
		sum[i] = 1.0/(2*i);
		count = count + sum[i];
	}
	printf("count = %f\n",count);
}
	
	
		


void zerosort()
{
	int str[10]={3,1,0,0,6,4,0,1,0,8};
	for(int i=0;i<10;i++)
                printf(" %d",str[i]);
	printf("\n");

	for(int i=0;i<10;i++)
		for(int j=0;j<9;j++)
		{
			if(str[j] >  str[j+1])
			{
				int temp;
				temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
		}
	for(int i=0;i<10;i++)
		printf(" %d",str[i]);	
	printf("\n");	
	int zeropoint;
	for(int i=0;i<10;i++)
		if(str[i] != 0)
		{
			zeropoint = i;
			break;
		}
	printf("zeropoint = %d\n",zeropoint);
	int str2[10-zeropoint];	
	for(int i=zeropoint;i<10;i++)
		str2[i-zeropoint] = str[i];	
	for(int i=0;i<6;i++)
                printf(" %d",str2[i]);
        printf("\n");

	

	memcpy(str,&str[4],sizeof(int)*6);
	 for(int i=0;i<10;i++)
                printf(" %d",str[i]);
        printf("\n");


	memset(&str[10-zeropoint],0,zeropoint*sizeof(int));
	for(int i=0;i<10;i++)
        	printf(" %d",str[i]);
        printf("\n");
		
			
}


void delet()
{
	int str[1000];
	for(int i=1;i<1001;i++)
		str[i] = i;
	int k=0;
	while(1)
	{
		int t = 0;
		for(int i=0;i<1000;i++)
		{
			if(str[i] != 0)
				t++;
		}
		if(t == 1)
		{
			for(int i=0;i<1000;i++)
			if(str[i] != 0)
				printf("%d\n",i);
			break;
		}

		while(str[k]==0)
		{
			k=k+1;
			if(k==1000)
                	        k=0;
                	if(k==1001)
                	        k=1;
		}
		while(str[k]==0)
		{
			k=k+1;
			if(k==1000)
        	                k=0;
                	if(k==1001)
                        	k=1;
		}
		
		str[k] = 0;
	}
}
/*		
void compare()
{
	std::string str1("hello sky");
	std::string str2("world");
	auto strlen1 = str1.size();
	auto strlen2 = str2.size();
	if(strlen1==strlen2)
	{
		if(str1 == str2)
			std::cout<<"str1 == str2"<<std::endl;	
		else 
		{
			if(strlen1<=strlen2)
				std::cout<<str1<<std::endl;
			else
				std::cout<<str2<<std::endl;
		}
	}
	else
	{
		if(strlen1>strlen2)
			std::cout<<"str2 is smarter"<<std::endl;
		else
			std::cout<<"str1 is smarter"<<std::endl;
	}
}
*/
void two(std::vector<int> &number,int count)
{
	std::vector<int> mindenumber;
	int mindepoint;
	if(number.size() == 1)
	{
		std::cout<<"two :"<<*number.begin()<<std::endl;
		return;
	}
	if((mindepoint = number.size()/2) == 0)
		mindepoint = 1;
	if(number[mindepoint] == count)
	{
		std::cout<<number[mindepoint]<<std::endl;
		return;
	} 
	if(number[mindepoint] < count)
	{
		for(int i =0;i<mindepoint;i++)
			mindenumber.push_back(number[i]);
		two(mindenumber,count);
	}
	else if(number[mindepoint] > count)
	{
		for(int i = mindepoint;i <number.size();i++)
			mindenumber.push_back(number[i]);
		two(mindenumber,count);
	}
	
}

void vector()
{
        std::vector<int> number;
        std::vector<int>::iterator iter;
	int count;
	int counts;
	std::cout<<"Enter your number choosed of 0 from "<<std::endl;
	std::cin>>counts;
        for(int i =0;i<counts;i++)
                number.push_back(i);
//        for(iter = number.begin();iter != number.end();iter ++)
//                std::cout<<*iter<<" ";
//        std::cout<<std::endl;
	std::cout<<"Enter your number that you want to check"<<std::endl;
	std::cin>>count;
	struct timeval time;
	long int starttime,endtime,fortime,twotime;
	gettimeofday(&time,NULL);
	starttime = time.tv_sec*1000+time.tv_usec/1000;
	for(int i=0;i<counts;i++)
	{
		if(number[i] == count)
		{	std::cout<<"for:"<<number[i]<<std::endl;
			break; 
		}
	}
	gettimeofday(&time,NULL);
	endtime = time.tv_sec*1000+time.tv_usec/1000;
	fortime = endtime - starttime;
	std::cout<<"fortime : "<<fortime<<std::endl;
	gettimeofday(&time,NULL);
	starttime = time.tv_sec*1000+time.tv_usec/1000;
	two(number,count);
	endtime = time.tv_sec*1000+time.tv_usec/1000;
	twotime = endtime -starttime;
	std::cout<<"twotime : "<<twotime<<std::endl;
}
	
void ordersort()
{
        int array[5] = {3,2,1,4,5};
        for(int i=0;i<5;i++)
                for(int j =0;j<4;j++)
                {
                        if(array[j] > array[j+1])
                        {
                                int temp;
                                temp = array[j] ;
                                array[j] = array[j+1];
                                array[j+1] = temp;
                        }
                }
        for(int i=0;i<5;i++)
                printf("%d",array[i]);
}

class Rectangle
{
public:
	Rectangle () = default;
	Rectangle(int Width,int Height):width(Width),height(Height){}
	int getArea(){	return width*height; }

private:
	int width;
	int height;
};

void F_E(int i)
{
	if(i == 1)
	{
		printf("0\n");
		return ;
	}
	if(i == 2)
	{
		printf("1\n");
		return;
	}
	if(i>2)
	{
		int first=0;
		int second=1;
		int third=0;
		for(int j=0;j<i-2;j++)
		{
			third = first + second;
			first = second;
			second = third;
		}
		printf("%d\n",third);
	}
}


struct list
{
	int val;
	struct list *next;
};

struct list *createList()
{
	list *head,*current,*prev;
	head = (struct list *)malloc(sizeof(struct list));
	prev = head;
	for(int i=0;i<7;i++)
	{
		current = (struct list *)malloc(sizeof(struct list));
		current->val=i;
		prev->next = current;
		prev = current;
	}
	head = head->next;
	prev->next=NULL;
	return head;
}
		
void listPrint(struct list *head)
{
	while(head != NULL)
	{
		printf("% d ",head->val);
		head = head->next;
	}
	printf("\n");
}
	
void listDelete(struct list *head)
{
	list *current,*prev;
	if(head == NULL)
		return ;
	prev = head;
	while(prev != NULL)
	{
		if(prev->val == 5)
		{
			if(prev == head)
			{
				head = prev->next;
				current = prev->next;
			}
			else
			{
				current->next=prev->next;
			}
		}
		else
			current = prev;
		prev = prev->next;
	}	
	listPrint(head);
}

void plalindrome()
{
	int cout,count;
	int bit=0;
	printf("Enter your nunber\n");
	scanf("%d",&cout);
	if(cout == 0)
	{
		printf("0 isnt plalindrome\n");
		return ;
	}
	count = cout;
	while(count != 0)
	{
		bit++;
		count=count/10;
	}
	int smart[bit];
	count = cout;
	for(int i = 0;i<bit;i++)
	{
		smart[i]=count%10;
		count = count/10;
	}
	int i=bit-1;
	int j=0;
	while(j != i)
	{
		if(smart[j] == smart[i])
		{
			j++;
			i--;
			if(j>i)
			{
				printf("%d is plalindrome\n",cout);
				return;
			}
		}	
		else
		{
			printf("%d isnt plalindrome\n",cout);
			return;
		}
	}
	printf("%d is plalindrome\n",cout);
}
	
void twoNumberSum()
{
	int array[] = {2,4,5,1,6,7,3};
	int m;
	int target = 9;
	m = sizeof(array);
	int first,second;
	for(int i=0;i<m;i++)
	{
		for(int j= 0;j<m;j++)
			if(array[i] + array[j] == target)
			{
				printf("%d,%d",i,j);
				return ;
			}
	}
}	
	
void listSum()
{
	list *one,*two;
	one = createList();
	two = createList();
	list *current1,*prev1,*current2,*prev2;
	prev1 = one;
	prev2 = two;
	while(prev1 != NULL && prev2 != NULL)
	{
		prev1->val=prev1->val+prev2->val;
	 	prev1=prev1->next;
		prev2=prev2->next;
	}
	listPrint(one);
}
	
void sum(int a,int b)
{
	int x,y;
	while(b!=0)
	{
		x = a^b;
		y = (a&b)<<1;
		a = x;
		b = y;
	}
	printf("%d\n",a);
}

void factorialZero(int target)
{
	int cout=1;
	for(int i=1;i<=target;i++)
	{
		cout = i*cout;
	}
	printf("%d\n",cout);
	int zeroCout=0;
	while( cout > 10)
	{
		if(cout %10 == 0)
		{
			zeroCout++;
			cout=cout/10;
		}
		else
		{
			printf("%d\n",zeroCout);
			return ;
		}
	}
}

int *createRandArray(int cout)
{
	if(cout<=0)
	{
		return NULL;
	}
	int array[cout];
	int *ptr;
	srand(time(NULL));
	for(int i=0;i<cout;i++)
	{
		array[i] = random()%100;
	}
	for(int i = 0;i<cout;i++)
	{
		printf(" %d ",array[i]);
	}
	printf("\n");
	return ptr=array;
}
		



void mindlesort()
{
	int *ptr;
	int cout = 10;
	ptr=createRandArray(cout);
	int temp;
	for(int i=0;i<cout;i++)
		for(int j = 0;j<cout-1;j++)
		{
			if(*(ptr+j) > *(ptr+j+1) )
			{
				temp = *(ptr+j);
				*(ptr+j) = *(ptr+j+1);
				*(ptr+j+1) = temp;
			}
			
		}
	for(int i = 0;i<cout;i++)
        {
                printf(" %d ",*(ptr+i));
        }
	printf("\n");
	
	
}


void quicksort(int array[],int low,int hight)
{
	int i,j,x;
	if(low < hight)
	{
		i=low;
		j=hight;
		x=array[i];
		while(i<j)
		{
			while(i<j && array[j] < x)
				j--;
			if(i<j)
			{
				array[i++] = array[j];
			}
			while(i<j && array[i] > x)
				i++;
			if(i<j) 
			{
				array[j] = array[i];
			}
		}
		array[i] = x;
		quicksort(array,low,i-1);
		quicksort(array,i+1,hight);
	}
}
	
void quicksortfunction()
{
        int *ptr;
	int cout = 10;
	int array[cout];
        ptr = createRandArray(cout);
	for(int i = 0;i<cout;i++)
		array[i] = *(ptr+i);
        quicksort(array,0,10);
}

void vectorEarse()
{
	std::vector<int> nums;
/*	for(int i =0;i<10;i++)
	{
		nums.push_back(i);
	}
	for(int i =0;i<10;i++)
        {
                nums.push_back(i);
        }
	
*/	int xx[] = { 0,-1,21,88,56};
	nums.insert(nums.end(),xx,xx+5);
	std::vector<int>::iterator iter,iter1,iter2;
	for(iter1 = nums.begin();iter1 != nums.end();iter1++)
	{
		for(iter2 = iter1+1;iter2 != nums.end();iter2++)
		{
			if(*(iter1) == *(iter2))
			{
				nums.erase(iter2);
				iter1 = nums.begin();
				iter2 = nums.begin();
			}
		}
	}
	for(iter = nums.begin();iter != nums.end();iter++)
		std::cout<<*iter<<std::endl;
}

struct Point
{
	int x;
	int y;
	Point() :x(0),y(0) {}
	Point(int a,int b) : x(a),y(b) {}
};

struct formula
{
	float k;
	float b;
	formula() : k(0),b(0) {}
	formula(float x,float y) : k(x),b(y) {}
};

void slove(int x1,int y1,int x2,int y2,float &k,float &b)
{
	float k_=0,b_=0;
	std::cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<std::endl;
	if(x1 == x2)
	{
		k = 90;
		b = 0;
		return ;
	}
	k_=(y1-y2)/(x1-x2);
	b_=y1-k_*x1;
	k = k_;
	b = b_;
	std::cout<<"k = "<<k<<" "<<"b = "<<b<<std::endl;	
}

int maxPoints(std::vector<Point> &pointnums)
{
	std::vector<Point> points;
	points = pointnums;
	if( points.size() == 0)
		return 0;
	int length = (int)points.size();
	std::vector<Point>::iterator iter1, iter2;
	std::vector<formula> formulas;
	for(iter1 = points.begin();iter1 != points.end();)
	{
		for( iter2=iter1+1;iter2 != points.end();iter2++)
		{
			float a,b;
			slove(iter1->x,iter1->y,iter2->x,iter2->y,a,b);
//			a=1,b=1;
			formula formulatemp(a,b);
			formulas.push_back(formulatemp);
		}
		points.erase(iter1);
		iter1 = points.begin();
	}
	points = pointnums;
//	formulas.sort();
//	formulas.unique();
	std::cout<<"***********************************************"<<std::endl;
	int len = (int) formulas.size();
	int pointnum[len];
	for(int i = 0;i<len;i++)
	{
		std::cout<<"k = "<<formulas[i].k<<" "<<"b = "<<formulas[i].b<<std::endl;
		if(formulas[i].k = 90)
		{
			for(iter1 = points.begin();iter1 != points.end();iter1++)
			{
				if(iter1->y == (iter1->x * formulas[i].k + formulas[i].b))
					pointnum[i]++;
			}
		}
		for(iter1 = points.begin();iter1 != points.end();iter1++)
		{
				if(iter1->y == (iter1->x * formulas[i].k + formulas[i].b))
                                	pointnum[i]++;
		}

	}
	int temp=0;
	for(int i =0 ;i<len;i++)
	{
		int max = 0;
		temp = pointnum[i];
		if(temp > max)
		{
			max = temp;
		}
	}
	
	return temp;
}

void point()
{
	int num;
	std::vector<Point> points;
	Point point1(1,2),point2(3,6),point3(0,0),point4(1,3);
	points.push_back(point1);
	points.push_back(point2);
	points.push_back(point3);
	points.push_back(point4);

	for(int i= 0;i<points.size();i++)
	{
		std::cout<<"x="<<points[i].x<<" y="<<points[i].y<<std::endl;
	}
	num=maxPoints(points);
	std::cout<<"num = "<< num <<std::endl;
}
	
int main()
{


//	back();
//	map();
//	strcp();
//	openfile();
//	checkstring();
//	strsum();
//	zerosort();
//	delet();
//	compare();
//	vector();
//	ordersort();
//	Rectangle area(5,3);
//	printf("%d",area.getArea());
//	F_E(10);
//	createList();
//	listPrint(createList());
//	listDelete(createList());
//	plalindrome();
//	twoNumberSum();
//	listSum();	
//	sum(3,4);
//	factorialZero(11);
//	mindlesort();
//	quicksortfunction();
//	vectorEarse();
	point();
}




































	

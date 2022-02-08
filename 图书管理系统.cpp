#include<iostream>
#include<string.h>
#include<stdlib.h>
#include <stdio.h> 


using namespace std;


typedef struct
{
	char no[20];	//图书编号 
	char name[20];	//图书名称 
	int price;	//图书价格 
}Book;

typedef struct
{
	Book *elem;		
	int length;
}SqList;

typedef struct                            
{
    char reader_num[10];                           //读者卡号 
    char reader_name[10];                         //读者名
} BO;

//读者模块
typedef struct                            
{
	BO *elem;
	int length;
} RD;

int IntList(SqList &L);
int GetList(SqList &L);
int LocalList(SqList L);
int NumberList(SqList L);
int InsertList(SqList &L);
int DeleteList(SqList &L);
void  ShowList(SqList L);

int IntRD(RD &R);
int GetRD(RD &R);
int LocalRD(RD &R);
int Borrow_book(RD &R,SqList &L);
int also_book(RD &R,SqList &L) ;

void writeBook(SqList &L) ;
void writeReader(RD &R); 
void readBook(SqList &L);
void readReader(RD &R);

int main(){

//	SqList buffer[1000];
	int n,i;
	SqList L;
	RD R;
	IntList(L);
	IntRD(R);
	while(1)
	{
		printf("***********************************\n");
		printf("--------欢迎进入图书管理系统-------\n");
		printf("-------   1、录入图书信息  --------\n");
		printf("-------   2、录入读者信息  --------\n");
		printf("-------   3、插入图书信息  --------\n");
		printf("-------   4、删除图书信息  --------\n");
		printf("-------   5、统计图书数量  --------\n");
		printf("-------   6、查找图书信息 --------\n");
		printf("-------   7、查找读者信息 --------\n");
		printf("-------   8、借书模块      --------\n");
		printf("-------   9、还书模块      --------\n");
		printf("-------   10、读取图书模块  --------\n");
		printf("-------   11、读取读者模块  --------\n");
		printf("-------   0、退出图书管理系统------\n");
		printf("请选择你要执行的操作:");
		scanf("%d",&n);
		switch(n)
		{

		case 1:
			GetList(L);
			writeBook(L);
			break;
		case 2:
			GetRD(R);
			writeReader(R); 
			break;
		case 3:
			InsertList(L);
			break;
		case 4:
			DeleteList(L);
			break;
		case 5:
			NumberList(L);
			break;
		case 6:
			LocalList(L);
			break;
		case 7:
			LocalRD(R);
			break;
		case 8:
			Borrow_book(R,L); 
			break;
		case 9:
			also_book(R,L);
			break; 
		case 10:
			readBook(L);
			break;
		case 11:
			readReader(R);
			break;
		case 0:
			printf("--------   谢谢使用图书管理系统!   --------\n");
			exit(0);
			break;
		default:
			printf("你输入的数字有错，请输入0`6的执行数字。\n");
			break;
		}
	}
	return 0 ; 
} 

/************************************************


******************图书表************************* 


************************************************/ 
//顺序表的初始化
int IntList(SqList &L)
{
	L.elem=new Book[3000];
	if(!L.elem){
		printf("顺序表构造失败!\n");
	exit(-1);
	}
	L.length=0;
	printf("顺序表构造成功!\n");
	return 1;
}

//顺序表的取值
int GetList(SqList &L)
{	
	int x,i;
	printf("请输入你要录入的图书数量:");
	scanf("%d",&x);
	for(i=1;i<=x;i++)
	{
		printf("书号:"); 
		scanf("%s",L.elem[i].no);
		printf("书名:");
		scanf("%s",L.elem[i].name);
		printf("图书价格：");
		//scanf("%d",L.elem[i].price);
		cin>>L.elem[i].price;
			++L.length;
	}
	return 0;
}

//顺序表的元素显示
void  ShowList(SqList L)
{
	int i=1;
	cout<<"书号\t\t"<<"书名\t\t"<<"图书价格"<<endl;
	for(i;i<=L.length;i++){
		cout<<L.elem[i].no<<"\t\t"<<L.elem[i].name<<"\t\t"<<L.elem[i].price<<endl;
	}
}


//顺序表的查找
int LocalList(SqList L)
{
	int i=1;
	int x,c;
	char a[20];
	char b[20];
	printf("1、按书号查找:");
	printf("2、按书名查找:");
	printf("3、按图书价格查找:");
	scanf("%d",&x);
	switch(x)
	{
	case 1:
		printf("请输入你要查询的书号:\n") ;
		scanf("%s",&a);
		for(i;i<=L.length;i++)
		{
			if(!strcmp(L.elem[i].no,a))
			{
				printf("书号\t\t书名\t\t图书价格\n");
				printf("%s\t\t%s\t\t%d\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
			}else{
				printf("此书不在书库中！\n");
			} 
			break;
		}
		break;
	case 2:
		printf("请输入你要查询的书名:\n");
		scanf("%s",&b);
		for(i;i<=L.length;i++)
		{
			if(!strcmp(L.elem[i].name,b))
			{
				printf("书号\t\t书名\t\t图书价格\n");
				printf("%s\t\t%s\t\t%d\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
			}else{
				printf("此书不在书库中！\n");
			}
			break;
		}
		break;
	case 3:
		printf("请输入你要查询的图书价格:");
		scanf("%s",&c);
		for(i;i<=L.length;i++)
		{
			if(L.elem[i].price==c)
			{
				printf("书号\t\t书名\t\t图书价格\n");
				printf("%s\t\t%s\t\t%d\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
			}else{
				printf("此书不在书库中！\n");
			}
			break;
		}
		break;
	default:
		printf("输入的数字选项有错误!\n");
		break;
	}
	return 0;
}

//顺序表的插入
int InsertList(SqList &L)
{
	int i;
	char a[20];
	char b[20];
	int  s;
	printf("请输入你要插入的位置:");
	scanf("%d",i);
	if(i<1||i>L.length+1)
	{
		printf("插入位置不合法!\n");
		return 0;
	}
	if(L.length==30)
	{
		printf("顺序表已经存满!\n");
		return 0;
	}
	for(int j=L.length;j>=i-1;j--)
	{
		L.elem[j+1].price=L.elem[j].price;
		strcpy(L.elem[j+1].name,L.elem[j].name);
		strcpy(L.elem[j+1].no,L.elem[j].no);
	}
	printf("请输入你要添加的图书信息:\n");
	printf("书号");
	scanf("%s",&a);
	strcpy(L.elem[i-1].no,a);
	printf("书名:");
	scanf("%s",&b);
	strcpy(L.elem[i-1].name,b);
	printf("图书价格:");
	scanf("%s",&b);
	L.elem[i-1].price=s;
	L.length++;
	return 0;
}

//顺序表的删除
int DeleteList(SqList &L)
{
	int i;
	printf("请输入你要删除的位置:") ;
	scanf("%d",&i);
	if(i<1||i>L.length)
	{	
		printf("输入的位置不合法!");
		return 0;
	}
	for(int j=i-1;j<L.length;j++)
	{
		L.elem[j].price=L.elem[j+1].price;
		strcpy(L.elem[j].name,L.elem[j+1].name);
		strcpy(L.elem[j].no,L.elem[j+1].no);
	}
	L.length--;
	return 1;
}

//顺序表存储的图书数量
int NumberList(SqList L)
{	
	printf("现有图书的总数量为:%d\n",L.length);
	return 0;
}
/************************************************


******************读者表************************* 


************************************************/ 

//初始化读者表
int IntRD(RD &R)
{
	R.elem=new BO[3000];
	if(!R.elem)
	{	
		printf("读者表构造成功！\n");
		exit(1); 
	}
	R.length=0;
	printf("读者表构造成功！\n");
	return 1;
} 
/**/ 
//读者表的取值（读者登记信息） 
int GetRD(RD &R)
{	
	int x,i; 
	printf("你想输入几位读者:\n");
	scanf("%d",&x);
	for(i=1;i<=x;i++)
	{	
		printf("请输入读者姓名\n");
		scanf("%s",R.elem[i].reader_name);
		printf("请输入读者卡号\n");
		scanf("%s",R.elem[i].reader_num);
			++R.length; 
	}
	return 0;
 } 
//查找读者
int LocalRD(RD &R){
	int i=1;
	int x;
	char a[20];
	char b[20];
	printf("1、按读者姓名查找:");
	printf("2、按读者卡号查找:");
	scanf("%d",&x);
	switch(x)
	{
	case 1:
		printf("请输入你要查询的读者姓名:\n") ;
		scanf("%s",&a);
		for(i;i<=R.length;i++)
		{
			if(!strcmp(R.elem[i].reader_name,a))
			{
				printf("读者姓名\t\t读者卡号\n");
				printf("%s\t\t%s\n",R.elem[i].reader_name,R.elem[i].reader_num);
			}else{
				printf("读者不存在！\n");
			} 
			break;
		}
		break;
	case 2:
		printf("请输入你要查询的读者卡号:\n");
		scanf("%s",&b);
		for(i;i<=R.length;i++)
		{
			if(!strcmp(R.elem[i].reader_num,b))
			{
				printf("读者姓名\t\t读者卡号\n");
				printf("%s\t\t%s\n",R.elem[i].reader_name,R.elem[i].reader_num);
			}else{
				printf("读者不存在！\n");
			}
			break;
		}
		break;
	default:
		printf("输入的数字选项有错误!\n");
		break;
	}
	return 0;
} 
// 借书模块 
int Borrow_book(RD &R,SqList &L) 
{
	int i;
	char re_num[10]; 
	char bo_num[20]; 
	printf("请输入你的借书卡号\n");
	scanf("%s",&re_num);
	for(i=1;i<=R.length;i++)
	{
		if(!strcmp(R.elem[i].reader_num,re_num))	//循环比较卡号 
		{
			printf("请输入你要查询的书名:");
			scanf("%s",&bo_num);
			for(i=1;i<=L.length;i++)
			{
				if(!strcmp(L.elem[i].name,bo_num))
				{
					printf("书号\t\t书名\t\t图书价格\n");
					scanf("%s\t\t%s\t\t%d\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
					printf("借书成功！"); 
				}else{
					printf("对不起，没有这本书！\n");
				}
				break;
			}	
		}else{
			printf("对不起，此卡号不存在！\n");
		}
		break;
	}
	return 0;
}
// 还书模块 
int also_book(RD &R,SqList &L) 
{
	int i;
	char re_num[10]; 
	char bo_name[20]; 
	printf("请输入你的借书卡号\n");
	scanf("%s",&re_num);
	for(i=1;i<=R.length;i++)
	{
		if(!strcmp(R.elem[i].reader_num,re_num))	//循环比较卡号 
		{
			printf("请输入你要还的书名:");
			scanf("%s",&bo_name);
			//L.elem[L.length+1].name=bo_name;
			printf("还书成功！"); 
		}else{
			printf("对不起，此卡号不存在！\n");
		}
		break;
	}
	return 0;
}

/******************************************


文件操作 


*******************************************/


//写入图书文件
void writeBook(SqList &L) {
    if(L.length == 0) {
        printf("图书数量为空!\n");
        return ;
    }
    FILE *fp = fopen("E://book.txt", "w");
    if(fp == NULL){
        printf("读取文件失败");
        return ;
    }
    for(int i = 1;i <= L.length;i++) {
    	//printf("%s,%s,%d",L.elem[i].no,L.elem[i].name,L.elem[i].price);
        fprintf(fp,"%10s%10s%10d",L.elem[i].no,L.elem[i].name,L.elem[i].price);
    }
    fclose(fp); 
    printf("图书写入成功!\n");
}
//写入读者文件
void writeReader(RD &R) {
    if(R.length == 0) {
        printf("读者数量为空!\n");
        return;
    }
    FILE *fp = fopen("E:\\reader.txt", "w");
    if(fp == NULL){
        printf("读取文件失败");
        return ;
    }
    for(int i = 1;i <=R.length;i++) {
        fprintf(fp, "%10s%10s",R.elem[i].reader_name,R.elem[i].reader_num);
    }
    fclose(fp);
    printf("读者信息写入成功!\n");
}
//读取图书文件 
void readBook(SqList &L) {
    FILE *fp = fopen("E://book.txt", "r");
    if(!fp){
        printf("读取文件失败");
        return ;
    }
	int i= 1; 
    while (1) {
        fscanf(fp, "%10s%10s%10d",L.elem[i].no,L.elem[i].name,&L.elem[i].price);
        ++L.length;
        if(feof(fp)) break;
        i++; 
    }
    fclose(fp); 
    printf("图书信息读取成功!\n");
}
//读取读者文件 
void readReader(RD &R) {
    FILE *fp = fopen("E:\\reader.txt", "r");
    
    if(fp == NULL){
        printf("读取文件失败");
        return ;
    }
    int i=1; 
    while (!feof(fp)) {
        fscanf(fp, "%10s%10s",&R.elem[i].reader_name,&R.elem[i].reader_num);
        ++R.length;
        if(feof(fp)) break;
        i++; 
    }
    fclose(fp);
    printf("读者信息读取成功!\n");
}



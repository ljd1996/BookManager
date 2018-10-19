#include"library.h"
void book_search()
{
	char search_num[20],search_title[20];
	Book *book;
	Reader *reader;
	int flag;
	printf("是否查询？按N退出！按任意键进入\n");
	scanf("%c",&charflag);
	fflush(stdin);
	if(charflag=='N')
	{
		system("cls");
	}
	else
	{
		if(book_num==0)
		{
			printf("无图书存储，请在管理员处理后重新查询！\n");
		}
		else
		{
	    while(1)
		{
		    flag=0;
			while(1)
			{
				printf("请输入查询的方式:1.名字    2.编号\n");
			    scanf("%d",&intflag);
	            fflush(stdin);
			    if((intflag!=1)&&(intflag!=2))
		     	printf("输入错误，请重新输入！\n");
		    	else
		    	break;
			}
		if(intflag==1)
		{
			printf("名字:");
			gets(search_title);
	        system("cls");

			book=book_head;
			while(book!=NULL)
			{
				if(strstr(book->title,search_title)!=NULL)//支持模糊查找
				{
					printf("\n===========\n");
					book_display(book);
					flag=1;
				}
				book=book->next;
			}
		}
		else
		{
			printf("编号:");
			gets(search_num);
	        system("cls");

			book=book_head;
			while(book!=NULL)
			{
				if(strcmp(book->num,search_num)==0)
				{
					printf("\n===========\n");
					book_display(book);
					flag=1;
			 	}
			    	book=book->next;
			}
		}
		if(flag!=1)
            printf("该图书不存在！\n");
		printf("\n是否继续查询？按N退出\n");
		scanf("%c",&charflag);
        fflush(stdin);
    	system("cls");
		if(charflag=='N')
		{
		    break;
		}
	}
	system("cls");
	}
	}
}

void book_display(Book *book)
{
	printf("书名:%s\n",book->title);
	printf("编号:%s\n",book->num);
	printf("作者:%s\n",book->author);
	printf("出版社:%s\n",book->publisher);
	printf("类别:%s\n",book->category);
	printf("价格:%f\n",book->price);
	printf("购书时间:%s\n",book->time);
	if(book->state==1)
	printf("该书在库\n");
	else
	printf("该书已被借出\n");
}

#include"library.h"
Reader *reader_login()
{
	Reader *p;
	char pw[20],ID[20];
	while(1)
	{
		p=reader_head;
		printf("请登录...\n");
    	printf("请输入校园卡号:");
	    gets(ID);
    	printf("请输入密码:");
    	gets(pw);
    	while(p!=NULL)
	    {
	    	if((strcmp(p->ID,ID)==0)&&(strcmp(p->pw,pw)==0))
	    	    return p;
		    p=p->next;
		}
		printf("校园卡号或密码错误！请重新登录...\n");
	}
}

Book *num_search()
{
	Book *book;
	char num[20];
	printf("请输入需要查询的图书的编号:");
	gets(num);
	book=book_head;
	while(book!=NULL)
	{
		if(strcmp(book->num,num)==0)
		{
			book_display(book);
			break;
		}
		book=book->next;
	}
	return book;
}

void book_borrow(Reader *reader,Book *book)
{
	Book *p=reader->borrow;
	Reader *pp=manager_head;
	if(((reader->identity_select==1)&&(reader->num<student_num))||((reader->identity_select==2)&&(reader->num<other_num)))//判断读者所借图书数量是否达上线
	{
    	book->state=2;
        fbook_save();
    	if(reader->num==0)
		{
     		reader->borrow=(Book *)malloc(sizeof(Book));
	    	*(reader->borrow)=*book;
	    	reader->borrow->next=NULL;
		}
    	else
		{
	    	Book *p=reader->borrow;
	    	while(p->next!=NULL)
			{
	    		p=p->next;
			}
	    	p->next=(Book *)malloc(sizeof(Book));
	    	*(p->next)=*book;
    		p->next->next=NULL;
		}
    	reader->num++;
    	freader_save();
    	printf("借书成功！\n");
    	while(pp!=NULL)//判断该读者是否为管理员
		{
	    	if(strcmp(pp->ID,reader->ID)==0)
			{
	     		*pp=*reader;
	    		fmanager_save();
	     		break;
			}
	    	pp=pp->next;
		}
	}
	else
	{
		printf("您所借图书已达上限！！！\n");
	}
}
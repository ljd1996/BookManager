#include"library.h"
Reader *reader_login()
{
	Reader *p;
	char pw[20],ID[20];
	while(1)
	{
		p=reader_head;
		printf("���¼...\n");
    	printf("������У԰����:");
	    gets(ID);
    	printf("����������:");
    	gets(pw);
    	while(p!=NULL)
	    {
	    	if((strcmp(p->ID,ID)==0)&&(strcmp(p->pw,pw)==0))
	    	    return p;
		    p=p->next;
		}
		printf("У԰���Ż�������������µ�¼...\n");
	}
}

Book *num_search()
{
	Book *book;
	char num[20];
	printf("��������Ҫ��ѯ��ͼ��ı��:");
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
	if(((reader->identity_select==1)&&(reader->num<student_num))||((reader->identity_select==2)&&(reader->num<other_num)))//�ж϶�������ͼ�������Ƿ������
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
    	printf("����ɹ���\n");
    	while(pp!=NULL)//�жϸö����Ƿ�Ϊ����Ա
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
		printf("������ͼ���Ѵ����ޣ�����\n");
	}
}
#include"library.h"
void book_search()
{
	char search_num[20],search_title[20];
	Book *book;
	Reader *reader;
	int flag;
	printf("�Ƿ��ѯ����N�˳��������������\n");
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
			printf("��ͼ��洢�����ڹ���Ա��������²�ѯ��\n");
		}
		else
		{
	    while(1)
		{
		    flag=0;
			while(1)
			{
				printf("�������ѯ�ķ�ʽ:1.����    2.���\n");
			    scanf("%d",&intflag);
	            fflush(stdin);
			    if((intflag!=1)&&(intflag!=2))
		     	printf("����������������룡\n");
		    	else
		    	break;
			}
		if(intflag==1)
		{
			printf("����:");
			gets(search_title);
	        system("cls");

			book=book_head;
			while(book!=NULL)
			{
				if(strstr(book->title,search_title)!=NULL)//֧��ģ������
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
			printf("���:");
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
            printf("��ͼ�鲻���ڣ�\n");
		printf("\n�Ƿ������ѯ����N�˳�\n");
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
	printf("����:%s\n",book->title);
	printf("���:%s\n",book->num);
	printf("����:%s\n",book->author);
	printf("������:%s\n",book->publisher);
	printf("���:%s\n",book->category);
	printf("�۸�:%f\n",book->price);
	printf("����ʱ��:%s\n",book->time);
	if(book->state==1)
	printf("�����ڿ�\n");
	else
	printf("�����ѱ����\n");
}

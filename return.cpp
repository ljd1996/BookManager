#include"library.h"
void book_return()
{
	Reader *reader,*q;
	Book *book,*pp,*qq;
	reader=reader_login();
	reader_display(reader);
	printf("是否还书？按N退出！按任意键进入\n");
	scanf("%c",&charflag);
	fflush(stdin);
	if(charflag=='N')
	{
		system("cls");
	}
	else
	{
		while(1)
		{
        	intflag=0;
			book=num_search();
			pp=reader->borrow;//所借图书的头指针
			while(pp!=NULL)
			{
				if(strcmp(book->num,pp->num)==0)
				{
					if(pp==reader->borrow)
					reader->borrow=pp->next;
					else
					qq->next=pp->next;
					free(pp);
					reader->num--;
					freader_save();
					book->state=1;
					fbook_save();
                    q=manager_head;
                    while(q!=NULL)
					{
                     	if(reader->ID==q->ID)
						{
    	                	*q=*reader;
    	                	fmanager_save();
						}
                    	q=q->next;
					}
					intflag=1;
					break;
				}
				else
				{
					qq=pp;
					pp=pp->next;
				}
			}
	    	if(intflag==1)
			{
		    	printf("还书成功，是否继续还书？按N退出！按任意键继续\n");
		    	scanf("%c",&charflag);
		    	fflush(stdin);
		    	if(charflag=='N')
				{
			    	system("cls");
			    	break;
				}
			}
	    	else
			{
		    	printf("编号输入有误，请重新还书！\n");
		    	system("pause");
		    	system("cls");
				break;
			}
		}
    	system("cls");
	}
}

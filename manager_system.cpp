#include"library.h"
void manager_system()
{
	Reader *manager;
	printf("\n\n===================\n");
	printf("欢迎进去管理系统，按任意健继续！\n");
	printf("\n\n===================\n");
	system("pause");
	system("cls");
	printf("是否登录管理员帐号，按N退出！按任意键继续\n");
	scanf("%c",&charflag);
	if(charflag=='N')
	{
		system("cls");
	}
	else
	{
		manager=manager_login();
		system("cls");
	    if(manager==manager_head)
		{
    	    manager_menu1();//主管理员功能菜单
		}
    	else
		{
    	   	manager_menu2();//次管理员功能菜单
		}
	}
}

Reader *manager_login()
{
	char manager_ID[20],manager_pw[20];
    Reader *p;
	while(1)
	{
	p=manager_head;
    fflush(stdin);
    printf("帐号:");
	gets(manager_ID);
	printf("密码:");
	gets(manager_pw);
	while(p!=NULL)
	{
		if((strcmp(p->ID,manager_ID)==0)&&(strcmp(p->pw,manager_pw)==0))
		{
			return p;
		}
		p=p->next;
	}
	printf("账号或密码错误!请重新登陆\n");
	}//while
}

void manager_menu1()
{
    Reader *p;
	while(1)
	{
		int cn;
	    char s[2];
	    printf("请选择:(数字代表后面的选项)\n");
	    printf("1.新增读者\n");
	    printf("2.新增管理员\n");
    	printf("3.新增图书\n");
    	printf("4.系统设置\n");
    	printf("5.删除读者\n");
    	printf("6.删除管理员\n");
    	printf("7.删除图书\n");
    	printf("8.修改读者信息\n");
    	printf("9.修改图书信息\n");
    	printf("10.查看读者信息\n");
    	printf("11.返回主菜单\n");
    	while(1)
    	{
    		gets(s);
	    	cn=atoi(s);
	    	if(cn<1||cn>11)
	    	printf("输入错误，重新输入！\n");
	    	else
	    	break;
     	}
    	system("cls");
        fflush(stdin);
		switch(cn)
		{
			case 1:
			reader_save();
			break;
			case 2:
			manager_save();
			break;
			case 3:
			book_save();
			break;
			case 4:
			system_setting();
			break;
			case 5:
			reader_del();
			break;
			case 6:
			manager_del();
			break;
			case 7:
		    book_del();
			break;
			case 8:
		    reader_change();
			break;
			case 9:
			book_change();
			break;
			case 10:
			p=reader_head;
			char ID[20];
			printf("是否继续？按N退出！按任意键继续\n");
			scanf("%c",&charflag);
        	if(charflag=='N')
        	{
        		system("cls");
        	}
       	else
	       {
	       	printf("请输入想要查看的读者的ID\n");
	       	gets(ID);
	       	while(p!=NULL)
	       	{
	       		if(strcmp(p->ID,ID)==0)
	       		{
	       			reader_display(p);
	       		    break;
	       		}
	       		p=p->next;
	       	}
	       }
	       break;
	       case 11:
	       return;
		}
	}
}

void manager_menu2()
{
    Reader *p;
	fflush(stdin);
	while(1)
	{
		int cn;
	    char s[2];
	    printf("请选择:(数字代表后面的选项)\n");
	    printf("1.新增读者\n");
    	printf("2.新增图书\n");
    	printf("3.系统设置\n");
    	printf("4.删除读者\n");
    	printf("5.删除图书\n");
    	printf("6.修改读者信息\n");
    	printf("7.修改图书信息\n");
    	printf("8.查看读者信息\n");
    	printf("9.返回主菜单\n");
    	while(1)
    	{
    		gets(s);
	    	cn=atoi(s);
	    	if(cn<1||cn>9)
	    	printf("输入错误，重新输入！\n");
	    	else
	    	break;
     	}
    	system("cls");
        fflush(stdin);
		switch(cn)
		{
			case 1:
			reader_save();
			break;
			case 2:
			book_save();
			break;
			case 3:
			system_setting();
			break;
			case 4:
			reader_del();
			break;
			case 5:
		    book_del();
			break;
			case 6:
		    reader_change();
			break;
			case 7:
			book_change();
			break;
			case 8:
			p=reader_head;
			char ID[20];
			printf("是否继续？按N退出！按任意键进入\n");
			scanf("%c",&charflag);
        	if(charflag=='N')
        	{
        		system("cls");
        	}
         	else
			{
	       	printf("请输入想要查看的读者的ID\n");
	       	gets(ID);
	       	while(p!=NULL)
	       	{
	       		if(strcmp(p->ID,ID)==0)
	       		{
	       			reader_display(p);
	       		    break;
	       		}
	       		p=p->next;
	       	}
			}
	       break;
	       case 9:
	       return;
		}
	}
}


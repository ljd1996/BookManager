#include"library.h"
void manager_system()
{
	Reader *manager;
	printf("\n\n===================\n");
	printf("��ӭ��ȥ����ϵͳ�������⽡������\n");
	printf("\n\n===================\n");
	system("pause");
	system("cls");
	printf("�Ƿ��¼����Ա�ʺţ���N�˳��������������\n");
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
    	    manager_menu1();//������Ա���ܲ˵�
		}
    	else
		{
    	   	manager_menu2();//�ι���Ա���ܲ˵�
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
    printf("�ʺ�:");
	gets(manager_ID);
	printf("����:");
	gets(manager_pw);
	while(p!=NULL)
	{
		if((strcmp(p->ID,manager_ID)==0)&&(strcmp(p->pw,manager_pw)==0))
		{
			return p;
		}
		p=p->next;
	}
	printf("�˺Ż��������!�����µ�½\n");
	}//while
}

void manager_menu1()
{
    Reader *p;
	while(1)
	{
		int cn;
	    char s[2];
	    printf("��ѡ��:(���ִ�������ѡ��)\n");
	    printf("1.��������\n");
	    printf("2.��������Ա\n");
    	printf("3.����ͼ��\n");
    	printf("4.ϵͳ����\n");
    	printf("5.ɾ������\n");
    	printf("6.ɾ������Ա\n");
    	printf("7.ɾ��ͼ��\n");
    	printf("8.�޸Ķ�����Ϣ\n");
    	printf("9.�޸�ͼ����Ϣ\n");
    	printf("10.�鿴������Ϣ\n");
    	printf("11.�������˵�\n");
    	while(1)
    	{
    		gets(s);
	    	cn=atoi(s);
	    	if(cn<1||cn>11)
	    	printf("��������������룡\n");
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
			printf("�Ƿ��������N�˳��������������\n");
			scanf("%c",&charflag);
        	if(charflag=='N')
        	{
        		system("cls");
        	}
       	else
	       {
	       	printf("��������Ҫ�鿴�Ķ��ߵ�ID\n");
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
	    printf("��ѡ��:(���ִ�������ѡ��)\n");
	    printf("1.��������\n");
    	printf("2.����ͼ��\n");
    	printf("3.ϵͳ����\n");
    	printf("4.ɾ������\n");
    	printf("5.ɾ��ͼ��\n");
    	printf("6.�޸Ķ�����Ϣ\n");
    	printf("7.�޸�ͼ����Ϣ\n");
    	printf("8.�鿴������Ϣ\n");
    	printf("9.�������˵�\n");
    	while(1)
    	{
    		gets(s);
	    	cn=atoi(s);
	    	if(cn<1||cn>9)
	    	printf("��������������룡\n");
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
			printf("�Ƿ��������N�˳��������������\n");
			scanf("%c",&charflag);
        	if(charflag=='N')
        	{
        		system("cls");
        	}
         	else
			{
	       	printf("��������Ҫ�鿴�Ķ��ߵ�ID\n");
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


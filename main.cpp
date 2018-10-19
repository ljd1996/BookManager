#include"library.h"
int book_num=0;
int reader_num=0;
int manager_num=0;
int student_num=0;
int other_num=0;
char charflag;
int intflag=0;
char system_information[100]=" ";
Book *book_head=NULL;
Reader *reader_head=NULL;
Reader *manager_head=NULL;
int main()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n                              ==================\n");
	printf("                              欢迎来到图书馆借阅管理系统！！！\n");
	printf("                              ==================\n\n\n\n\n\n");
	system("pause");
	system("cls");
	initialization();
	load();
    menu_select();
    return 0;
}

void initialization()
{
	FILE *fp;
	if((fp=fopen("fmanager","rb"))==NULL)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n                              欢迎初次实用该系统，请主管理员注册登录存入相关信息！\n\n\n\n\n\n\n");
		system("pause");
    	system("cls");
    	printf("请确定学生和非在校所借阅图书的最大值！\n");
    	printf("学生:");
    	scanf("%d",&student_num);
    	printf("非在校生:");
    	scanf("%d",&other_num);
    	system("pause");
    	system("cls");
    	printf("请输入主管理员的相关信息完成注册:\n");
    	main_manager_save();
	}
}

void menu_select()
{
    Reader *reader;
	while(1)
	{
		int cn;
	    char s[2];
	    printf("请选择:(数字代表后面的选项)\n");
	    printf("1.图书查询\n");
	    printf("2.图书借阅\n");
	    printf("3.图书归还\n");
	    printf("4.管理系统\n");
	    printf("5.系统消息\n");
	    printf("6.退出系统\n");
	    while(1)
	    {
			fflush(stdin);
	    	gets(s);
	    	cn=atoi(s);
	    	if(cn<1||cn>6)
	    	printf("输入错误，重新输入！\n");
	    	else
		    break;
    	}
    	system("cls");
        fflush(stdin);
		switch(cn)
		{
			case 1:
				book_search();
			    break;
			case 2:
                printf("是否继续？按N退出！按任意键进入\n");
            	scanf("%c",&charflag);
            	fflush(stdin);
            	if(charflag=='N')
				{
	            	system("cls");
				}
				else
				{
			 	reader=reader_login();
			    while(1)
				{
					Book *book=num_search();
			        if(book!=NULL)
					{
                    	if(book->state==2)
						{
                	        system("pause");
                        	system("cls");
                	    	break;
						}
						book_borrow(reader,book);
			            printf("\n是否继续借阅？按N退出！按任意键进入\n");
			        	scanf("%c",&charflag);
						fflush(stdin);
			            if(charflag=='N')
							break;
					}
			        else
					{
						printf("查无此书!\n");
						break;
					}
				}
			    system("pause");
        	    system("cls");
				}
		    	break;
			case 3:
			    book_return();
		    	break;
			case 4:
				manager_system();
		     	break;
			case 5:
		    	system_information_display();
		    	break;
			case 6:
		    	exit(0);
		}
	}
}

void load()
{
	FILE *fp;
	Reader *p1;
	Reader *p2;
	Book *p3;
	printf("数据载入中...");
	if((fp=fopen("fdata","rb"))==NULL)
	{
		printf("error!!!\n");
		exit(1);
	}
	fread(&book_num,sizeof(int),1,fp);
	fread(&reader_num,sizeof(int),1,fp);
	fread(&manager_num,sizeof(int),1,fp);
	fread(&student_num,sizeof(int),1,fp);
	fread(&other_num,sizeof(int),1,fp);
    fread(system_information,100*sizeof(char),1,fp);
	fclose(fp);//读出相关数据
	if((fp=fopen("freader","rb"))==NULL)
	{
		printf("error!!!\n");
		exit(1);
	}
	p1=reader_head=(Reader *)malloc(sizeof(Reader));
	while(1)
	{
		fread(p1,sizeof(Reader),1,fp);
		if(!feof(fp))
		{
			p1->next=(Reader *)malloc(sizeof(Reader));
		    p1=p1->next;
		}
		else
			break;
	}
	p1->next=NULL;
	fclose(fp);//把文件内容读出
	if((fp=fopen("fmanager","rb"))==NULL)
	{
		printf("error!!!\n");
		exit(1);
	}
	p2=manager_head=(Reader *)malloc(sizeof(Reader));
	while(1)
	{
		fread(p2,sizeof(Reader),1,fp);
		if(!feof(fp))
		{
			p2->next=(Reader *)malloc(sizeof(Reader));
		    p2=p2->next;
		}
		else
			break;
	}
	p2->next=NULL;
	fclose(fp);//把文件内容读出
	if((fp=fopen("fbook","rb"))==NULL)
	{
		printf("error!!!\n");
		exit(1);
	}
	p3=book_head=(Book *)malloc(sizeof(Book));
	while(1)
	{
		fread(p3,sizeof(Book),1,fp);
		if(!feof(fp))
		{
			p3->next=(Book *)malloc(sizeof(Book));
		    p3=p3->next;
		}
		else
			break;
	}
	p3->next=NULL;
	fclose(fp);//把文件内容读出
    system("pause");
	system("cls");
}

void main_manager_save()
{
	Reader *preader_register;
	preader_register=(Reader *)malloc(sizeof(Reader));
    	while(1)
    	{
    		printf("请选择身份:1.学生  2.非在校生\n请选择:");
    		scanf("%d",&preader_register->identity_select);
			fflush(stdin);
    		if((preader_register->identity_select!=1)&&(preader_register->identity_select!=2))
    		{
    			printf("输入有误，请重新输入！\n");
    		}
    		else
    		{
    			break;
    		}
    	}
    	printf("姓名:");
    	scanf("%s",preader_register->name);
    	printf("校园卡号:");
    	scanf("%s",preader_register->ID);
    	while(1)
    	{
			fflush(stdin);
    		printf("性别:(M代表男，W代表女)");
    		scanf("%c",&preader_register->sex);
			fflush(stdin);
    		if((preader_register->sex!='M')&&(preader_register->sex!='W'))
    		{
    			printf("输入有误，请重新输入！\n");
    		}
    		else
    		{
    			break;
    		}
    	}
    printf("电话:");
    scanf("%s",preader_register->tel);
    printf("所在院系:");
    scanf("%s",preader_register->faculty);
    printf("所在班级:");
    scanf("%s",preader_register->clas);
    printf("校园卡密码:");
    scanf("%s",preader_register->pw);
    preader_register->num=0;
    if(preader_register->identity_select==1)
    {
    	preader_register->limit=student_num;
    }
    else
    {
    	preader_register->limit=other_num;
    }
    preader_register->borrow=NULL;
    preader_register->next=NULL;//信息输入完毕
    manager_head=preader_register;
    manager_head->next=NULL;//将主管理员作为管理员链表的头结点
    reader_head=preader_register;
    reader_head->next=NULL;//将主管理员作为读者链表的头结点
    manager_num++;
    fmanager_save();
    reader_num++;
   	freader_save();
	fbook_save();
   	data_save();
	free(preader_register);
}

void system_information_display()
{
	printf("\n\n\n\n\n            ");
	if(strcmp(system_information," ")==0)
	printf("无系统通知!");
	else
	puts(system_information);
	printf("\n\n\n\n\n");
	system("pause");
	system("cls");
}
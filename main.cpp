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
	printf("                              ��ӭ����ͼ��ݽ��Ĺ���ϵͳ������\n");
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
		printf("\n\n\n\n\n\n\n\n\n\n\n\n                              ��ӭ����ʵ�ø�ϵͳ����������Աע���¼���������Ϣ��\n\n\n\n\n\n\n");
		system("pause");
    	system("cls");
    	printf("��ȷ��ѧ���ͷ���У������ͼ������ֵ��\n");
    	printf("ѧ��:");
    	scanf("%d",&student_num);
    	printf("����У��:");
    	scanf("%d",&other_num);
    	system("pause");
    	system("cls");
    	printf("������������Ա�������Ϣ���ע��:\n");
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
	    printf("��ѡ��:(���ִ�������ѡ��)\n");
	    printf("1.ͼ���ѯ\n");
	    printf("2.ͼ�����\n");
	    printf("3.ͼ��黹\n");
	    printf("4.����ϵͳ\n");
	    printf("5.ϵͳ��Ϣ\n");
	    printf("6.�˳�ϵͳ\n");
	    while(1)
	    {
			fflush(stdin);
	    	gets(s);
	    	cn=atoi(s);
	    	if(cn<1||cn>6)
	    	printf("��������������룡\n");
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
                printf("�Ƿ��������N�˳��������������\n");
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
			            printf("\n�Ƿ�������ģ���N�˳��������������\n");
			        	scanf("%c",&charflag);
						fflush(stdin);
			            if(charflag=='N')
							break;
					}
			        else
					{
						printf("���޴���!\n");
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
	printf("����������...");
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
	fclose(fp);//�����������
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
	fclose(fp);//���ļ����ݶ���
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
	fclose(fp);//���ļ����ݶ���
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
	fclose(fp);//���ļ����ݶ���
    system("pause");
	system("cls");
}

void main_manager_save()
{
	Reader *preader_register;
	preader_register=(Reader *)malloc(sizeof(Reader));
    	while(1)
    	{
    		printf("��ѡ�����:1.ѧ��  2.����У��\n��ѡ��:");
    		scanf("%d",&preader_register->identity_select);
			fflush(stdin);
    		if((preader_register->identity_select!=1)&&(preader_register->identity_select!=2))
    		{
    			printf("�����������������룡\n");
    		}
    		else
    		{
    			break;
    		}
    	}
    	printf("����:");
    	scanf("%s",preader_register->name);
    	printf("У԰����:");
    	scanf("%s",preader_register->ID);
    	while(1)
    	{
			fflush(stdin);
    		printf("�Ա�:(M�����У�W����Ů)");
    		scanf("%c",&preader_register->sex);
			fflush(stdin);
    		if((preader_register->sex!='M')&&(preader_register->sex!='W'))
    		{
    			printf("�����������������룡\n");
    		}
    		else
    		{
    			break;
    		}
    	}
    printf("�绰:");
    scanf("%s",preader_register->tel);
    printf("����Ժϵ:");
    scanf("%s",preader_register->faculty);
    printf("���ڰ༶:");
    scanf("%s",preader_register->clas);
    printf("У԰������:");
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
    preader_register->next=NULL;//��Ϣ�������
    manager_head=preader_register;
    manager_head->next=NULL;//��������Ա��Ϊ����Ա�����ͷ���
    reader_head=preader_register;
    reader_head->next=NULL;//��������Ա��Ϊ���������ͷ���
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
	printf("��ϵͳ֪ͨ!");
	else
	puts(system_information);
	printf("\n\n\n\n\n");
	system("pause");
	system("cls");
}
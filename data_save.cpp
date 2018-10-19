#include"library.h"
void data_save()
{
	FILE *fp;
	if((fp=fopen("fdata","wb"))==NULL)
	{
		printf("error!!!\n");
		exit(1);
	}
	fwrite(&book_num,sizeof(int),1,fp);
	fwrite(&reader_num,sizeof(int),1,fp);
	fwrite(&manager_num,sizeof(int),1,fp);
	fwrite(&student_num,sizeof(int),1,fp);
	fwrite(&other_num,sizeof(int),1,fp);
    fwrite(system_information,100*sizeof(char),1,fp);
	fclose(fp);//存入相关数据
}

void fbook_save()
{
	FILE *fp;
	Book *p=book_head;
	if((fp=fopen("fbook","wb"))==NULL)
	{
		printf("error!!\n");
        exit(1);
    }
	while(p!=NULL)
	{
		fwrite(p,sizeof(Book),1,fp);
		p=p->next;
	}
    fclose(fp);
}

void fmanager_save()
{
	FILE *fp;
	Reader *p=manager_head;
	if((fp=fopen("fmanager","wb"))==NULL)
	{
		printf("error!!\n");
        exit(1);
    }
	while(p!=NULL)
	{
		fwrite(p,sizeof(Reader),1,fp);
		p=p->next;
	}
    fclose(fp);
}

void freader_save()
{
	FILE *fp;
	Reader *p=reader_head;
	if((fp=fopen("freader","wb"))==NULL)
	{
		printf("error!!\n");
        exit(1);
    }
	while(p!=NULL)
	{
		fwrite(p,sizeof(Reader),1,fp);
		p=p->next;
	}
    fclose(fp);
}
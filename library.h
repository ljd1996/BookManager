#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Book//ͼ����Ϣ�Ľṹ��
{
	char  num[20];//ͼ����
	char  title[20];//ͼ������
	char  author[10];//ͼ������
	float  price;//ͼ��۸�
	char  publisher[30];//��������Ϣ
	char  category[10];//ͼ�����
	char  time[10];//����ʱ��
	int state;//ͼ��״̬(1Ϊ�ڿ� 2Ϊ���)
	struct Book *next;
} Book;
typedef struct Reader//������Ϣ�Ľṹ��
{
	int identity_select;//�������ѡ��
	char  name[10];//����
	char  ID[20];//һ��ͨ���
	char  sex;//�Ա�
	char tel[12];//�绰
	char faculty[20];//����Ժϵ
	char clas[20];//�༶
	char  pw[20];//����
	int  num;//������ͼ�����Ŀ
	int  limit;//������ͼ����Ŀ
	Book *borrow;//����ͼ����Ϣ�Ľṹ��
	struct Reader *next;
} Reader;
extern char charflag;//�����ж��Ƿ�(Y/N)�ı���
extern int intflag;
extern char system_information[100];//ϵͳ֪ͨ
extern int book_num;//ͼ������
extern int reader_num;//��������
extern int manager_num;//����Ա����
extern int student_num;//ѧ����������
extern int other_num;//����У����������
extern Book *book_head;//ͼ������ͷָ��
extern Reader *reader_head;//��������ͷָ��
extern Reader *manager_head;//����Ա����ͷָ��
void initialization();
void menu_select();
void load();
void book_search();
void book_display(Book *);
void reader_display(Reader *);
Book *num_search();
Reader *reader_login();
void book_borrow(Reader *,Book *);
void book_return();
void manager_system();
Reader *manager_login();
void manager_menu1();
void manager_menu2();
void reader_save();
void manager_save();
void main_manager_save();
void book_save();
void reader_del();
void manager_del();
void book_del();
void reader_change();
void book_change();
void system_setting();
void system_information_display();
void data_save();
void freader_save();
void fmanager_save();
void fbook_save();
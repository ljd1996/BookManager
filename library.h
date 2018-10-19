#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
typedef struct Book//图书信息的结构体
{
	char  num[20];//图书编号
	char  title[20];//图书名字
	char  author[10];//图书作者
	float  price;//图书价格
	char  publisher[30];//出版社信息
	char  category[10];//图书类别
	char  time[10];//购买时间
	int state;//图书状态(1为在库 2为借出)
	struct Book *next;
} Book;
typedef struct Reader//读者信息的结构体
{
	int identity_select;//读者身份选择
	char  name[10];//姓名
	char  ID[20];//一卡通编号
	char  sex;//性别
	char tel[12];//电话
	char faculty[20];//所在院系
	char clas[20];//班级
	char  pw[20];//密码
	int  num;//所借阅图书的数目
	int  limit;//最多借阅图书数目
	Book *borrow;//所借图书信息的结构体
	struct Reader *next;
} Reader;
extern char charflag;//用于判断是否(Y/N)的变量
extern int intflag;
extern char system_information[100];//系统通知
extern int book_num;//图书总量
extern int reader_num;//读者数量
extern int manager_num;//管理员总量
extern int student_num;//学生借阅数量
extern int other_num;//非在校生借阅数量
extern Book *book_head;//图书链表头指针
extern Reader *reader_head;//读者链表头指针
extern Reader *manager_head;//管理员链表头指针
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
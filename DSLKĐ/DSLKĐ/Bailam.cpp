#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
using namespace std;

struct Node
{
	int info; 
	Node* next;
};

struct  List
{
	Node* head;
	Node* tail;
};

void initList(List& l)
{
	l.head = NULL;
	l.tail = NULL;
}

int CheckEmpty(List l)
{
	if (l.head == NULL)
		return 1;
	else
		return 0;
}

Node* createNode(int x)
{
	Node* p = new Node;
	if (p == NULL)
		printf("Ko the cap phat");
	p->info = x;
	p->next = NULL;
	return p;
}

void AddNodetoList(List& l, Node*& p)
{
	if (p == NULL)
		return;
	else
	{
		if (l.head == NULL)
			l.head = l.tail = p;
		else
		{
			l.tail->next = p;
			l.tail = p;
		}
	}
}

void createList(List& l, int& n)
{
	int x;
	initList(l);
	Node* p;
	do
	{
		printf("Cho biet so phan tu cua danh sach (n > 0): ");
		scanf("%d", &n);
	} while (n <= 0);
	for (int i = 1; i <= n; i++)
	{
		printf("Nhap phan tu thu %d la: ", i);
		scanf("%d", &x);
		p = createNode(x);
		if (p == NULL)
		{
			printf("khong du bo nho \n");
			_getch();
			return;
		}
		AddNodetoList(l, p);
	}
}

void ShowList(List l)
{
	for (Node* k = l.head; k != NULL; k = k->next)
	{
		printf("=> %d \t", k->info);
	}
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void insertNode(List l, Node* q, Node* p)
{
	if (q == NULL || p == NULL)
		return;

	p->next = q->next;
	q->next = p;
}

void Insert(List l, int& x)
{
	int a = 0;
	printf("nhap phan tu muon chen sau no: ");
	scanf("%d", &a);


	Node* q = createNode(x);
	for (Node* k = l.head; k != NULL; k = k->next)
	{
		if (k->info == a)
			insertNode(l, k, q);
	}
}

int DeleteHead(List& l, int& x)
{
	if (CheckEmpty(l) == 1)
		return 0;
	Node* p = l.head;
	l.head = l.head->next;
	if (l.head == NULL)
		l.tail = NULL;
	x = p->info;
	delete p;
	return 1;
}
int DeleteAfter(List& l, Node* q, int& x)
{
	if (q == NULL || q->next == NULL)
		return 0;
	Node* p = q->next;
	q->next = p->next;
	if (l.tail == p)
		l.tail = q;
	x = p->info;
	delete p;
	return 1;
}

int DeleteNodeX(List& l, int x)
{
	if (CheckEmpty(l) == 1)
		return 0;
	Node* p = l.head;
	Node* q = NULL;
	while ((p!=NULL) && (p->info !=x))
	{
		q = p;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	if (p == l.head)
		DeleteHead(l, x);
	else
		DeleteAfter(l, q, x);
	return 1;
}

int findNode(List l, int x)
{
	if (CheckEmpty(l) == 1)
		return 0;
	Node* p = l.head;
	Node* q = NULL;
	while ((p != NULL) && (p->info != x))
	{
		q = p;
		p = p->next;
	}
	if (p == NULL)
		printf("Khong tim thay phan tu ban muon tim !");
	else
		printf("Da tim thay phan tu ban muon tim la %d.", x);
	return 1;
	
}

void SapXepDanhSach(List l)
{
	for (Node* k = l.head; k != l.tail; k = k->next)
		for (Node* q = k; q != NULL; q = q->next)
			if (k->info > q->info)
				swap(k->info, q->info);
	printf("\nSap xep danh sach theo thu tu tang dan: ");
	ShowList(l);

	printf("\n");

	for (Node* k = l.head; k != l.tail; k = k->next)
		for (Node* q = k; q != NULL; q = q->next)
			if (k->info < q->info)
				swap(k->info, q->info);
	printf("\nSap xep danh sach theo thu tu giam dan: ");
	ShowList(l);
}

int Dem(List& l)
{
	int count = 0;
	Node* p = l.head;
	while (p!=NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

int TimMax(List l) {
	int max = 0;
	Node* p = l.head;
	while (p != NULL) {
		if (p->info > max) {
			max = p->info;
		}
		p = p->next;
	}
	return max;
}
void XuatChan(List l) {
	int count = 0;
	Node* p = l.head;
	while (p != NULL) {
		if (count % 2 == 0) {
			printf("%d ", p->info);
		}
		count++;
		p = p->next;
	}
	printf("\n");
}
void XoaTrung(List& l) {
	Node* p = l.head;
	Node* q;
	while (p != NULL) {
		q = p->next;
		while (q != NULL) {
			if (q->info == p->info) {
				q = q->next;
				p->next = q;
			}
			else {
				q = q->next;
			}
		}
		p = p->next;
	}
}
void main()
{
	List l;
	initList(l);
	if (CheckEmpty(l) == 1)
		printf("danh sach cua ban dang rong!\nvui long nhap nhap phan tu de tao danh sach!\n\n");
	int n = 0;
	createList(l, n);
	ShowList(l);
	/*printf("\n\nBan muon chen them mot phan tu x ?\n");
	int x = 0;
	printf("Nhap gia tri can chen: ");
	scanf("%d", &x);
	Insert(l, x);
	printf("Them thanh cong !\n");
	ShowList(l);*/
	/*printf("\n\nBan muon xoa phan tu x ?\n");
	int z = 0;
	printf("Nhap phan tu x ban muon xoa: ");
	scanf("%d", &z);
	DeleteNodeX(l, z);
	printf("Xoa thanh cong !\n");
	ShowList(l);*/
	/*printf("\n\nBan muon tim phan tu x ?\n");
	int c = 0;
	printf("nhap phan tu ban muon tim: ");
	scanf("%d", &c);
	findNode(l, c);*/
	/*printf("\n\nSap xep danh sach\n");
	SapXepDanhSach(l);*/
	/*int count = Dem(l);
	printf("\n\nSo phan tu trong danh sach: %d", count);*/
	/*int max = TimMax(l);
	printf("\n\nPhan tu lon nhat trong danh sach: %d", max);*/
	printf("\nXoa phan tu trung");
	XoaTrung(l);
	printf("\nXoa thanh cong!\n");
	ShowList(l);
}
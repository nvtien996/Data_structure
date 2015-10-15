/*
	Thuc hanh tuan 5: LinkedList
	Tac gia: Nguyen Thi Huyen Trang
	MSSV: 14020484

*/

#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

// Kieu Node bieu dien 1 nut trong DSLK don
struct Node
{
    int data;
    Node * next;
};

// Them nut chua value vao dau DSLK
void addFirst(Node *& head, int value){
    // tao nut moi
    Node * tmp = new Node;
    tmp->data = value;
    tmp->next = NULL;

    if(head == NULL){
        // them trong truong hop DS rong
        head = tmp;
    } else{
        // them trong truong hop DS khong rong
        tmp->next = head;
        head = tmp;
    }
}

//them nut chua value vao cuoi danh sach
void append(Node *& head, int v)
{
	Node *tmp, *p;
    tmp = new Node;
    tmp->data = v;
	tmp->next = NULL;

	if(head == NULL)
        head = tmp;
	else
	{
        p = head;
        while(p->next != NULL)
		{
            p = p->next;
        }
        p->next = tmp;
    }
}

// Doc day so trong tep co ten filename vao DSLK
void readFile(Node *& head,const char * filename) //Doc xuoi theo tep
{
    ifstream fin(filename);
    if(!fin.good())
	{
        cout << "Loi doc file " << filename << endl;
        return;
    }
    int v;
    do
	{
		fin>>v;
		append(head, v);

	}while(!fin.eof()) ;
	fin.close();
}

// Doc nguoc voi tep
void readFileReverse(Node *& head,const char * filename)
{
	ifstream fin(filename);
    if(!fin.good()){
        cout << "Loi doc file " << filename << endl;
        return;
    }
    int v;
    while(fin >> v) addFirst(head, v);
    fin.close();
}

//Kiem tra danh sach co trong khong
int Empty(Node *&head)
{
	if(head == NULL)
		return 1;
	return 0;
}

//Dem so phan tu
int length (Node* &head)
{
	Node *p;
	p = head;
	int length = 0;
	if(head != NULL)
	{
		length++;
		while(p->next != NULL)
		{
			p = p->next;
			length++;
		}
	}
	return length;
}

//Tra ve phan tu o vi tri thu i
int element(Node* &head, int i)
{
	Node *p;
	p = head;
	for(int j=0; j<i; j++)
		p = p->next;
	return p->data;
}

//chen x vao vi tri thu i
void insert(Node* &head, int x, int i)
{
	Node *p, *tmp;
	p = head;
	tmp = new Node;
	tmp->data = x;
	if(i==0)
		addFirst(head, i);
	else
	{
	    for(int j=0; j<i-1; j++)
	    	p = p->next;
	    tmp->next = p->next;
	    p->next = tmp;
	}
}

//xoa phan tu vi tri thu i
void erase(Node* &head, int i)
{
	Node *p;
	p = head;
	if(i==0)
		{
			head = head->next;
			delete p;
		}
	else
		{
			for(int j=1; j<i; j++)
				p = p->next;
			Node *q;
			q = p->next;

			if(i == length(head) - 1)
				{
					p->next = NULL;
					delete q;
					q=NULL;
				}
			else
				{
					p->next = q->next;
					delete q;
					q=NULL;
				}
		}
}

//tinh tong tat ca cac so
int Sum(Node *& head)
{
	Node *p;
	p = head;
	int Sum=0;
	while(p->next != NULL)
	{
		Sum += p->data;
		p = p->next;
	}
	Sum += p->data;
	return Sum;
}

//tim max
int Max(Node *& head)
{
	Node *p;
	p = head;
	int Max = head->data;
	while(p->next != NULL)
	{
		if(p->data > Max) Max = p->data;
		p = p->next;
	}
	return Max;
}

//tim min
int Min(Node *& head)
{
	Node *p;
	p = head;
	int Min = head->data;
	while(p->next != NULL)
	{
		if(p->data < Min) Min = p->data;
		p = p->next;
	}
	return Min;
}

//xoa bo so le
void eraseOdd(Node *& head)
{
	Node *p;
	p = head;
	int i=0;
	while(p != NULL)
	{
		if(p->data % 2 == 1)
		{
			p = p->next;
			erase(head, i);
		}else {
			i++;
			p = p->next;
		}
	}
//	if(p->data % 2 == 1) erase(head, i);
}

//in danh sach
void print(Node *head)
{
//	Node *p;
	if (head == NULL)
        cout << "This list  is empty!";
	else
        for(Node *p = head; p!= NULL; p = p->next)
            cout << p->data << "\t";
	cout<<endl;
}

// Chuong trinh chinh
int main(){
    cout << "Chuong trinh demo DSLK don." << endl;
    cout << "Tac gia: [Nguyen Thi Huyen Trang]\n--------------------" << endl;
    Node * head1, * head2;
    head1 = NULL; // Khoi tao DSLK1 rong
    head2 = NULL; // Khoi tao DSLK2 rong
    readFile(head1, "numbers1.txt");
    readFileReverse(head2, "numbers2.txt");
    cout<<"Danh sach 1: "<<endl;
	print(head1);
	cout<<"\tSum: "<<Sum(head2)<<endl;
    cout<<"\tMax: "<<Max(head2)<<endl<<"\tMin: "<<Min(head2)<<endl;
    cout<<"\tXoa so le: "<<endl;
    eraseOdd(head1);
    print(head1);
    cout<<"\tPhan tu o vi tri thu 2: "<<element(head1, 2);
    cout << "\n------------------------"<<endl<<endl;

    cout<<endl<<"Danh sach 2: "<<endl;
    print(head2);
    cout<<"\tSum: "<<Sum(head2)<<endl;
    cout<<"\tMax: "<<Max(head2)<<endl<<"\tMin: "<<Min(head2)<<endl;
    cout<<"\tXoa so le: "<<endl;
    //erase(head2, 8);
	eraseOdd(head2);
	print(head2);
	cout<<"\tChen 3 vao vi tri 2: "<<endl;
	insert(head2, 3, 2);
	print(head2);
    cout << "\nXong!" << endl;

    getch();
    return 0;
}

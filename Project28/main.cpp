#include <iostream>
using namespace std;

struct Element
{
	// ������
	char data;
	// ����� ���������� �������� ������
	Element* Next;
};

// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element* Head;
	// ����� ��������� �������� ������
	Element* Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();

	// ���������� �������� � ������
	// (����� ������� ���������� ���������)
	void Add(char data);

	void AddByPosition(char data, int index);

	void DeleteByPosition(int index);

	int FindIndex(char data);

	// �������� �������� ������
	// (��������� �������� �������)
	void Del();
	// �������� ����� ������
	void DelAll();

	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();
};

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

void List::Add(char data)
{
	// �������� ������ ��������
	Element* temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� �����������
	temp->Next = NULL;
	// ����� ������� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ������� ���������� ������������
	// ���� �� ������ �����������
	else {
		Head = Tail = temp;
	}
	Count++;
}

void List::AddByPosition(char data, int index)
{
	Element* temp = Head;
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->Next;
	}
	Element* temp2 = new Element;
	temp2->data = data;
	temp2->Next = temp->Next;
	temp->Next = temp2;
	Count++;
}

void List::DeleteByPosition(int index)
{
	Element* temp = Head;
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->Next;
	}
	Element* temp2 = new Element;
	temp2 = temp->Next;
	temp2 = temp2->Next; // temp->next->next
	temp->Next = temp2;
}

int List::FindIndex(char data)
{
	Element* temp = Head;
	for (int i = 0; i < Count; i++)
	{
		cout << i << endl;
		if (temp->data == data)
		{
			return i;
		}
		temp = temp->Next;
	}
	return NULL;
}

void List::Del()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ������������� ������ �� ��������� �������
	Head = Head->Next;
	// ������� ������ �������� �������
	Count--;
	delete temp;
}

void List::DelAll()
{
	// ���� ��� ���� ��������
	while (Head != 0)
		// ������� �������� �� ������
		Del();
}

void List::Print()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}

	cout << "\n\n";
}

// �������� ������
void main()
{
	// ������� ������ ������ List
	List lst;

	// �������� ������
	char s[] = "Hello, World !!!\n";
	// ������� ������
	cout << s << "\n\n";
	// ���������� ����� ������
	int len = strlen(s);
	// �������� ������ � ������
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// ������������� ���������� ������
	lst.Print();
	// ������� ��� �������� ������
	lst.Del();
	lst.Del();
	lst.Del();
	//������������� ���������� ������
	lst.Print();
	lst.AddByPosition('T', 6);
	lst.Print();
	lst.DeleteByPosition(5);
	lst.Print();
	cout << lst.FindIndex('W') << " index" << endl;
	cout << lst.GetCount() << endl;
}


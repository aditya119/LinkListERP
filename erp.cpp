#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;

struct address
{
	int h_no, pin;
	char street[20], district[20], city[20];
	void input();
	void output();
	void update();
};

typedef struct address address;

void address :: input()
{
	cout << "enter house number:\n";
	cin >> h_no;
	cout << "enter street:\n";
	cin >> street;
	cout << "enter district:\n";
	cin >> district;
	cout << "enter city:\n";
	cin >> city;
	cout << "enter PIN:\n";
	cin >> pin;
}

void address :: output()
{
	cout << "House number:\t" << h_no << endl;
	cout << "Street:\t\t" << street << endl;
	cout << "District:\t" << district << endl;
	cout << "City:\t\t" << city << endl;
	cout << "PIN:\t\t" << pin << endl;
}

void address :: update()
{
	cout << "enter new house number:\n";
	cin >> h_no;
	cout << "enter new street:\n";
	cin >> street;
	cout << "enter new district:\n";
	cin >> district;
	cout << "enter new city:\n";
	cin >> city;
	cout << "enter new PIN:\n";
	cin >> pin;
}

struct name
{
	char first[20], middle[20], last[20];
	void input();
	void output();
	void update();
};

typedef struct name name;

void name :: input()
{
	cout << "enter first name:\n";
	cin >> first;
	cout << "enter middle name:(if not applicable, enter '0')\n";	//in case person doesn't have a middle name
	cin >> middle;
	cout << "enter last name:\n";
	cin >> last;
}

void name :: output()
{
	if(middle[0] == '0')
	{
		cout << "name:\t" << first << " " << last << endl;
	}
	else
	{
		cout << "name:\t" << first << " " << middle << " " << last << endl;
	}
}

void name :: update()
{
	cout << "enter new first name:\n";
	cin >> first;
	cout << "enter new middle name:(if not applicable, enter '0')\n";
	cin >> middle;
	cout << "enter new last name:\n";
	cin >> last;
}

struct record
{
	int s_id;
	name stu_name, f_name, m_name;
	char branch[3];
	address a;
	struct record *next;
};

typedef struct record rec;

void view(rec *q)
{
	system("clear");
	rec *temp;
	temp = q;
	if(q == NULL)
	{
		cout << "List Empty\n\n";	//check underflow
		return;
	}
	else
	{
		cout << "CSE:\n";
		do
		{
			if(strcmp(temp->branch, "CSE") != 0)
			{
				temp = temp->next;
				continue;
			}
			cout << "Student id:\t" << temp->s_id << endl;
			cout << "Student's ";
			temp->stu_name.output();
			cout << endl;
			cout << "Father's ";
			temp->f_name.output();
			cout << endl;
			cout << "Mother's ";
			temp->m_name.output();
			cout << endl;
			cout << "Branch:\t\t" << temp->branch << endl;
			temp->a.output();
			cout << endl << endl;
			temp = temp->next;
		}
		while(temp != NULL);
		
		temp = q;
		cout << "ECE:\n";
		while(temp != NULL)
		{
			if(strcmp(temp->branch, "ECE") != 0)
			{
				temp = temp->next;
				continue;
			}
			cout << "Student id:\t" << temp->s_id << endl;
			cout << "Student's ";
			temp->stu_name.output();
			cout << endl;
			cout << "Father's ";
			temp->f_name.output();
			cout << endl;
			cout << "Mother's ";
			temp->m_name.output();
			cout << endl;
			cout << "Branch:\t\t" << temp->branch << endl;
			temp->a.output();
			cout << endl << endl;
			temp = temp->next;
		}
		
		temp = q;
		cout << "ME:\n";
		while(temp != NULL)
		{
			if(strcmp(temp->branch, "ME") != 0)
			{
				temp = temp->next;
				continue;
			}
			cout << "Student id:\t" << temp->s_id << endl;
			cout << "Student's ";
			temp->stu_name.output();
			cout << endl;
			cout << "Father's ";
			temp->f_name.output();
			cout << endl;
			cout << "Mother's ";
			temp->m_name.output();
			cout << endl;
			cout << "Branch:\t\t" << temp->branch << endl;
			temp->a.output();
			cout << endl << endl;
			temp = temp->next;
		}
		
		temp = q;
		cout << "\bCE:\n";
		while(temp != NULL)
		{
			if(strcmp(temp->branch, "CE") != 0)
			{
				temp = temp->next;
				continue;
			}
			cout << "Student id:\t" << temp->s_id << endl;
			cout << "Student's ";
			temp->stu_name.output();
			cout << endl;
			cout << "Father's ";
			temp->f_name.output();
			cout << endl;
			cout << "Mother's ";
			temp->m_name.output();
			cout << endl;
			cout << "Branch:\t\t" << temp->branch << endl;
			temp->a.output();
			cout << endl << endl;
			temp = temp->next;
		}		
		cout << endl;
	}
}

rec* insert(rec *q)
{
	system("clear");
	rec *node, *naya;
	naya = (rec*)malloc(sizeof(rec));
	if(!naya)
	{
		cout << "Memory Error\n\n";	//check overflow
		return 0;
	}
	node = q;
	if(q == NULL)	//in case list is empty
	{
		cout << "enter student id for new node:\n";
		cin >> naya->s_id;
		cout << "enter name\n";
		naya->stu_name.input();
		cout << "enter father's name:\n";
		naya->f_name.input();
		cout << "enter mother's name:\n";
		naya->m_name.input();
		cout << "enter branch(CSE/ECE/ME/CE):\n";
		cin >> naya->branch;
		naya->a.input();
		q = naya;
		naya->next = NULL;
		return q;
	}
	else
	{
		cout << "enter student id for new node:\n";
		int x;
		cin >> x;
		if(node->s_id > x)	//if list not empty and insertion at first node
		{
			q = naya;
			naya->next = node;
			naya->s_id = x;
			cout << "enter name\n";
			naya->stu_name.input();
			cout << "enter father's name:\n";
			naya->f_name.input();
			cout << "enter mother's name:\n";
			naya->m_name.input();
			cout << "enter branch(CSE/ECE/ME/CE):\n";
			cin >> naya->branch;
			naya->a.input();
			return q;
		}
		else
		{
			rec *temp;
			while(node->s_id < x)	//for insertion at intermediate node
			{
				temp = node;
				if(node->next == NULL)	//inserting at last node
				{
					node->next = naya;
					naya->next = NULL;
					naya->s_id = x;
					cout << "enter name:\n";
					naya->stu_name.input();
					cout << "enter father's name:\n";
					naya->f_name.input();
					cout << "enter mother's name:\n";
					naya->m_name.input();
					cout << "enter branch(CSE/ECE/ME/CE):\n";
					cin >> naya->branch;
					naya->a.input();
					return q;
				}
				node = node->next;
			}
			temp->next = naya;	//inserting at intermediate node
			naya->next = node;
			naya->s_id = x;
			cout << "enter name\n";
			naya->stu_name.input();
			cout << "enter father's name:\n";
			naya->f_name.input();
			cout << "enter mother's name:\n";
			naya->m_name.input();
			cout << "enter branch(CSE/ECE/ME/CE):\n";
			cin >> naya->branch;
			naya->a.input();
			return q;
		}
	}
}

rec* remove(rec *q)
{
	system("clear");
	rec *node;
	if(q == NULL)
	{
		cout << "List empty\n\n";	//check underflow
		return NULL;
	}
	node = q;
	cout << "enter student id of node to be deleted:\n";
	int x;
	cin >> x;
	if(q->s_id == x)
	{
		if(q->next == NULL)	//if first and only node is to be deleted
		{
			cout << "student id " << q->s_id << " removed\n\n";
			q = NULL;
			free(node);
			return q;
		}
		else 	//if first node is to be deleted
		{
			cout << "student id " << q->s_id << " removed\n\n";
			q = q->next;
			free(node);
			return q;	
		}
	}
	else
	{
		while(node->next->s_id != x)	//deleting intermediate node
		{
			node = node->next;
			if(node->next == NULL)
			{
				cout << "Node does not exist\n\n";	//if node doesn't exist
				return q;
			}
		}
		cout << "student id " << node->next->s_id << " removed\n\n";
		rec *temp;
		temp = node->next;
		node->next = temp->next;
		free(temp);
		return q;
	}
}

void update(rec *q)
{
	system("clear");
	rec *node;
	if(q == NULL)
	{
		cout << "List empty\n\n";	//check underflow
		return;
	}
	node = q;
	cout << "enter student id of the node to be updated:\n";
	int x;
	cin >> x;
	while(node->s_id != x)
	{
		node = node->next;
		if(node == NULL)
		{
			cout << "Node does not exist\n\n";	//if node doesn't exist
			return;
		}
	}
	cout << "What do you want to update?\n(N)ame\n(F)ather's name\n(M)other's name\n(B)ranch\n(A)ddress\n";
	char ch;
	cin >> ch;
	switch(ch)
	{
		case 'N': cout << "enter new name:\n"; node->stu_name.update(); break;
		case 'F': cout << "enter father's new name:\n"; node->f_name.update(); break;
		case 'M': cout << "enter mother's new name:\n"; node->m_name.update(); break;
		case 'B': cout << "enter new branch:\n"; cin >> node->branch; break;
		case 'A': node->a.update(); break;
	}
	cout << "Record of student id " << node->s_id << " updated\n\n";
}

void count(rec *q)
{
	system("clear");
	rec *current;
	current = q;
	int count = 0;
	if(q == NULL)	//check underflow
	{
		cout << "Number of nodes in list = " << count << endl << endl;
		return;
	}
	else
	{
		while(current != NULL)
		{
			count++;
			current = current->next;
		}
		cout << "Number of nodes in list = " << count << endl << endl;
		return;
	}
}

rec* readFile()
{
	rec *q, *node;
	ifstream file("database", ios :: in);
	int count = 0;
	node = (rec*)malloc(sizeof(rec));
	q = node;
	file.seekg(0);
	rec *temp;
	while(file)	//read every information associated to a node of every node from file
	{
		node->next = (rec*)malloc(sizeof(rec));
		file >> node->s_id;
		file >> node->stu_name.first;
		file >> node->stu_name.middle;
		file >> node->stu_name.last;
		file >> node->f_name.first;
		file >> node->f_name.middle;
		file >> node->f_name.last;
		file >> node->m_name.first;
		file >> node->m_name.middle;
		file >> node->m_name.last;
		file >> node->branch;
		file >> node->a.h_no;
		file >> node->a.street;
		file >> node->a.district;
		file >> node->a.city;
		file >> node->a.pin;
		temp = node;
		node = node->next;
		count++;
	}
	file.close();	//two unwanted nodes retrieved and count is one less
	count--;	//not taking into consideration the unwanted node
	if(count == 0)
	{
		cout << count << " nodes retrieved\n\n";
		q = NULL;
		return q;
	}
	else
	{
		temp->next = NULL;
		free(node);	//first unwanted node removed
		cout << count << " nodes retrieved\n\n";
		return q;
	}
	return q;
}

void writeFile(ofstream &file, rec *q)
{
	if(q == NULL)	//check underflow
	{
		cout << "List Empty\nWriting nothing to file\n"; 
	}
	else
	{
		rec *node;
		node = q;
		int count = 0;
		do
		{
			file << node->s_id << "\t";
			file << node->stu_name.first << "\t";
			file << node->stu_name.middle << "\t";
			file << node->stu_name.last << "\t";
			file << node->f_name.first << "\t";
			file << node->f_name.middle << "\t";
			file << node->f_name.last << "\t";
			file << node->m_name.first << "\t";
			file << node->m_name.middle << "\t";
			file << node->m_name.last << "\t";
			file << node->branch << "\t";
			file << node->a.h_no << "\t";
			file << node->a.street << "\t";
			file << node->a.district << "\t";
			file << node->a.city << "\t";
			file << node->a.pin << endl;
			file.write ((char*)node, sizeof(rec));
			node = node->next;
			count++;
		}
		while(node != NULL);	//write every information associated to a node of every node to file
		cout << count << " nodes added\n\n";
	}
}

rec* removeRedundant(rec *q)	//removes second unwanted node
{
	rec *node;
	node = q;
	if(q == NULL)
	{
		return q;
	}
	else
	{
		rec *temp;
		while(node->s_id != 0)
		{
			temp = node;
			node = node->next;
		}
		temp->next = NULL;
		free(node);
		return q;
	}
}

int main()
{
	rec *start;
	system("clear");
	start = readFile();	//reads database
	start = removeRedundant(start);
	char ch;
	do
	{
		cout << "what do you want to do?\n(V)iew List\n(I)nsert Node\n(R)emove Node\n(U)pdate Node\n(C)ount Nodes\n(E)xit\n";
		cin >> ch;
		switch(ch)
		{
			case 'V': view(start); break;
			case 'I': start = insert(start); break;
			case 'R': start = remove(start); break;
			case 'U': update(start); break;
			case 'C': count(start); break;
		}
	}
	while(ch != 'E');	//creates a menu-based program
	ofstream dbi("database", ios :: trunc);	//overwrites any existing data
	writeFile(dbi, start);	//writes data to file
	dbi.close();
	return  0;
}

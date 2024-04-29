#include<iostream>

using namespace std;
int c,c1,c2;
class Employee
{
    public:
    int age,c=0;
    string name;
    long int salary;
    Employee *lchild,*rchild;
    void accept();
    void search(Employee *root,long int n);
    void display(Employee *root);
    void height();
    void displayLeafNodes(Employee *root);
    void insert(Employee *root,Employee *next);
    void calculate();
    void find_min(Employee* root);
    void find_max(Employee* root);
} *root;

void Employee::find_min(Employee* root)
{
    while(root->lchild!=NULL)
    {
        root=root->lchild;
    }
   cout<<"\nMin salary of a Employee:  "<<root->salary;
}

void Employee::find_max(Employee* root)
{
    while(root->rchild!=NULL)
    {
        root=root->rchild;
    }
    cout<<"\nMax salary of an Employee:  "<<root->salary;
} 

void Employee :: display(Employee *root)
{
    if (root != nullptr)
    {
        display(root->lchild);
        cout << "\n" << root->name << "\t" << root->salary << endl;
        display(root->rchild);
    }
};

void Employee::height()
{
if(c1>=c2)
{
cout<<"Heigheight of tree is : "<<c1;
}
else
{
cout<<"Heigheight of tree is : "<<c2;
}
}

void Employee::displayLeafNodes(Employee *root)
{
    if (root == nullptr)
        return;

    if (root->lchild == nullptr && root->rchild == nullptr)
    {
        cout << "\nLeaf Node: " << root->name << "\t" << root->salary << endl;
    }

    displayLeafNodes(root->lchild);
    displayLeafNodes(root->rchild);
}



void Employee::search(Employee *root, long int n) {
    if (root == NULL) {
        cout << "Tree is Employeety";
        return;
    }

    if (root->salary == n) {
        cout << "Employeeloyee is found:" << endl;
        cout << "\nNAME\tSALARY";
        cout << "\n" << root->name << "\t" << root->salary;
        return;
    }

    // Search lchild subtree if target name is less than current node'salary name
    if (n < root->salary)
        search(root->lchild, n);
    // Search righeight subtree if target name is greater than current node'salary name
    else
        search(root->rchild, n);
}



void Employee::accept()
{
    Employee *next;
    root=new Employee;
    
    int ch;
    cout<<"Enter the name: ";
    cin>>root->name;
    cout<<"Enter salary : ";
    cin>>root->salary;
    root->lchild=root->rchild=NULL;
    c++;
    c1=c2=c;
    do
    {
        cout << "\nu want to add more employee if yes then press 1 otherwise press any key : " << endl;
        cin >> ch;
        if (ch == 1)
        {
            next = new Employee();
            cout << "enter the following Employee information :" << endl;
            cout<<"Enter the name: ";
            cin>>next->name;
            cout<<"Enter salary : ";
            cin>>next->salary;
            next->lchild = NULL;
            next->rchild = NULL;
            insert(root, next);
        }
    } while (ch == 1);
}


void Employee::insert(Employee *root,Employee *next)
{ 
   string chr;
    if (root->salary > next->salary)
    {
        if (root->lchild == NULL)
        {c++;
            c1++;
            root->lchild = next;
  cout<<"Inserted successfully";
        }
        else
        {
            insert(root->lchild, next);
        }
    }
    if (root->salary < next->salary)
    {
        if (root->rchild == NULL)
        {    c++;
            c2++;
            root->rchild = next;
            cout<<"Inserted successfully";
        }
        else
        {
            insert(root->rchild, next);
        }
    }
}

void Employee::calculate()
{
    cout<<"The total number of record : "<<c;
}

int main()
{
    Employee f;
    int ch;
    long int n;
    do
    {
        cout<<"\nWELCOME TO Employee TREE ";
        cout<<"\n1.Add the Employee member\n2.display \n3.display the total generation\n4.display the leaf node\n5.calculate total record\n6.find\n7.find min salary\n8.find max salary \n9.exit ";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            f.accept();
            break;
            case 2:
            cout<<"\nNAME\tSALARY";
            f.display(root);
            
            break;
            case 3:
            f.height();
            break;
            case 4:
            f.displayLeafNodes(root);
            break;
            case 5:
            f.calculate();
            break;
            case 6:
            cout<<"Enter the salary for search : ";
            cin>>n;
            f.search(root,n);
            break;
            case 7:
            f.find_min(root);
            break;
            case 8:
            f.find_max(root);
            break;
            case 9:
            cout<<"Thanks for visiting...!!!";
            break;
            default:
            cout<<"Wrong choice";

        }
    } while (ch!=9);
    
}

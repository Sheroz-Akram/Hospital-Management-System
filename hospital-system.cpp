#include<iostream>
#include<fstream>
using namespace std;
char sub_menu();
void temp(char **arr,int row,int *col,int num);
void delete_patient(ifstream &fin,int select);
int get_patient_no(ifstream &fin);
void add_new(ofstream &fout,int num);
int sub_menu_3();
void Searching_patient(ifstream &fin,int select);
char *regrow(char *ptr,char input,int &size);
char **two_D_regrow(char **ptr,int size);
void editing_patient(ifstream &fin,int select);
int *regrowd(int *ptr,int input,int &size);
void delete_2d(char **arr,int &size);
void display_record(ifstream &fin);
void display(char **arr,int row,int *col,int num);
void menu();
int main()
{
  menu();	
  return 0;
}
int sub_menu_2()
{
  char choice;
  while(true)
  {
  cout<<endl<<endl;
  cout<<"		***********Hospital Management system***********"<<endl<<endl;
  cout<<"		================================================"<<endl<<endl;
  cout<<"		**************Type Selection Section*************"<<endl<<endl;
  cout<<"		================================================"<<endl<<endl;
  cout<<"		Press 1 By Name "<<endl;
  cout<<"		Press 2 By Address"<<endl;
  cout<<"		Press 3 By patient No"<<endl;
  cout<<"		============================================="<<endl<<endl;
  cout<<"		Select what do you want to do ? = ";
  cin>>choice;
  if(choice=='1')
  {
    return 1;
  }	
  else if(choice=='2')
  {
    return 2;
  }
  else if(choice=='3')
  {
    return 3;
  }
  else
  {
    cout<<"Input invalid!!"<<endl;
  }
  }
}
void menu()
{
  char choice;
  while(true)
  {
  cout<<endl<<endl;
  cout<<"		***********Hospital Management system***********"<<endl<<endl;
  cout<<"		============================================="<<endl<<endl;
  cout<<"		Press 1 for Add New Patient Record"<<endl;
  cout<<"		Press 2 for Edit Patient Record "<<endl;
  cout<<"		Press 3 for Search Patient Record"<<endl;
  cout<<"		Press 4 for List Record Of Patients"<<endl;
  cout<<"		Press 5 for Delete Patient Records"<<endl;
  cout<<"		Press 6 for end program "<<endl;
  cout<<"		============================================="<<endl<<endl;
  cout<<"		Select what do you want to do ? = ";
  cin>>choice;
  if(choice=='6')
  {
    exit(0);
  }
  else if (choice=='1')
  {
    char choice=sub_menu();
    if(choice=='1')
    {
      ifstream fin("Emergency_Patients.txt");
      if(!fin.is_open())
      {
      ofstream fout("Emergency_Patients.txt",ios::app);
      add_new(fout,0);
      cout<<"Add Patient Information Successfully !!"<<endl;
      fout.close();
      }
      else
      {
      int num=get_patient_no(fin);
      ofstream fout("Emergency_Patients.txt",ios::app);
      add_new(fout,num);
      cout<<"Add Patient Information Successfully !!"<<endl;
      fout.close();
      }
    }
    else if(choice=='2')
    {
      ifstream fin("O.P.D.patients.txt");
      if(!fin.is_open())
      {
      ofstream fout("O.P.D.patients.txt",ios::app);
      add_new(fout,0);
      cout<<"Add Patient Information Successfully !!"<<endl;
      fout.close();
      }
      else
      {
      int num=get_patient_no(fin);
      ofstream fout("O.P.D.patients.txt",ios::app);
      add_new(fout,num);
      cout<<"Add Patient Information Successfully !!"<<endl;
      fout.close();
      }
    }
    else if(choice=='3')
    {
        ifstream fin("Particular_date_patients.txt");
      if(!fin.is_open())
      {
      ofstream fout("Particular_date_patients.txt",ios::app);
      add_new(fout,0);
      cout<<"Add Patient Information Successfully !!"<<endl;
      fout.close();
      }
      else
      {
      int num=get_patient_no(fin);
      ofstream fout("Particular_date_patients.txt",ios::app);
      add_new(fout,num);
      cout<<"Add Patient Information Successfully !!"<<endl;
      fout.close();
      }
    }
  }
  else if(choice=='2')
  {
    char choice=sub_menu();
    if(choice=='1')
    {
      int num=sub_menu_2();
      ifstream fin("Emergency_Patients.txt");
      if(!fin.is_open())
      {
        cout<<"File is not Found !!!"<<endl;
      }
      else
      {
        editing_patient(fin,num);
        fin.close();
        remove("Emergency_Patients.txt");
        rename("temp.txt","Emergency_Patients.txt");
      }
    }
    else if(choice=='2')
    {
      int num=sub_menu_2();
      ifstream fin("O.P.D.patients.txt");
      if(!fin.is_open())
      {
        cout<<"File is not Found !!!"<<endl;
      }
      else
      {
        editing_patient(fin,num);
        fin.close();
        remove("O.P.D.patients.txt");
        rename("temp.txt","O.P.D.patients.txt");
      }
    }
    else if(choice=='3')
    {
      int num=sub_menu_2();
      ifstream fin("Particular_date_patients.txt");
      if(!fin.is_open())
      {
        cout<<"File is not Found !!!"<<endl;
      }
      else
      {
        editing_patient(fin,num);
        fin.close();
        remove("Particular_date_patients.txt");
        rename("temp.txt","Particular_date_patients.txt");
      }
    }
  }
  else if(choice=='3')
  {
      char choice=sub_menu();
    if(choice=='1')
    {
      int num=sub_menu_2();
      ifstream fin("Emergency_Patients.txt");
      if(!fin.is_open())
      {
        cout<<"File is not Found !!!"<<endl;
      }
      else
      {
        Searching_patient(fin,num);
        fin.close();
      }
    }
    else if(choice=='2')
    {
      int num=sub_menu_2();
      ifstream fin("O.P.D.patients.txt");
      if(!fin.is_open())
      {
        cout<<"File is not Found !!!"<<endl;
      }
      else
      {
        Searching_patient(fin,num);
        fin.close();
      }
    }
    else if(choice=='3')
    {
      int num=sub_menu_2();
      ifstream fin("Particular_date_patients.txt");
      if(!fin.is_open())
      {
        cout<<"File is not Found !!!"<<endl;
      }
      else
      {
        Searching_patient(fin,num);
        fin.close();
      }
    }
  }
  else if(choice=='4')
  {
    char choice=sub_menu();
    if(choice=='1')
    {
      ifstream fin("Emergency_Patients.txt");
      if(!fin.is_open())
      {
        cout<<"File is not Found !!!"<<endl;
      }
      else
      {
        display_record(fin);
      }
      fin.close();
    }
    else if(choice=='2')
    {
      ifstream fin("O.P.D.patients.txt");
      if(!fin.is_open())
      {
        cout<<"File is not Found !!!"<<endl;
      }
      else
      {
        display_record(fin);
      }
      fin.close();
    }
    else if(choice=='3')
    {
      ifstream fin("Particular_date_patients.txt");
      if(!fin.is_open())
      {
        cout<<"File is not Found !!!"<<endl;
      }
      else
      {
        display_record(fin);
      }
      fin.close();
    }
  }
  else if(choice=='5')
  {
      char choice=sub_menu();
      if(choice=='1')
    {
      int num=sub_menu_2();
      ifstream fin("Emergency_Patients.txt");
      if(!fin.is_open())
      {
        cout<<"File is not Found !!!"<<endl;
      }
      else
      {
        delete_patient(fin,num);
        fin.close();
        remove("Emergency_Patients.txt");
        rename("temp.txt","Emergency_Patients.txt");
      }
    }
    else if(choice=='2')
    {
      int num=sub_menu_2();
      ifstream fin("O.P.D.patients.txt");
      if(!fin.is_open())
      {
        cout<<"File is not Found !!!"<<endl;
      }
      else
      {
        delete_patient(fin,num);
        fin.close();
        remove("O.P.D.patients.txt");
        rename("temp.txt","O.P.D.patients.txt");
      }
    }
    else if(choice=='3')
    {
      int num=sub_menu_2();
      ifstream fin("Particular_date_patients.txt");
      if(!fin.is_open())
      {
        cout<<"File is not Found !!!"<<endl;
      }
      else
      {
        delete_patient(fin,num);
        fin.close();
        remove("Particular_date_patients.txt");
        rename("temp.txt","Particular_date_patients.txt");
      }
    }
  }
  }
}
char sub_menu()
{
  char choice;
  while(true)
  {
  cout<<endl<<endl;
  cout<<"		***********Hospital Management System***********"<<endl<<endl;
  cout<<"		============================================="<<endl<<endl;
  cout<<"		*************Type Selection Section*************"<<endl<<endl;
  cout<<"		============================================="<<endl<<endl;
  cout<<"		Press 1 for Emergency Patients"<<endl;
  cout<<"		Press 2 for O.P.D. Patients"<<endl;
  cout<<"		Press 3 for Patients In A Particular Date"<<endl;
  cout<<"		Press 4 for end"<<endl;
  cout<<"		============================================="<<endl<<endl;
  cout<<"		Select what do you want to do ? = ";
  cin>>choice;
  if(choice=='1'||choice=='2'||choice=='3')
  {
    break;
  }
  else if(choice=='4')
  {
    exit(0);
  }
  else 
  {
    cout<<"Input Invalid !!!"<<endl;
  }
  }
  return choice;
}
void delete_2d(char **arr,int &size)
{
  for(int i=0;i<size;i++)
  {
    delete[]arr[i];
    arr[i]=NULL;
  }
  delete[]arr;
  size=0;
}
int *regrowd(int *ptr,int input,int &size)
{
  int *temp=new int [size+1];
  for(int i=0;i<size;i++)
  {
    temp[i]=ptr[i];
  }
  temp[size]=input;
  size++;
  delete[]ptr;
  ptr=NULL;
  return temp;
}
char *regrow(char *ptr,char input,int &size)
{
  char *temp=new char [size+1];
  for(int i=0;i<size;i++)
  {
    temp[i]=ptr[i];
  }
  temp[size]=input;
  size++;
  delete[]ptr;
  ptr=NULL;
  return temp;
}
char **two_D_regrow(char **ptr,int size)
{
  char **temp=new char *[size+1];
  for(int i=0;i<size;i++)
  {
    temp[i]=ptr[i];
    ptr[i]=NULL;
  }
  temp[size]=new char[1];
  return temp;
}
void add_new(ofstream &fout,int num)
{
  num+=1;
  fout<<num<<",";
  char input;
  int row=6;
  cin.ignore();	
  char **arr=new char*[row];
  int *col=new int[row];
  cout<<"Enter A Patient Name : ";
  arr[0]=new char[1];
  col[0]=0;
  while(true)
  {
    cin.get(input);
    if(input!='\n')
    {
      arr[0]=regrow(arr[0],input,col[0]);
    }
    else
    {
      break;
    }
  }
  cout<<"Enter A Patient Address : ";
  arr[1]=new char[1];
  col[1]=0;
  while(true)
  {
    cin.get(input);
    if(input!='\n')
    {
      arr[1]=regrow(arr[1],input,col[1]);
    }
    else
    {
      break;
    }
  }
  cout<<"Enter A Patient age : ";
  arr[2]=new char[1];
  col[2]=0;
  while(true)
  {
    cin.get(input);
    if(input!='\n')
    {
      arr[2]=regrow(arr[2],input,col[2]);
    }
    else
    {
      break;
    }
  }
  cout<<"Enter A Patient Sex : ";
  col[3]=0;
  arr[3]=new char[1];
  while(true)
  {
    cin.get(input);
    if(input!='\n')
    {
      arr[3]=regrow(arr[3],input,col[3]);
    }
    else
    {
      break;
    }
  }
  cout<<"Enter a Patient disease description : ";
  col[4]=0;
  arr[4]=new char[1];
  while(true)
  {
    cin.get(input);
    if(input!='\n')
    {
      arr[4]=regrow(arr[4],input,col[4]);
    }
    else
    {
      break;
    }
  }
  cout<<"Enter a Patient specialist room number (if not specialist room so enter only NO) : ";
  col[5]=0;
  arr[5]=new char[1];
  while(true)
  {
    cin.get(input);
    if(input!='\n')
    {
      arr[5]=regrow(arr[5],input,col[5]);
    }
    else
    {
      break;
    }
  }
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col[i];j++)
    {
      fout<<arr[i][j];
    }
    if(i<row-1)
    {
    fout<<",";
    }
  }
  fout<<endl;
  delete_2d(arr,row);
  arr=NULL;
  delete[]col;
  col=NULL;
}
void display(char **arr,int row,int *col,int num)
{
  cout<<"			Patient no : "<<num<<endl;
  for(int i=0;i<row;i++)
  {
    if(i==0)
    {
      cout<<"			Name : ";
    }
    else if(i==1)
    {
      cout<<"			Address : ";
    }
    else if(i==2)
    {
      cout<<"			Age : ";
    }
    else if(i==3)
    {
      cout<<"			Sex : ";
    }
    else if(i==4)
    {
      cout<<"			Disease description : ";
    }
    else if(i==5)
    {
      cout<<"			Specialist Room Number : ";
    }
    for(int j=0;j<col[i];j++)
    {
      cout<<arr[i][j];
    }
    cout<<endl;
  }
  cout<<"			=============================================="<<endl<<endl;
}
void display_record(ifstream &fin)
{
  cout<<"		***********Hospital Management System***********"<<endl<<endl;
  cout<<"		============================================="<<endl<<endl;
  cout<<"		*************Record List Section*************"<<endl<<endl;
  cout<<"		============================================="<<endl<<endl;
  int num;
  while(fin>>num)
  {
  fin.ignore();
  char input;
  int row=6;	
  char **arr=new char*[row];
  int *col=new int[row];
  arr[0]=new char[1];
  col[0]=0;
  while(true)
  {
    fin.get(input);

    if(input!=',')
    {
      arr[0]=regrow(arr[0],input,col[0]);
    }
    else
    {
      break;
    }
  }
  arr[1]=new char[1];
  col[1]=0;
  while(true)
  {

    fin.get(input);
    if(input!=',')
    {
      arr[1]=regrow(arr[1],input,col[1]);
    }
    else
    {
      break;
    }
  }
  arr[2]=new char[1];
  col[2]=0;
  while(true)
  {

    fin.get(input);

    if(input!=',')
    {
      arr[2]=regrow(arr[2],input,col[2]);
    }
    else
    {
      break;
    }
  }
  col[3]=0;
  arr[3]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[3]=regrow(arr[3],input,col[3]);
    }
    else
    {
      break;
    }
  }
  col[4]=0;
  arr[4]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[4]=regrow(arr[4],input,col[4]);
    }
    else
    {
      break;
    }
  }
  col[5]=0;
  arr[5]=new char[1];
  while(true)
  {
    fin.get(input);
    if(int(input)!=10)
    {
      arr[5]=regrow(arr[5],input,col[5]);
    }
    else
    {
      break;
    }
  }
  display(arr,row,col,num);
  delete_2d(arr,row);
  arr=NULL;
  delete[]col;
  col=NULL;
  }
  cout<<"		============================================="<<endl<<endl;
}
int get_patient_no(ifstream &fin)
{
  int num=0;
  while(fin>>num)
  {
  fin.ignore();
  char input;
  int row=6;	
  char **arr=new char*[row];
  int *col=new int[row];
  arr[0]=new char[1];
  col[0]=0;
  while(true)
  {
    fin.get(input);

    if(input!=',')
    {
      arr[0]=regrow(arr[0],input,col[0]);
    }
    else
    {
      break;
    }
  }
  arr[1]=new char[1];
  col[1]=0;
  while(true)
  {

    fin.get(input);
    if(input!=',')
    {
      arr[1]=regrow(arr[1],input,col[1]);
    }
    else
    {
      break;
    }
  }
  arr[2]=new char[1];
  col[2]=0;
  while(true)
  {

    fin.get(input);

    if(input!=',')
    {
      arr[2]=regrow(arr[2],input,col[2]);
    }
    else
    {
      break;
    }
  }
  col[3]=0;
  arr[3]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[3]=regrow(arr[3],input,col[3]);
    }
    else
    {
      break;
    }
  }
  col[4]=0;
  arr[4]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[4]=regrow(arr[4],input,col[4]);
    }
    else
    {
      break;
    }
  }
  col[5]=0;
  arr[5]=new char[1];
  while(true)
  {
    fin.get(input);
    if(int(input)!=10)
    {
      arr[5]=regrow(arr[5],input,col[5]);
    }
    else
    {
      break;
    }
  }
  delete_2d(arr,row);
  arr=NULL;
  delete[]col;
  col=NULL;
  }
  return num;
}
void temp(char **arr,int row,int *col,int num)
{
  ofstream fout("temp.txt",ios::app);
  fout<<num<<",";
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col[i];j++)
    {
      fout<<arr[i][j];
    }
    if(i<row-1)
    {fout<<",";}
  }
  fout<<endl;
  fout.close();
}
void delete_patient(ifstream &fin,int select)
{
  cout<<select<<endl;
  cin.ignore();
  char input;
  char *arr1=new char[1];
  int size=0;
  if(select==1)
  {
    cout<<"Enter a Name : ";
    while(true)
    {
      cin.get(input);
      if(input!='\n')
      {
        arr1=regrow(arr1,input,size);
      }
      else
      {
        break;
      }
    }
  }
  else if(select==2)
  {
    cout<<"Enter a address : ";
    while(true)
    {
      cin.get(input);
      if(input!='\n')
      {
        arr1=regrow(arr1,input,size);
      }
      else
      {
        break;
      }
    }
  }
  else if(select==3)
  {
    cout<<"Enter a Patient Number : ";
    cin>>size;
  }
  if(select!=3)
  {
    int flag=0;
  int num=0;
  while(fin>>num)
  {
  fin.ignore();

  int row=6;	
  char **arr=new char*[row];
  int *col=new int[row];
  arr[0]=new char[1];
  col[0]=0;
  while(true)
  {
    fin.get(input);

    if(input!=',')
    {
      arr[0]=regrow(arr[0],input,col[0]);
    }
    else
    {
      break;
    }
  }
  arr[1]=new char[1];
  col[1]=0;
  while(true)
  {

    fin.get(input);
    if(input!=',')
    {
      arr[1]=regrow(arr[1],input,col[1]);
    }
    else
    {
      break;
    }
  }
  arr[2]=new char[1];
  col[2]=0;
  while(true)
  {

    fin.get(input);

    if(input!=',')
    {
      arr[2]=regrow(arr[2],input,col[2]);
    }
    else
    {
      break;
    }
  }
  col[3]=0;
  arr[3]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[3]=regrow(arr[3],input,col[3]);
    }
    else
    {
      break;
    }
  }
  col[4]=0;
  arr[4]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[4]=regrow(arr[4],input,col[4]);
    }
    else
    {
      break;
    }
  }
  col[5]=0;
  arr[5]=new char[1];
  while(true)
  {
    fin.get(input);
    if(int(input)!=10)
    {
      arr[5]=regrow(arr[5],input,col[5]);
    }
    else
    {
      break;
    }
  }
  flag=0;
  if(size==col[select-1])
  {
    for(int i=0;i<size;i++)
    {
      if(arr1[i]!=arr[select-1][i]&&arr1[i]+32!=arr[select-1][i]&&arr1[i]-32!=arr[select-1][i])
      {
        flag=1;
        break;
      }
    }
  if(flag==1)
  {
    temp(arr,row,col,num);
  }
  }
  else
  {
    temp(arr,row,col,num);
  }
  delete_2d(arr,row);
  arr=NULL;
  delete[]col;
  col=NULL;
  }
  }
  else
  {
  int num=0;
  while(fin>>num)
  {
  fin.ignore();

  int row=6;	
  char **arr=new char*[row];
  int *col=new int[row];
  arr[0]=new char[1];
  col[0]=0;
  while(true)
  {
    fin.get(input);

    if(input!=',')
    {
      arr[0]=regrow(arr[0],input,col[0]);
    }
    else
    {
      break;
    }
  }
  arr[1]=new char[1];
  col[1]=0;
  while(true)
  {

    fin.get(input);
    if(input!=',')
    {
      arr[1]=regrow(arr[1],input,col[1]);
    }
    else
    {
      break;
    }
  }
  arr[2]=new char[1];
  col[2]=0;
  while(true)
  {

    fin.get(input);

    if(input!=',')
    {
      arr[2]=regrow(arr[2],input,col[2]);
    }
    else
    {
      break;
    }
  }
  col[3]=0;
  arr[3]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[3]=regrow(arr[3],input,col[3]);
    }
    else
    {
      break;
    }
  }
  col[4]=0;
  arr[4]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[4]=regrow(arr[4],input,col[4]);
    }
    else
    {
      break;
    }
  }
  col[5]=0;
  arr[5]=new char[1];
  while(true)
  {
    fin.get(input);
    if(int(input)!=10)
    {
      arr[5]=regrow(arr[5],input,col[5]);
    }
    else
    {
      break;
    }
  }
  if(size!=num)
  {
    temp(arr,row,col,num);
  }
  delete_2d(arr,row);
  arr=NULL;
  delete[]col;
  col=NULL;
  }
  }
}
int sub_menu_3()
{
  char ch;
  while(true)
  {
  cout<<"		***********Hospital Management System***********"<<endl<<endl;
  cout<<"		================================================"<<endl<<endl;
  cout<<"		****************Editing Section*****************"<<endl<<endl;
  cout<<"		================================================"<<endl<<endl;
    cout<<"			Press 1 for Name "<<endl;
    cout<<"			Press 2 for Address"<<endl;
    cout<<"			Press 3 for Age"<<endl;
    cout<<"			Press 4 for Sex"<<endl;
    cout<<"			Press 5 for disease description "<<endl;
    cout<<"			Press 6 for room no "<<endl;
    cout<<"			= ";
    cin>>ch;
    if(ch=='1')
    {
      return 1;
    }
    else if(ch=='2')
    {
      return 2;
    }
    else if(ch=='3')
    {
      return 3;
    }
    else if(ch=='4')
    {
      return 4;
    }
    else if(ch=='5')
    {
      return 5;
    }
    else if(ch=='6')
    {
      return 6;
    }
    else
    {
      cout<<"Input invalid!!"<<endl;
    }
  }
}
void editing_patient(ifstream &fin,int select)
{
  cin.ignore();
  char input;
  char *arr1=new char[1];
  int size=0;
  if(select==1)
  {
    cout<<"Enter a Name : ";
    while(true)
    {
      cin.get(input);
      if(input!='\n')
      {
        arr1=regrow(arr1,input,size);
      }
      else
      {
        break;
      }
    }
  }
  else if(select==2)
  {
    cout<<"Enter a address : ";
    while(true)
    {
      cin.get(input);
      if(input!='\n')
      {
        arr1=regrow(arr1,input,size);
      }
      else
      {
        break;
      }
    }
  }
  else if(select==3)
  {
    cout<<"Enter a Patient Number : ";
    cin>>size;
  }
  if(select!=3)
  {
    int flag=0;
  int num=0;
  while(fin>>num)
  {
  fin.ignore();

  int row=6;	
  char **arr=new char*[row];
  int *col=new int[row];
  arr[0]=new char[1];
  col[0]=0;
  while(true)
  {
    fin.get(input);

    if(input!=',')
    {
      arr[0]=regrow(arr[0],input,col[0]);
    }
    else
    {
      break;
    }
  }
  arr[1]=new char[1];
  col[1]=0;
  while(true)
  {

    fin.get(input);
    if(input!=',')
    {
      arr[1]=regrow(arr[1],input,col[1]);
    }
    else
    {
      break;
    }
  }
  arr[2]=new char[1];
  col[2]=0;
  while(true)
  {

    fin.get(input);

    if(input!=',')
    {
      arr[2]=regrow(arr[2],input,col[2]);
    }
    else
    {
      break;
    }
  }
  col[3]=0;
  arr[3]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[3]=regrow(arr[3],input,col[3]);
    }
    else
    {
      break;
    }
  }
  col[4]=0;
  arr[4]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[4]=regrow(arr[4],input,col[4]);
    }
    else
    {
      break;
    }
  }
  col[5]=0;
  arr[5]=new char[1];
  while(true)
  {
    fin.get(input);
    if(int(input)!=10)
    {
      arr[5]=regrow(arr[5],input,col[5]);
    }
    else
    {
      break;
    }
  }
  flag=0;
  if(size==col[select-1])
  {
    for(int i=0;i<size;i++)
    {
      if(arr1[i]!=arr[select-1][i]&&arr1[i]+32!=arr[select-1][i]&&arr1[i]-32!=arr[select-1][i])
      {
        flag=1;
        break;
      }
    }
  if(flag==0)
  {
    int num1=sub_menu_3();
    delete[]arr[num1-1];
    col[num1-1]=0;
    cin.ignore();
    arr[num1-1]=new char[1];
    cout<<"Enter new editng = ";
    while(true)
    {
      cin.get(input);
      if(input!='\n')
      {
      arr[num1-1]=regrow(arr[num1-1],input,col[num1-1]);	
      }
      else 
      {
        break;
      }
    }
  }
}
  temp(arr,row,col,num);
  delete_2d(arr,row);
  arr=NULL;
  delete[]col;
  col=NULL;
  }
  }
  else
  {
  int num=0;
  while(fin>>num)
  {
  fin.ignore();

  int row=6;	
  char **arr=new char*[row];
  int *col=new int[row];
  arr[0]=new char[1];
  col[0]=0;
  while(true)
  {
    fin.get(input);

    if(input!=',')
    {
      arr[0]=regrow(arr[0],input,col[0]);
    }
    else
    {
      break;
    }
  }
  arr[1]=new char[1];
  col[1]=0;
  while(true)
  {

    fin.get(input);
    if(input!=',')
    {
      arr[1]=regrow(arr[1],input,col[1]);
    }
    else
    {
      break;
    }
  }
  arr[2]=new char[1];
  col[2]=0;
  while(true)
  {

    fin.get(input);

    if(input!=',')
    {
      arr[2]=regrow(arr[2],input,col[2]);
    }
    else
    {
      break;
    }
  }
  col[3]=0;
  arr[3]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[3]=regrow(arr[3],input,col[3]);
    }
    else
    {
      break;
    }
  }
  col[4]=0;
  arr[4]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[4]=regrow(arr[4],input,col[4]);
    }
    else
    {
      break;
    }
  }
  col[5]=0;
  arr[5]=new char[1];
  while(true)
  {
    fin.get(input);
    if(int(input)!=10)
    {
      arr[5]=regrow(arr[5],input,col[5]);
    }
    else
    {
      break;
    }
  }
  if(size==num)
  {
    cin.ignore();
    int num1=sub_menu_3();
    delete[]arr[num1-1];
    col[num1-1]=0;
    arr[num1-1]=new char[1];
    cout<<"Enter new editng = ";
    while(true)
    {
      cin.get(input);
      if(input!='\n')
      {
      arr[num1-1]=regrow(arr[num1-1],input,col[num1-1]);	
      }
      else 
      {
        break;
      }
    }
  }
  temp(arr,row,col,num);
  delete_2d(arr,row);
  arr=NULL;
  delete[]col;
  col=NULL;
  }
  }
}
void Searching_patient(ifstream &fin,int select)
{
  cin.ignore();
  char input;
  char *arr1=new char[1];
  int size=0;
  if(select==1)
  {
    cout<<"Enter a Name : ";
    while(true)
    {
      cin.get(input);
      if(input!='\n')
      {
        arr1=regrow(arr1,input,size);
      }
      else
      {
        break;
      }
    }
  }
  else if(select==2)
  {
    cout<<"Enter a address : ";
    while(true)
    {
      cin.get(input);
      if(input!='\n')
      {
        arr1=regrow(arr1,input,size);
      }
      else
      {
        break;
      }
    }
  }
  else if(select==3)
  {
    cout<<"Enter a Patient Number : ";
    cin>>size;
  }
  int count=0;
  if(select!=3)
  {
    int flag=0;
  int num=0;
  while(fin>>num)
  {
  fin.ignore();

  int row=6;	
  char **arr=new char*[row];
  int *col=new int[row];
  arr[0]=new char[1];
  col[0]=0;
  while(true)
  {
    fin.get(input);

    if(input!=',')
    {
      arr[0]=regrow(arr[0],input,col[0]);
    }
    else
    {
      break;
    }
  }
  arr[1]=new char[1];
  col[1]=0;
  while(true)
  {

    fin.get(input);
    if(input!=',')
    {
      arr[1]=regrow(arr[1],input,col[1]);
    }
    else
    {
      break;
    }
  }
  arr[2]=new char[1];
  col[2]=0;
  while(true)
  {

    fin.get(input);

    if(input!=',')
    {
      arr[2]=regrow(arr[2],input,col[2]);
    }
    else
    {
      break;
    }
  }
  col[3]=0;
  arr[3]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[3]=regrow(arr[3],input,col[3]);
    }
    else
    {
      break;
    }
  }
  col[4]=0;
  arr[4]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[4]=regrow(arr[4],input,col[4]);
    }
    else
    {
      break;
    }
  }
  col[5]=0;
  arr[5]=new char[1];
  while(true)
  {
    fin.get(input);
    if(int(input)!=10)
    {
      arr[5]=regrow(arr[5],input,col[5]);
    }
    else
    {
      break;
    }
  }
  flag=0;
  if(size==col[select-1])
  {
    for(int i=0;i<size;i++)
    {
      if(arr1[i]!=arr[select-1][i]&&arr1[i]+32!=arr[select-1][i]&&arr1[i]-32!=arr[select-1][i])
      {
        flag=1;
        break;
      }
    }
  if(flag==0)
  {
    display(arr,row,col,num);
    count++;
  }
  }
  delete_2d(arr,row);
  arr=NULL;
  delete[]col;
  col=NULL;
  }
  }
  else
  {
  int num=0;
  while(fin>>num)
  {
  fin.ignore();

  int row=6;	
  char **arr=new char*[row];
  int *col=new int[row];
  arr[0]=new char[1];
  col[0]=0;
  while(true)
  {
    fin.get(input);

    if(input!=',')
    {
      arr[0]=regrow(arr[0],input,col[0]);
    }
    else
    {
      break;
    }
  }
  arr[1]=new char[1];
  col[1]=0;
  while(true)
  {

    fin.get(input);
    if(input!=',')
    {
      arr[1]=regrow(arr[1],input,col[1]);
    }
    else
    {
      break;
    }
  }
  arr[2]=new char[1];
  col[2]=0;
  while(true)
  {

    fin.get(input);

    if(input!=',')
    {
      arr[2]=regrow(arr[2],input,col[2]);
    }
    else
    {
      break;
    }
  }
  col[3]=0;
  arr[3]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[3]=regrow(arr[3],input,col[3]);
    }
    else
    {
      break;
    }
  }
  col[4]=0;
  arr[4]=new char[1];
  while(true)
  {
    fin.get(input);
    if(input!=',')
    {
      arr[4]=regrow(arr[4],input,col[4]);
    }
    else
    {
      break;
    }
  }
  col[5]=0;
  arr[5]=new char[1];
  while(true)
  {
    fin.get(input);
    if(int(input)!=10)
    {
      arr[5]=regrow(arr[5],input,col[5]);
    }
    else
    {
      break;
    }
  }
  if(size==num)
  {
    display(arr,row,col,num);
    count++;
  }
  delete_2d(arr,row);
  arr=NULL;
  delete[]col;
  col=NULL;
  }
  }
  if(count==0)
  {
    cout<<"No Record!!"<<endl;
  }
}


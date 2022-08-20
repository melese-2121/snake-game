#include <iostream>
using namespace std;
struct student
{
    string ID;
    string  F_name;
    string L_name;
    string c[10];
    int age;
    string sex;
    struct student *next;
};

 struct course
 {
     int course_no;
     string course_name;
     int credit_hour;
     struct course *next;
 };

bool check_list_empty(student *&head)
{
    if(head == NULL)
        return  true;
    else
        return false;
}

void add_first_student(student *&head,student *&last,string ID,string F_name,string L_name,int age,string sex)
{

       student *temp = new student;
       head = temp;
       last = temp;
       cout<<"Enter students ID, first name, last name, age and sex respectively"<<endl;
           cin>>temp->ID;
           cin>>temp->F_name;
           cin>>temp->L_name;
           cin>>temp->age;
           cin>>temp->sex;

}
void add_student_at_end(student *&head,student *&last,string ID,string F_name,string L_name,int age, string sex)
{
    if(check_list_empty(head))
        add_first_student(head,last,ID,F_name,L_name,age,sex);
    else
    {
        student *temp = new student;
        cout<<"Enter students ID, first name, last name, age and sex respectively"<<endl;
        cin>>temp->ID;
        cin>>temp->F_name;
        cin>>temp->L_name;
        cin>>temp->age;
        cin>>temp->sex;

        temp->next=NULL;
        last->next=temp;
        last = temp;

    }
}

void delete_student(student *&head)
{

 student *temp = head,*temp1=head;
    string id;
    cout<<"Enter id of student to be deleted"<<endl;
    cin>>id;

    if(check_list_empty(head))
        cout<<"The student list is already empty"<<endl;
    else if(temp->ID == id)
    {
    if(temp->next == NULL)
      {
       delete temp;
       temp = NULL;
      }
    else if(temp->next != NULL)
    {
        student *temp2 = temp->next;
        delete temp;
        head = temp2;
    }
    else
        cout<<"The student with this ID is not found"<<endl;
    }
    else if(temp->ID != id && temp->next != NULL)
    {
        temp = temp->next;
        while(temp->next !=NULL)
            {
        if(temp->next != NULL && temp->ID == id)
            {
                temp1->next = temp->next;
                delete temp;
            }

            temp = temp->next;
            temp1 = temp1->next;
            }

        if(temp->next == NULL && temp->ID == id)
            {
              temp1->next = NULL;
              delete temp;
            }

    }


}

void show_the_list(student *current)
{
    if(check_list_empty(current))
        cout<<"the list is empty"<<endl;
    else
        {
        cout<<"The list contains: "<<endl;
        while(current!=NULL)
        {
            cout<<"students id:  "<<current->ID<<endl;
            cout<<"first name:   "<<current->F_name<<endl;
            cout<<"last name:    "<<current->L_name<<endl;
            cout<<"age           "<<current->age<<endl;
            cout<<"sex           "<<current->sex<<endl;

            current = current->next;
        }
        }

}

char choice()
{
    char Choice;
    cout<<"These are the choices you have:" <<endl;

    cout<<"press 'A':  to register student"<<endl;
    cout<<"press 'B':  to delete student "<<endl;
    cout<<"Press 'C':  to show list of student"<<endl;
    cout<<"press 'D':  to access student information by id"<<endl;
    cout<<"press 'E':  to add a course:"<<endl;
    cout<<"press 'F':  to show course using its number"<<endl;
    cout<<"press 'G':  to register student for courses"<<endl;
    cout<<"Press 'H':  to delete course by course number"<<endl;
    cout<<"press 'I':  to see list if courses"<<endl;
    cout<<"press 'J':  to show courses of student"<<endl;
    cout<<"press 'K':  to leave the page"<<endl;

    cin>>Choice;
    return Choice;
}

bool check_the_course_empty(course *&head1)
{
    if(head1 == NULL)
        return true;
    else
        return false;
}


void search_student_by_id(student *&head)
{

    student *temp=head;
    string id;
    bool found = false;
    cout<<"Enter ID of the student: "<<endl;
    cin>>id;
    if(check_list_empty(head))
        cout<<"The list is empty"<<endl;
    while(temp!=NULL)
    {
        if(temp->ID == id)
        {
            cout<<"The student detail information is: "<<endl<<endl;
            cout<<"ID:         "<<temp->ID<<endl;
            cout<<"first name: "<<temp->F_name<<endl;
            cout<<"last name:  "<<temp->L_name<<endl;
            cout<<"age:        "<<temp->age<<endl;
            cout<<"sex:        "<<temp->sex<<endl<<endl;
            cout<<"the student is registered for those courses:"<<endl;
            for(int i=0;i<6;i++)
            cout<<temp->c[i]<<"  ";

            found = true;
        }

        temp = temp->next;
    }
    if(!found)
        cout<<"The student with this ID is not found"<<endl<<endl;


}


void add_course(course *&head1,course *&last1)
{
    course *temp,*temp1;
    int course_no, credit_hour;
    char course_name[50];
    cout<<"Enter course number, course name and credit hour respectively"<<endl;

    if(check_the_course_empty(head1))
    {
        temp = new course;
        head1 = temp;
        last1 = head1;
        cin>>temp->course_no>>temp->course_name>>temp->credit_hour;
        temp->next = NULL;
    }
    else
    {
     temp1 = new course;

        cin>>temp1->course_no>>temp1->course_name>>temp1->credit_hour;
        last1->next = temp1;
        temp1->next = NULL;
        last1 = temp1;
    }
    cout<<"the course registered successfully"<<endl;

}


void search_course(course *&head1)
{
    course *temp = head1;
    int number;
    cout<<"Enter course number!"<<endl;
    cin>>number;

    if(check_the_course_empty(head1))
        cout<<"No course is registered!"<<endl;
    else if(!(check_the_course_empty(head1)))
        {
          do
            {
                if(temp->course_no == number)
                    cout<<" the course is:   "<<temp->course_name<<endl;
                temp = temp->next;
            }
            while(temp != NULL);
        }
    else
         cout<<"The course with this course number is not found"<<endl;

}


void course_tegister(student *&head, course *&head1)
{
    int i=0;
    int result;
    student *temp = head;
    course  *temp1 = head1;
    string id;
    cout<<"Enter id of student"<<endl;
    cin >>id;
    if(check_list_empty(head))
        cout<<"There is no student to register for courses"<<endl;
    else if(!(check_list_empty(head)))
    {
    	bool found = false;
        do
        {
            if(temp->ID == id)
            {
            	found = true;
                cout<<"press 1 for   "<<temp1->course_name<<"    else press any key"<<endl;
                cin>>result;
                if(result == 1)
                {
                   temp->c[i] = temp1->course_name;
                   cout<<"you registered for this course"<<endl;
                   i++;

                }

            }
            if(found == false && temp != NULL)
             temp = temp->next;
             temp1 = temp1->next;

         }while( temp1 != NULL );
    }
    else
        cout<<"The student with this id is not found"<<endl;
}

void delete_course_by_no(course *&head1)
{
    course *temp = head1,*temp1=head1;
    int no;

    cout<<"Enter course number"<<endl;
    cin>>no;

    if(check_the_course_empty(head1))
        cout<<"The course is already empty"<<endl;
    else if(temp->course_no == no)
    {
    if(temp->next == NULL)
      {
       delete temp;
       temp = NULL;
      }
    else if(temp->next != NULL)
    {
        course *temp2 = temp->next;
        delete temp;
        head1 = temp2;
    }
    else
        cout<<"the course with this number is not found"<<endl;
    }
    else if(temp->course_no != no && temp->next != NULL)
    {
        temp = temp->next;
        while(temp->next !=NULL)
            {
        if(temp->next != NULL && temp->course_no == no)
            {
                temp1->next = temp->next;
                delete temp;
            }

            temp = temp->next;
            temp1 = temp1->next;
            }

        if(temp->next == NULL && temp->course_no == no )
            {
              temp1->next = NULL;
              delete temp;
            }

    }


}
void show_course(course *&head1)
{
    course *temp=head1;
    while(temp != NULL)
    {
    cout<<temp->course_no<<"  "<<temp->course_name<<"  "<<temp->credit_hour<<endl;
       temp = temp->next;
    }
}


void show_student_course(student *&head)
{
    string id;
    cout<<"Enter id of student"<<endl;
    cin>>id;
    student *temp = head;
    bool found=false;
    while(temp->next != NULL)
    {
        if(temp->ID == id)
        {
            found = true;
            int i=0;
            cout<<"The student is registered for:"<<endl;
          while(i<10)
          {
              cout<<"     "<<temp->c[i]<<endl;
              i++;

          }
        }

        temp = temp->next;
    }
    if(found = false)
        cout<<"The student with this id is not found"<<endl;


}

int main()
{
    student *head = NULL;
    student *last = NULL;
    course *head1 = NULL;
    course *last1 = NULL;

    char result;
    int age;
    string F_name,L_name,sex,ID;

    do
        {
            result =  choice();
            switch(result)
            {
                case 'a':  add_student_at_end(head,last,ID,F_name,L_name,age,sex);
                           break;
                case 'b':  delete_student(head);
                           break;
                case 'c':  show_the_list(head);
                           break;
                case 'd':  search_student_by_id(head);
                           break;
                case 'e':  add_course(head1, last1);
                           break;
                case 'f':  search_course(head1);
                           break;
                case 'g':  course_tegister(head,head1);
                           break;
                case 'h':  delete_course_by_no(head1);
                           break;
                case 'i':  show_course(head1);
                           break;
                case 'j':  show_student_course(head);
                           break;
                default :
                           break;

            }
        }
    while(result!='k');


    return 0;
}
#include <iostream>
#include<vector>
using namespace std;
struct Course {
	int courseNo;
	string course_title;
	int crh;
	Course *nextCourse;

}*headCourse = NULL;

struct Student{
	int id;
	string first_name;
	string last_name;
	int age;
	string sex;
	Course *courses;
	Student *nextStudent;
}*headStudent = NULL;

bool checkStudent(int id){
	if(headStudent == NULL){
		return false;
	}
	else {
		Student *tempStudent = headStudent;
		while(tempStudent != NULL){
			if(tempStudent->id == id){
				return true;
			}
			tempStudent = tempStudent->nextStudent;
		}
	}
	return false;
	
}
bool checkCourse(int courseNO){
	if(headCourse == NULL){
		return false;
	}
	else {
		Course *tempCourse = headCourse;
		while(tempCourse != NULL){
			if(tempCourse->courseNo == courseNO){
				return true;
			}
			tempCourse = tempCourse->nextCourse;
		}
	}
	return false;
}
void registerStudent()
{
	Student *temp_student = new Student;
	int temp_id;
	cout << "Insert the Id of student" << endl;
	cin >> temp_id;
	if(checkStudent(temp_id)){
		cout << "The Student already exists" << endl;
	}
	 else {
		temp_student->id = temp_id;
		cout << "Enter the first name of student " << endl;
		cin >> temp_student->first_name;
		cout << "Enter the last name of student " << endl;
		cin >> temp_student->last_name;
		cout << "Enter the age of Student " << endl;
		cin >> temp_student->age;
		cout << "Enter the sex of Student " << endl;
		cin >>temp_student->sex;
		temp_student->nextStudent = headStudent;
		headStudent = temp_student;
		cout << "*************STUDENT REGISTERED SUCCESSFULLY***********" << endl;
	}
}
void registerCourse(){
	int temp_id;
	cout << "Insert the Id of course" << endl;
	cin >> temp_id;
	if(checkCourse(temp_id)){
		cout << "The Course already exists" << endl;
	}
	else {
		Course *temp_course = new Course;
		temp_course->courseNo = temp_id;
		cout << "Enter the name of the course " << endl;
		cin >> temp_course->course_title;
		cout << "Enter the the credit hour of the course " << endl;
		cin >> temp_course->crh;
		temp_course->nextCourse = headCourse;
		headCourse = temp_course;
		cout << "****************************************Course REGISTERD SUCCESSFULLY**************************************" << endl;
		cout << "**********************************************************************************************************" << endl;
		
	}
}
void registerStudentForAcourse(){
	int studentId;int courseNo;
	cout << "Enter the Id of a student " << endl;
	cin >> studentId;
	cout << "Enter the courseNo of a Course " << endl;
	cin >> courseNo;

	Student* currentStudent = headStudent;
    while (currentStudent != NULL && currentStudent->id != studentId) {
        currentStudent = currentStudent->nextStudent;
    }
    Course* currentCourse = headCourse;
    while (currentCourse != NULL && currentCourse->courseNo != courseNo) {
        currentCourse = currentCourse->nextCourse;
    }
    if (currentStudent != NULL && currentCourse != NULL) {
        Course* newCourse = new Course;
        newCourse->courseNo = currentCourse->courseNo;
        newCourse->course_title = currentCourse->course_title;
        newCourse->nextCourse = currentStudent->courses;
        currentStudent->courses = newCourse;
    }
    cout << currentStudent->first_name << " is registered for " << currentCourse->course_title << " successfully "<< endl;
    cout << "************************************************************************************************************" << endl;
}
void displayStudent(){
	int id;
	cout << "Enter the ID of a student " << endl;
	cin >> id;
	Student* currentStudent = headStudent;
    while (currentStudent != NULL && currentStudent->id != id) {
        currentStudent = currentStudent->nextStudent;
    }
    cout << "The first name of a student is " << currentStudent->first_name << endl;
    cout << "The second name of a student is " << currentStudent->last_name << endl;
    cout << currentStudent->first_name << "Registerd for " << currentStudent ->courses->course_title << endl;
    cout << "******************************************************************************************" << endl;
    

} 
void displayCourse(){
	int id;
	cout << "Enter the course number of a course " << endl;
	cin >> id;
	Course* currentCourse = headCourse;
    while (currentCourse != NULL && currentCourse->courseNo != id) {
        currentCourse = currentCourse->nextCourse;
    }
    cout << currentCourse->course_title << endl;
    cout << currentCourse->crh << endl;
    cout << "*******************************************************************************************" << endl;

}
void displayStudents(){
	Student *student_ptr;
	student_ptr = headStudent;
	if(headStudent == NULL){
		cout << "There is not student to be displayed for " << endl;
	}
	while(student_ptr != NULL){
		cout << student_ptr->id << endl;
		cout << student_ptr->first_name << endl;
		cout << student_ptr->last_name << endl;
		cout << student_ptr->age << endl;
		cout << student_ptr->sex << endl;
		cout << "*********************************************************" << endl;
		student_ptr = student_ptr->nextStudent;
	}
}
void sortStudents(){
	Student *a, *b;
	if(headStudent == NULL){
		return;
	}
	int temp; string temp1; string temp2; int temp3; string temp4; int temp5; string temp6; int temp7;
	for(a = headStudent; a->nextStudent != NULL; a = a->nextStudent){
		for(b = a->nextStudent; b != NULL; b = b->nextStudent){
			if(a->first_name > b->first_name){
				temp = a->id;
				temp1 = a->first_name;
				temp2 = a->last_name;
				temp3 = a->age;
				temp4 = a->sex;
//				temp5 = a->courses->courseNo;
//				temp6 = a->courses->course_title;
//				temp7 = a->courses->crh;
				a->id = b->id;
				a->first_name = b->first_name;
				a->last_name = b->last_name;
				a->age = b->age;
				a->sex = b->sex;
//				a->courses->courseNo = b->courses->courseNo;
//				a->courses->course_title = b->courses->course_title;
//				a->courses->crh = b->courses->crh;
				b->id = temp;
				b->first_name = temp1;
				b->last_name = temp2;
				b->age = temp3;
				b->sex = temp4;
//				b->courses->courseNo = temp5;
//				b->courses->course_title = temp6;
//				b->courses->crh = temp7;
			}
		}
	}
}
void deleteStuById() {
	int id;
	cout << "Enter the id of a student " << endl;
	cin >> id;
	
    if (headStudent == NULL) {
        cout << "Student with ID " << id << " not found." << endl;
        return;
    }
    if (headStudent->id == id) {
        Student* temp = headStudent;
        headStudent = headStudent->nextStudent;
        delete temp;
        return;
    }
    Student* prev = headStudent;
    Student* curr = headStudent->nextStudent;
    while (curr != NULL) {
        if (curr->id == id) {
            prev->nextStudent = curr->nextStudent;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->nextStudent;
    }
    cout << "Student with ID " << id << " not found." << endl;
}
void deleteCouById() {
	int id;
	cout << "Enter the course number of a course " << endl;
	cin >> id;
	
    if (headCourse == NULL) {
        cout << "Course with Course no " << id << " not found." << endl;
        return;
    }
    if (headCourse->courseNo == id) {
        Course* temp = headCourse;
        headCourse = headCourse->nextCourse;
        delete temp;
        return;
    }
    Course* prev = headCourse;
    Course* curr = headCourse->nextCourse;
    while (curr != NULL) {
        if (curr->courseNo == id) {
            prev->nextCourse = curr->nextCourse;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->nextCourse;
    }
    cout << "Course with course no " << id << " not found." << endl;
}	

int main(int argc, char** argv) {
	int choice;
	while(true){
		cout << "1.Register a student " << endl;
		cout << "2.Register a course " << endl;
		cout << "3.Register a student for a course " << endl;
		cout << "4.Display a student " << endl;
		cout << "5.Display a course " << endl;
		cout << "6.Display all students " << endl;
		cout << "7.Delete student by id " << endl;
		cout << "8.Delete course by courseNo" << endl;
		cout << "7. exit " << endl;
		cin >> choice;
		
		switch(choice){
			case 1:
				registerStudent();
				break;
			case 2:
				registerCourse();
				break;
			case 3:
				registerStudentForAcourse();
				break;
			case 4: 
				displayStudent();
				break;
			case 5:
				displayCourse();
				break;
			case 6:
				sortStudents();
				displayStudents();
				break;
			case 7:
				deleteStuById();
				break;
			case 8:
				deleteCouById();
				break;
			case 9:
				exit(1);	
		}
	}
	return 0;
}


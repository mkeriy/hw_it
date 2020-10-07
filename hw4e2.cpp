#include <iostream>
#include <vector>
#include <string>


struct Student;

struct Lesson{

    Lesson()
    {}

    Lesson(const std::string course):
        less(course)
    {}
	
    ~Lesson()
    {}

    std::string less;
    std::vector <Student*> student_ptr; 
};


struct Student{
    
    Student()
    {}

    Student(const std::string n):
        name(n)
    {}

    

    void add_lesson(std::vector<Lesson> & v, const std::string j, Lesson* a)
    {
        
        for(auto & l: v)
        {
            if(j == l.less)
            {
                a = &l;
				lesson_ptr.push_back(a);
				a->student_ptr.push_back(this);
            }
        }
        
    }

    void print_lessons() 
    {
		for (auto & s : lesson_ptr) 
        {
            
			std::cout << s->less;
		}
    }
      ~Student()
    {}
    std::string name;
    std::vector <Lesson*> lesson_ptr;

};


int main(){


    std::vector <Student> student;
    std::vector <Lesson> subject;
    Lesson a;
    
	Student s1("Ivanov");
    Student s2("Petrov");
    student.push_back(s1);
    student.push_back(s2);
	
    Lesson c1("Math");
    Lesson c2("IT");
	Lesson c3("PE");
    subject.push_back(c1);
	subject.push_back(c2);
	subject.push_back(c3);

	student[0].add_lesson(subject, "Math", &a);
    
	student[0].add_lesson(subject, "IT", &a);
   
    student[1].add_lesson(subject, "PE", &a);
    
	student[0].print_lessons();
    std::cout << std::endl;
    student[1].print_lessons();
    
    
    return 0;
}
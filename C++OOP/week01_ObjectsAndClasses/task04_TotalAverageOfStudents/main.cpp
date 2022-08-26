#include<iostream>
#include<vector>
#include<string>
class Student
{
private:
    std::string name;
    std::string lastName;
    double average;
public:
    Student(std::string _name, std::string _lastName, double _average):
    name(_name), lastName(_lastName), average(_average)
    {

    }
    void print()
    {
        std::cout << name << " " << lastName << " " << average << std::endl;
    }
    
};
int main()
{
    std::vector<Student> students;
    int n = 0;
    std::cin >> n;
    double totalAverage = 0;
    for (size_t i = 0; i < n; i++)
    {
        std::string name;
        std::string lastName;
        double average;
        std::cin >> name;
        std::cin >> lastName;
        std::cin >> average;
        students.push_back(Student(name, lastName, average));
        totalAverage += average;
    }
    totalAverage /= n;
    if (students.empty())
    {
        std::cout << "Invalid input" << std::endl;
    }
    else
    {
        for (Student student : students)
        {
            student.print();
        }
        std::cout << totalAverage << std::endl;
    }    
    


    return 0;
}
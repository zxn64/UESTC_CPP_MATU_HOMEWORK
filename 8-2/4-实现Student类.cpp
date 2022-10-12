#include <iostream>
#include <string>

using namespace std;

class Student {
    string name_, id_;
    int grade_[3];
public:
    Student(const string &name, const string &id, const int &grade1, const int &grade2, const int &grade3) {
        name_ = name;
        id_ = id;
        grade_[0] = grade1;
        grade_[1] = grade2;
        grade_[2] = grade3;
    }

    void display() {
        cout << name_ << ' ' << id_ << ' ';
        for (int i = 0; i < 3; ++i) {
            cout << grade_[i];
            cout << ((i == 2) ? '\n' : ' ');
        }
    }

    int GetGrade(int idx) {
        return grade_[idx];
    }
};

Student *stu1, *stu2, *stu3;

double average(int idx) {
    --idx;
    double sum = stu1->GetGrade(idx) + stu2->GetGrade(idx) + stu3->GetGrade(idx);
    return sum / 3;
}

int main() {
    string name1, name2, name3;
    string num1, num2, num3;
    int grade1[3], grade2[3], grade3[3];
    cin >> name1 >> num1 >> grade1[0] >> grade1[1] >> grade1[2];
    cin >> name2 >> num2 >> grade2[0] >> grade2[1] >> grade2[2];
    cin >> name3 >> num3 >> grade3[0] >> grade3[1] >> grade3[2];
    stu1 = new Student(name1, num1, grade1[0], grade1[1], grade1[2]);
    stu2 = new Student(name2, num2, grade2[0], grade2[1], grade2[2]);
    stu3 = new Student(name3, num3, grade3[0], grade3[1], grade3[2]);

    stu1->display();
    stu2->display();
    stu3->display();

    cout << "The average grade of course1:" << average(1) << endl;
    cout << "The average grade of course2:" << average(2) << endl;
    cout << "The average grade of course3:" << average(3) << endl;
    return 0;
}

#ifndef SELECTONSORT_STUDENT_H
#define SELECTONSORT_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student
{
  string name;
  int score;

  // 对小于运算符进行重载
  bool operator<(const Student &otherStudent)
  {
    // 分数相等则根据字典顺序来排序
    return score != otherStudent.score ? score < otherStudent.score : name > otherStudent.name;
  }

  //对输出运算符进行重载
  friend ostream &operator<<(ostream &os, const Student &student)
  {
    os << "Student:" << student.name << " " << student.score << endl;
    return os;
  }
};

#endif
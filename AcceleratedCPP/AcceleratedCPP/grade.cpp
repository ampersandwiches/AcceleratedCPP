#include <stdexcept>
#include <vector>
#include <list>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;	using std::vector;
using std::cin;				using std::cout;
using std::endl;			using std::list;

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();
	while (iter != students.end())
	{
		if (fgrade(*iter))
		{
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}

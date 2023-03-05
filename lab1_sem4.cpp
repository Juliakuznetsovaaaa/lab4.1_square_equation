#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && (std::isdigit(*it)||((*it)=='.'))) ++it;
    return !s.empty() && it == s.end();
}

void reading(float* nums) {
    ifstream fin("C:\\Users\\Julia\\source\\repos\\4sem_lab1\\input.txt");
    string num;
    for (int i = 0; i < 3; i++) {
        fin >> num;
        if (is_number(num)) {
            std::stringstream ss;
            ss << num;
            float num_float;
            ss >> num_float;
            nums[i] = num_float;
        }
        else {
            break;
        }
    }
}

float discriminant(float a, float b, float c) {
    float discriminant = b * b - 4 * a * c;
    return discriminant;
}

float root_1(float a, float b, float c, float discr) {
    return ((-b + sqrt(discr)) / (2 * a));
}

float root_2(float a, float b, float c, float discr) {
    return ((-b - sqrt(discr)) / (2 * a));
}
void find_roots(float discr, float a, float b, float c) {
    ofstream fout("C:\\Users\\Julia\\source\\repos\\4sem_lab1\\output.txt");
    if ((discr > 0) & (a != 0)) {
        fout << "Корень 1: ";
        float k1 = root_1(a, b, c, discr);
        fout << k1 << endl;
        fout << "Корень 2: ";
        float k2 = root_2(a, b, c, discr);
        fout << k2 << endl;
    }
    else if ((discr == 0) & (a != 0)) {
        float k = root_1(a, b, c, discr);
        fout << "Корень: " << k << endl;
    }
    else {
        fout << "корней нет";
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    float nums[] = { 0, 0, 0 };
    reading(nums);
    ofstream fout("C:\\Users\\Julia\\source\\repos\\4sem_lab1\\output.txt");
    float a = nums[0];
    float b = nums[1];
    float c = nums[2];
    float discr = discriminant(a, b, c);
    find_roots(discr, a, b, c);
}

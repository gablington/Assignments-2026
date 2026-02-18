#include<iostream>
#include<string>
#include<sstream>
#include<stdexcept>
#include<cmath>
#include<stdlib.h>
#include<vector>
#include<fstream>
#include <bits/stdc++.h>

std::string data_file{"Assignment_2/course_marks.dat"};

// Function to calculate mean.
// Input:  All the useful input data (vector of vector of strings) and the number of modules (integer).
// Output: The mean of the scores in each modules (float).
float mean_calculation(float grade_total, float number_of_courses)
{
    float mean{grade_total/number_of_courses};
    return(mean);
}

// calculate std dev
float standard_deviation_calculation(float number_of_courses, float mean_grade_squared)
{
    float standard_deviation{sqrtf(mean_grade_squared/(number_of_courses-1))};
    return(standard_deviation);
}

// calculate std err
float standard_error_calculation(float standard_deviation, float number_of_courses)
{
    float standard_error{standard_deviation/sqrtf(number_of_courses)};
    return(standard_error);
}

// read data into vector of strings
// std::vector<std::string> data_reader();
// {

// }

int main()
{
    char yn_restart;
    std::string three_spaces{"   "};
    float grade;
    std::string module_code;
    std::string data_line;
    std::stringstream decantable_data_line;
    std::vector<float> average_marks;
    std::vector<std::string> stackable_data_line(1);
    std::vector<std::vector<std::string>> dataset;

    yn_restart == 'Y';

    do
    {
        float number_of_lines{0};
        float grade_total{0};
        float mean_centered_grade_squared{0};

        std::fstream file;//data("course_marks.dat");
        file.open(data_file);//("Assignment_2/course_marks.dat");
        if(file.is_open())
        {
            std::cout<<"File is open. Proceeding..."<<std::endl;
        }
        if (!file.is_open())
        {
            std::cout<<"File cannot open. Please check file and try again."<<std::endl;
            return 0;
        }
        while(std::getline(file, data_line))
        {
            decantable_data_line.str("");
            stackable_data_line.clear();
            number_of_lines+=1;

            std::cout<<data_line<<std::endl;
            stackable_data_line.push_back(data_line); //whole unordered dataset


            decantable_data_line<<data_line;
            decantable_data_line>>grade;
            average_marks.push_back(grade);


            decantable_data_line>>module_code; //need to extract first character of module code for year and maybe semester
            char year{module_code[0]};
            

            auto pos{data_line.find(three_spaces)}; //find where the module name starts
            std::string module_name{data_line.erase(0, pos+3)};
            dataset.push_back(stackable_data_line);
        }

        std::for_each(average_marks.begin(), average_marks.end(), [&] (float n)
        {
         grade_total += n;
        });

        float mean_grade{mean_calculation(grade_total, number_of_lines)};

        std::for_each(average_marks.begin(), average_marks.end(), [&] (float n)
        {
         mean_centered_grade_squared += (n-mean_grade)*(n-mean_grade);
        });

        float standard_deviation{standard_deviation_calculation(number_of_lines, mean_centered_grade_squared)};
        float standard_error{standard_error_calculation(standard_deviation, number_of_lines)};

        std::cout<<mean_grade<<" "<<standard_deviation<<" "<<standard_error<<" "<<std::endl;


        //leaving clear to keep code that needs work separated from complete code

        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Would you like to restart? Y/N: "<<std::endl;
        std::cin>>yn_restart;
        
        while(yn_restart!='Y' && yn_restart!='N')
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Please select Y or N: "<<std::endl;
            std::cin>>yn_restart;
        }
        file.close();
    }while(yn_restart=='Y');

    if(yn_restart=='N')
        {
            std::cout<<"Thank you for playing!"<<std::endl;
        }

    return 0;
}
#include<iostream>
#include<string>
#include<sstream>
#include<stdexcept>
#include<cmath>
#include<stdlib.h>
#include<vector>
#include<fstream>

std::string data_file{"course_marks.dat"};

// Function to calculate mean.
// Input:  All the useful input data (vector of vector of strings) and the number of modules (integer).
// Output: The mean of the scores in each modules (float).
float mean_calcilation(std::vector<std::string> all_data, int number_of_course)
{
    float mean{};
}

// calculate std dev

// calculate std err

// read data into vector of strings
// std::vector<std::string> data_reader();
// {

// }

int main()
{
    char yn_restart;
    std::string grade;
    std::string module_code;
    std::string data_line;
    std::stringstream decantable_data_line;
    std::vector<std::string> stackable_data_line(2);
    std::vector<std::vector<std::string>> dataset;

    yn_restart == 'Y';

    std::ifstream data(data_file);

    if (!data.is_open())
    {
        std::cout<<"File cannot open. Please check file and try again."<<std::endl;
        return 0;
    }

    do
    {
        int number_of_lines{0};

        while (getline(data, data_line))
        {
            stackable_data_line.clear();
            number_of_lines+1;
            std::cout<<data_line<<std::endl;
            decantable_data_line<<data_line;
            decantable_data_line>>grade;
            decantable_data_line>>module_code; //need to extract first character of module code for year and maybe semester
            std::string year{module_code[0]};
            stackable_data_line.push_back(grade);
            stackable_data_line.push_back(module_code);
            dataset.push_back(stackable_data_line);
        }
        



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
    }while(yn_restart='Y');

    if(yn_restart=='N')
        {
            std::cout<<"Thank you for playing!"<<std::endl;
        }

    data.close();
    return 0;
}
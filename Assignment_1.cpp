#include<iostream>
#include<string>
#include<sstream>
#include<stdexcept>
#include<cmath>
#include<stdlib.h>

float energy_calculation(float atomic_number, float initial_n, float final_n)
{
    float energy_in_eV;
    int one_or_two;
    const float rydberg{13.6};
    std::string units;

    std::cout<<"If you would like the transition energy in eV, press 1. If you would like it in "<<
    "Joules, press 2: "<<std::endl;
    std::cin>>one_or_two;
    while (one_or_two!=1 && one_or_two!=2)
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Please press 1 or 2: "<<std::endl;
        std::cin>>one_or_two;
    }
    if(one_or_two==1)
    {
        energy_in_eV = 1;
        units = "eV";
    }
    if(one_or_two==2)
    {
        energy_in_eV = 1.6e-19;
        units = "J";
    }
    
    float energy{energy_in_eV*atomic_number*rydberg*(1/(final_n*final_n) - 1/(initial_n*initial_n))};
    std::cout<<energy<<std::endl;
return energy;
}


int main()
{
    std::string input_values;
    float initial_n;
    float final_n;
    float atomic_number;
    char yn_restart;

    yn_restart == 'Y';

    do
    {
        std::cout<<"Assuming Bohr's model of the atom, one can calculate the energy of "<<
        "photons released in transitions from higher to lower energy levels. Please state "<<
        "a higher energy level, one that an electron will initially be in, followed by the "<<
        "lower energy level that the electron will fall to, and then the atomic number of "<<
        "the atom that is emitting the photon. These should all be integers seperated by spaces: "<<std::endl;
        std::getline(std::cin,input_values);

        std::stringstream readable_input_values(input_values);
        readable_input_values>>initial_n;
        readable_input_values>>final_n;
        readable_input_values>>atomic_number;

        while (initial_n <= 1 || initial_n!=floor(initial_n))
        {
            std::cin.clear();
            std::cin.ignore();
            if(initial_n!=floor(initial_n))
            {
                std::cout<<"You have not input an integer initial energy level. "<<std::endl;
            }
            if(initial_n<1)
            {
                std::cout<<"Your input initial energy level is less than 1, or you have used non-numeric values. "<<std::endl;
            }
            if(initial_n==1)
            {
                std::cout<<"Your input energy level is equal to 1, so the photon cannot de-excite. "<<std::endl;
            }
            std::cout<<"Please choose an integer of value greater than 1 for your intial energy level. "<<std::endl;
            std::cin>>initial_n;
        }

        while (final_n < 1 || final_n!=floor(final_n) || final_n>=initial_n )//do
        {
            std::cin.clear();
            std::cin.ignore();
            if(final_n!=floor(final_n))
            {
                std::cout<<"You have not input an integer final energy level. "<<std::endl;
            }
            if(final_n<1)
            {
                std::cout<<"Your input final energy level is less than 1, or you have used non-numeric values. "<<std::endl;
            }
            if(final_n>=initial_n)
            {
                std::cout<<"Your final energy state is greater than your initial energy state. "<<std::endl;
            }
            std::cout<<"Please choose an integer of value greater than 0 which is lower than the initial energy level "<<
            "for your final energy level. "<<std::endl;
            std::cin>>final_n;
        }
        
        while(atomic_number<1 || atomic_number!=floor(atomic_number) || atomic_number>118)
        {
            std::cin.clear();
            std::cin.ignore();
            if(atomic_number!=floor(atomic_number))
            {
                std::cout<<"You have not input an integer atomic number. "<<std::endl;
            }
            if(atomic_number<=0)
            {
                std::cout<<"Your input atomic number is less than 1.  "<<std::endl;
            }
            if(atomic_number>118)
            {
                std::cout<<"The highest possible atomic number is 118, which is Oganesson. "<<std::endl;
            }
            std::cout<<"Your chosen atomic number is not valid. Please choose an integer that is greater than zero: "<<std::endl;
            std::cin>>atomic_number;
        }

        std::cout<<"The photon energy of the transition from "<<initial_n<<" to "<<final_n<<
        " for an atom of atomic number "<<atomic_number<<" is "<<energy_calculation(atomic_number, initial_n, final_n)<<
        std::endl;

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
        
        std::cin.clear();
        std::cin.ignore();
        
    } while (yn_restart=='Y');

    if(yn_restart=='N')
        {
            std::cout<<"Thank you for playing!"<<std::endl;
        }

return 0;
}
/**
    FixMeStick_exercise.cpp
    Purpose: Sorts a vector of strings containing software versions in ascending order
    Compiler: gcc 5.4.0

    @author Hamed Mohammadian
    @version 1.1 28/04/17
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

// using namespace std;

std::string versionToKey(std::string input)
{
	std::rotate(input.begin(), input.begin() + 11, input.end());
	return input;
}

std::list<std::string> sortSoftwareVersions(std::list<std::string> input)
{
	input.sort([](const std::string& a, const std::string& b) {
		return versionToKey(a) < versionToKey(b);
	});

	return input;
}


int main()
{

	std::list<std::string> str = { "02.10.70.09", "03.00.00.00", "03.02.01.00", "02.00.00.00", "02.10.70.08",
	                               "02.01.07.99", "20.06.60.03", "29.80.10.50", "12.11.22.33", "12.11.21.33"
	                             };
	std::list<std::string> strSorted = sortSoftwareVersions(str);
	std::list<std::string>::iterator itr;
	
	 std::cout << "List before sorting :" << std::endl;
	for(itr = str.begin(); itr != str.end(); ++itr)
		std::cout << *itr << std::endl;

	std::cout << std::endl;
	
    std::cout << std::endl << "List after sorting :" << std::endl;   
	for(itr = strSorted.begin(); itr != strSorted.end(); ++itr)
		std::cout << *itr << std::endl;
		
	
}

/**
    FixMeStick_exercise.cpp
    Purpose: Sorts a vector of strings containing software versions in ascending order
    Compiler: gcc 5.4.0

    @author Hamed Mohammadian
    @version 2.0 08/05/17
*/

#include <iostream>
#include <algorithm>
#include <vector>

// using namespace std;

std::vector<std::string> sortSoftwareVersions(const std::vector<std::string>& input) {
	std::vector<std::string> tmp = input;
	std::sort(tmp.begin(), tmp.end());

	return tmp;
}

int main() {

	std::vector<std::string> str { "20.0.1.2", "3.2.0.0", "3.2.1.0", "20.1.0.0", "2.1.0.0", "2.1.0.99", "2.1.0.98", "0.0.0.98", "20.0.0.1" };
	std::vector<std::string>::iterator itr;

	std::cout << "Vector before sorting :" << std::endl;

	for(itr = str.begin(); itr != str.end(); ++itr)
		std::cout << *itr << std::endl;

	std::cout << std::endl << "Vector after sorting :" << std::endl;


	// Sort function
	std::sort(str.begin(), str.end(), [](std::string l, std::string r) {
		std::vector<int> l_;
		std::vector<int> r_;
		std::string tmp;
		unsigned int i;
		unsigned int maxOctets;

		for(i = 0; i < l.length(); i++) {
			if(l[i] != '.')
				tmp += l[i];
			else {
				l_.push_back(std::stoi(tmp));
				tmp.clear();
			}
		}

		l_.push_back(std::stoi(tmp));
		tmp.clear();

		for(i = 0; i < r.length(); i++) {
			if(r[i] != '.')
				tmp += r[i];
			else {
				r_.push_back(std::stoi(tmp));
				tmp.clear();
			}
		}

		r_.push_back(std::stoi(tmp));


		if (r_.size() < l_.size())
			maxOctets = r_.size();
		else
			maxOctets = l_.size();

		for(i = 0; i < maxOctets; i++) {
			if(l_[i] < r_[i])
				return true;

			if(l_[i] == r_[i])
				continue;

			if(l_[i] > r_[i])
				return false;
		}
	});

	for(itr = str.begin(); itr != str.end(); ++itr)
		std::cout << *itr << std::endl;

	return 0;
}

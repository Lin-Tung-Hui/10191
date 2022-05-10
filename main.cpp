#include <string>
#include <stack>
#include <deque>
#include <iostream>
#include <sstream>

//#define GTEST

class Rail
{
public:
    Rail(std::stringstream &permutation, int number)
        : number_(number)
    {
        init_rail_A();
        init_rail_B(permutation);
    };
    bool check_permutation();

public:
    void init_rail_A();
    void init_rail_B(std::stringstream &permutation);

private:
    int number_;
    std::deque< int > rail_A;
    std::deque< int > rail_B;
    std::stack< int > station;
};

void Rail::init_rail_A()
{
    for (int i = 1; i <= number_; i++)
        rail_A.push_back(i);
}
void Rail::init_rail_B(std::stringstream &permutation)
{
    for (int i = 0; i < number_; i++) {
        int number;
        permutation >> number;
        rail_B.push_back(number);
    }
}

bool Rail::check_permutation()
{
    while (!rail_B.empty()) {
        if (rail_B.front() >= rail_A.front()) {
            station.push(rail_A.front());
            rail_A.pop_front();
        }

        while ((!rail_B.empty()) && (!station.empty())) {

            if (!rail_A.empty()) {
                if ((rail_A.front() > rail_B.front()) && (station.top() > rail_B.front()))
                    return false;
            }

            if (station.top() == rail_B.front()) {
                rail_B.pop_front();
                station.pop();
            } else
                break;
        }

        if (rail_A.empty() && (!rail_B.empty())) {
            return false;
        }
    }

    return true;
}

void uva541(std::istream &is, std::ostream &os)
{
    while (true) {
        std::string line;
        std::getline(is, line);

        if (line == "")
            break;

        int number = atoi(line.c_str());
        if (number == 0)
            break;

        while (true) {
            std::getline(is, line);
            if (atoi(line.c_str()) == 0) {
                os << std::endl;
                break;
            }
            std::stringstream permutation(line);
            Rail uva541_rail(permutation, number);
            if (uva541_rail.check_permutation() == true)
                os << "Yes\n";
            else
                os << "No\n";
        }
    }
}

int main(int argc, char **argv)
{

#ifdef GTEST
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    uva541(std::cin, std::cout);
#endif
    return 0;
}

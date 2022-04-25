#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#ifdef GTEST
#include <gtest/gtest.h>
#endif

struct appointment {
    int start_time;
    int total_time;
};

struct LongestSnap {
    int day;
    int start_time;
    int total_time;
};

struct LongestSnap count_longest_snap(std::vector< appointment > &appointments)
{
    int longest_snap_time = 0;
    int longest_snap_begin = 0;
    int total_nums = appointments.size();
    int snap_begin = 600, snap_end = 0, tmp_snap_time;
    int i = 0;
    while (snap_end < 1080) {
        while (snap_begin >= appointments[i].start_time && (i < total_nums)) {
            if (snap_begin < appointments[i].start_time + appointments[i].total_time)
                snap_begin = appointments[i].start_time + appointments[i].total_time;
            i++;
        }

        if (i == appointments.size())
            snap_end = 1080;
        else
            snap_end = appointments[i].start_time;

        tmp_snap_time = snap_end - snap_begin;
        if (tmp_snap_time > longest_snap_time) {
            longest_snap_time = tmp_snap_time;
            longest_snap_begin = snap_begin;
        }
        snap_begin = snap_end;
    }

    LongestSnap longest_snap;
    longest_snap.start_time = longest_snap_begin;
    longest_snap.total_time = longest_snap_time;

    return longest_snap;
}

struct LongestSnap get_longest_snap(std::istream &is, int number, int day)
{
    std::string input;
    LongestSnap longest_snap;
    std::vector< appointment > appointments;

    for (int i = 0; i < number; i++) {
        std::getline(is, input);

        std::stringstream ss(input);
        struct appointment my_appointment;
        int hh1, mm1, hh2, mm2;
        char ch;
        ss >> hh1 >> ch >> mm1;
        ss >> hh2 >> ch >> mm2;
        my_appointment.start_time = (hh1 * 60 + mm1);
        my_appointment.total_time = (hh2 * 60 + mm2) - my_appointment.start_time;

        appointments.push_back(my_appointment);
    }
    std::sort(appointments.begin(), appointments.end(), [](appointment a, appointment b) {
        return a.start_time < b.start_time;
    });

    longest_snap = count_longest_snap(appointments);
    longest_snap.day = day;

    return longest_snap;
}

bool dump_longest_snap(struct LongestSnap longest_snap, std::ostream &os)
{
    std::stringstream output;
    output << "Day #" << longest_snap.day << ": the longest nap starts at ";
    char start_time[6];
    snprintf(start_time, 6, "%02d:%02d", (longest_snap.start_time / 60), (longest_snap.start_time % 60));
    output << start_time;
    output << " and will last for ";
    if (longest_snap.total_time >= 60) {
        output << (longest_snap.total_time / 60) << " hours and ";
    }
    output << (longest_snap.total_time % 60) << " minutes." << std::endl;
    os << output.str();

    return true;
}

void uva10191(std::istream &is, std::ostream &os)
{
    int day = 1;
    while (true) {
        std::string input;
        std::getline(is, input);
        std::stringstream ss;
        ss << input;

        int number = 0;
        ss >> number;
        if (number <= 0)
            break;
        dump_longest_snap(get_longest_snap(is, number, day), os);
        day++;
    }
}

int main(int argc, char **argv)
{

#ifdef GTEST
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    uva10191(std::cin, std::cout);
#endif
}

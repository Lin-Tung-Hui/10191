#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "main.cpp"

TEST(longest_snap, test_1)
{
    std::istringstream iss(R"--(4
10:00 12:00 Lectures
12:00 13:00 Lunch, like always.
13:00 15:00 Boring lectures...
15:30 17:45 Reading
4
10:00 12:00 Lectures
12:00 13:00 Lunch, just lunch.
13:00 15:00 Lectures, lectures... oh, no!
16:45 17:45 Reading (to be or not to be?)
4
10:00 12:00 Lectures, as everyday.
12:00 13:00 Lunch, again!!!
13:00 15:00 Lectures, more lectures!
15:30 17:15 Reading (I love reading, but should I schedule it?)
1
12:00 13:00 I love lunch! Have you ever noticed it? :)
1
12:00 16:00 I love lunch! Have you ever noticed it? :)
2
10:00 16:00 Reading......
16:01 18:00 Take exercise(table tennis with Professor Z)
)--");

    std::ostringstream oss;

    uva10191(iss, oss);

    EXPECT_EQ(
            "Day #1: the longest nap starts at 15:00 and will last for 30 minutes.\n"
            "Day #2: the longest nap starts at 15:00 and will last for 1 hours and 45 minutes.\n"
            "Day #3: the longest nap starts at 17:15 and will last for 45 minutes.\n"
            "Day #4: the longest nap starts at 13:00 and will last for 5 hours and 0 minutes.\n"
            "Day #5: the longest nap starts at 10:00 and will last for 2 hours and 0 minutes.\n"
            "Day #6: the longest nap starts at 16:00 and will last for 1 minutes.\n",
            oss.str());
}
TEST(longest_snap, test_2)
{
    std::istringstream iss("4\n"
                           "10:00 12:00 Lectures\n"
                           "12:00 13:00 Lunch, like always.\n"
                           "12:00 12:05 Boring lectures...\n"
                           "15:30 17:45 Reading\n");

    std::ostringstream oss;

    uva10191(iss, oss);

    EXPECT_EQ("Day #1: the longest nap starts at 13:00 and will last for 2 hours and 30 minutes.\n", oss.str());
}

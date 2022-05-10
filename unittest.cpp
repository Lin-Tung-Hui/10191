#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "main.cpp"

TEST(rail, test_1)
{
    std::istringstream iss(R"--(5
1 2 3 4 5
5 4 1 2 3
1 4 3 2 5
3 4 2 5 1
3 4 2 1 5
4 3 5 2 1
0
3
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
0
4
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
0
10
5 7 10 9 8 6 4 3 2 1
5 6 4 8 7 3 2 9 1 10
0
0
)--");

    std::ostringstream oss;

    uva541(iss, oss);

    EXPECT_EQ(R"--(Yes
No
Yes
Yes
Yes
Yes

Yes
Yes
Yes
Yes
No
Yes

Yes
Yes
Yes
Yes
No
Yes
Yes
Yes
Yes
Yes
No
Yes
No
No
Yes
Yes
No
Yes
No
No
No
No
No
Yes

Yes
Yes

)--",
              oss.str());
}

TEST(rail, test_2)
{
    std::istringstream iss(R"--(5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0
)--");

    std::ostringstream oss;

    uva541(iss, oss);

    EXPECT_EQ(
            "Yes\n"
            "No\n"
            "\n"
            "Yes\n"
            "\n",
            oss.str());
}

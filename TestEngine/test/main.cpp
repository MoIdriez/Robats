#include <gtest/gtest.h>
#include "PrintGamePad.cpp"
#include "CSVCrazyFlie.cpp"
#include "SimpleHover.cpp"
#include "SimpleFly.cpp"
#include "SimpleBalance.cpp"

//#include "TestCounter.h"
//
//TEST(TestCounter, Increment) {
//      TestCounter tc;
//      EXPECT_EQ(0, tc.Increment());
////      EXPECT_EQ(0, tc.Increment());
////      EXPECT_EQ(1, tc.Increment());
////      EXPECT_EQ(2, tc.Increment());
//}

//TEST(Counter, Increment) {
//      Counter c;
//      EXPECT_EQ(0, c.Increment());
//      EXPECT_EQ(1, c.Increment());
//      EXPECT_EQ(2, c.Increment());
//}
//
//TEST(Crazyflie, Hover) {
//	GamePadTest g;
//	g.run();
//}


int main(int argc, char *argv[]) {
	try {
//		CSVCrazyFlie* x = new CSVCrazyFlie("Something.txt");
		SimpleFly x;
		x.run();
	} catch(char const* msg) {
		std::cout << msg;
	}
	//::testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
}

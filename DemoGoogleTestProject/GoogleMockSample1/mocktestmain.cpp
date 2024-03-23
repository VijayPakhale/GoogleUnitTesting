#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace std;
TEST(SampleTest, BasicAddTest)
{
	ASSERT_EQ(2, 1 + 1);
}

class MyClass
{
public:
	MyClass() = default;
	void MyMethod()
	{
		cout << "MyMethod" << endl;
	}
};

class MyClassMock : public MyClass
{
public:
	MOCK_METHOD0(MyMethod, void());
};

TEST(SampleMockTest, MyClassMethod)
{
	cout << "In SampleMockTest/MyClassMethod." << endl;
	MyClassMock classMock;

	//EXPECT_CALL(classMock, MyMethod).Times(1);
	EXPECT_CALL(classMock, MyMethod);
	classMock.MyMethod();
	cout << "MyMethod called 1 Time." << endl;
	//classMock.MyMethod();
}

int main(int argc, char* argv[])
{
	cout << "First Sample GMock Project" << endl;
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
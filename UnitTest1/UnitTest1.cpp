#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_8.1_char.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(CountTest)
        {
            char str[] = "abcababcabc";
            Assert::AreEqual(3, Count(str));
        }

        TEST_METHOD(ChangeTest)
        {
            
            char str1[] = "abcababcababc";
            char exp1[] = "**ab**ab**";
            Change(str1);
            Assert::AreEqual(exp1, str1); // Перевірка результату

        }
	};
}

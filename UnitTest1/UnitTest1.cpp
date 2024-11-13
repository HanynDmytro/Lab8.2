#include "pch.h"
#include "CppUnitTest.h"
#include "../pr8.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string input = "Hello (World)!";
			string expected = "Hello !";
			Assert::AreEqual(expected, removeParenthesesContent(input));
		}
	};
}

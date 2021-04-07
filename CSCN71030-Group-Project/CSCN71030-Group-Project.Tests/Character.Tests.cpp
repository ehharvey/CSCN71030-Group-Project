#include "pch.h"
#include "CppUnitTest.h"
#include "../CSCN71030-Group-Project/Character.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CharacterTests
{
	TEST_CLASS(CharacterTests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Character* UserChar = new spoon("name");
		}
	};
}

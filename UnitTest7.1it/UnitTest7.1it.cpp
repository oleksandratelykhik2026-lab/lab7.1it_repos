#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.1it/lab7.1it.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71it
{
	TEST_CLASS(UnitTest71it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int a[ROWS][COLS];

            // Заповнюємо матрицю непарними числами,
            // щоб початкові елементи не відповідали умові
            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    a[i][j] = 1;

            a[0][0] = 2;
            a[0][1] = 7;
            a[0][2] = 14;
            a[0][3] = 16;
            a[0][4] = 21;
            a[0][5] = 74;
            a[1][0] = 70;
            a[1][1] = 18;

            int S = 0;
            int k = 0;

            Calc(a, S, k);

            Assert::AreEqual(110, S);
            Assert::AreEqual(4, k);

            Assert::AreEqual(0, a[0][0]);
            Assert::AreEqual(7, a[0][1]);
            Assert::AreEqual(14, a[0][2]);
            Assert::AreEqual(0, a[0][3]);
            Assert::AreEqual(21, a[0][4]);
            Assert::AreEqual(0, a[0][5]);
            Assert::AreEqual(70, a[1][0]);
            Assert::AreEqual(0, a[1][1]);
		}
	};
}

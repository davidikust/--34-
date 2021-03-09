#include "pch.h"
#include "CppUnitTest.h"
#include "string"

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	string programm(double a, double b, double c, double d, double e, double f)
	{
		string ans = "";


		// Branch 5
		if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0))
		{
			return "5";
		}

		// Branch 2xy
		else if ((a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0)))
		{
			double y = (a * f - c * e) / (a * d - c * b);
			double x = (d * e - b * f) / (d * a - b * c);

			ans = string("2xy");
			return ans;
		}

		// Branch 34__
		else if (((a * d - c * b == 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))) 
			||(a == 0 && c == 0 && e / b != f / d) 
			||(b == 0 && d == 0 && e / a != f / c)
			||(a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0)))
			 {
			ans = "!";

				// Branch 4y
				if (((a == 0 && b == 0 && e == 0 && d != 0 && c == 0) ||
					(c == 0 && d == 0 && f == 0 && b != 0 && a == 0)))
				{
					double y;
					if (b == 0)
						y = f / d;
					else if (d == 0)
						y = e / b;
					else if (e == 0 || f == 0)
						y = 0;

					ans += string("4y");
					return ans;
				}
				// Branch 3x
				else if (((a == 0 && b == 0 && e == 0 && c != 0 && d == 0) ||
					(c == 0 && d == 0 && f == 0 && a != 0 && b == 0)))
					 {
						double x;
						if (a == 0)
							x = f / c;
						else if (c == 0)
							x = e / a;
						else if (e == 0 || f == 0)
							x = 0;

						ans += string("3x");
						return ans;
					 }
				// Branch 0
				else
				{
					ans += "0";
					return ans;
			 	}
			 }//End of 34__

		// Branch 4y
		else if (a == 0 && c == 0)
		{
			double y;
			if (e == 0)
				y = f / d;
			else if (f == 0)
				y = e / b;
			else
				y = e / b;
			
			ans = string("4y");
			return ans;
		}

		// Branch 3x
		else if (b == 0 && d == 0)
		{
			double x;
			if (e == 0)
				x = f / c;
			else if (f == 0)
				x = e / a;
			else
				x = e / a;
			
			ans = string("3x");
			return ans;
		}

		// Branch 1k_b0_e0
		else if (b == 0 && e == 0)
		{
			double k, n;
			k = -c / d;
			n = f / d;

			ans = string("1k_b0e0");
			return ans;
		}

		// Branch 1k_d0_f0
		else if (d == 0 && f == 0)
		{
			double k, n;
			k = -a / b;
			n = e / b;

			ans = string("1k_d0f0");
			return ans;
		}

		// Branch 1k_a0_e0
		else if (a == 0 && e == 0)
		{
			double k, n;
			k = -d / c;
			n = f / c;

			ans = string("1k_a0e0");
			return ans;
		}

		// Branch 1k_c0_f0
		else if (c == 0 && f == 0)
		{
			double k, n;
			k = -b / a;
			n = e / a;

			ans = string("1k_c0f0");
			return ans;
		}

		// Branch 1k_ab_cd
		else if ((a / b == c / d))
		{
			double k, n;
			k = -c / d;
			n = f / d;

			ans = string("1k_ab_cd");
			return ans;
		}

		// Branch AreYouKidding
		else
		{
			return "AreYouKidding";
		}
		return 0;
	}





	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(BranchIfElse5Test)
		{
			//(a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0)
			Assert::IsTrue(programm(0, 0, 0, 0, 0, 0) == "5", L"BranchIfElse5Test mismatch");
		}
		TEST_METHOD(BranchIfElse2xyTest)
		{
			//(a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))
			Assert::IsTrue(programm(3, 5, 2, 4, 5, 3) == "2xy", L"BranchIfElse2xyTest mismatch");
		}

		TEST_METHOD(BranchIfElseEnterIn34__Test)
		{
			/*
			(((a * d - c * b == 0) && ((e * d - b * f != 0) || (a * f - c * e != 0)))
			|| (a == 0 && c == 0 && e / b != f / d)
			|| (b == 0 && d == 0 && e / a != f / c)
			|| (a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0)))
			*/



			//(a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))
			Assert::IsTrue(programm(3, 5, 2, 4, 5, 3)[0] == '!', L"BranchIfElseEnterIn341___Test1 mismatch");

			//(a == 0 && c == 0 && e / b != f / d)
			Assert::IsTrue(programm(0, 1, 0, 1, 5, 3)[0] == '!', L"BranchIfElseEnterIn341___Test2 mismatch");

			//(b == 0 && d == 0 && e / a != f / c)
			Assert::IsTrue(programm(1, 0, 1, 0, 5, 3)[0] == '!', L"BranchIfElseEnterIn341___Test3 mismatch");

			//(a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0)))
			Assert::IsTrue(programm(0, 5, 0, 4, 5, 3)[0] == '!', L"BranchIfElseEnterIn341___Test4 mismatch");
		}

		TEST_METHOD(BranchIfElse34_4yTest)
		{
			//(a == 0 && b == 0 && e == 0 && d != 0 && c == 0)
			Assert::IsTrue(programm(0, 0, 0, 3, 0, 2) == "!4y", L"BranchIfElse34_4yTest1 mismatch");

			//(c == 0 && d == 0 && f == 0 && b != 0 && a == 0)
			Assert::IsTrue(programm(0, 2, 0, 0, 2, 0) == "!4y", L"BranchIfElse34_4yTest2 mismatch");
		}

		TEST_METHOD(BranchIfElse34_3xTest)
		{
			//(a == 0 && b == 0 && e == 0 && c != 0 && d == 0)
			Assert::IsTrue(programm(0, 0, 1, 0, 0, 2) == "!3x", L"BranchIfElse34_3xTest1 mismatch");
			
			//(c == 0 && d == 0 && f == 0 && a != 0 && b == 0)
			Assert::IsTrue(programm(1, 0, 0, 0, 2, 0) == "!3x", L"BranchIfElse34_3xTest2 mismatch");
		}

		TEST_METHOD(BranchIfElse34_0Test)
		{
			Assert::IsTrue(programm(0, 0, 0, 0, 2, 3) == "!0", L"BranchIfElse34_0Test2 mismatch");
		}


		TEST_METHOD(BranchIfElse4yTest)
		{
			//((e* d - b * f == 0) || (a * f - c * e == 0)) && (a == 0 && c == 0)
			Assert::IsTrue(programm(0, 2, 0, 4, 0, 0) == "4y", L"BranchIfElse4yTest mismatch");
		}

		TEST_METHOD(BranchIfElse3xEnterTest)
		{
			//((e* d - b * f == 0) || (a * f - c * e == 0)) && (b == 0 && d == 0)
			Assert::IsTrue(programm(3, 0, 1, 0, 0, 0) == "3x", L"BranchIfElse3yTest mismatch");
		}

		TEST_METHOD(BranchIfElse_1k_b0e0_Test)
		{
			//((e* d - b * f == 0) || (a * f - c * e == 0)) && (b == 0 && e == 0)
			Assert::IsTrue(programm(3, 0, 1, 4, 0, 0) == "1k_b0e0", L"BranchIfElseTest_1k_b0e0 mismatch");
		}

		TEST_METHOD(BranchIfElse_1k_d0f0Test)
		{
			//((e* d - b * f == 0) || (a * f - c * e == 0)) && (d == 0 && f == 0)
			Assert::IsTrue(programm(3, 2, 1, 0, 0, 0) == "1k_d0f0", L"BranchIfElseTest_1k_d0f0 mismatch");
		}

		TEST_METHOD(BranchIfElse_1k_a0e0Test)
		{
			//((e* d - b * f == 0) || (a * f - c * e == 0)) && (a == 0 && e == 0)
			Assert::IsTrue(programm(0, 2, 1, 4, 0, 0) == "1k_a0e0", L"BranchIfElseTest_1k_a0e0 mismatch");
		}

		TEST_METHOD(BranchIfElse_1k_c0f0Test)
		{
			//((e* d - b * f == 0) || (a * f - c * e == 0)) && (c == 0 && f == 0)
			Assert::IsTrue(programm(3, 2, 0, 4, 0, 0) == "1k_c0f0", L"BranchIfElseTest_1k_c0f0 mismatch");
		}

		TEST_METHOD(BranchIfElse_1k_ab_cdTest)
		{
			//((e* d - b * f == 0) || (a * f - c * e == 0)) && (a / b == c / d)
			Assert::IsTrue(programm(3, 3, 4, 4, 0, 0) == "1k_ab_cd", L"BranchIfElseTest_1k_ab_cd mismatch");
		}

		TEST_METHOD(InputTest)
		{
			Assert::IsTrue(programm(3, 3, 4, 4, 2, 1) != "", L"InputPositiveIntTest mismatch");
			Assert::IsTrue(programm(-3, -3, -4, -4, -2, -1) != "", L"InputNegativeIntTest mismatch");
			Assert::IsTrue(programm(3.3, 3.3, 4.4, 4.4, 2.2, 1.1) != "", L"InputPositivefloatTest mismatch");
			Assert::IsTrue(programm(3.3, 3.3, 4.4, 4.4, 2.2, 1.1) != "", L"InputNegativefloatTest mismatch");
			Assert::IsTrue(programm(0, 0, 0, 0, 0, 0) != "", L"InputZeroTest mismatch");
		}
	};
}

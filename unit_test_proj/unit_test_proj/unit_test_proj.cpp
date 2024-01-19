#include "pch.h"
#include "CppUnitTest.h"
#include "../../ConferenceProgram/processing.h"
#include "../../ConferenceProgram/conf_prog.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	conf_prog* build_subscription(int s_hours,int s_minut, int f_hours, int f_minut)
	{
		conf_prog* confs = new conf_prog;
		confs->start.min = s_minut;
		confs->start.hour = s_hours;
		confs->finish.min = f_minut;
		confs->finish.hour = f_hours;
		return confs;
	}

	      
	void delete_subscription(conf_prog* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}


	TEST_CLASS(UnitTest1)
	{
	public:
	public:
		TEST_METHOD(TestMethod2) //        
		{
			conf_prog* confes[2];
			confes[0] = build_subscription(12, 12, 12, 35);
			confes[1] = build_subscription(12, 36, 12, 40);
			Assert::AreEqual(23, getLongestProject(confes));
			delete_subscription(confes, 2);
		}
		TEST_METHOD(TestMethod3) //        
		{
			conf_prog* confes[4];
			confes[0] = build_subscription(12, 12, 12, 19);
			confes[1] = build_subscription(12, 12, 12, 18);
			confes[2] = build_subscription(12, 15, 12, 19);
			confes[3] = build_subscription(12, 19, 12, 24);
			Assert::AreEqual(7, getLongestProject(confes));
			delete_subscription(confes, 4);
		}
	};
}
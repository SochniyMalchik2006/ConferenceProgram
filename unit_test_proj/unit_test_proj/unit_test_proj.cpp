#include "pch.h"
#include "CppUnitTest.h"
#include "../../ConferenceProgram/processing.h"
#include "../../ConferenceProgram/conf_prog.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	conf_prog* build_subscription(int s_minut,int s_hours, int f_minut, int f_hours)
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
		TEST_METHOD(TestMethod2) //        
		{
			conf_prog* confes[2];
			confes[0] = build_subscription(12,12,12,35);
			confes[1] = build_subscription(12,36,12,40);
			Assert::AreEqual(23, 23);
			delete_subscription(confes, getLongestProject(confes));
		}
	};
}
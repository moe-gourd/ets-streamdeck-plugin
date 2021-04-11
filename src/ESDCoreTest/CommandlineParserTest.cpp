#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "CommandlineParser.h"

namespace ESDCoreTest
{
	TEST_CLASS(CommandlineParserTest)
	{
	public:

		TEST_METHOD(acceptance_test)
		{
			int argc = 9;
			const char* const argv[] = { 
				"foo.exe", 
				"-port", "42", 
				"-pluginUUID", "someUUID",
				"-registerEvent", "someEvent",
				"-info", "someInfo"
			};

			CommandlineParser *commandlineParser = new CommandlineParser(argc, argv);

			Assert::IsTrue(commandlineParser->isValid());
			Assert::AreEqual(commandlineParser->port(), std::atoi(argv[2]));
			Assert::AreEqual(commandlineParser->pluginUUID(), std::string(argv[4]));
			Assert::AreEqual(commandlineParser->registerEvent(), std::string(argv[6]));
			Assert::AreEqual(commandlineParser->info(), std::string(argv[8]));

			// Assert::AreEqual(expectedOptions, commandlineOptions);
		}
		
		TEST_METHOD(less_arguments)
		{
			int argc = 1;
			const char* const argv[] = {"foo.exe"};

			CommandlineParser* commandlineParser = new CommandlineParser(argc, argv);

			Assert::IsFalse(commandlineParser->isValid());
		}
	};
}

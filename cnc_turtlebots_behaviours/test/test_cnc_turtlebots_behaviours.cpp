using namespace std;

#include <SystemConfig.h>
#include <engine/AlicaEngine.h>
#include <gtest/gtest.h>

/**
 * Tests the plan parser with some nice plans
 */
TEST(TurtleBotsBehaviours, threadPool)
{
	// determine the path to the test config
	string path = supplementary::FileSystem::getSelfPath();
	int place = path.rfind("devel");
	path = path.substr(0, place);
	path = path + "src/alica/test";

	// bring up the SystemConfig with the corresponding path
	supplementary::SystemConfig* sc = supplementary::SystemConfig::getInstance();
	sc->setRootPath(path);
	sc->setConfigPath(path + "/etc");

	// setup the engine
	alica::AlicaEngine* ae = alica::AlicaEngine::getInstance();
	ae->init("WM09", "WM09", "WM09", false);

	//ae->start();
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

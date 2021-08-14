#include <qapplication.h>           // for QApplication
#include <nano/node/common.hpp>     // for node_singleton_memory_pool_purge_...
#include "gtest/gtest_pred_impl.h"  // for InitGoogleTest, RUN_ALL_TESTS

QApplication * test_application = nullptr;
namespace nano
{
void cleanup_dev_directories_on_exit ();
void force_nano_dev_network ();
}

int main (int argc, char ** argv)
{
	nano::force_nano_dev_network ();
	nano::node_singleton_memory_pool_purge_guard memory_pool_cleanup_guard;
	QApplication application (argc, argv);
	test_application = &application;
	testing::InitGoogleTest (&argc, argv);
	auto res = RUN_ALL_TESTS ();
	nano::cleanup_dev_directories_on_exit ();
	return res;
}

#include "framework.h"

using namespace std;

int main()
{
	srand(time(NULL));
	shared_ptr<World> world = make_shared<World>();

	while (true)
	{
		world->Update();

		if (world->End())
			break;
	}

	return 0;
}
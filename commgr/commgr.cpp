#include "commgr.h"

using namespace linz;
using namespace com;

ComMgr::ComMgr()
{

}

ComMgr::~ComMgr()
{

}

bool ComMgr::Register(Component *com)
{
	reg_com_vct_.push_back(com);
}

bool ComMgr::UnRegister(std::string &name)
{
	return components_map_.erase(name) != components_map_.end();
}

bool ComMgr::Run()
{
	while(true)
	{
		for (std::vector<Component*>::iterator it = reg_com_vct_.begin(); it != reg_com_vct_.end();)
		{
			if (Component::Success == it->Start())
			{
				it = reg_com_vct_.erase(it);
			} else {
				++it;
			}
		}

		for (auto it : components_map_)
		{
			it->DoOnce();
		}

		for (std::vector<Component*>::iterator it = unreg_com_vct_.begin(); it != unreg_com_vct_.end();)
		{
			if (Component::Success == it->Start())
			{
				it = reg_com_vct_.erase(it);
			} else {
				++it;
			}
		}
	}
}
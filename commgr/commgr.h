#include <stdint.h>

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>

namespace linz
{
	namespace com
	{
		class Component{
		public:
			Component();
			Component(std::string &name){ name_ = name; }
			virtual ~Component(){}

		public:
			enum EResultType{
				Success,
				Pending,
				Failure,
			};
			virtual uint8_t Start() = 0;
			virtual uint8_t DoOnce() = 0;
			virtual uint8_t Stop() = 0;

		public:
			inline const std::string & get_name(){ return name_; }

		private:
			std::string name_;
		}

		class ComMgr 
		{
		public:
			ComMgr();
			~ComMgr();

		public:
			bool Register(Component *com);
			bool UnRegister(std::string &name);
			bool Run();

		public:
			inline Component* get_com(std::string &name) { return components_map_[name]; }

		private:
			std:;vector<Component*> reg_com_vct_;
			std:;vector<Component*> unreg_com_vct_;
			std::map<std::string, Component*> components_map_;
		}	
	}
}

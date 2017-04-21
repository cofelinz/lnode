#include <stdint.h>

namespace linz
{
	namespace network
	{

		template<class T>
		class Net
		{
		public:
			Net();
			~Net();

		public:
			bool Listen(const char* ip, unsigned short port, backlog);
			uint32_t Send(char* data, uint32_t length);
			bool Disconnect();

			bool RegEvent(T event);
			void Run();
		}	
	}
}

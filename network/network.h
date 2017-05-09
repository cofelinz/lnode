#include <stdint.h>

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>

namespace linz
{
	namespace network
	{

		template<class T>
		class Net : public 
		{
		public:
			Net();
			~Net();

		public:
			virtual uint8_t Start();
			virtual uint8_t Run();
			virtual uint8_t Stop();

		public:
			bool Listen(const char* ip, uint16_t port, uint16_t backlog);
			uint32_t Send(char* data, uint32_t length);
			bool Disconnect();

			bool RegEvent(T *event)
			{
				event_ = event;
			}

			

		private:
			T *event_;

			struct event_base *base_;
		}	
	}
}

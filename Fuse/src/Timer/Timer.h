#pragma once
#include <time.h>

namespace Fuse
{
	class Timer
	{
		public:
			Timer() { m_BegTime = 0; }
			~Timer() {}

		public:
			void Start() { m_BegTime = clock(); }
			void Restart() { m_BegTime = clock(); }

		public:
			bool isOnTimeout(unsigned long seconds) { return seconds >= elapsedTime(); }
			unsigned long elapsedTime() { return ((unsigned long)clock() - m_BegTime) / CLOCKS_PER_SEC; }
	
		private:
			unsigned long m_BegTime;
	};
}
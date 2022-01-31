#pragma once

namespace Fuse
{
	class Layer
	{
		public:
			Layer() {}
			~Layer() {}

		public:
			virtual void OnCreate() {}
			virtual void OnUpdate() {}
			virtual void OnDestroy() {}
	};
}
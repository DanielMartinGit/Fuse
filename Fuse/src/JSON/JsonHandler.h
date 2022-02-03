#pragma once
#include "../../Vendor/Entt/entt.hpp"
#include "../../Vendor/JSON/json.hpp"

namespace Utils
{
	class JsonHandler
	{
		public:
			JsonHandler() {}
			~JsonHandler() {}

		public:
			static void SerialiseEntity(entt::entity& entity, std::ofstream& sceneFile)
			{
				nlohmann::json entityToSerialise =
				{
					{"Entity Name: ", Fuse::EntitySystem::GetComponent<Fuse::Entity>(entity).GetEntityName() },
					{"Entity ID: ", Fuse::EntitySystem::GetComponent<Fuse::Entity>(entity).GetEntityID() },
					{"Entity Tag: ", Fuse::EntitySystem::GetComponent<Fuse::Entity>(entity).GetEntityTag() }
				};

				sceneFile << std::setw(4) << entityToSerialise;
			}
	};
}
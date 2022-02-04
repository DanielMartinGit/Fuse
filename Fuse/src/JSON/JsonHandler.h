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
				nlohmann::json sceneData;
				sceneData["Entity Name"] = Fuse::EntitySystem::GetComponent<Fuse::Entity>(entity).GetEntityName();
				sceneData["Entity Tag"] = Fuse::EntitySystem::GetComponent<Fuse::Entity>(entity).GetEntityTag();
				sceneFile << std::setw(4) << sceneData;
			}
	};
}
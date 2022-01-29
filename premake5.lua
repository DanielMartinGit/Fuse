workspace("Fuse")
  architecture "x64"

configurations
{
  "Debug",
  "Release"
}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Fuse"
	location "Fuse"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		"%prj.name/Vendor/Entt/",
		"%prj.name/Vendor/GLAD/",
		"%prj.name/Vendor/GLAD/KHR/",
		"%prj.name/Vendor/GLFW/",
		"%prj.name/Vendor/GLM/",
		"%prj.name/Vendor/ImGui/",
		"%prj.name/Vendor/ImGuizmo/",
		"%prj.name/Vendor/JSON/",
		"%prj.name/Vendor/STB/"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Editor")
		}

	filter "configurations.Debug"
		symbols "On"

	filter "configurations.Release"
		optimize "On"

project "Editor"
	location "Editor"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	links
	{
		"Fuse"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations.Debug"
		symbols "On"

	filter "configurations.Release"
		optimize "On"

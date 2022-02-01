workspace("Fuse")
  architecture "x64"

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

configurations
{
  "Debug",
  "Release"
}

project "Fuse"
	location "Fuse"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.c",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**.hpp",
		"%{prj.name}/**.inl",
		"%{prj.name}/**.dll",
		"%{prj.name}/**.lib",
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
		"%prj.name/Vendor/STB/",

		"%prj.name/Vendor/",
		"%prj.name/src/"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines {}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Editor"),
			("{COPY} %{cfg.buildtarget.relpath} ../Fuse/Vendor/Libraries/Fuse")
		}

	filter "configurations.Debug"
		symbols "On"

	filter "configurations.Release"
		optimize "On"
	
	filter { "system:windows", "configurations:Debug"}
		buildoptions "/MDd"
	filter { "system:windows", "configurations:Release"}
		buildoptions "/MD"

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
	
	libdirs
	{
		"Fuse/Vendor/Libraries/GLFW",
		"Fuse/Vendor/Libraries/Fuse"
	}

	links
	{
		"Fuse",
		"glfw3"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.19041.0"

	filter "configurations.Debug"
		symbols "On"

	filter "configurations.Release"
		optimize "On"

	filter { "system:windows", "configurations:Debug"}
		buildoptions "/MDd"
	filter { "system:windows", "configurations:Release"}
		buildoptions "/MD"

project "FuseHub"
	location "Fuse Hub"
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
		"Fuse",
		"Editor"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.19041.0"

	filter "configurations.Debug"
		symbols "On"

	filter "configurations.Release"
		optimize "On"

	filter { "system:windows", "configurations:Debug"}
		buildoptions "/MDd"
	filter { "system:windows", "configurations:Release"}
		buildoptions "/MD"
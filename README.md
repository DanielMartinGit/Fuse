# FuseEngine
Fuse Engine is a 2D engine made with OpenGL 4.6 and ImGui <br/>

My goal with Fuse is to learn about OpenGL 4.6 and how graphics programming works. By the end of this project I would like to have the ability to make a simple 2D platformer within Fuse and export it into a Windows .exe file. <br/>

# Libraries
1) Entt <br/>
2) GLAD <br/>
3) GLFW <br/>
4) GLM <br/>
5) ImGui <br/>
6) ImGuizmo <br/>
7) Nlohmann Json <br/>
8) PFD (Portable-File-Dialogs) <br/>
9) STB <br/>

# Features
Fuse (Framework): <br/>
1) 2D Renderer - Used for drawing and rendering textured 2D quads to the screen, these are renderer to a FBO and then to the Scene Viewport within the Editor <br/>
2) ECS - A wrapper written around the widely used Entt library. Used for defining Entities within a Game World and allows for a Component Based system within a scene <br/>
3) Shaders/Shader Program - Used for creating/using and managing custom OpenGL shaders within the Editor <br/>

Editor: <br/>
1) Asset Browser - Used for managing a loaded projects structure and files/assets <br/>
2) Console - Allows custom messages with different types (ACTION, WARNING, ERROR, MESSAGE) to be written, notifying the developer of any important warnings or errors within their project <br/>
3) Game Viewport - Will use the Camera Entity within a scene as the Game Camera (When Exported), this panel will display what the camera sees <br/>
4) Inspector - Used to modify an Entities components and their data such as name or tag <br/>
5) Profiler - This panel displays the current FPS/Frametime, DeltaTime, how many Entities are in the current loaded scene, how many draw calls and vertices/indices <br/>
6) Resources - This panel tells the developer how many assets are currently loaded such as Textures and Shaders <br/>
7) Scene Hierarchy - Used to add Entities to a scene and manage a scenes hierarchy <br/>
8) Scene Viewport - This panel has a FBO rendered to a Texture, this FBO consists of the current scene but rendered to a Texture <br/>

# Setup 
1) Clone Repository <br/>
2) Run GenerateProject.bat (This will run the premake5.lua file) <br/>
3) Build project within Visual Studio <br/>
4) Navigate to bin/Debug-platform-architecture/Editor and run the Editor.exe <br/>

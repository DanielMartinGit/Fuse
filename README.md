# FuseEngine
Fuse Engine is a 2D engine made with OpenGL 4.6 and ImGui <br/>

My goal with Fuse is to learn about OpenGL 4.6 and how graphics programming works. By the end of this project I would like to have the ability to make a simple 2D platformer within Fuse and export it into a Windows .exe file. <br/>

# Libraries
Entt <br/>
GLAD <br/>
GLFW <br/>
GLM <br/>
ImGui <br/>
ImGuizmo <br/>
Nlohmann Json <br/>
PFD (Portable-File-Dialogs) <br/>
STB <br/>

# Features
Fuse (Framework): <br/>
2D Renderer - Used for drawing and rendering textured 2D quads to the screen, these are renderer to a FBO and then to the Scene Viewport within the Editor <br/>
ECS - A wrapper written around the widely used Entt library. Used for defining Entities within a Game World and allows for a Component Based system within a scene <br/>
Shaders/Shader Program - Used for creating/using and managing custom OpenGL shaders within the Editor <br/>

Editor: <br/>
Asset Browser - Used for managing a loaded projects structure and files/assets <br/>
Console - Allows custom messages with different types (ACTION, WARNING, ERROR, MESSAGE) to be written, notifying the developer of any important warnings or errors within their project <br/>
Game Viewport - Will use the Camera Entity within a scene as the Game Camera (When Exported), this panel will display what the camera sees <br/>
Inspector - Used to modify an Entities components and their data such as name or tag <br/>
Profiler - This panel displays the current FPS/Frametime, DeltaTime, how many Entities are in the current loaded scene, how many draw calls and vertices/indices <br/>
Resources - This panel tells the developer how many assets are currently loaded such as Textures and Shaders <br/>
Scene Hierarchy - Used to add Entities to a scene and manage a scenes hierarchy <br/>
Scene Viewport - This panel has a FBO rendered to a Texture, this FBO consists of the current scene but rendered to a Texture <br/>

# Setup 
Clone Repository <br/>
Run GenerateProject.bat (This will run the premake5.lua file) <br/>
Build project within Visual Studio <br/>
Navigate to bin/Debug-platform-architecture/Editor and run the Editor.exe <br/>

# Links
Trello - https://trello.com/b/YQkfvOEg/fuse <br/>

# Screenshots
![image](https://user-images.githubusercontent.com/19360613/154978902-00b3bac9-337c-42a4-8c4d-bd36be696ac6.png)
![image](https://user-images.githubusercontent.com/19360613/154978983-8dc44004-ed79-4099-bfe4-18182a86b6e2.png)
![image](https://user-images.githubusercontent.com/19360613/154979064-a80356bf-5057-4f45-bf6e-3bef99844c59.png)



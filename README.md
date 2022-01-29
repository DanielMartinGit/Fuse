# FuseEngine
Fuse Engine is a 2D engine made with OpenGL 4.6 and ImGui

My goal with Fuse is to learn about OpenGL 4.6 and how graphics programming works. By the end of this project I would like to have the ability to make a simple 2D platformer within Fuse and export it into a Windows .exe file.

Current Implemented Features: 

Resource Management: The Resource Manager contains static functions that only have return types, this is so they can be used without an instance and can be put into relative Data Types fairly easily, an example of this is the Fuse::ResourceManager::LoadTexture() which takes in a path to the texture being loaded, and returns an uint32_t which can be stored for use by the Renderer later down the line.  

2D Renderer: The 2D renderer is used for drawing sprites into a scene, currently a scene Binds the renderer, renders all the sprites and then unbinds the renderer, this also calls the relative functions for the FBO which is then converted to a Texture and rendered to the Scene Viewport Panel.  

Editor Camera Controller: The Camera Controller for the Scene Viewport uses the Input class and allows the user to navigate around a 2D scene currently using W,A,S,D with support for mouse controls to make this more intuative. 
Input: The Input class is used for detecting when a certain key is pressed and will allow the user to create actions based on Key Presses.  

UI Panels:  

Scene Viewport: This is a viewport for viewing the current active scene and all Entities inside this scene  

Console: The console is used for logging various strings of text such as errors, warnings, actions and messages  

Resources: The Resources Panel is used for showing the user how many Textures/Sprites, Shaders, Sounds and any other Resource file are currently loaded, I do plan to have another button for viewing all Sprites/Textures in a separate panel.  

Profiler: The Profiler Panel is used mostly for Debugging purposes, with information such as the OpenGL version, GPU information such as the specific card and manufacturer, FPS and Frametime and how many Entities, Draw calls, indices and vertices are in the currently renderer scene.  
Asset Browser: The Asset Browser Panel is used for viewing and navigating the current loaded projects directory, this can be used to grab sprites for use in game, adding sounds and textures to a project or creating new folders inside a project for organisation.  

![image](https://user-images.githubusercontent.com/48921196/148675768-54376f28-f8fc-4551-9a14-7b28899ed1d1.png)
![image](https://user-images.githubusercontent.com/48921196/148676039-79872c4c-eb7f-4e7e-ac14-c767bb946cd5.png)

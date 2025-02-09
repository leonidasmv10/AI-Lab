#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/random.hpp>

#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <fstream>
#include <sstream>
#include <spdlog/spdlog.h>

// Imgui
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "API.h"

// Math
#include "Vector3.h"

// Types
#include "InputType.h"
#include "MaterialType.h"
#include "ProjectionType.h"
#include "RenderType.h"
#include "TextureType.h"
#include "GuiType.h"

// Data
#include "vertex.h"
#include "frustrum.h"

// Shaders
#include "RenderProgram.h"
#include "GLSLShader.h"

// Textures
#include "Texture.h"
#include "GLTexture.h"

// Materials
#include "Material.h"
#include "GLSLMaterial.h"

// Core
#include "Entity.h"
#include "Mesh3D.h"
#include "Object.h"
#include "Object3D.h"

// Inputs
#include "InputManager.h"
#include "GLFWInputManager.h"

// Camera
#include "Camera.h"
#include "CameraKeyboard.h"

// Renders
#include "Render.h"
#include "GL1Render.h"
#include "GL4Render.h"

// Times
#include "TimeManager.h"
#include "GLFWTimeManager.h"

// Gui
#include "Gui.h"
#include "GLFWImGui.h"

// Statics
#include "FactoryEngine.h"
#include "System.h"

// DataTypes
#include "GLFWwindowDataType.h"

// Engine
#include "Def.h"
#include "EObject.h"
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "CoreBehaviour.h"

// Templates
#include "Box3d.h"



#include "../Windows/Window.h"
#include "../Shape/Box/TestBox/TestBox.h"
#include "../Camera/Camera.h"
#include "../Graphics/Material/Material.h"
#include "../Graphics/Node/Node.h"
#include "../Scene/Scene.h"
#include "../EventSystem/Input.h"


const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;

using namespace Graphics;
using namespace UI;
using namespace EventSystem;

void KeyBoardEvent(const WindowPtr window, Input& input);
void MouseEvent(const WindowPtr window, Input& input, float deltaTime);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void ProcessMouseButtons(Input& input);
void ProcessMouseMotion(Vector2 mousePosition);

void UpdateCamera(Camera* cam);

Vector3 cameraPos(Vector3(2, 2, 2));
Vector3 cameraTarget(Vector3(0, 0, 0));
Vector3 cameraUp(Vector3(0, 1, 0));

bool isCameraDirty;
bool isMouseTracking;


float yaw = -90.0f;
float pitch = 0.0f;
float firstClickPosX = SCR_WIDTH / 2.0f;
float firstClickPosY = SCR_HEIGHT / 2.0f;

float radian=3.14/180.0f;
int main(int argc, char* argv[])
{

    UI::WindowPtr  window(new UI::Window(SCR_WIDTH, SCR_HEIGHT, "UNAGI"));

    //glfwSetScrollCallback(window->windowPtr,)

  
    Three_D::Camera camera(cameraPos,cameraTarget,cameraUp, 5000.0f, 0.01f, 60);


    ShaderLoader shader(
        "E:/Shagufta/Workspace/Opengl/Unagi_2.0/Unagi_2.0/ShaderFiles/VertexShader.vs",
        "E:/Shagufta/Workspace/Opengl/Unagi_2.0/Unagi_2.0/ShaderFiles/FragmentShader.fs"
    );

    Graphics::Material mat(&shader);

    Node node(&mat, GeometryType::BOX);
   // node.SetScale(Vector3(1, 2, 2));
    EnvironmentScene::Scene scene(&camera);
    scene.AddToScene(&node);


    EventSystem::Input input(window, &scene);
   // TestBox box(camera);
    
  /*  box.SetPosition(Vector3(0, 0.1f, 50));
    box.SetScale(Vector3(0.25f, 0.25f, 0.25f));
    box.SetRotation(Vector3(0, 45, 0));*/

    float x = 0;

    while (!window->IsWindowClosed())
    {
        window->ClearBG();

        KeyBoardEvent(window, input);
        MouseEvent(window, input, 0.0f);
        UpdateCamera(&camera);

     //   node.SetPosition(Vector3(x, 0, 0));
      //  x += 0.01f;
      //  box.Draw();
        //node.Draw(&camera);
        scene.Render();
        window->SwapBuffer();
    }
  //  box.DeleteBufferData();
    return 0;
    
}

void UpdateCamera(Camera*  cam)
{
   /* if(!isCameraDirty)
    {
        return;
    }*/
   // std::cout << cameraPos.x << " " << cameraPos.y << " " << cameraPos.z << std::endl;
    cam->SetPosition(cameraPos);
    cam->SetTarget(cameraTarget);
    cam->SetUp(cameraUp);

}

void KeyBoardEvent(const WindowPtr window, Input& input)
{
    if(input.IsKeyPressed(GLFW_KEY_ESCAPE))
    {
        window->Close();
    }

    if(input.IsKeyPressed(GLFW_KEY_SPACE))
    {
    //    std::cout << "space pressed " << std::endl;
        isCameraDirty = true;
        cameraPos = Vector3(2, 0, 0);
        cameraTarget = Vector3(0, 0, 0);
        cameraUp = Vector3(0, 1, 0);
    }


}


void MouseEvent(const WindowPtr window, Input& input, float deltaTime)
{   
    ProcessMouseMotion(Input::mousePosition);

}

void spherical2Cartesian(float r, float alpha, float beat)
{
    cameraPos.x = cameraTarget.x + r * sin(alpha*radian)*cos(beat*radian);
    cameraPos.y = cameraTarget.y+r*sin(beat*radian);
    cameraPos.z= cameraTarget.x + r * cos(alpha*radian)*cos(beat*radian);
}

void ProcessMouseMotion(Vector2 mousePosition)
{
   /* if (!isMouseTracking)
    {
        return;;
    }*/

    int deltaX, deltaY;
    float alphaAux, betaAux;
    float rAux = (cameraTarget - cameraPos).Magnitude();

    deltaX = static_cast<int>(-mousePosition.x + firstClickPosX);
    deltaY = static_cast<int>(-mousePosition.y + firstClickPosY);

    alphaAux = yaw + deltaX;
    betaAux = pitch + deltaY;

    if(betaAux>85.0f)
    {
        betaAux = 85.0f;
    }
    else if (betaAux<-85.0)
    {
        betaAux = -85.0f;
    }
    //std::cout << mousePosition.x << " " << mousePosition.y <<  std::endl;
    //std::cout << "alpha " << alphaAux << " brata " << betaAux << std::endl;
    spherical2Cartesian(rAux, alphaAux, betaAux);
}

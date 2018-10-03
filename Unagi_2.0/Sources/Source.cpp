
#include "../Windows/Window.h"
#include "../Shape/Box/TestBox/TestBox.h"
#include "../Camera/Camera.h"



const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;

int main(int argc, char* argv[])
{

    UI::WindowPtr  window(new UI::Window(SCR_WIDTH, SCR_HEIGHT, "UNAGI"));

  /*  Camera(
        const Vector3& a_position,
        const Vector3& a_target,
        const Vector3& a_up,
        float a_far,
        float a_near,
        float a_FOV
    );*/

  
    Three_D::Camera camera(Vector3(2, 2, 2), Vector3(0, 0, 0),Vector3(0,1,0), 5000.0f, 0.01f, 60);

    Shape::TestBox box(camera);
    //box.SetPosition(Vector3(0, 0.1f, 50));
    //box.SetScale(Vector3(0.25f, 0.25f, 0.25f));
    //box.SetRotation(Vector3(0, 45, 0));

    while (!window->IsWindowClosed())
    {
        window->ClearBG();

        box.Draw();

        window->SwapBuffer();
    }
    box.DeleteBufferData();
    return 0;
    
}

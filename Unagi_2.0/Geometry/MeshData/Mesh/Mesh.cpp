#include "Mesh.h"
namespace Geometry
{
    Mesh::Mesh():
    isDirty(false)
    {
        numOfVertex = 0;
        rendererMeshData.Clear();
    }
   
}
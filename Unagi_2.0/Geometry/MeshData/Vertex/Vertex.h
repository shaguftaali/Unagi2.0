#pragma once
#include "../HalfEdgeElement/HalfEdgeElement.h"
#include "../../../Maths/Vector/Vector3.h"
#include "../HalfEdge/HalfEdge.h"

using namespace Maths;
namespace Geometry
{
    class Vertex : public HalfEdgeElement
    {
    protected:
        HalfEdgeIter _halfEdge;

    public:
        HalfEdgeIter&  halfEdge() { return _halfEdge; }

        HalfEdgeCIter halfEdge() const { return _halfEdge; }

        int id;
        Vector3 position;
        Vector3 color;
        Vector3 normal;


    };
}

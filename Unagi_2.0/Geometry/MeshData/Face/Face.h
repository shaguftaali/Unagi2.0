#pragma once
#include "../HalfEdgeElement/HalfEdgeElement.h"
#include "../../../Maths/Vector/Vector3.h"

using namespace Maths;
namespace Geometry
{
    class Face: public HalfEdgeElement
    {
    protected:
        HalfEdgeIter _halfEdge;

    public:
        HalfEdgeIter & halfEdge() { return _halfEdge; }

        HalfEdgeCIter halfEdge() const { return _halfEdge; }


    public:
        int id;
        bool isBoundary();
        //Maths::Vector3 normal();

        //Vector3 centroid() const;
    };
}

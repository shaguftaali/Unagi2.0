#pragma once
#include "../HalfEdgeElement/HalfEdgeElement.h"

namespace Geometry
{

    class Edge:public HalfEdgeElement
    {
    public: 
        HalfEdgeIter & halfEdge() { return _halfEdge; }
        HalfEdgeCIter halfEdge() const { return _halfEdge; }

        int id;
    protected:
        HalfEdgeIter _halfEdge;

        
    };
}

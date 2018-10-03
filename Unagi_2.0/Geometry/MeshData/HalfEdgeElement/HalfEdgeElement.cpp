#include "HalfEdgeElement.h"
#include "../HalfEdge/HalfEdge.h"

namespace Geometry
{
    HalfEdge * HalfEdgeElement::getHalfEdge()
    {
        return dynamic_cast<HalfEdge*>(this);
    }
    Vertex * HalfEdgeElement::getVertex()
    {
        return dynamic_cast<Vertex*>(this);
    }
    Edge * HalfEdgeElement::getEdge()
    {
        return dynamic_cast<Edge*>(this);
    }
    Face * HalfEdgeElement::getFace()
    {
        return dynamic_cast<Face*>(this);
    }

    HalfEdgeElement::~HalfEdgeElement()
    {
    }
}
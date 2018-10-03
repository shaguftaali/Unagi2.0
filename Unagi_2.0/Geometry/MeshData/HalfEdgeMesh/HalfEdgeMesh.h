#pragma once
#include <stddef.h>
#include <vector>
#include "../../../Maths/Vector/Vector3.h"
#include <list>
#include "../Vertex/Vertex.h"
#include "../Face/Face.h"
#include "../Vertex/Vertex.h"
#include "../HalfEdge/HalfEdge.h"



using namespace std;
using namespace Maths;
namespace Geometry
{
    class HalfEdgeMesh
    {
    public:
        HalfEdgeMesh();

        HalfEdgeMesh(const HalfEdgeMesh& mesh);

        void build(
            const vector<vector<int>>& polygons,
            const vector<Vector3>& vertexPosition
        );

        VertexIter      newVertex() { return vertices.insert(vertices.end(), Vertex()); }

        HalfEdgeIter    newHalfEdge() { return halfEdges.insert(halfEdges.end(), HalfEdge()); }

        EdgeIter        newEdge() { return edges.insert(edges.end(), Edge()); }

        HalfEdgeIter        halfEdgesBegin() { return halfEdges.begin(); }
        HalfEdgeIter        halfEdgesEnd() { return  halfEdges.end(); }
        VertexIter          verticesBegin() { return vertices.begin(); }
        VertexIter          verticesEnd() { return  vertices.end(); }
        EdgeIter            edgesBegin() { return  edges.begin(); }
        EdgeIter            edgesEnd() { return  edges.end(); }
        FaceIter            facesBegin() { return faces.begin(); }
        FaceIter            facesEnd() { return faces.end(); }

    protected:
        list<HalfEdge>      halfEdges;
        list<Vertex>        vertices;
        list<Edge>          edges;
        list<Face>          faces;
    };
}
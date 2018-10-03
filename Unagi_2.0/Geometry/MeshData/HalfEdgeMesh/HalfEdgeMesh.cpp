#include "HalfEdgeMesh.h"
#include <map>
#include "../../TypeDef.h"
#include <iostream>
#include <set>

Geometry::HalfEdgeMesh::HalfEdgeMesh()
{
}

Geometry::HalfEdgeMesh::HalfEdgeMesh(const HalfEdgeMesh & mesh)
{
}

void Geometry::HalfEdgeMesh::build(const vector<vector<int>>& polygons, const vector<Vector3>& vertexPosition)
{
    typedef vector<int>                     IndexList;
    typedef IndexList::const_iterator       IndexListCIter;
    typedef vector<IndexList>               FaceList;
    typedef FaceList::const_iterator        FaceListCIter;

    typedef pair<int, int>                   IndexPair;

    halfEdges.clear();
    vertices.clear();
    edges.clear();
    faces.clear();

    map<int, VertexIter>     indexToVertex;

    map<VertexIter, Size>     vertexDegree;


   

    for (FaceListCIter f=polygons.begin();f!=polygons.end();f++)
    {
        if(f->size()<3)
        {
            std::cerr << "face can not be form with less than 3 vertices" << std::endl;
            exit(1);
        }

        set<int> faceIndices;

        for (IndexListCIter i=f->begin();i!=f->end();i++)
        {
            faceIndices.insert(*i);
            if(indexToVertex.find(*i)==indexToVertex.end())
            {
                VertexIter v = newVertex();
                v->halfEdge() = halfEdgesEnd();
                indexToVertex[*i] = v;
                vertexDegree[v] = 1;
            }
            else
            {
                vertexDegree[indexToVertex[*i]] ++;
            }
        }

        Size degree = f->size();

        if(faceIndices.size()<degree)
        {
            cerr << "Error converting polygons to halfedge mesh: one of the input polygons does not have distinct vertices!" << endl;
            cerr << "(vertex indices:";
        }
    }

    Size nVertices = indexToVertex.size();

    Size nFaces = polygons.size();
    faces.resize(nFaces);

    map<IndexPair, HalfEdgeIter> pairToHalfEdge;

    FaceListCIter faceListCIter;
    FaceIter faceIter;

    for (faceListCIter=polygons.begin(),faceIter=faces.begin();faceListCIter!=polygons.end();faceListCIter++,faceIter++)
    {
        vector<HalfEdgeIter> faceHalfEdge;
        Size degree = faceListCIter->size();

        for (int i=0;i<degree;i++)
        {
            int a = (*faceListCIter)[i];
            int b = (*faceListCIter)[i + 1] % degree;
            IndexPair ab(a, b);
            HalfEdgeIter hab;

            if(pairToHalfEdge.find(ab)!=pairToHalfEdge.end())
            {
                //TODO
                exit(1);
            }
            else
            {
                hab = newHalfEdge();
                pairToHalfEdge[ab] = hab;

                hab->face() = faceIter;
                hab->face()->halfEdge() = hab;

                hab->vertex() = indexToVertex[a];
                hab->vertex()->halfEdge() = hab;

                faceHalfEdge.push_back(hab);
            }

            IndexPair ba(b, a);
            map<IndexPair, HalfEdgeIter>::iterator iba = pairToHalfEdge.find(ba);
            if(iba!=pairToHalfEdge.end())
            {
                HalfEdgeIter hba = iba->second;

                hab->twin() = hba;
                hba->twin() = hab;


                EdgeIter e = newEdge();
                hab->edge() = e;
                hba->edge() = e;
                e->halfEdge() = hab;
            }
            else
            {
                hab->twin() = halfEdges.end();
            }
        }

        for (int i=0;i<degree;i++)
        {
            int j = (i + 1) % degree;
            faceHalfEdge[i]->next() = faceHalfEdge[j];
        }
    }

    int faceIndex = 0;
    ////TODO

    for (VertexIter v=verticesBegin();v!=verticesEnd();v++)
    {
        if(v->halfEdge()==halfEdges.end())
        {
            cerr << "Error converting polygons to halfedge mesh: some vertices are not referenced by any polygon." << endl;
            exit(1);
        }

        Size count = 0;
        HalfEdgeIter h = v->halfEdge();

        do
        {
            if(!h->face()->isBoundary())
            {
                count++;
            }
            h->twin()->next();
        }
        while (h!=v->halfEdge());

        /*if (count != vertexDegree[v])
        {
            cerr << "Error converting polygons to halfedge mesh: at least one of the vertices is nonmanifold." << endl;
            exit(1);
        }*/
    }

    if (vertexPosition.size() != vertices.size())
    {
        //TODO
        exit(1);
    }

    int i = 0;
    map<int, VertexIter>::const_iterator vertItr;
    for (vertItr=indexToVertex.begin();vertItr!=indexToVertex.end();vertItr++)
    {
        VertexIter v = vertItr->second;

        v->position = vertexPosition[i];
        v->id = vertItr->first;
        i++;
    }

    unsigned int edgeId = 0;
    for (auto e = edgesBegin();e != edgesEnd();e++)
    {
        e->id = edgeId;
        edgeId++;
    }
}

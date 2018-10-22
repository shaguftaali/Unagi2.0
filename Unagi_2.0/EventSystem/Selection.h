#pragma once
#include "../Graphics/Node/Node.h"

using namespace Graphics;

namespace EventSystem
{
    class Selection
    {
    public:
        enum class Axis{ X, Y, Z, Center, None};

        Node* object;

        HalfEdgeElement* element;

        Vector3 coordinates;

        Axis axis;

        Selection()
        {
            clear();
        }

        void clear()
        {
            object = nullptr;
            element = nullptr;
            coordinates = Vector3(0, 0, 0);
            axis = Axis::None;
        }

        bool operator==(const Selection &s) const
        {
            return (
                object == s.object && element == s.element && axis == s.axis &&
                coordinates.x == s.coordinates.x &&
                coordinates.y == s.coordinates.y &&
                coordinates.z == s.coordinates.z
                );
        }

        bool operator!=(const Selection &s) const
        {
            return !(*this == s);
        }
    };
}

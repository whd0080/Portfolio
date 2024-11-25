#include "framework.h"
#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

bool Collider::IsCollision(shared_ptr<Collider> collider)
{
    if (auto circle = dynamic_pointer_cast<CircleCollider>(collider))
    {
        if (auto thisCircle = dynamic_cast<CircleCollider*>(this))
        {
            return thisCircle->IsCollision(circle);
        }
    }

    if (auto rect = dynamic_pointer_cast<RectCollider>(collider))
    {
        if (auto thisCircle = dynamic_cast<CircleCollider*>(this))
        {
            return thisCircle->IsCollision(rect);
        }
    }

    return false;
}
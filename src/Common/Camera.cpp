#include <string>
#include "Camera.h"

Camera::Camera() : x(0.0f), y(0.0f), width(2.0f), height(2.0f), reverseY(false)
{
    this->halfWidth = width / 2.0f;
    this->halfHeight = height / 2.0f;
}

Camera::Camera(float x, float y, float width, float height) : x(x), y(y), width(width), height(height), reverseY(false)
{
    this->halfWidth = width / 2.0f;
    this->halfHeight = height / 2.0f;
}

void Camera::MoveTo(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Camera::MoveBy(float dx, float dy)
{
    this->x += dx;
    this->y += dy;
}

void Camera::SetDimensions(float width, float height)
{
    this->width = width;
    this->halfWidth = width / 2.0f;
    this->height = height;
    this->halfHeight = height / 2.0f;
}

float Camera::getX()
{
    return this->x;
}

float Camera::getY()
{
    return this->y;
}

float Camera::getWidth()
{
    return this->width;
}

float Camera::getHeight()
{
    return this->height;
}

float Camera::GetLeft()
{
    return this->x - this->halfWidth;
}

float Camera::GetRight()
{
    return this->x + this->halfWidth;
}

float Camera::GetTop()
{
    if (this->reverseY)
    {
        return this->y - this->halfHeight;
    }
    else
    {
        return this->y + this->halfHeight;
    }
}

float Camera::GetBottom()
{
    if (this->reverseY)
    {
        return this->y + this->halfHeight;
    }
    else
    {
        return this->y - this->halfHeight;
    }
}


std::string Camera::ToString()
{
    return "X: " + std::to_string(this->x) + " Y: " + std::to_string(this->y) + " Width: " + std::to_string(this->width) + " Height: " + std::to_string(this->height);
}

std::string Camera::ToStringLRTB()
{
    return "Left: " + std::to_string(this->GetLeft()) + " Right: " + std::to_string(this->GetRight()) + " Top: " + std::to_string(this->GetTop()) + " Bottom: " + std::to_string(this->GetBottom());
}

void Camera::SetReverseY(bool reverseY)
{
    this->reverseY = reverseY;
}

Camera::~Camera()
{
    
}
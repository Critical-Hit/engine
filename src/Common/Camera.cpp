#include "Camera.h"

Camera::Camera()
{

}

Camera::Camera(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
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

Camera::~Camera()
{

}
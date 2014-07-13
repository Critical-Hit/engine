#pragma once
class Vec2
{
public:
    int X;
    int Y;
    Vec2()
    {
        this->X = 0;
        this->Y = 0;
    }

    void Set(int x, int y)
    {
        this->X = x;
        this->Y = y;
    }
};
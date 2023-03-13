//
// Created by sosis on 12.03.2023.
//

#ifndef TASK_2_VECTOR2_H
#define TASK_2_VECTOR2_H

namespace utils
{

class Vector2
{
private:
    int x;
    int y;

public:
    Vector2();
    Vector2(const int x, const int y);

    ~Vector2();

public:
    const int getX() const;
    const int getY() const;

    void setX(const int x);
    void setY(const int y);
};

} // utils

#endif //TASK_2_VECTOR2_H

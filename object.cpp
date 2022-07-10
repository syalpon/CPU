#include "object.h"

static U4 u4g_object_num = 0;

Object::Object()
{
    Object(nullptr);
}

Object::Object(S1 *name)
{
    object_number = u4g_object_num++;
    object_name = name;
}
#ifndef _ROS_template_v1_Temp1_h
#define _ROS_template_v1_Temp1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace template_v1
{

  class Temp1 : public ros::Msg
  {
    public:
      typedef float _volt1_type;
      _volt1_type volt1;
      typedef float _volt2_type;
      _volt2_type volt2;

    Temp1():
      volt1(0),
      volt2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_volt1;
      u_volt1.real = this->volt1;
      *(outbuffer + offset + 0) = (u_volt1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_volt1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_volt1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_volt1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->volt1);
      union {
        float real;
        uint32_t base;
      } u_volt2;
      u_volt2.real = this->volt2;
      *(outbuffer + offset + 0) = (u_volt2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_volt2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_volt2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_volt2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->volt2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_volt1;
      u_volt1.base = 0;
      u_volt1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_volt1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_volt1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_volt1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->volt1 = u_volt1.real;
      offset += sizeof(this->volt1);
      union {
        float real;
        uint32_t base;
      } u_volt2;
      u_volt2.base = 0;
      u_volt2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_volt2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_volt2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_volt2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->volt2 = u_volt2.real;
      offset += sizeof(this->volt2);
     return offset;
    }

    const char * getType(){ return "template_v1/Temp1"; };
    const char * getMD5(){ return "0886d2dc572a02a2914565c368d2c3d3"; };

  };

}
#endif
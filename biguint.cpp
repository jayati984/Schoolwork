#include "biguint.h"
#include <string>
#include <cstdlib>
#include <cassert>


biguint::biguint(){
  for(int i = 0; i < CAPACITY; i++){
  data_[i] = 0;
  }
}

biguint::biguint(const std::string &str){
   for(int i = 19; i >= 0; i--){  
      data_[i] = 0;
    }
  std::size_t i=0;
  while(i<str.size()){
    data_[i] = (str[str.size() - i - 1]) - '0';
    i++;
  }
}

unsigned short biguint::operator [](std::size_t pos) const{
  assert(pos < CAPACITY);
  short ret = data_[pos];
  return ret;
}

int biguint::compare(const biguint & b) const
{
    for (int i = CAPACITY - 1; i >= 0 ; i--)
    {
        if (data_[i] > b[i])
        {
            return 1;
        }
        else if (data_[i] < b[i])
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

bool operator < (const biguint & lhs, const biguint & rhs)
{
     if(lhs.compare(rhs)==-1)
     {
        return true;
     }
     else
     {
        return false;
     }
}
bool operator <= (const biguint & lhs, const biguint & rhs)
{
     if(lhs.compare(rhs)== -1 || lhs.compare(rhs)==0)
     {
        return true;
     }
     else
     {
        return false;
     }
}
bool operator != (const biguint & lhs, const biguint & rhs)
{
    if(lhs.compare(rhs)!= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator == (const biguint & lhs, const biguint & rhs)
{
     if(lhs.compare(rhs)==0)
     {
        return true;
     }
     else
     {
        return false;
     }
}
bool operator >= (const biguint & lhs, const biguint & rhs)
{
    if(lhs.compare(rhs)== 1 || lhs.compare(rhs)==0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool operator > (const biguint & lhs, const biguint & rhs)
{
     if(lhs.compare(rhs)==1)
     {
        return true;
     }
     else
     {
        return false;
     }
}

void biguint::operator += (const biguint & b)
{
    for(int i = CAPACITY -1 ; i >= 0; i--)
    {
        data_[i] += b[i];
    }
}

biguint operator + (const biguint & lhs, const biguint & rhs)
{
    biguint b = lhs;
    b += rhs;
    return b;
}

std::ostream& operator << (std::ostream& out, const biguint& b)
{
    for(int i = biguint::CAPACITY - 1; i >= 0; i--)
    {
        out << b[i] << " ";
    }
    return out;
}
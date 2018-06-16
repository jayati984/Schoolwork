#ifndef BIGUINT_H
#define BIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>


class biguint
{
public:
    // CONSTANTS & TYPES

    static const std::size_t CAPACITY = 20;

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint();

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(const std::string &);

    // CONSTANT MEMBER FUNCTIONS

    // pre: pos < CAPACITY
    // post: returns the digit at position pos
    //          0 is the least significant (units) position

    unsigned short operator [](std::size_t pos) const;

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(const biguint & b) const;



    // MODIFICATION MEMBER FUNCTIONS


    // pre: none
    // post: b is added to this biguint; ignore last carry bit if any
    void operator += (const biguint & b);
    void operator -= (const biguint & b);

private:

    unsigned short data_[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

// nonmember functions

biguint operator + (const biguint &, const biguint &);
biguint operator - (const biguint &, const biguint &);

bool operator < (const biguint &, const biguint &);
bool operator <= (const biguint &, const biguint &);
bool operator != (const biguint &, const biguint &);
bool operator == (const biguint &, const biguint &);
bool operator >= (const biguint &, const biguint &);
bool operator > (const biguint &, const biguint &);

std::ostream& operator << (std::ostream& out, const biguint& b);

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
    for(int i = 0 ; i < CAPACITY; i++)
    {
         int x = data_[i] + b[i];
         if (x >= 10)
         {
             data_[i] = x % 10;
             data_[i+1] = data_[i+1] + x/10;
         }
         else 
         {
             data_[i] = x;
        }
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


#endif // BIGUINT_H
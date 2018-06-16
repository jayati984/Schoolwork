#include "bag.h"

Bag::Bag(){
    size_ = 0;
}

Bag::Bag(int arr[], size_type size){
    for(size_type i = 0; i<size; i++){
        data_[i] = arr[i];
    }
    size_ = size;
}

Bag::size_type Bag::size() const{
 return size_;   
}

Bag::size_type Bag::count(int target) const{//Need Bag::size_type because the typedef is only for the scope of Bag, and the return type of the function is outside that scope.  So this use of :: is more like std::size_t, not like Bag::count(...
    size_type count = 0;
    for(size_type i = 0; i<size_; i++){
     if(data_[i] == target)
         count++;
    }
    return count;
    
}

void Bag::insert(int target){
    if(size() < CAPACITY)
    {
        size_++;
        data_[size_-1] = target;
    }
}
#include <iostream>
#include <cstdint>

template<uint32_t D>
struct cube_opposite_faces{
    uint8_t f1[D];
    uint8_t f2[D];
};

static_assert(sizeof(cube_opposite_faces<3> == 6));
static_assert(sizeof(cube_opposite_faces<4> == 8));

template<uint32_t D>
struct cube{
    uint8_t f1[D];
    uint8_t f2[D];
};

static_assert(sizeof(cube<3> == 6));
static_assert(sizeof(cube<4> == 8));

template<uint32_t D>
struct chain{
    cube<D> arr[4];
};

template<uint32_t D>
cube<D> next_color(uint64_t index){
    cube<D> retMe;
    
    index++;
    
    retMe.f1
    
    
    return retMe;
}

int main(){
    
    std::cout << "Instant insanity brute force." << "\n";
    int total_solutions = 0;
    
    
    
    
    
    
    
}


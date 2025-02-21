#include <iostream>
#include <algorithm>
#include <cstdint>
#include <set>

// stoler from SO, ty very mooch astraujums, https://stackoverflow.com/questions/283977/c-stl-set-difference
template<typename T>
std::set<T> operator -(std::set<T> reference, std::set<T> items_to_remove)
{
    std::set<T> result;
    std::set_difference(
        reference.begin(), reference.end(),
        items_to_remove.begin(), items_to_remove.end(),
        std::inserter(result, result.end()));
    return result;
}
// end SO attributed code.

template<typename T>
std::set<T> operator -=(std::set<T>& result, std::set<T> subMe){
    result = result - subMe;
    return result;
}

// the two coob types are useful for the population vs the rotation parts. Rotation only blocks out one side of the 
// if we enumerate all valid cubes with ignorance of rotation, we eliminate the need for computing rotations ie the lack of explicit rotation is our rotation. Otherwise we have to explicitly find duplicates & what not. (GARBAGE), so we don't do that.

template<uint32_t D>
struct cube_opposite_faces{
    uint8_t f1[D];
    uint8_t f2[D];
};

static_assert(sizeof(cube_opposite_faces<3>) == 6);
static_assert(sizeof(cube_opposite_faces<4>) == 8);

template<uint32_t D>
struct cube{
    uint8_t faces[2*D];
};

static_assert(sizeof(cube<3>) == 6);
static_assert(sizeof(cube<4>) == 8);

template<uint32_t D>
struct chain{
    cube<D> arr[4];
};

template<uint32_t D>
cube<D> get_cube(uint64_t index){
    cube<D> retMe;
    
    std::set<uint8_t> faces_left = {0,1,2,3,4,5};
    
    auto f = faces_left.begin();
    std::advance(f,index%6);
    faces_left -= {*f};
    
    
    
    
    index /= 5;
    
    return retMe;
}

int main(){
    
    std::cout << "Instant insanity brute force." << "\n";
    int total_solutions = 0;
    int number = 0;
    for( int i = 0; i < number; i++ ){
    for( int j = 0; j < number; j++ ){
    for( int k = 0; k < number; k++ ){
    for( int l = 0; l < number; l++ ){
    
    }}}}
    
    
    
    
    
}


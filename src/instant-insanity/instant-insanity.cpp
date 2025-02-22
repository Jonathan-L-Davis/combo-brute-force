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

template<typename T>
std::set<T> operator +(std::set<T>& og, std::set<T> addMe){
    std::set<T> retMe = og.insert(addMe);
    return retMe;
}

template<typename T>
std::set<T> operator +=(std::set<T>& result, std::set<T> addMe){
    result = result + addMe;
    return result;
}

// the two coob types are useful for the population vs the rotation parts. Rotation only blocks out one side of the 
// if we enumerate all valid cubes with ignorance of rotation, we eliminate the need for computing rotations ie the lack of explicit rotation is our rotation. Otherwise we have to explicitly find duplicates & what not. (GARBAGE), so we don't do that.

template<uint32_t D>
struct cube_opposite_faces{// ended up not using this to optimize, lazy solution works well enough (I hope, not worth effort rn).
    uint8_t f1[D];
    uint8_t f2[D];
};

static_assert(sizeof(cube_opposite_faces<3>) == 6);
static_assert(sizeof(cube_opposite_faces<4>) == 8);

template<uint32_t D>
struct cube{
    static_assert(D>0);
    uint8_t faces[2*D];
};

static_assert(sizeof(cube<3>) == 6);
static_assert(sizeof(cube<4>) == 8);

template<uint32_t D>
struct chain{
    cube<D> arr[4];
};


//actually kind of a cool mapping. I'm drunk rn, so you probably have to ask me later/in person.
template<uint32_t D>// last 2 don't matter at all. Went through several optimization steps, lots of symmetry. Rotations don't matter if you enumerate all colorations anyway. Can ignore 2 sides & that's a 16 x speed up per cube.
cube<D> get_cube(uint64_t index){
    cube<D> retMe;
    
    retMe.faces[0] = index%4;
    index >>= 2;
    retMe.faces[1] = index%4;
    index >>= 2;
    retMe.faces[2] = index%4;
    index >>= 2;
    retMe.faces[3] = index%4;//only works for 3;
    
    return retMe;
}

template<uint32_t D>
bool is_solution( chain<D> checkMe ){
    static_assert(D >= 1);// really doesn't make sense for 0 dimensions. 1 dimension is bad enough, but 0?! You basically waste a dimension out of every N dimensions. This can be used for optimization, but not while drinking.
    bool retMe = true;
    std::set<uint8_t> colors = {0,1,2,3};
    for( int i = 0; i < 2*(D-1); i++ ){// for each face of tower
        std::set<uint8_t> touched_colors = {};
        for( int j = 0; j<4; j++ ){// for each cube
            
            touched_colors.insert(checkMe.arr[j].faces[i]);
            
        }
        if(touched_colors != colors)
            retMe = false;
    }
    return retMe;
}

int main(){
    
    std::cout << "Instant insanity brute force." << "\n";
    int total_solutions = 0;
    int number = 256;
    for( int i = 0; i < number; i++ ){
        cube<3> cube_i = get_cube<3>(i);
    for( int j = 0; j < number; j++ ){
        cube<3> cube_j = get_cube<3>(j);
    for( int k = 0; k < number; k++ ){
        cube<3> cube_k = get_cube<3>(k);
    for( int l = 0; l < number; l++ ){
        cube<3> cube_l = get_cube<3>(l);
            
            chain<3> checkMe = {cube_i,cube_j,cube_k,cube_l};
            
            if(is_solution(checkMe))
                total_solutions++;
    }}}
    
    std::cout << i << "\n";
    std::cout << "Solutions: " << total_solutions << "\n";
    }
    
    
    std::cout << "Total solutions to all instant insanity cube settings\n";
    std::cout << total_solutions << "\n";
    
}


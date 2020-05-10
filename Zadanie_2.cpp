#include <iostream>
#include <array>
#include <vector>

/*

Function "pickMorphs" takes reference of the vector containing floats and returns std::array containing indexes of four highest numbers from given vector.

If the vector has less than four elements - function will just use all of the indeces from the vector and any empty spot in the array will contain number -1.

If elements of the vector have the same value and there is not be enough space to place both indeces in the array - lower index will be chosen.

*/


int findHighestNotRepeatedMorph(    const std::array < int, 4>&,     const std::vector <float>&  );
bool checkIfNotAlreadyUsed(   const int index,   const std::array < int, 4>&  );

std::array < int, 4 > pickMorphs(const std::vector <float>& weights) {

    std::array <int, 4> morphs = { -1,-1,-1,-1 };

    if (weights.size() < 5){
        for (int i = 0; i < weights.size(); i++)
            morphs[i] = i;
        return morphs;
    }

    for (int i = 0; i < morphs.size(); i++) {

        morphs[i] = findHighestNotRepeatedMorph(morphs, weights);
    }
    return morphs;

}


int findHighestNotRepeatedMorph(const std::array < int, 4>& morphs, const std::vector <float>& weights) {

    int nextMorphToAssign = 0;

    while (!checkIfNotAlreadyUsed(nextMorphToAssign, morphs))                         //for proper work of j loop - "nextMorphToAssign" need to be not repeated index
        nextMorphToAssign++;

    for (int j = 0; j < weights.size(); j++) {

        if (weights[j] > weights[nextMorphToAssign] && checkIfNotAlreadyUsed(j, morphs)) {
            nextMorphToAssign = j;
        }
    }
    return  nextMorphToAssign;
}

bool checkIfNotAlreadyUsed ( const int index, const std::array < int, 4> &morphs) {
    for (int j = 0; j < morphs.size(); j++) {
        if (morphs[j] == index)
            return false;
    }
    return true;
}

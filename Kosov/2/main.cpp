#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "numbers.dat"


bool prime(int n){
    
    if(n == 1) return false;
    
    for(int i=2; i*i<=n; i++)
        if(n%i==0)
            return false;
    
    return true;
    
}

int main(int argc, char*argv[]){
    
    if((argc < 2) || !(argc%2)) return -1;

    for(int i = 1; i<argc; i+=2){
        
        int first = std::atoi(argv[i]),
            second = std::atoi(argv[i+1]),
            num = 0;

        if(first > second){
            std::cout << 0 << " ";
            return 0;
        }

        if(
           !(std::binary_search(Data, Data+Size, first)) ||
           !(std::binary_search(Data, Data+Size, second))
           )
            return -1;
        
        auto current = std::lower_bound(Data, Data + Size, first);
        auto end = std::upper_bound(Data, Data + Size, second);

        while(current != end){
            if(prime(*current)){
                num++;
            }
            current++;
        }
        std::cout << num << "\n";
    }
        return 0;
}

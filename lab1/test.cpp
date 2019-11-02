//test
#include <iostream>
using namespace std;

int main(void){
   int x[4] = {2, 7, 11, 15};
   int targ = 9;
    int[4] comp;

    for(int i = 0; i < 4; i++){
        if(comp[nums[i]] >= 0){
            cout<<comp[nums[i]]<<" "<<i<<endl;
        }
        comp[targ - nums[i]] = i;
    }

}

void Solar(){
    int i = 1;
    while(i < 101){
        if(i % 3 == 0 && i % 5 == 0)
            cout<<"solarCar"<<endl;
        else if(i % 3 == 0)
            cout<<"solar"<<endl;
        else if(i % 5 == 0)
            cout<<"car"<<endl;
        else
            cout<<i<<endl;
        i++;
    }
}

/* const twoSum = function(nums, target) {
    const comp = {};
    for(let i=0; i<nums.length; i++){
        if(comp[nums[i] ]>=0){
            return [ comp[nums[i] ] , i]
        }
        comp[target-nums[i]] = i
    }
}; */
import java.util.HashMap;
import java.util.Map;

class test {
    public static void main(String[] args) {
        /* 
        int target = 9;
        int[] comp = new int[50];

        for(int i = 0; i < x.length; i++){
            if(comp[x[i]] >= 0){
                System.out.println(comp[x[i]] + " " +  i);
            }
            if(target-x[i] >=0)
            comp[target-x[i]] = i;
        } */
        int[] x2 = {2, 7, 11, 15};
        int[] x = new int[2];
        twoSum(x2, 9);
        //System.out.println(x[0] + x[1]);
    }


    public static void twoSum(int[] nums, int target) {
        System.out.println("XXX");
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                //return new int[] { map.get(complement), i };
                System.out.println(map.get(complement) + i );
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
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
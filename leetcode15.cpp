class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        if(nums.size()<3){
            return ans;
        }
        
        sort(nums.begin(),nums.end());
        
        int ptr1 =0 ,ptr2 = nums.size()-1;
        for(int i=0;i<nums.size();i++){
            vector<int> temp ;
            int target = nums[i]*-1; //(a + b + c) = 0.  b+c = -a
            
            if(i>0 && nums[i-1] == nums[i])//重複
                continue;
            ptr1 = i+1;
            ptr2 = nums.size()-1;
            while(ptr1 < ptr2){
                int b = nums[ptr1];
                int c = nums[ptr2];
                if( b+c < target){ // b+c < a b往右移動
                    ptr1+=1;
                    if( b == nums[ptr1])//右移還是一樣數字 再往右一次
                        ptr1 +=1;
                }else if( b+c > target){// b+c > a c往左移動
                    ptr2 -=1;
                    if( c  == nums[ptr2])
                        ptr2 -=1;
                }else if( b+c == target){ // b+c = a
                    temp.push_back(nums[i]);
                    temp.push_back(nums[ptr1]);
                    temp.push_back(nums[ptr2]);
                    ptr1+=1;
                    ptr2-=1;
                    if(ans.size()>0){//重複的要刪除
                        if(ans[ans.size()-1] == temp)
                            ans.pop_back();
                    }
                    ans.push_back(temp);
                    temp.clear();
                }
            }    
        }
        return ans;
    }
};

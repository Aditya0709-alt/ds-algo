public class JumpGame55 {
  static int max(int a, int b){
    return (a > b) ? a : b;
  }
  
  public static boolean canJump(int [] nums){
    int a = 0;
    for(int i = 0; i < nums.length; i++){
      if(i > a){
        return false;
      }
      a = max(a, i + nums[i]);
    }
    return true;
  }
  
  public static void main(String [] args){
    int [] nums = {2,3,1,1,4};
    
    if(canJump(nums)){
      System.out.println("Possible");
    }
    else {
      System.out.println("Not possible");
    }
  }
}

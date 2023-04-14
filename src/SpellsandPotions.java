import java.util.Arrays;

public class SpellsandPotions {
    static int[] successfulPairs(int[] spells, int[] potions, long success) {
        int[] pairs = new int[spells.length];
        
        for (int i=0; i<spells.length; i++){
          for(int j=0; j<potions.length; j++) {
            long prod=(long)spells[i]*potions[j];
            if (prod >= success)
              pairs[i]++;
          }
        }
        return pairs;
      }


  public static void main(String[] args) {
      int spells[]={5,1,3};
      int potions[]={1,2,3,4,5};
      long success=7;
      
      int x[]= successfulPairs(spells,potions,success);
      

      System.out.println(Arrays.toString(x));
    
  }
}

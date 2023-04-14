public class SpellsandPotions {
  static int[] successfulPairs(int[] spells, int[] potions, long success) {
      int n= spells.length;
      int m= potions.length;

      int i=0,j=0;
      int a[]=new int[n];
      int arr[]=new int[m];
      
      for (i=0;i<n;i++)
      {
        
          for(j=0;j<m;j++) {
              int prod;
              prod=spells[i]*potions[j];
              arr[j]=prod;
          }
              int c=0;
          for(int k=0;k<m;k++) {
            if(arr[k]>=success)
                    c++;
      }
      //System.out.println(c);
      for(int l=0;l<n;l++)
      {
        a[l]=c;
      }
      System.out.println(a);
      }
      //System.out.println(a);
      return a;
  }
      
      
   


  public static void main(String[] args) {
      int spells[]={5,1,3};
      int potions[]={1,2,3,4,5};
      long success=7;
      int x[]=successfulPairs(spells,potions,success);

      System.out.println(x);
    
  }
}

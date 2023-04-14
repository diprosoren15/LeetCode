public class SearchBinary {

  int binarySearch(int arr[], int size, int element) {
      int high, mid, low;
      high = size - 1;
      low = 0;

      while (low <= high) {
          mid = (low + high) / 2;
          if (arr[mid] == element) {
              return mid;
          }
          if (arr[mid] > element) {
              high = mid - 1;
          } else low = mid +1;
      }
      return -1;
  }

  public static void main(String[] args) {
      SearchBinary ob = new SearchBinary();
      int arr[] = {1,7,9,18,32,64,72,88,91,106};
      int size = arr.length;
      int element = 91;
      int searchResult = ob.binarySearch(arr, size, element);

      if(searchResult==-1){
          System.out.println(element+" not present");
      }else  System.out.println("The element " + element + " is present in index " + searchResult);

  }
}

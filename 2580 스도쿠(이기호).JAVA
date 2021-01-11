import java.util.ArrayList;
import java.util.Scanner;
 
class xy {
    int x ;
    int y ;
 
    public xy(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
 
public class Main {
 
    static int[][] check ;
 
    static ArrayList<xy> arrayList = new ArrayList<xy>();
    public static void main(String[] args) {
 
        Scanner sc = new Scanner(System.in);
        check = new int[9][9];
        for (int i = 0; i <9 ; i++) {
            for (int j = 0; j <9 ; j++) {
                check[i][j] = sc.nextInt();
            }
        }
 
        for (int i = 0; i < 9 ; i++) {
            for (int j = 0; j <9 ; j++) {
                if(check[i][j] == 0){
                    arrayList.add(new xy(i,j)); 
                }
            }
        }
        dfs (arrayList,0);
    }
 
    static private void dfs(ArrayList<xy> arr, int idx){
 
        if(idx == arrayList.size()) {
            for (int i = 0; i <9 ; i++) {
                for (int j = 0; j <9 ; j++) {
                    System.out.print(check[i][j]+ " ");
                }
                System.out.println("");
            }
            System.exit(0);
        }
 
        for (int i = 1; i <10 ; i++) { 
            if(checkRow(arr,idx,i) == true && checkCol(arr,idx,i) == true && checkBox(arr,idx,i) == true){
                check[arr.get(idx).x][arr.get(idx).y] = i;            
                dfs(arr, idx+1);
            }
 
            if(i==9){ 
                check[arr.get(idx).x][arr.get(idx).y] = 0;
            }
        }
    }
 
    static boolean checkRow(ArrayList<xy> arr, int idx, int pro){
        for (int i = 0; i <9 ; i++) {
            if(arr.get(idx).y == i) continue; 
            if(check[arr.get(idx).x][i] == pro) return false;
        }
        return true;
    }
 
    static boolean checkCol(ArrayList<xy> arr, int idx, int pro){
        for (int i = 0; i <9 ; i++) {
            if(arr.get(idx).x == i) continue;
            if(check[i][arr.get(idx).y] == pro) return false;
        }
        return true;
    }
 
    static boolean checkBox(ArrayList<xy> arr, int idx, int pro){
 
       int a = arr.get(idx).x/3;
        int b = arr.get(idx).y/3;
        a *= 3;
        b *= 3;
 
        for (int i = a; i <a+3 ; i++) {
            for (int j = b; j <b+3 ; j++) {
                if(i == arr.get(idx).x && j==arr.get(idx).y) continue;
                if(check[i][j]!=0 && check[i][j] == pro) return false;
            }
        }
 
        return true;
    }
 
}

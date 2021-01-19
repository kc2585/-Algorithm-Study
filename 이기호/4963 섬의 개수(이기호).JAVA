import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        while(a != 0 && b != 0){
            int[][] arr = new int[b][a];
            for(int i = 0; i < b; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < a; j++){
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            int sum = 0;
            for(int i = 0; i < b; i++){
                for(int j = 0; j < a; j++){
                    if(arr[i][j] == 1){
                        sum++;
                        island(arr, b, a, i, j);
                    }
                }
            }
            bw.write(sum +"\n");

            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
        }

        bw.flush();
        br.close();
        bw.close();
    }
    public static void island(int[][] arr, int b, int a, int i, int j){
        if(i >= b || i < 0 || j >= a || j < 0) return;
        if(arr[i][j] == 1){
            arr[i][j] = 0;
            island(arr, b, a, i + 1, j + 1);
            island(arr, b, a, i + 1, j);
            island(arr, b, a, i + 1, j - 1);
            island(arr, b, a, i, j + 1);
            island(arr, b, a, i, j - 1);
            island(arr, b, a, i - 1, j + 1);
            island(arr, b, a, i - 1, j);
            island(arr, b, a, i - 1, j - 1);
        } else {
            return;
        }
    }
}

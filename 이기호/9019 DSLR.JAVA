import java.util.*;
 
public class Main {
	
	static String[] arr = new String[10000]; 
    static boolean[] visited = new boolean[10000]; 
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
 
        for (int i = 0; i <n ; i++) {
            int a = sc.nextInt();
            int b =sc.nextInt();
           
            Queue<Integer> q = new LinkedList<>();
 
            visited[a] = true;
            q.add(a);
            Arrays.fill(arr,"");
            while (!q.isEmpty() && !visited[b]){
                int now =q.poll();
                int D = (2*now)%10000;
                int S = (now == 0) ? 9999 : now-1;
                int L = (now % 1000) * 10 + now/1000;
                int R = (now % 10) * 1000 + now/10;
 
                if(!visited[D]){
                    q.add(D);
                    visited[D]=true;
                    arr[D]=arr[now] + "D";
                }
 
                if(!visited[S]){
                    q.add(S);
                    visited[S]=true;
                    arr[S]=arr[now] + "S";
                }
                if(!visited[L]){
                    q.add(L);
                    visited[L]=true;
                    arr[L]=arr[now] + "L";
                }
                if(!visited[R]){
                    q.add(R);
                    visited[R]=true;
                    arr[R]=arr[now] + "R";
                }
            }
            System.out.println(arr[b]);
        }
 
    }
}

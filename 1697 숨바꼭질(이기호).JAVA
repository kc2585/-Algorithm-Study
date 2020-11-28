import java.util.*;
import java.io.*;

public class Main {
	
	static boolean[] visited = new boolean[100001];
    static int[] time = new int[100001];
    static int[] move = { 1, -1, 2 };

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		   
	    int n = sc.nextInt();
	    int k = sc.nextInt();
	 
	    if(n >= k)
	        System.out.println(n-k);
	    else
	        bfs(n, k);
	}
	
	public static void bfs (int n, int k) {
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(n);
        visited[n] = true;
        time[n] = 0;
 
        while(!queue.isEmpty()) {
            int num = queue.poll();
 
            for(int i=0; i<3; i++) {
                int next;
                if(i == 2) {
                    next = num * move[i];
                } else {
                    next = num + move[i];
                }
 
                if(next <= 100000 && -1 < next && !visited[next]) {
                    queue.add(next);
                    visited[next] = true;
                    time[next] = time[num] + 1;
                }
            }
        }
        System.out.println(time[k]);
    }

}

import java.io.*;
import java.util.*;

public class Main {
	
	static boolean visit[] = new boolean[100001];
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		PriorityQueue<int[]> q = new PriorityQueue<int[]>(new Comparator<int[]>() {
			public int compare(int o1[],int o2[]) {
				return Integer.compare(o1[1], o2[1]);
			}
		});
		
		q.add(new int[] {N,0});
		visit[N]=true;
		int answer=Integer.MAX_VALUE;
		while(!q.isEmpty()) {
			int[] p = q.poll();
			visit[p[0]]=true;
			if(p[0] == K) {
				answer = p[1];
				break;
			}
			if(p[0]-1 >= 0 && !visit[p[0]-1]) q.add(new int[] {p[0]-1,p[1]+1});
			if(p[0]+1 <= 100000 &&!visit[p[0]+1]) q.add(new int[] {p[0]+1,p[1]+1});
			if(2 * p[0] <= 100000 &&!visit[p[0]*2]) q.add(new int[] {p[0]*2,p[1]});
		}
		System.out.println(answer);
	}
}

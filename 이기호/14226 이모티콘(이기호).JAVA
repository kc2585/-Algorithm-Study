import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {

	static boolean visit[][] = new boolean[10001][10001];
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		Queue<Point> que = new LinkedList<Point>();
		que.offer(new Point(1, 0)); 
		visit[1][0] = true;
		int cnt = 0;
		gg:while (!que.isEmpty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				Point now = que.poll();
				if(now.x == N) {
					break gg;
				}
				if (!visit[now.x][now.x]) {
					visit[now.x][now.x] = true;
					que.offer(new Point(now.x, now.x));
				}
				if(now.x-1 >0 && !visit[now.x-1][now.y]) {
					visit[now.x-1][now.y] = true;
					que.offer(new Point(now.x-1,now.y));
				}
				if(!visit[now.x+now.y][now.y]) {
					visit[now.x+now.y][now.y] = true;
					que.offer(new Point(now.x+now.y, now.y));
				}
			}
			cnt++;
		}
		System.out.println(cnt);

	}

}

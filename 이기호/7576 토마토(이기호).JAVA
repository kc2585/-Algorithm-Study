import java.util.*;

public class Main {
	
	public static int M, N;
	public static int map[][];
	public static boolean visit[][];
	
	static int dx[] = {1, 0, -1, 0};
	static int dy[] = {0, 1, 0, -1};
	static Queue<Integer> qx = new LinkedList<Integer>();
	static Queue<Integer> qy = new LinkedList<Integer>();
	
	public static void bfs() {
		int result = 0;
		int x, y;
		
		while(!qx.isEmpty() && !qy.isEmpty()) {
			x = qx.poll();
			y = qy.poll();
			
			visit[x][y] = true;
			
			for(int i = 0; i < 4; i++) {
				int _x = x + dx[i];
				int _y = y + dy[i];
				
				if(_x >= 0 && _y >= 0 && _x < N && _y < M) {
					if(map[_x][_y] == 0 && visit[_x][_y] == false) {
						qx.add(_x);
						qy.add(_y);
						visit[_x][_y] = true;
						
						map[_x][_y] = map[x][y] + 1;
						result = map[_x][_y];
					}
				}
			}
		}
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(map[i][j] == 0) {
					result = -1;
				}
			}
		}
		
		if(result > 0) {
			System.out.println(result-1);
		} else {
			System.out.println(result);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
Scanner sc = new Scanner(System.in);
		
		M = sc.nextInt();
		N = sc.nextInt();
		
		map = new int[N][M];
		visit = new boolean[N][M];
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				map[i][j] = sc.nextInt();
				
				if(map[i][j] == 1) {
					qx.add(i);
					qy.add(j);
				}
			}
		}
		bfs();
	}

}

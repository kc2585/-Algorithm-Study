import java.util.*;
import java.io.*;

public class Main {

	static int arr[][];
	static boolean visited[][];
	static int dx[] = {0, 0, 1, -1};
	static int dy[] = {1, -1, 0, 0};
	static int N, M;
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        arr = new int[N][M];
        visited = new boolean[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String line = st.nextToken();
            for (int j = 0; j < M; j++) {
                arr[i][j] = line.charAt(j) - '0';
            }
        }

        bfs(0,0);

        System.out.println(arr[N-1][M-1]);
	}

	public static void bfs(int i, int j) {
		 Queue<int[]> q = new LinkedList<>();
	        q.offer(new int[] {i,j});

	        while(!q.isEmpty()){
	            int location[] = q.poll();
	            visited[i][j] = true;

	            for(int dir = 0; dir < 4; dir++){
	                int r = location[0] + dy[dir];
	                int c = location[1] + dx[dir];

	                if(r >= 0 && c >= 0 && r < N && c < M){
	                    if(arr[r][c] != 0 && !visited[r][c]){
	                        q.offer(new int[] {r,c});
	                        visited[r][c] = true;
	                        arr[r][c] = arr[location[0]][location[1]] + 1;
	                    }
	                }
	            }
	        }
	
	}
}

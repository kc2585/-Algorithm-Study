import java.io.*;

public class Main {
	
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static String ans = "No";
    static int r;
    static int c;
    static char[][] map;

    public static void main(String[] args) throws Exception{
    	
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        r = Integer.parseInt(input[0]);
        c = Integer.parseInt(input[1]);
        map = new char[r][c];
        visited = new boolean[r][c];

        for(int i = 0; i < r; i++) {
            String row = br.readLine();
            for(int j = 0; j < c; j++)
                map[i][j] = row.charAt(j);
        }

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(ans.equals("Yes")) {
                    System.out.println(ans);
                    return;
                }

                if(!visited[i][j]) {
                    visited[i][j] = true;
                    dfs(i, j, map[i][j], -1);
                }

            }
        }
        System.out.println(ans);
    }

    public static void dfs(int x, int y, char color, int idx) {
        if(ans.equals("Yes")) return;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(idx + i == 1 || idx + i == 5) continue;

            if(nx < 0 || nx >= r || ny < 0 || ny >= c || map[nx][ny] != color) continue;
            if(visited[nx][ny]) {
                ans = "Yes";
                return;
            }
            visited[nx][ny] = true;
            dfs(nx, ny, color, i);
        }
    }
}

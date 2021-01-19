import java.io.*;
import java.util.*;
 
public class Main {
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    static int[][] map;
    public static int ans = 0;
    public static boolean[] visited = new boolean[26];
    static int r;
    static int c;
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
 
        r = Integer.parseInt(stk.nextToken());
        c = Integer.parseInt(stk.nextToken());
        map = new int[r][c];
 
        for (int i = 0; i < r; i++) {
            String s = br.readLine();
            for (int j = 0; j < c; j++) {
                map[i][j] = s.charAt(j) - 'A';
            }
        }
 
        bt(0, 0, 0);
        System.out.println(ans);
    }
 
    public static void bt(int x, int y, int depth) {
        if (visited[map[x][y]]) {
            ans = Math.max(ans, depth);
            return;
        } else {
            visited[map[x][y]] = true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                    bt(nx, ny, depth + 1);
                }
            }
            visited[map[x][y]] = false;
        }
    }
}

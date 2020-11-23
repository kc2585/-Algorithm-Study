import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int M;
    static int ans = 0;
    static ArrayList<Integer>[] map;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        map = new ArrayList[N];
        for(int i=0; i<N; i++)
            map[i] = new ArrayList<>();

        for(int i=0; i<M; i++) {
            input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);

            map[a].add(b);
            map[b].add(a);
        }

        for(int i=0; i<N; i++) {
            if(ans==1) break;
            dfs(new boolean[N], i, 0);
        }

        System.out.println(ans);
    }

    public static void dfs(boolean[] visited, int num, int cnt) {
        if(ans==1) return;

        if(cnt>=5) {
            ans=1;
            return;
        }

        for(int i=0; i<map[num].size(); i++) {
            int x = map[num].get(i);

            if(!visited[x]) {
               visited[x] = true;
               dfs(visited, x, cnt+1);
               visited[x] = false;
            }
        }
    }
}

import java.io.*;
import java.util.*;
 
public class Main {
 
    private static int N, K;
    private static int[] visited = new int[100001];
    private static int[] parent = new int[100001];
 
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
 
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
 
        bfs(N, K);
        System.out.println(visited[K] - 1);
 
        Stack<Integer> s = new Stack<>();
        int idx = K;
        while (idx != N) {
            s.push(idx);
            idx = parent[idx];
        }
        s.push(idx);
 
        while (!s.isEmpty()) {
            System.out.print(s.pop() + " ");
        }
 
        br.close();
    }
 
    private static void bfs(int start, int end) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        visited[start] = 1;
 
        while (!queue.isEmpty()) {
            int now = queue.poll();
 
            if (now + 1 <= 100000 && visited[now + 1] == 0) {
                visited[now + 1] = visited[now] + 1;
                parent[now + 1] = now;
                queue.add(now + 1);
            }
            if (now - 1 >= 0 && visited[now - 1] == 0) {
                visited[now - 1] = visited[now] + 1;
                parent[now - 1] = now;
                queue.add(now - 1);
            }
            if (now * 2 <= 100000 && visited[now * 2] == 0) {
                visited[now * 2] = visited[now] + 1;
                parent[now * 2] = now;
                queue.add(now * 2);
            }
 
            if (visited[end] != 0) return;
        }
    }
}

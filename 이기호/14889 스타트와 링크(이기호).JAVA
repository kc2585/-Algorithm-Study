import java.util.*;
import java.io.*;

public class Main {

	static int N;
	static int arr[][];
	static boolean visited[];
	static int min = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		arr = new int [N][N];
		visited = new boolean [N];
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				arr[i][j] = sc.nextInt();	
			}
		}

		DFS(0, 0);
		System.out.println(min);
	}

	public static void DFS(int idx, int count) {
		if(count == N / 2) {
			diff();
			return;
		}
		
		for(int i = idx; i < N; i++) {
			if(!visited[i]) {
				visited[i] = true;	
				DFS(i + 1, count + 1);	
				visited[i] = false;	
			}
		}
	}
	
	public static void diff() {
		int start = 0;
		int link = 0;
		
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (visited[i] == true && visited[j] == true) {
					start += arr[i][j];
					start += arr[j][i];
				}
				else if (visited[i] == false && visited[j] == false) {
					link += arr[i][j];
					link += arr[j][i];
				}
			}
		}
		
		int val = Math.abs(start - link);
		
		if(val == 0) {
			System.out.print(val);
			System.exit(0);
		}
		
		min = Math.min(val, min);
	}
}

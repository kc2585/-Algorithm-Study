import java.util.*;
import java.io.*;

public class Main {

	 static int N;
	 static int parent[];
	 static int[][] map;
	 static int cur;
	 static int Answerh = 0;
	 static int Answer = Integer.MIN_VALUE;
	 static Tree[] node;
	 static int deep = 1;
	
	 static class Tree {
		 int left;
		 int data;
		 int right;
		 
		 public Tree(int left, int data, int right) {
			 this.left = left;
			 this.data = data;
			 this.right = right;
		 }
	 }
	 
	 static int Find(int x) {
		 if(parent[x]==x) {
			 return x;
		 }
		 return Find(parent[x]);
	 }
	
	 public static void DFS(int row, int data) {
		 if(data==-1)
			 return;
		 deep = Math.max(deep, row);
		 DFS(row+1,node[data].left);
	     map[0][row] = Math.min(map[0][row], cur);
	     map[1][row] = Math.max(map[1][row], cur++);
	     DFS(row+1,node[data].right);
	 }
	 
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		node = new Tree[N + 1];
        parent = new int[N+1];
        
        int left = 0;
        int data = 0;
        int right = 0;
        
        for(int n=1;n<=N;n++) {
            parent[n]=n;
        }
        
        for (int n = 1; n <= N; n++) {
            String[] str = br.readLine().split(" ");
            data = Integer.parseInt(str[0]);
            left = Integer.parseInt(str[1]);
            right = Integer.parseInt(str[2]);
            
            node[data] = new Tree(left, data, right);
  
            if(left!=-1) {
                parent[left] = data;
            }
            
            if(right!=-1) {
                parent[right] =data;
            }
        }
        
        map = new int[2][N+1];
       
        int root = Find(1);
        cur = 1;
        for(int n=1;n<=N;n++) {
            map[0][n] = Integer.MAX_VALUE;
            map[1][n] = Integer.MIN_VALUE;
        }
        
        DFS(2,node[root].left);
        map[0][1] = Math.min(map[0][1], cur);
        map[1][1] = Math.max(map[1][1], cur++);
        DFS(2,node[root].right);
        
        for(int d=1;d<=deep;d++) {
            if(Answer < map[1][d] - map[0][d] +1) {
                Answerh = d;
                Answer = map[1][d] - map[0][d] +1;
            }
        }
        
        System.out.print(Answerh+" "+Answer);

	}

}

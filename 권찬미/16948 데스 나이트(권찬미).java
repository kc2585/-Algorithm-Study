import java.awt.image.BufferedImageFilter;
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {


    public static int start_r,start_c,end_r, end_c, size;

    public static int[][] chess=new int[201][201];

    public static boolean[][] visited=new boolean[201][201];

    public static int[][] plus = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};



    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);

        size=scan.nextInt();
        start_r=scan.nextInt();
        start_c=scan.nextInt();
        end_r=scan.nextInt();
        end_c=scan.nextInt();

        System.out.println(make_route());



        scan.close();


    }

    public static int make_route(){

        Queue<Integer> queue=new LinkedList<>();

        queue.add(start_r);
        queue.add(start_c);

        int move_num=0;
        boolean flag=true;

        while(!queue.isEmpty()){
            int qsize=queue.size()/2;

            for(int x=0;x<qsize;x++){
                int now_r=queue.poll();
                int now_c=queue.poll();

                for(int y=0;y<6;y++){
                    int next_r=now_r+plus[y][0];
                    int next_c=now_c+plus[y][1];

                    if(!isRange(next_r,next_c) || visited[next_r][next_c])
                        continue;

                    if(next_r==end_r && next_c==end_c){
                        flag=false;
                        queue.clear();
                        break;
                    }

                    queue.add(next_r);
                    queue.add(next_c);

                    visited[next_r][next_c]=true;
                }

                if(!flag)
                    break;

            }

            move_num++;
        }


        if(flag)
            return -1;
        else
            return move_num;
    }


    public static boolean isRange(int r,int c){
        if(0<=r && r<size && 0<=c && c<size)
            return true;
        return false;
    }

}

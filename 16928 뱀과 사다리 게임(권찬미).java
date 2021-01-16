import java.awt.image.BufferedImageFilter;
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {


    public static int ladder, snake;

    public static int[][] map=new int[10][10];

    public static int[][] cache=new int[10][10];

    public static boolean[][] visited=new boolean[10][10];



    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);

        ladder=scan.nextInt();
        snake=scan.nextInt();

        for(int index=0;index<ladder+snake;index++){
            int start=scan.nextInt();
            int end=scan.nextInt();

            start--;
            end--;

            map[start/10][start%10]=end;
        }



        System.out.println(make_route());



        scan.close();


    }

    public static int make_route(){

        Queue<Integer> queue=new LinkedList<>();

        queue.add(0);

        int dice_num=0;
        boolean flag=true;

        while(!queue.isEmpty()){
            int qsize=queue.size();

            for(int x=0;x<qsize;x++){
                int now=queue.poll();

                for(int y=1;y<=6;y++){
                    now++;

                    if(visited[now/10][now%10])
                        continue;

                    if(now==99){
                        queue.clear();
                        flag=false;
                        break;
                    }

                    visited[now/10][now%10]=true;

                    if(map[now/10][now%10]!=0){
                        queue.add(map[now/10][now%10]);
                    }else{
                        queue.add(now);
                    }
                }

                if(!flag)
                    break;
            }

            dice_num++;
        }

        return dice_num;
    }



}

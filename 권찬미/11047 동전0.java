import java.awt.image.BufferedImageFilter;
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {



    public static void main(String[] args) throws IOException {

        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st=new StringTokenizer(br.readLine());

        int num=Integer.parseInt(st.nextToken());
        int price=Integer.parseInt(st.nextToken());

        int[] list=new int[num];

        int answer=0;

        for(int x=0;x<num;x++)
            list[x]=Integer.parseInt(br.readLine());

        for(int x=num-1;x>=0;x--){
            if(list[x]>price)
                continue;

            answer+=price/list[x];
            price%=list[x];
        }

        bw.write(String.valueOf(answer));

        bw.flush();
        bw.close();
        br.close();




    }








}
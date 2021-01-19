import java.util.*;

class Main{
    static int[][] map ;
    static boolean[][] block;
    static int n;
    static int[] dx = new int[]{0,1};
    static int[] dy = new int[]{1,0};
    static boolean[][] c1 ;
    static boolean[][] c2 ;
    static boolean[][] c3 ;
    static boolean flag ;


    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a,b;
        int tc = 1;
        char[] chArr;
        while(true){
            flag = false;
            n = sc.nextInt();
            block = new boolean[10][10];
            map = new int[9][9];
            c1 = new boolean[10][10];
            c2 = new boolean[10][10];
            c3 = new boolean[10][10];
            if(n == 0) break;
            for(int i=0;i<n;i++){
                a = sc.nextInt();
                chArr = sc.next().toCharArray();
                int l1 = chArr[0]-'A';
                int l2 = chArr[1]-'1';
                map[l1][l2] = a;
                checking(l1,l2,a,true);

                b=sc.nextInt();
                chArr = sc.next().toCharArray();
                l1 = chArr[0]-'A';
                l2 = chArr[1]-'1';
                map[l1][l2] = b;
                checking(l1,l2,b,true);

                block[a][b] = true;
                block[b][a] = true;
            }
            for(int i=1;i<10;i++){
                chArr = sc.next().toCharArray();
                int l1 = chArr[0]-'A';
                int l2 = chArr[1]-'1';
                map[l1][l2] = i;
                checking(l1,l2,i,true);
            }
            System.out.println("Puzzle "+tc);
            tc++;
            dfs(0);

        }
    }

    static void dfs2(int a,int b){
        if(a==9) {
            if(!flag) {
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        System.out.printf("%d", map[i][j]);
                    }
                    System.out.println();
                }
                flag = true;
            }
            return;
        }
        int na=a,nb=b+1;
        if(nb>9) {
            ++na; nb=na+1;
        }
        if(block[a][b]) {
            dfs2(na,nb);
        }
        else {
            int ni,nj;
            for(int k =0 ;k < 2 ;k ++) {
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        ni = i + dx[k];
                        nj = j + dy[k];
                        if(!rangeCheck(ni,nj)) continue;
                        if(map[i][j]!=0) continue;
                        if(map[ni][nj]!=0) continue;
                        if(can(i,j,a) && can(ni,nj,b)){
                            map[i][j] = a;
                            map[ni][nj] = b;
                            block[a][b] = block[b][a]=true;
                            checking(i,j,a,true);
                            checking(ni,nj,b,true);
                            if(!flag)
                                dfs2(na,nb);
                            block[a][b] = block[b][a]=false;
                            checking(i,j,a,false);
                            checking(ni,nj,b,false);
                            map[i][j]=0;
                            map[ni][nj]=0;
                        }
                        if(can(i,j,b) && can(ni,nj,a)){
                            map[i][j] = b;
                            map[ni][nj] = a;
                            block[a][b] = block[b][a]=true;
                            checking(i,j,b,true);
                            checking(ni,nj,a,true);
                            if(!flag)
                                dfs2(na,nb);
                            block[a][b] = block[b][a]=false;
                            checking(i,j,b,false);
                            checking(ni,nj,a,false);
                            map[i][j]=0;
                            map[ni][nj]=0;
                        }
                    }
                }
            }

        }
    }

    static void dfs(int idx){ 
        if(idx == 81 ){
            if(!flag) {
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        System.out.printf("%d", map[i][j]);
                    }
                    System.out.println();
                }
                flag = true;
            }
            return;
        }
        int x = idx/9;
        int y = idx%9;


        int nx,ny;
        if(map[x][y]!=0){
            dfs(idx+1);
        }else{
            for(int k=0;k<2;k++){
                nx = x + dx[k];
                ny = y + dy[k];
                if(0>nx || nx>=9 || 0>ny || ny>=9) continue;
                if(map[nx][ny]!=0) continue;
                for(int i=1;i<=9;i++){
                    for(int j=1;j<=9;j++){
                        if(i!=j && !block[i][j] && can(x,y,i) && can(nx,ny,j)){
                            map[x][y]=i;
                            map[nx][ny]=j;
                            block[i][j]=block[j][i]=true;
                            checking(x,y,i,true);
                            checking(nx,ny,j,true);
                            if(!flag) dfs(idx+1);
                            checking(x,y,i,false);
                            checking(nx,ny,j,false);
                            block[i][j]=block[j][i]=false;
                            map[x][y]=0;
                            map[nx][ny]=0;
                        }
                    }
                }
            }
        }

    }

    static boolean rangeCheck(int x,int y){
        if(0>x || x>=9 || 0>y || y>=9) return false;
        else return true;
    }

    static int toBox(int x,int y){
        return (x/3)*3+(y/3);
    }

    static boolean can(int x,int y,int num){
        return !c1[x][num] && !c2[y][num] && !c3[toBox(x,y)][num];
    }

    static void checking(int x,int y,int num,boolean what){
        c1[x][num] = what; 
        c2[y][num] = what; 
        c3[toBox(x,y)][num] = what; 
    }


}

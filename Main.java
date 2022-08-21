package PermutationsandPrimes;

import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int n = readInt();
        ArrayList<Integer> al = new ArrayList<>();
        if (n == 2 || n == 3 || n == 4) System.out.println(-1);
        else if (n == 1) System.out.println(1);
        else {
            int x = 1;
            while (x <= n) {
                if (x != 5) al.add(x);
                x+= 2;
            }
            al.add(5);
            al.add(4);
            int y = 2;
            while (y <= n){
                if (y != 4) al.add(y);
                y += 2;
            }
            int count = 0;
            for (int i: al) {
                System.out.print(count == n-1? i + "\n": i + " ");
                count++;
            }
        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}


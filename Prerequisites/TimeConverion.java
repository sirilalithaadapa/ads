import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result {

    /*
     * Complete the 'timeConversion' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String timeConversion(String s) {
    // Write your code here
    int len = s.length();
         String time = s.substring(len-2, len);
         String[] t = s.substring(0, len-2).split(":");
         
         int int_hrs = Integer.parseInt(t[0]);
         String mins = t[1];
         String secs = t[2];
         
         if (time.equals("PM") && int_hrs != 12) int_hrs += 12;
         if (time.equals("AM") && int_hrs == 12) int_hrs = 0;
         
         String hrs = String.valueOf(int_hrs);
         if (hrs.length() < 2) 
            hrs = "0" + hrs;

         return hrs + ":" + mins + ":" + secs;

    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = bufferedReader.readLine();

        String result = Result.timeConversion(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
// Problem statement: https://www.hackerrank.com/challenges/time-conversion/problem

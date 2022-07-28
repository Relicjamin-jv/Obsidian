```Java 
import java.util.ArrayList;  
import java.util.Arrays;  
import java.util.Comparator;  
import java.util.PriorityQueue;  
  
class Solution {  
    public static void main(String[] args) {  
        int[][] classes = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};  
  
        System.out.println(scheduleCourse(classes));  
    }  
  
    public static int scheduleCourse(int[][] courses) {  
        int count = 0;  
        Arrays.sort(courses, (a, b) -> Integer.compare(a[1], b[1])); // Want to deal with the earliest deadlines first.  
        PriorityQueue<Integer> pq=new PriorityQueue<>((a, b)->b-a); // This is making a max queue  
        int tTime = 0;  
  
        for (int[] course: courses) {  
            int time = course[0], end = course[1];  
            pq.offer(time); //adding the current time of the course we are looking at. Should be the lowest time.  
            tTime += time;  
            count++;  
            while (tTime > end) { //if exceeds the daily amount of time  
                tTime -= pq.poll(); //remove the highest costing time taken from this func  
                count--;  
            }  
        }  
        return count;  
    }  
}
```
Greedy solution works here. We sort the array by earliest deadline first and we make a max pq. Max pq because if we add a course with a earlier deadline but a massive time taken then we want to remove the class that takes the most amount of time until the var tTime is lower than the ending time. We dont want to drop the current course because that may lead to an issue where a larger endtime course might not fit due to have the not most effiecient course time to course ratio.

# Problem

There are totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day. ("less than sign" already accomodates for 101, and does so for the rest also)
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.

##### Constraints:
-   `1 <= courses.length <= 10^4`
-   `1 <= durationi, lastDayi <= 10^4`
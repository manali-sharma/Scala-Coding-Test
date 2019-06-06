# Scala-Coding-Test
This repository is intended to share solutions to a specific problem. 

# Given Problem Statement
Four people come to a river in the night. There is a narrow bridge, but it can only hold two people at a time. They have one torch and, because it's night, the torch has to be used when crossing the bridge. Person A can cross the bridge in 1 minute, B in 2 minutes, C in 5 minutes, and D in 10 minutes. When two people cross the bridge together, they must move at the slower person's pace.
<br>
Write a program in C++ that determines the fastest time they can cross the bridge. The entry to the program will be a yaml file that describes the speeds of each Person. In this situation there are 4 people but your program should assume any number of people can be passed in.

# Problem Statement Interpetation 
Let,<br>
totalPeople be the number of people trying to cross the bridge <br>
crossingSpeeds store the time required by each person to cross the bridge <br>
Time taken by 2 people (t1 and t2) to cross the bridge = max(crossingSpeeds[t1], crossingSpeeds[t2]) <br>
Determine the minimum time required for all of the totalPeople to cross the bridge <br>

# Solution Approach 1 : 
Follow the following steps sequentially:<br>
STEP 1:<br>
Sort the crossingSpeeds vector<br>
total_time_taken = 0
<br>
<br>
STEP 2:<br>
Pick the person with the fastest crossing Speeds and call him the transporter
<br>
<br>
STEP 3:<br>
Pick any one of the other totalPeople-1 such that the transporter who is the fastest(f1) and this selected person (s1) cross the bridge together. Thus total_time_taken = total_time_taken + max(crossingSpeeds[f1], crossingSpeeds[s1]) = total_time_taken + crossingSpeeds[s1]
<br>
<br>
STEP 4:<br>
The transporter f1 returns back to the initial point crossing back the bridge. total_time_taken = total_time_taken + crossingSpeeds[f1]
<br>
<br>
STEP 5:<br>
Make s1 as visited, such that it is not selected again as it has already crossed the bridge.
<br>
<br>
STEP 6:<br>
Jump to STEP 3 until there is just one person(last_person) remaining to cross the bridge.
<br>
<br>
STEP 7:<br>
The last person and the transporter f1 cross the bridge together. total_time_taken = total_time_taken + crossingSpeeds[last_person]
<br>

# Solution Approach 1 implementation:
The solution can be implemented using the following lines of code:<br>
sort(crossingSpeeds.begin(),crossingSpeeds.end());<br>
total_time_taken = (totalPeople - 2) * crossingSpeeds[0] + accumulate(crossingSpeeds[1], crossingSpeeds.end(), 0);
<br>
<br>
crossingSpeeds[0] refers to the fastest person -> thus it is assigned as the transporter
<br>
The fastest person would cross the bridge with totalPeople-1 slower people, as max(crossingSpeed[0], crossingSpeed[anyother]) = crossingSpeeds[anyother], thus we sum the bridge crossing time of all the other nodes.
<br>
As per STEP 6, the transporter f1 returns to the initial point until there are 2 nodes remaining thus it returns totalPeople-2 times. Therefore, (totalPeople - 2) * crossingSpeeds[0] is added to the total time.
<br>
Since we pass over every node. The total time complexity = complexity of sort + O(n)
<br>
Time Complexity =O(nlogn+n) = O(nlogn)

# Problem with Solution Approach 1:
The solution Approach 1 picks the fastest node and send all the other slower nodes one by one. But, we can make two nodes cross the bridge at once. We did not use this property properly. If two slower people s1 and s2 with nearly same crossingSpeeds cross the bridge together, we can reduce the total time taken by a factor of crossingSpeeds[s1]/2.
<br>
Thus solution approach 1 does not give the correct solution.

# Solution Approach 2 : 
Follow the following steps sequentially:<br>
STEP 1:<br>
Sort the crossingSpeeds vector<br>
total_time_taken = 0
<br>
<br>
STEP 2: <br>
Use approach 1 until you see that it is inefficient to send the two people together. That is the bias created from second fastest and the fastest node described in the implementation section is greater than the crossingSpeed of a pair.
<br>
<br>
STEP 3:<br>
Pick the 2 people with the fastest crossing Speeds and call them the transporters t1 and t2.<br>
assume t1 is the fastest.
<br>
<br>
STEP 4:<br>
t1 and t2 cross the bridge together. <br>
total_time_taken = total_time_taken + crossing_Speeds[t2]
<br>
<br>
STEP 5:<br>
The transporter t1 returns to the initial point crossing back the bridge. <br>
total_time_taken = total_time_taken + crossingSpeeds[t1]
<br>
<br>
STEP 6:<br>
Pick any two of the other totalPeople-2 slower people (s1 and s2) who cross the bridge together.  <br>
total_time_taken = total_time_taken + max(crossingSpeeds[s1], crossingSpeeds[s2])
Make s1 and s2 as visited, such that they are not selected again as they have already crossed the bridge.
<br>
<br>
STEP 7:<br>
Jump to STEP 4 
<br>

# Solution Approach 2 implementation:
This implementation is extended from the Solution Approach 1 in the code -  making the code scalable.
<br>
Change to the previous implementation:
total_time_taken = (totalPeople - 3) * crossingSpeeds[0] + accumulate(crossingSpeeds.begin(), crossingSpeeds.end(), 0);

Since two people cross the bridge at a time. In the end there would be two people remaining instead of one who have not crossed the bridge. Thus, the fastest person crosses back totalPeople-3. 
Note that we have summed all the crossingSpeeds initially. Then later in the while loop we jump over every alternate node and subtract the faster speed as the time taken to cross = max(crossingSpeeds[node1], crossingSpeeds[node2]) where node 1 and node 2 any arbitary nodes.

STEP 3 and STEP 4 imply there is a bias added everytime a set of people cross the bridge.<br>
The fastest and the second fastest cross the bridge and one of these transporters comes back with the tourch then after the two slower people have crossed the bridge the other transporter comes back with the tourch.
<br>
bias = time taken for fastest and second fastest to cross + time taken by second fastest to return + time taken by the fastest to return<br>
bias = max(crossingSpeeds[t1], crossingSpeeds[t2])+crossingSpeed[t2]+crossingSpeeds[t1]<br>
<br>
since the vector is soreted t1=0, t2=1
<br>
<br>
bias = max(crossingSpeeds[0], crossingSpeeds[1])+crossingSpeeds[1]+crossingSpeeds[0]<br>
bias = crossingSpeeds[1]+crossingSpeeds[1]+crossingSpeeds[0]<br>
bias = 2 * crossingSpeeds[1] + crossingSpeeds[0]<br>
<br>
This bias is added to every pair of people crossing the bridge as follows:
bias = 2 * crossingSpeeds[1] - crossingSpeeds[0];<br>
		while (crossingSpeeds[i - 2] > bias) {<br>
			total_time_taken -= crossingSpeeds[i - 2] - bias;<br>
			i = i - 2;<br>
		}<br>
    <br>
The While condition:<br>
This condition combines approach 1 and approach 2. If the bias is greater than the speed of the pair of people crossing the bridge then use approach 1, otherwise use approach 2.
Why do we still keep approcah 1? -> For the beginning values when the bias is larger than the speed of the crossing people, it is better to send the fastest person with the slower person whose crossingSpeed is very close to the crossingSpeed of the second fastest person instead of using the second fastest person twice.




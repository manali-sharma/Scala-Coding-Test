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
Time taken by 2 people (p1 and p2) to cross the bridge = max(crossingSpeeds[p1], crossingSpeeds[p2]) <br>
Determine the minimum time required for all of the totalPeople to cross the bridge <br>

# Solution Approach 1 : 
Follow the following steps sequentially:<br>
STEP 1:<br>
Sort the crossingSpeeds vector
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
STEP 6:
Jump to STEP 3 until there is just one person(last_person) remaining to cross the bridge.
<br>
<br>
STEP 7:<br>
The last person and the transporter f1 cross the bridge together. total_time_taken = total_time_taken + crossingSpeeds[last_person]
<br>

# Solution Approach 1 implementation:
The solution can be implemented using the following lines of code:<br>
sort(crossingSpeeds.begin(),crossingSpeeds.end());<br>
mintotal = (totalPeople - 3) * crossingSpeeds[0] + accumulate(crossingSpeeds[1], crossingSpeeds.end(), 0);
<br>
<br>
crossingSpeeds[0] refers to the fastest person -> thus it is assigned as the transporter
<br>
The fastest person would cross the bridge with totalPeople-1 slower people, as max(crossingSpeed[0], crossingSpeed[anyother]) = crossingSpeeds[anyother], thus we sum the bridge crossing time of all the other nodes.
<br>
As per STEP 6, the transporter f1 returns to the initial point until there are 2 nodes remaining thus it returns totalPeople-3 times. Therefore, (totalPeople - 3) * crossingSpeeds[0] is added to the total time.
<br>

# Problem with Solution Approach 1:
The solution Approach 1 picks the fastest node and send all the other slower nodes one by one. But, we can make two nodes cross the bridge at once. We did not use this property properly. If two slower people s1 and s2 with nearly same crossingSpeeds cross the bridge together, we can reduce the total time taken by a factor of crossingSpeeds[s1]/2.
<br>
Thus solution approach 1 does not give the correct solution.



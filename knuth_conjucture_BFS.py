name="Aditya Singh"
rollNo="21/11/EC/028"




# Python program to find KNUTH CONJECTURE solution of a given input number
import math

def find_knuth_conjecture_bfs(target):
    queue = [(4, "4")]
    while queue:
        current, steps = queue.pop(0)
        if current == target:
            return steps
        else:
            if(current == int(current)) :
                if(current < 100):
                    queue.append((math.factorial(int(current)), steps + "!" ))
            else:
                queue.append((math.floor(current), steps + "]" ))
            if current > 1:
                queue.append((current**0.5, steps + "v" ))
        # print(queue)
    return None

#In this if the code is used in dfs format then if we take a wrong step once then we are trapped in a very long loop which would never be able to reach the target since the path to a target is unique.
print(find_knuth_conjecture_bfs(int(input("Enter a number to find the KNUTH CONJECTURE solution "))))
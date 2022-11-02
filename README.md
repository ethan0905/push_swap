# push_swap 🧮
You're gonna need to sort a random list of numbers, using two stacks and with the less amount of moves. To do so, you're gonna manipulate the stacks using only allowed movements: swap (sa, sb, ss), rotate (ra, rb, rr), reverse (rra, rrb, rrr) and push (pa, pb)

###### Read more [here](https://cdn.intra.42.fr/pdf/pdf/39493/en.subject.pdf)

## Preview

https://user-images.githubusercontent.com/77629339/146821288-20e3957c-9d56-4786-9ad4-d90eab1e57be.mov

## Algorithm made: Intelligent Insertion sort  
  
Goal in this project is to create an algorithm that can sort the list with the less amount of moves.  
  
There is tons of sorting algorithms, but we want to work on one that gonna be enought efficient, and not to hard to develop.  That why i created my own algorithm, that think by himself, and take good and the best optimized decision each round.  
  
Everytime my algo need to select one number to sort, it calculate on all remaining numbers which one can be placed at the right place, in the less amount of moves. It takes it, and place it. Then, we iterating until there stack B is empty. We end up with fully sorted stack A.

#### Step to follow for implementation of my IIS algorithm:   
1. Push all number from the stack A to the stack B. If that number is < to the median number of the final stack, push it to B (pb) then rotate it in order to make it goes under the stack (rb). Else, if that number is > to the median, simply push it to B (pb). This way, we have a pre-sorted stack on B, with 2 blocks of numbers, the big ones and the small ones.  
2. Check the first number of stack B (stackB[0]) and count how much moves you gonna need in order to push it on right spot in A. Then check how much moves you need to push the stackB[1] in on the right spot in A, and so on... When you did this on all stackB, push to A only the one that needed the less amount of moves.  
3. Repeat the operation till there is no more number in B.  

## Performances  
  
| | Required for 5/5 | Mine |
| ------------- | ------------- | ------------- |
| For 5 numbers:  | < 12 moves | 5-11 moves |
| For 100 numbers:  | < 700 moves | 500-670 moves |
| For 500 numbers:  | < 5500 moves | 4300-4900 moves |

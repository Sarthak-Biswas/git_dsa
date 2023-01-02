# Dijkstras Important notes :

## Priority queue in C++ stl :
1. For max-heap  
   ```priority_queue<int>```
2. For min-heap  
   ```priority_queue<int, vector<int>, greater<int>>```
3. For pairs (max-heap on first element in pair)  
   ```priority_queue<pair<int, int>>```
4. For pairs (min-heap on first element in pair)  
   ```priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>```
5. For pairs (max/min-heap on second element in pair)  
   ```priority_queue<pair<int, int>, vector<pair<int, int>>, myComp>```  
   Use a custom operator overloading

### About opertor overloading :
- Use this for max-heap  
   ```
   struct myComp{
        bool operator()(
            pair<int,int> const &a,
            pair<int,int> const &b
        ){
            return a.second>b.second;
        }
    };
    ```
- Use this for min-heap  
   ```
   struct myComp{
        bool operator()(
            pair<int,int> const &a,
            pair<int,int> const &b
        ){
            return a.second<b.second;
        }
    };
    ```

## Concept :
- Priority queue stores the edges of shortest path.
- If edge shorter than this exists from the edge to child edge, it is pushed in the queue.
- Repeat until priority queue is empty or destination edge is reached.
- It works because no negative edge exists. So this greedy approach works.

## Drawbacks :
- Does not work for negative weights.
- Slower than directed topological shortest path.
- Time complexity = O(V.logE)

## Steps :
- Make the graph.
- Choose the source and destination node.
- Make a vector (or any other datastructure) to store the distance and initialize the distances to infinity.
- Mark the source node distance to 0.
- Make a priority queue and push the source node with weight.
- Now until priority queue is empty.
- Push all edeges to priority queue whose (weight + weight of the current node) is less than it's previous distance.
- If the destination node is reached or if queue gets empty then break.
- Return the distance of destination node.
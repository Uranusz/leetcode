
//bfs
//clone nodes and edges
public class 133CloneGraph {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if(node == null)
        return null;
        
    ArrayList<UndirectedGraphNode> nodes = new ArrayList<UndirectedGraphNode>();
    HashMap<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
    
    //clone nodes
    
    UndirectedGraphNode copyNode = new UndirectedGraphNode(node.label);
   
    map.put(node, copyNode);   // map<original node, copied node>
    nodes.add(node);
    int start = 0;
    while(start < nodes.size()){
        UndirectedGraphNode head = nodes.get(start++);
        //check the neighbor
        for(int i = 0; i < head.neighbors.size(); i++){
            UndirectedGraphNode neighbor = head.neighbors.get(i);
            if(!map.containsKey(neighbor)){
                copyNode = new UndirectedGraphNode(neighbor.label);
                nodes.add(neighbor);
                map.put(neighbor, copyNode );
                
            }
        }
    }
    
    //connect the edges
    for(UndirectedGraphNode oldNode : nodes){
        UndirectedGraphNode newNode = map.get(oldNode);
        for(UndirectedGraphNode neighbor : oldNode.neighbors){
            //map.get(neighbor) -->new neighbour, then add to new Node's neighbor
            newNode.neighbors.add(map.get(neighbor));
            
        }
        
    }
    return map.get(node);
}
}

  class UndirectedGraphNode {
      int label;
     List<UndirectedGraphNode> neighbors;
      UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 };
 

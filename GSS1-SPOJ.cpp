// Suyash Deshpande
#include <bits/stdc++.h>
using namespace std;

struct node {
    int sum, prefixSum, suffixSum, maxSum;
};

node query(node *tree,int ss,int se,int qs,int qe,int index){

    node result;
    result.sum = result.prefixSum = -600000;
    result.suffixSum = result.maxSum = -600000;

    ///Complete Overlap
    if(ss>=qs && se<=qe){
        return tree[index];
    }
    
    //No Overlap
    if(qe<ss || qs>se){
        return result;
    }
    
    //Partial Overlap - Call both sides and update the current ans 
    int mid = (ss+se)/2;
    node leftAns = query(tree,ss,mid,qs,qe,2*index);
    node rightAns  = query(tree,mid+1,se,qs,qe,2*index+1);
   
    result.sum = leftAns.sum + rightAns.sum;
    result.prefixSum = max(leftAns.prefixSum, leftAns.sum + rightAns.prefixSum);
    result.suffixSum = max(rightAns.suffixSum, rightAns.sum + leftAns.suffixSum);
    result.maxSum = max(result.prefixSum, 
                    max(result.suffixSum, 
                     max(leftAns.maxSum, 
                         max(rightAns.maxSum,
                            leftAns.suffixSum + rightAns.prefixSum))));
   return result;  
    
}


void buildTree(int *a,int s,int e,node *tree,int index){
    // leaf node
    if(s==e){
        tree[index].sum = a[s];
        tree[index].prefixSum = a[s];
        tree[index].suffixSum = a[s];
        tree[index].maxSum = a[s];
        return ;
    }
    
    //Rec case
    int mid = (s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);

    tree[index].sum = tree[2*index].sum + tree[2*index + 1].sum;
    tree[index].prefixSum = max(tree[2*index].prefixSum, tree[2*index].sum + tree[2*index+1].prefixSum);
    tree[index].suffixSum = max(tree[2*index+1].suffixSum, tree[2*index+1].sum + tree[2*index].suffixSum);
    tree[index].maxSum =  max(tree[index].prefixSum,
                            max(tree[index].suffixSum,
                                max(tree[2*index].maxSum,
                                    max(tree[2*index+1].maxSum,
                                        tree[2*index].suffixSum +tree[2*index+1].prefixSum))));
    
    return;
}

int main() {
    
   int n;
   cin>>n;

   int *a = new int[n];
   node *tree  = new node[4*n+1];

   for(int i=0;i<n;i++) {
       cin>>a[i];
   }

   buildTree(a, 0, n-1, tree, 1);

   int m;
   cin>>m;
   while(m--) {
       int x, y;
       cin>>x>>y;
        cout<<query(tree, 0, n-1, x-1, y-1, 1).maxSum<<endl;

   }
    
    
    
    return 0;
}

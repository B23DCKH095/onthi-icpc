#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int a[maxn], segm_tree[4*maxn];

void recalculate(int node) {
    //calculate the solution for the current segment,
    //considering the sons are correctly solved
    segm_tree[node] = min(segm_tree[2 * node + 1], segm_tree[2 * node + 2]);
}

void build(int node, int left, int right) { //"node" is the index in the array, while "left"
                                            // and "right" are the ends of the current segment
    if (left == right) {
        segm_tree[node] = a[left]; //we are in a leaf node
    } else {
        int middle = (left + right) / 2;
        build(2 * node + 1, left, middle);
        build(2 * node + 2, middle + 1, right);
        recalculate(node);
    }
}

void update(int node, int left, int right, int x, int y) {
    if (left == right) { //we are in the xth leaf
        segm_tree[node] = y;
    } else {
        int middle = (left + right) / 2;
        if (x <= middle) { //we need to update the left son
            update(2 * node + 1, left, middle, x, y);
        } else {
            update(2 * node + 2, middle + 1, right, x, y);
        }
        //after updating said son, recalculate the current segment
        recalculate(node);
    }
}
int query(int node, int left, int right, int x, int y) {
    if (x <= left && right <= y) {
        //the segment of "node" is completely included in the query
        return segm_tree[node];
    } else {
        int answer = 1e9;
        int middle = (left + right) / 2;
        if (x <= middle) {
            //the query segment and the left son segment have at least one element in common
            answer = min(answer, query(2 * node + 1, left, middle, x, y));
        }
        if (y >= middle + 1) {
            //the query segment and the right son segment have at least one element in common
            answer = min(answer, query(2 * node + 2, middle + 1, right, x, y));
        }
        //we would not have entered this function if (x, y) and (left, right) had nothing in common,
        //so there is no risk of answer returning -Infinity here, as either the left or the right son
        //would update it
        return answer;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1 ; i<= n ; i++) cin >> a[i];
    build(0,1,n);
    for(int i = 0 ; i< m ;i++){
        int t,u,v;
        cin >> t>> u >> v;
        if(t==1){
            update(0,1,n,u,v);
        }
        else cout << query(0,1,n,u,v)<< endl;
    }
}
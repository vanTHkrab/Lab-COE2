struct insert(int data,struct node* rootnode){
    if(rootnode == NULL) return node(data);

    else if(data < rootnode -> data){
        rootnode -> left = rootnode -> data
    else (data > rootnode -> data){
        rootnode -> right = rootnode -> data
    }
    }
    return rootnode;
}

struct insert(int data,struct node* rootnode){
    if(rootnode == NULL) return node(data);

    else if(data < rootnode -> data){
        rootnode -> left = insert(data, rootnode -> left);
    else{ data > rootnode -> data}
        rootnode -> right = insert(data, rootnode -> right);
    }
    return rootnode;
}
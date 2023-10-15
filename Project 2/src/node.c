typedef struct TreeNode{
	char *data;
	struct TreeNode* l;
	struct TreeNode* r;
}link;

link* CreateTree(int height) {
    if (height == -1) { return NULL; }

    link* x = (link*)malloc(sizeof(link));
    x->l = CreateTree(height - 1);
    x->r = x->l; // Initialize right subtree as a copy of the left

    // If height is 0, both left and right subtrees are NULL
    if (height == 0) { x->l = NULL; }
    x->data = NULL;
    return x;
}

void DestroyTree(link* root) {
    if (root == NULL) { return; }
    DestroyTree(root->l);
    DestroyTree(root->r);
    if (root->data != NULL) { free(root->data); }
    free(root);
}

int count(link* h) {
    return (h == NULL) ? 0 : count(h->l) + count(h->r) + 1;
}
void PrintTree(link* root, int height) {
    static int counter = 1;
    if (root == NULL || height < 0) { return; }
    if (height == 0) { printf("%d) %s\n", counter, root->data); counter++; }
    PrintTree(root->l, height - 1);
    PrintTree(root->r, height - 1);
}
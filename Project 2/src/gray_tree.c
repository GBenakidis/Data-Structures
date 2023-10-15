link* SimpleGrayTree(link* root1, int height) {
    root1->l->data = (unsigned char*)malloc((height + 1) * sizeof(unsigned char));
    root1->r->data = (unsigned char*)malloc((height + 1) * sizeof(unsigned char));
    
    if (root1->l->data == NULL || root1->r->data == NULL) { perror("Memory allocation failed"); exit(1); }

    for (int i = 0; i < height; i++) {
        root1->l->data[i] = '0';
        root1->r->data[i] = '1';
    }
    root1->l->data[height] = '\0';
    root1->r->data[height] = '\0';
    return root1;
}

void DuplicateTree(link* root1, link* root2, int height) {
    if (root1->l == NULL || root1->r == NULL) {
        unsigned char* tmp = (unsigned char*)malloc((height + 1) * sizeof(unsigned char));

        for (int i = 0; i <= height; i++) {
            tmp[i] = root1->data[i];
        }

        root1->data = (unsigned char*)malloc((height + 2) * sizeof(unsigned char));
        root2->data = (unsigned char*)malloc((height + 2) * sizeof(unsigned char));
        root1->data[0] = '0';
        root2->data[0] = '1';

        for (int i = 1; i < height + 2; i++) {
            root1->data[i] = root2->data[i] = tmp[i - 1];
        }
        root1->data[height + 1] = root2->data[height + 1] = '\0';
        free(tmp);
    } else {
        DuplicateTree(root1->l, root2->r, height);
        DuplicateTree(root1->r, root2->l, height);
    }
}
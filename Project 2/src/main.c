#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "node.c"
#include "encoding.c"
#include "gray_tree.c"
#include "printing.c"

int main(void) {
    int height = 8;
    link* root = CreateTree(height);
    PopulateAscii(root, height);

    char str[10000] = {0};
    printf("\nGive a message: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    EncodeString(root, str);
    PopulateGrey(root, height);
    DecodeString(root);

    int choice;
    printf("\nTell me the size of the gray tree you want to create: ");
    scanf("%d", &choice);

    link* finalTree = NULL;
    link* currentTree = NULL;
    int i = 1;

    while (i < choice) {
        link* root3 = CreateTree(i);
        DuplicateTree(currentTree, root3, i);
        link* x = (link*)malloc(sizeof(link));
        x->l = currentTree;
        x->r = root3;
        x->data = NULL;

        if (finalTree) {
            link* newFinalTree = CreateTree(i + 1);
            DuplicateTree(finalTree, x, i);
            DestroyTree(finalTree);
            DestroyTree(x);
            finalTree = newFinalTree;
        } else {
            finalTree = x;
        }

        currentTree = finalTree;
        i++;
    }

    printTree(finalTree, i);
    DestroyTree(finalTree);
    DestroyTree(root);
    return 0;
}

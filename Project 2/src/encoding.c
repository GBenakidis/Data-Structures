void EncodeString(link* root, const char* str) {
    FILE* fp;
    unsigned char code;
    link* tree = NULL;

    if ((fp = fopen("Decoded.txt", "w")) == NULL) {
        perror("File could not open");
        DestroyTree(root);
        exit(1);
    }

    printf("Encode:");

    for (int i = 0; i < strlen(str); i++) {
        unsigned char* ptr = charToBinary(str[i]);
        tree = root;
        int j = 0;

        while (ptr[j] != '\0') {
            if (ptr[j] == '0') {
                tree = tree->l;
            }
            else if (ptr[j] == '1') {
                tree = tree->r;
            }
            j++;
        }

        code = 0;
        for (j = strlen(ptr) - 1; j >= 0; j--) {
            if (tree->data[strlen(ptr) - 1 - j] == '1') {
                code += (unsigned char)pow(2, j);
            }
        }
        free(ptr);
        if (i == 0) {
            fprintf(fp, "%c", code);
            printf("%c", code);
        } else {
            fprintf(fp, "%c", code);
            printf("%c", code);
        }
    }

    fclose(fp);
}

void DecodeString(link* root) {
    FILE* fp;
    unsigned char decode;
    link* tree = NULL;

    if ((fp = fopen("Encoded.txt", "r")) == NULL) {
        printf("File could not open \n");
        DestroyTree(root);
        exit(1);
    }
    printf("Decode:");
    unsigned char ch;
    while (fread(&ch, sizeof(ch), 1, fp) == 1) {
        unsigned char* ptr = charToBinary(ch);
        tree = root;
        int j = 0;
        while (ptr[j] != '\0') {
            if (ptr[j] == '0') {
                tree = tree->l;
            }
            else if (ptr[j] == '1') {
                tree = tree->r;
            }
            j++;
        }
        decode = 0;
        for (j = strlen(ptr) - 1; j >= 0; j--) {
            if (tree->data[strlen(ptr) - 1 - j] == '1') {
                decode += pow(2, j);
            }
        }
        free(ptr);
        printf("%c", decode);
    }
    fclose(fp);
}

unsigned char* charToBinary(unsigned char n) {
    unsigned char* binaryString = (unsigned char*)malloc(9);
    if (binaryString == NULL) { perror("Memory allocation failed"); exit(1); }
    binaryString[8] = '\0';  // Null-terminate the string
    for (int i = 7; i >= 0; i--) {
        binaryString[i] = (n & (1 << i)) ? '1' : '0';
    }
    return binaryString;
}
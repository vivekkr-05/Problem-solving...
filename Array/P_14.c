char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    for (int i = 1; i < strsSize; i++) {
        if (strs[0][0] != strs[i][0]) {
            return "";
        }
    }

    char* common = strs[0];

    for (int i = 1; i < strsSize; i++) {
        int j = 0;

        while (common[j] && strs[i][j] && common[j] == strs[i][j]) {
            j++;
        }

        common[j] = '\0';

        if (common[0] == '\0') return "";
    }

    return common;
}
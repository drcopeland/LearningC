/* Ex. 2-5: Write the function any(s1, s2) which returns the
first location in the string s1 where any character from the string s2
occurs, or -1 if s1 contains no characters from s2. */

main () {
    char s[] = "Hello, world.";
    char t[] = "My nam is ZZyzx.";

    printf("%d\n", any(s,t));

}

int any(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; (s2[j] != '\0') && (s2[j] != s1[i]); ++j) ;
        if (s2[j] != '\0') { // this means s1[i] is contained in s2 
            return i;
        }
    }
    return -1;
}
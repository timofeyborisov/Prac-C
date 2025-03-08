#include <stdio.h>
struct character {
    int from;
    // from state
    int label;
    // transition label
    int to;
    // to state 
};
int
main(void)
{
    int num_t;
    scanf("%d", &num_t);
    struct character t[num_t];
    for (int i = 0; i < num_t; i++) {
        scanf("%d %d %d", &t[i].from, &t[i].label, &t[i].to);
    }
    printf("%s\n", "#include <stdio.h>");
    printf("%s\n", "int");
    printf("%s\n", "main(void)");
    printf("%s\n", "{");
    printf("%s\n", "    int a = 0");
    printf("%s\n", "    //input");
    printf("%s\n", "    int state = 0");
    printf("%s\n", "    //start state");
    printf("%s\n", "    //start state");
    printf("%s\n", "    while (1) {");
    printf("%s\n", "        scanf(\"%%d\\n\", &a);");
    printf("%s\n", "                if (a == 0) {");
    printf("%s\n", "                    break;");
    printf("%s\n", "                }");
    printf("%s\n", "                switch (state) {");
    for (int i = 0; i < t[i].label; i++) {
        printf("%s%d\n", "                    case %d: {", t[i].from);
        printf("%s%d\n", "                        if (a == %d) {", t[i].label);
        printf("%s%d\n", "                            state = %d;", t[i].to);
        printf("%s\n", "                            break;");
        printf("%s\n", "                        }");
    }
    printf("%s\n", "                    }");
    printf("%s\n", "                }");
    printf("%s\n", "                if (state == 0) {");
    printf("%s\n", "                    printf(\"%%s\\n\", \"YES\")");
    printf("%s\n", "                }");
    printf("%s\n", "                else {");
    printf("%s\n", "                    printf(\"%%s\\n\", \"NO\")");
    printf("%s\n", "                }");
    printf("%s\n", "                return 0;");
    printf("%s\n", "}");
    return 0;
}

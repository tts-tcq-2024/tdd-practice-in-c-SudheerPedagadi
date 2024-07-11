#define MAX_NUMBERS 100
#define BUFFER_SIZE 100

void split(const char* str, const char* delimiter, char result[MAX_NUMBERS][BUFFER_SIZE], int* count) {
    char temp[BUFFER_SIZE];
    strcpy(temp, str);

    char* token = strtok(temp, delimiter);
    while (token != NULL) {
        strcpy(result[*count], token);
        (*count)++;
        token = strtok(NULL, delimiter);
    }
}

void handleNegatives(int negatives[], int neg_count) {
    if (neg_count > 0) {
        printf("Negatives not allowed:");
        for (int i = 0; i < neg_count; i++) {
            printf(" %d", negatives[i]);
        }
        printf("\n");
        exit(1);
    }
}

const char* parseDelimiter(const char* input, char delimiter[BUFFER_SIZE]) {
    if (strncmp(input, "//", 2) == 0) {
        const char* newline = strchr(input, '\n');
        if (newline != NULL) {
            int len = newline - input - 2;
            strncpy(delimiter, input + 2, len);
            delimiter[len] = '\0';
            return newline + 1;
        }
    }
    strcpy(delimiter, ",\n");
    return input;
}

int calculateSum(const char* input, const char* delimiter) {
    char numbers[MAX_NUMBERS][BUFFER_SIZE];
    int count = 0;
    split(input, delimiter, numbers, &count);

    int sum = 0;
    int negatives[MAX_NUMBERS];
    int neg_count = 0;

    for (int i = 0; i < count; i++) {
        int number = atoi(numbers[i]);
        if (number < 0) {
            negatives[neg_count++] = number;
        } else if (number <= 1000) {
            sum += number;
        }
    }

    handleNegatives(negatives, neg_count);
    return sum;
}

int add(const char* input) {
    if (input == NULL || *input == '\0') {
        return 0;
    }

    char delimiter[BUFFER_SIZE];
    input = parseDelimiter(input, delimiter);
    return calculateSum(input, delimiter);
}


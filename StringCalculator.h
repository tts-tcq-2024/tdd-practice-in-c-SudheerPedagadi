int add(const char* input) {
    if (input == NULL || strlen(input) == 0) {
        return 0;
    }

    int sum = 0;
    char delimiter = ',';
    const char* numbers = input;

    // Check for custom delimiter
    if (strncmp(input, "//", 2) == 0) {
        delimiter = input[2];
        numbers = input + 4; // Skip "//[delimiter]\n"
    }

    char buffer[100];
    int bufferIndex = 0;

    for (size_t i = 0; i <= strlen(numbers); ++i) {
        if (numbers[i] == delimiter || numbers[i] == '\n' || numbers[i] == '\0') {
            if (bufferIndex > 0) {
                buffer[bufferIndex] = '\0';
                int number = atoi(buffer);
                if (number <= 1000) {
                    sum += number;
                }
                bufferIndex = 0;
            }
        } else {
            buffer[bufferIndex++] = numbers[i];
        }
    }

    return sum;
}

//Editorial: Approach 4: Using Math Formula

int leastInterval(char* tasks, int tasks_size, int n) {
    if (n == 0) return tasks_size;

    int freq[26] = {0};

    for (int i = 0; i < tasks_size; i++) {
        freq[tasks[i] - 'A']++;
    }

    int max_freq = 0, max_count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_count = 1;
        } else if (freq[i] == max_freq) {
            max_count++;
        }
    }

    int part_count = max_freq - 1;
    int part_length = n + 1;
    int min_intervals = part_count * part_length + max_count;

    return tasks_size > min_intervals ? tasks_size : min_intervals;
}
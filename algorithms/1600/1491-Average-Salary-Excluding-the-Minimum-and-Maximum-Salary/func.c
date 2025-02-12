double average(int* salary, int salarySize) {
    double max, min, sum;
    max = min = sum = salary[0];
    for (int i = 1; i < salarySize; i++) {
        if (salary[i] > max) {
            max = salary[i];
        } else if (salary[i] < min) {
            min = salary[i];
        }
        sum += salary[i];
    }

    return (sum - max - min) / (salarySize - 2);
}
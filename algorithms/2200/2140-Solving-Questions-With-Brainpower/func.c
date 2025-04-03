long long mostPoints(int** questions, int questionsSize, int* questionsColSize) {
    long long* dp = (long long*)calloc((questionsSize + 1), sizeof(long long));
    
    // Process questions from the end to the start
    for (int i = questionsSize - 1; i >= 0; i--) {
        int points = questions[i][0];
        int brainpower = questions[i][1];
        int next_question = i + brainpower + 1;
        
        if (next_question < questionsSize) {
            dp[i] = (dp[i + 1] > points + dp[next_question]) ? dp[i + 1] : points + dp[next_question];
        } else {
            dp[i] = (dp[i + 1] > points) ? dp[i + 1] : points;
        }
    }
    
    long long result = dp[0];
    free(dp);
    return result;
}
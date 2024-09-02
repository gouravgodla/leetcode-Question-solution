class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long Sum = 0;
        //TO CHECK THE NO OF CHALKS IN TOTAL
        for (int i = 0; i < chalk.length; i++) {
            Sum += chalk[i];
        }
        int remainingchalks = (int) (k % Sum); //TYPE CASTING USED HERE TO CONVERT LONG TO INT
        for (int i = 0; i < chalk.length; i++) {
            //IF REMAINING CHALKS ARE LESS THEN THE SIZE OF CHALKS
            if (remainingchalks < chalk[i]) {
                return i;
            }
           remainingchalks -= chalk[i];
        }
        return -1;
    }
}

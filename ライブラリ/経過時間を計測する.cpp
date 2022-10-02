const int LIMIT_TIME = 500;
bool timeCheck(){return clock() * 100 / CLOCKS_PER_SEC <= LIMIT_TIME;}
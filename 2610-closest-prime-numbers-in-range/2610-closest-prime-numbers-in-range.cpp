class Solution {
public:
    bool isPrime(int n){
        if(n == 1)return false;
        for(int i = 2; i*i <= n; i++){
            if(n % i == 0)return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        priority_queue<int> pq;
        map<int, vector<pair<int,int>>> m;
        
        // make prime list
        for(int n = left; n <= right; n++){
            if(isPrime(n))primes.push_back(n);
        }

        if(primes.size() < 2)return {-1,-1};

        for(int i = 0; i < primes.size()-1; i++){
            pq.push(-(primes[i+1]-primes[i]));
            m[-(primes[i+1]-primes[i])].push_back({primes[i],primes[i+1]});
        }
        return {m[pq.top()][0].first, m[pq.top()][0].second};

    }
};
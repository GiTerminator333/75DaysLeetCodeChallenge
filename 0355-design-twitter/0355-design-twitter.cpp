// init linked list of pair<int, int>
class Twitter {
public:
    struct Node {
        pair<int, int> data;
        Node* next;
        Node(int time, int tweet) {
            data.first = time, data.second = tweet;
            next = NULL;
        }
    };
    // more like merge k sorted LL
    // i will maintain a LL of all the post for each acc in the map <id,
    // pair<int size,node* head> LL design 
    //i will also maintain a map of users who is following
    // then merge the feeds based on recency using maxheap
    // jyada timer val -> more recent tweet

    int timer = 0; // timing of the tweets
    unordered_map<int, pair<int, Node*>> mp;
    unordered_map<int, unordered_set<int>> isFollowing;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        // 10 most recent tweet
        Node* temp = new Node(timer, tweetId);
        if (mp.find(userId) == mp.end()) {
            mp[userId] = {1, temp};
        } else {
            auto &m = mp[userId];
            int size = m.first;
            Node* head = m.second;

            temp->next = head;
            //joining new tweet before last newest tweet
            mp[userId] = {size, temp};
        }

        timer++;
    }

    typedef pair<int, Node*> pi;
    vector<int> getNewsFeed(int userId) {
        // jyada timer val -> more recent tweet
        priority_queue<pi> pq;

        //pushing user node
        if(mp.find(userId) != mp.end()){
            auto head = mp[userId].second;
            pq.push({head->data.first, head}); //{time of recent tweet, head}
        }

        // iterate all the following
        for (auto x : isFollowing[userId]) {
            if(mp.find(x) == mp.end()) continue;
            Node* h = mp[x].second;
            int time = h->data.first;
            pq.push({time, h});
        }

        vector<int> v;

        while (!pq.empty() && v.size() < 10) {
            auto h = pq.top().second;
            pq.pop();
            v.push_back(h->data.second);

            if (h->next) {
                int time = h->next->data.first;
                pq.push({time, h->next});
            }
        }

        return v;
    }

    void follow(int followerId, int followeeId) {
        isFollowing[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        isFollowing[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
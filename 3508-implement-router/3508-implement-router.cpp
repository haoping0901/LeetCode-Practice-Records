class Router {
    // Flow:
        // check if identical pkt exist => need to rec the src, dst, and timestamp of pkt
            // if not, add pkt to FIFO  => a queue with all info
        // pop the pkt in FIFO
        // an unordered_map {dst, timestamp}, maintain simutaneously when updating FIFO
    unordered_map<int, deque<int>> pkt_time_;
    deque<tuple<int, int, int>> fifo_;
    set<tuple<int, int, int>> exist_pkts_;
    int mem_avail_;
public:
    Router(int memoryLimit) {
        mem_avail_ = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        // need to check if a packet with the same src, dst, and timestamp already exist
            // need the src, dst, time info of the packets in FIFO
            // timestamp_{n+1} >= timestamp_n
        tuple<int, int, int> pkt(source, destination, timestamp);

        if (exist_pkts_.find(pkt) != exist_pkts_.end())
            return false;
        
        if (mem_avail_ == 0)
            forwardPacket();
        
        --mem_avail_;
        fifo_.push_back(pkt);
        pkt_time_[destination].push_back(timestamp);
        exist_pkts_.insert(pkt);

        return true;
    }
    
    vector<int> forwardPacket() {
        // pop the front packet in FIFO
        vector<int> ret;

        if (!fifo_.empty()) {
            auto pkt = fifo_.front();
            fifo_.pop_front();
            ret = vector<int>({get<0>(pkt), get<1>(pkt), get<2>(pkt)});
            exist_pkts_.erase(pkt);
            pkt_time_[ret[1]].pop_front();
            ++mem_avail_;
        }

        return ret;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        // return number of packets with the same dst and timestamp in [start, end] range
            // need the dst and the time info of the packets in FIFO
        auto start = lower_bound(pkt_time_[destination].begin(), 
                                 pkt_time_[destination].end(), startTime);
        auto end = upper_bound(pkt_time_[destination].begin(),
                               pkt_time_[destination].end(), endTime);

        return end - start;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
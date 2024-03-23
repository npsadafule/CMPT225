#include <iostream>
#include <vector>
#include <unordered_map>
#include <exception>
#include <algorithm>
#include <stdexcept>

template<int initialSize = 10>
class IPQ {
public:
    IPQ() {
        heap_.reserve(initialSize);
    }

    explicit IPQ(const std::vector<std::pair<std::string, int>>& tasks) {
        heap_.reserve(std::max(static_cast<int>(tasks.size()), initialSize));
        for (const auto& task : tasks) {
            insert(task.first, task.second);
        }
        // Optionally, could apply a more efficient bulk insert + heapify operation.
    }

    void insert(const std::string& tid, int p) {
        if (map_.find(tid) != map_.end()) {
            throw std::invalid_argument("Task ID already exists.");
        }
        Node node = {p, tid};
        heap_.push_back(node);
        int index = heap_.size() - 1;
        map_[tid] = index;
        percolateUp(index);
    }

    std::string deleteMin() {
        if (isEmpty()) {
            throw std::out_of_range("Heap is empty.");
        }
        std::string minTaskID = heap_.front().tid;
        remove(minTaskID);
        return minTaskID;
    }

    std::string& getMin() {
        if (isEmpty()) {
            throw std::out_of_range("Heap is empty.");
        }
        return heap_.front().tid;
    }

    void updatePriority(const std::string& tid, int p) {
        if (map_.find(tid) == map_.end()) {
            throw std::invalid_argument("Task ID does not exist.");
        }
        int index = map_[tid];
        bool isHigherPriority = heap_[index].priority > p;
        heap_[index].priority = p;
        
        if (isHigherPriority) {
            percolateUp(index);
        } else {
            percolateDown(index);
        }
    }

    void remove(const std::string& tid) {
        if (map_.find(tid) == map_.end()) {
            throw std::invalid_argument("Task ID does not exist.");
        }
        int index = map_[tid];
        swap(index, heap_.size() - 1);
        heap_.pop_back();
        map_.erase(tid);

        if (!heap_.empty()) {
            percolateDown(index);
            percolateUp(index);
        }
    }

    bool isEmpty() const {
        return heap_.empty();
    }

    int size() const {
        return heap_.size();
    }

    void clear() {
        heap_.clear();
        map_.clear();
    }

    void reserve(int i) {
        heap_.reserve(std::max(i, initialSize));
    }

private:
    struct Node {
        int priority;
        std::string tid;
    };

    std::vector<Node> heap_;
    std::unordered_map<std::string, int> map_;

    void percolateUp(int index) {
        if (index == 0) return; // Root node, no parent to percolate up to.

        int parentIndex = (index - 1) / 2;
        if (heap_[index].priority < heap_[parentIndex].priority) {
            swap(index, parentIndex);
            percolateUp(parentIndex);
        }
    }

    void percolateDown(int index) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int smallestIndex = index;

        if (leftChildIndex < heap_.size() && heap_[leftChildIndex].priority < heap_[smallestIndex].priority) {
            smallestIndex = leftChildIndex;
        }
        
        if (rightChildIndex < heap_.size() && heap_[rightChildIndex].priority < heap_[smallestIndex].priority) {
            smallestIndex = rightChildIndex;
        }

        if (smallestIndex != index) {
            swap(index, smallestIndex);
            percolateDown(smallestIndex);
        }
    }

    void swap(int i, int j) {
        std::swap(heap_[i], heap_[j]);
        map_[heap_[i].tid] = i;
        map_[heap_[j].tid] = j;
    }
};
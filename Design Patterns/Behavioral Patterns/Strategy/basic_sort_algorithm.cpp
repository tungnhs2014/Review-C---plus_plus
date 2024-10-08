#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> // For std::swap

// Strategy interface
class SortStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0; // Pure virtual function
    virtual ~SortStrategy() {} // Virtual destructor for cleanup
};

// Concrete strategy for Bubble Sort
class BubbleSortStrategy : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data.size() - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
        std::cout << "Sorted using Bubble Sort.\n";
    }
};

// Concrete strategy for Quick Sort
class QuickSortStrategy : public SortStrategy {
public:
    void quickSort(std::vector<int>& data, int low, int high) {
        if (low < high) {
            int pi = partition(data, low, high);
            quickSort(data, low, pi - 1);
            quickSort(data, pi + 1, high);
        }
    }

    int partition(std::vector<int>& data, int low, int high) {
        int pivot = data[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (data[j] < pivot) {
                i++;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[i + 1], data[high]);
        return i + 1;
    }

    void sort(std::vector<int>& data) override {
        quickSort(data, 0, data.size() - 1);
        std::cout << "Sorted using Quick Sort.\n";
    }
};

// Context class that holds a reference to a sorting strategy
class SortContext {
private:
    std::shared_ptr<SortStrategy> strategy; // Holds the current strategy
public:
    void setStrategy(std::shared_ptr<SortStrategy> newStrategy) {
        strategy = newStrategy; // Set new strategy at runtime
    }

    void sort(std::vector<int>& data) {
        if (strategy) {
            strategy->sort(data); // Use the selected strategy to sort data
        } else {
            std::cout << "No sorting strategy selected.\n";
        }
    }
};

int main() {
    std::vector<int> data = {34, 7, 23, 32, 5, 62};

    SortContext context;

    // Use Bubble Sort
    context.setStrategy(std::make_shared<BubbleSortStrategy>());
    context.sort(data);

    // Use Quick Sort
    context.setStrategy(std::make_shared<QuickSortStrategy>());
    context.sort(data);

    return 0;
}

/*
    Sorted using Bubble Sort.
    Sorted using Quick Sort.

*/

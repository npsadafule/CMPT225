# Performance Comparison of Quicksort Variants

## Experiment Overview

This experiment was conducted to evaluate the performance of different Quicksort variants compared to `std::sort`, an optimized sorting function provided by the C++ Standard Library. The objective was to determine how different pivot selection strategies and partitioning schemes affect the efficiency of the Quicksort algorithm on large datasets.

## Quicksort Variants Described

1. **Quicksort with Lomuto Partitioning and Last Element as Pivot**: This variant uses the Lomuto partitioning scheme where the last element of the array segment is chosen as the pivot.
2. **Quicksort with Hoare Partitioning and First Element as Pivot**: This variant employs Hoare's partitioning method with the first element as the pivot, which typically performs fewer swaps compared to Lomuto's method.
3. **Quicksort with Lomuto Partitioning and Median-of-Three Pivot**: This enhances the basic Lomuto partitioning by selecting the pivot as the median of the first, middle, and last elements, aiming to avoid poor pivot choices and improve performance on more diverse datasets.
4. **Quicksort with Hoare Partitioning and Median-of-Three Pivot**: Similar to the third variant, but uses Hoare's partitioning method. This combination is expected to offer robust performance across different types of input data by minimizing the worst-case scenarios typical of standard Quicksort.

## Strategy for Variant Selection

The chosen variants aim to explore the impact of different partitioning methods and pivot selection strategies on the performance of Quicksort. By comparing Lomuto and Hoare partitioning schemes—both with simple and advanced pivot selection methods—we can understand their efficiencies and identify optimal use cases. The inclusion of median-of-three pivot selection tests the hypothesis that a more "intelligent" pivot choice can significantly reduce the number of comparisons and swaps needed, particularly in nearly sorted or reverse-sorted arrays.

## Input Description

The input for the sorting algorithms consisted of a randomly generated array of 100 million integers, ranging from 1 to 1,000,000. This large dataset ensures that the performance differences between the algorithms are significant and observable, providing a robust test of their scalability and efficiency.

## Runtime Performance Table

| Sorting Algorithm                         | Runtime (seconds) |
|-------------------------------------------|-------------------|
| `std::sort`                               | 5.738             |
| Quicksort (Lomuto, Last Element Pivot)    | 29.922            |
| Quicksort (Hoare, First Element Pivot)    | 17.485            |
| Quicksort (Lomuto, Median-of-Three Pivot) | 30.147            |
| Quicksort (Hoare, Median-of-Three Pivot)  | 17.046            |

## Conclusions

- **Efficiency of `std::sort`**: As expected, `std::sort` was the most efficient algorithm tested, likely due to its implementation of introsort, which combines the quicksort, heapsort, and insertion sort algorithms to optimize performance across various data scenarios.
- **Impact of Partitioning Scheme**: Hoare's partitioning consistently outperformed Lomuto's, regardless of the pivot selection strategy used. This suggests that Hoare's method, which reduces the number of swaps and typically has a better balance of split arrays, is more efficient for large datasets.
- **Effect of Median-of-Three Pivot**: The median-of-three pivot selection did not significantly change the performance for Lomuto's partitioning and provided a marginal improvement for Hoare's partitioning. This indicates that while median-of-three can help mitigate worst-case scenarios, its benefits are not as pronounced on random data distributions.
- **Optimal QuickSort Strategy**: For applications where Quicksort is required, using Hoare's partitioning with a median-of-three pivot selection appears to be the most efficient approach among the tested variants. However, for most practical purposes, standard library functions like `std::sort` are recommended due to their superior optimization and reliability.

This experiment highlights the importance of choosing the right algorithm and parameters based on the data characteristics and application requirements to optimize sorting performance.
